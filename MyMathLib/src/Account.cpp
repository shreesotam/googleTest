#include "Account.h"
#include <stdexcept>

Account::Account() :mBalance{0}
{

}

void Account::deposite(double sum)
{
    mBalance+=sum;
}
void Account::withdraw(double sum)
{
    if(mBalance<sum)
    {
        throw std::runtime_error("Insufficient funds");
    }
    mBalance-= sum;

}
double Account::getBalance() const
{
    return mBalance;
}
void Account::transfer(Account& to, double sum)
{
    withdraw(sum);
    to.deposite(sum);
}