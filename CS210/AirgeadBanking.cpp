#include "AirgeadBanking.h"
#include <iostream>
#include <iomanip>
using namespace std;

AirgeadBanking::AirgeadBanking() {
    m_initialInvestment = 0.0;
    m_monthlyDeposit = 0.0;
    m_annualInterest = 0.0;
    m_numberOfYears = 0;
}

void AirgeadBanking::getUserInput() {
    cout << "**********************************" << endl;
    cout << "********** Data Input ************" << endl;

    cout << "Initial Investment Amount: ";
    cin >> m_initialInvestment;

    cout << "Monthly Deposit: ";
    cin >> m_monthlyDeposit;

    cout << "Annual Interest: ";
    cin >> m_annualInterest;

    cout << "Number of years: ";
    cin >> m_numberOfYears;
}

void AirgeadBanking::displayMenu() const {
    cout << fixed << setprecision(2);
    cout << "\nPress Enter to continue . . ." << endl;
    cin.ignore();
    cin.get();
}

void AirgeadBanking::displayReportWithoutMonthlyDeposits() const {
    double balance = m_initialInvestment;

    cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
    cout << "=========================================================\n";
    cout << "Year\tYear End Balance\tYear End Earned Interest\n";

    for (int year = 1; year <= m_numberOfYears; year++) {
        double yearlyInterest = 0.0;

        for (int month = 1; month <= 12; month++) {
            double interest = balance * ((m_annualInterest / 100) / 12);
            balance += interest;
            yearlyInterest += interest;
        }

        cout << year << "\t$" << balance << "\t\t$" << yearlyInterest << endl;
    }
}

void AirgeadBanking::displayReportWithMonthlyDeposits() const {
    double balance = m_initialInvestment;

    cout << "\nBalance and Interest With Additional Monthly Deposits\n";
    cout << "=====================================================\n";
    cout << "Year\tYear End Balance\tYear End Earned Interest\n";

    for (int year = 1; year <= m_numberOfYears; year++) {
        double yearlyInterest = 0.0;

        for (int month = 1; month <= 12; month++) {
            balance += m_monthlyDeposit;
            double interest = balance * ((m_annualInterest / 100) / 12);
            balance += interest;
            yearlyInterest += interest;
        }

        cout << year << "\t$" << balance << "\t\t$" << yearlyInterest << endl;
    }
}