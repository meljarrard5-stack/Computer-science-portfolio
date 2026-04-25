#include "AirgeadBanking.h"

int main() {
    AirgeadBanking banking;

    banking.getUserInput();
    banking.displayMenu();
    banking.displayReportWithoutMonthlyDeposits();
    banking.displayReportWithMonthlyDeposits();

    return 0;
}