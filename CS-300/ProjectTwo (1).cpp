// Melanie Jarrard
// CS 300 Project Two - ABCU Advising Assistance
// Stores course objects in a vector, as recommended in Project One.
// Compile: g++ -std=c++11 -Wall -Wextra -pedantic ProjectTwo.cpp -o ProjectTwo

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct Course {
    std::string number;
    std::string title;
    std::vector<std::string> prerequisites;
};

std::string trim(const std::string& text) {
    const std::string whitespace = " \t\r\n";
    const auto first = text.find_first_not_of(whitespace);
    if (first == std::string::npos) {
        return "";
    }
    return text.substr(first, text.find_last_not_of(whitespace) - first + 1);
}

std::string normalizeNumber(std::string number) {
    number = trim(number);
    for (char& character : number) {
        character = static_cast<char>(std::toupper(static_cast<unsigned char>(character)));
    }
    return number;
}

// Supports comma-separated fields and quoted titles containing commas.
// A doubled quotation mark inside a quoted field represents one quote.
bool parseCsvLine(const std::string& line, std::vector<std::string>& fields) {
    fields.clear();
    std::string field;
    bool inQuotes = false;
    bool closedQuote = false;
    for (std::size_t i = 0; i < line.size(); ++i) {
        const char character = line[i];
        if (inQuotes) {
            if (character == '"') {
                if (i + 1 < line.size() && line[i + 1] == '"') {
                    field += '"';
                    ++i;
                } else {
                    inQuotes = false;
                    closedQuote = true;
                }
            } else {
                field += character;
            }
        } else if (character == ',') {
            fields.push_back(trim(field));
            field.clear();
            closedQuote = false;
        } else if (character == '"') {
            if (closedQuote || !trim(field).empty()) {
                return false;
            }
            field.clear();
            inQuotes = true;
        } else {
            if (closedQuote && !std::isspace(static_cast<unsigned char>(character))) {
                return false;
            }
            field += character;
        }
    }
    if (inQuotes) {
        return false;
    }
    fields.push_back(trim(field));
    return true;
}

// Linear search matches the vector design from Project One.
const Course* findCourse(const std::vector<Course>& courses, const std::string& number) {
    for (const Course& course : courses) {
        if (course.number == number) {
            return &course;
        }
    }
    return nullptr;
}

bool loadCourses(const std::string& filename, std::vector<Course>& courses) {
    std::ifstream input(filename);
    if (!input) {
        std::cout << "Error: Could not open file: " << filename << '\n';
        return false;
    }

    // Validate a temporary catalog first. A failed reload preserves existing data.
    std::vector<Course> pendingCourses;
    std::string line;
    std::size_t lineNumber = 0;
    while (std::getline(input, line)) {
        ++lineNumber;
        // Remove a UTF-8 byte order mark if an editor added one.
        if (lineNumber == 1 && line.compare(0, 3, "\xEF\xBB\xBF") == 0) {
            line.erase(0, 3);
        }
        if (trim(line).empty()) {
            continue;
        }
        std::vector<std::string> fields;
        if (!parseCsvLine(line, fields) || fields.size() < 2 ||
            fields[0].empty() || fields[1].empty()) {
            std::cout << "Error: Invalid course record on line " << lineNumber << ".\n";
            return false;
        }
        Course course;
        course.number = normalizeNumber(fields[0]);
        course.title = fields[1];
        if (findCourse(pendingCourses, course.number) != nullptr) {
            std::cout << "Error: Duplicate course " << course.number
                      << " on line " << lineNumber << ".\n";
            return false;
        }
        for (std::size_t i = 2; i < fields.size(); ++i) {
            const std::string prerequisite = normalizeNumber(fields[i]);
            if (prerequisite.empty() || prerequisite == course.number) {
                std::cout << "Error: Invalid prerequisite on line " << lineNumber << ".\n";
                return false;
            }
            if (std::find(course.prerequisites.begin(), course.prerequisites.end(),
                          prerequisite) == course.prerequisites.end()) {
                course.prerequisites.push_back(prerequisite);
            }
        }
        pendingCourses.push_back(course);
    }
    if (input.bad()) {
        std::cout << "Error: Could not finish reading the file.\n";
        return false;
    }
    if (pendingCourses.empty()) {
        std::cout << "Error: The file contains no course records.\n";
        return false;
    }

    // Check references after reading all records, allowing prerequisites later in the file.
    for (const Course& course : pendingCourses) {
        for (const std::string& prerequisite : course.prerequisites) {
            if (findCourse(pendingCourses, prerequisite) == nullptr) {
                std::cout << "Error: " << course.number << " references missing prerequisite "
                          << prerequisite << ".\n";
                return false;
            }
        }
    }
    courses.swap(pendingCourses);
    std::cout << "Successfully loaded " << courses.size() << " courses.\n";
    return true;
}

void printCourseList(std::vector<Course>& courses) {
    // Sort the complete catalog, including MATH courses, by course number.
    std::sort(courses.begin(), courses.end(), [](const Course& left, const Course& right) {
        return left.number < right.number;
    });
    std::cout << "Here is a sample schedule:\n\n";
    for (const Course& course : courses) {
        std::cout << course.number << ", " << course.title << '\n';
    }
}

void printCourseInformation(const std::vector<Course>& courses, const std::string& number) {
    const Course* course = findCourse(courses, normalizeNumber(number));
    if (course == nullptr) {
        std::cout << "Error: Course not found.\n";
        return;
    }
    std::cout << course->number << ", " << course->title << '\n';
    if (course->prerequisites.empty()) {
        std::cout << "Prerequisites: None\n";
        return;
    }
    std::cout << "Prerequisites:\n";
    for (const std::string& prerequisite : course->prerequisites) {
        const Course* requiredCourse = findCourse(courses, prerequisite);
        if (requiredCourse != nullptr) {
            std::cout << "  " << requiredCourse->number << ", " << requiredCourse->title << '\n';
        }
    }
}

int main() {
    std::vector<Course> courses;
    std::string choice;
    std::cout << "Welcome to the course planner.\n";
    while (true) {
        std::cout << "\n1. Load Data Structure.\n"
                  << "2. Print Course List.\n"
                  << "3. Print Course.\n"
                  << "9. Exit\n\nWhat would you like to do? ";
        if (!std::getline(std::cin, choice)) {
            break;
        }
        choice = trim(choice);
        if (choice == "9") {
            break;
        } else if (choice == "1") {
            std::string filename;
            std::cout << "Enter the course data filename (or full path): ";
            if (!std::getline(std::cin, filename)) {
                break;
            }
            filename = trim(filename);
            // Windows Copy as path may surround a filename with quotes.
            if (filename.size() >= 2 && filename.front() == '"' && filename.back() == '"') {
                filename = filename.substr(1, filename.size() - 2);
            }
            loadCourses(filename, courses);
        } else if (choice == "2" || choice == "3") {
            if (courses.empty()) {
                std::cout << "Please load the course data using option 1 first.\n";
                continue;
            }
            if (choice == "2") {
                printCourseList(courses);
            } else {
                std::string number;
                std::cout << "What course do you want to know about? ";
                if (!std::getline(std::cin, number)) {
                    break;
                }
                printCourseInformation(courses, number);
            }
        } else {
            std::cout << "Invalid option. Please enter 1, 2, 3, or 9.\n";
        }
    }
    std::cout << "Thank you for using the course planner!\n";
    return 0;
}
