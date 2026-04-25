#ifndef AIRGEADBANKING_H
#define AIRGEADBANKING_H

class AirgeadBanking {
private:
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterest;
    int m_numberOfYears;

public:
    AirgeadBanking();

    void getUserInput();
    void displayMenu() const;
    void displayReportWithoutMonthlyDeposits() const;
    void displayReportWithMonthlyDeposits() const;
};

#endif