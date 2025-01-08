#pragma once

class Account
{
    public:
    Account();
    void deposite(double sum);
    void withdraw(double sum);
    double getBalance() const;
    void transfer(Account& to, double sum);
    private:
        double mBalance;
};