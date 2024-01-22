#include "Account.h"
#include <iostream>

// Constructor to initialize the account
Account::Account(const std::string &name, const int accountNumber, float initialBalance)
    : name(name), accountNumber(accountNumber), balance(initialBalance) {}

// Deposit money into the account
void Account::deposit(float amount) {
    if (amount > 0) 
    {
        balance += amount;
    } 
    else
    {
        std::cout << "Invalid deposit amount " << std::endl;
    }
}

// Withdraw money from the account
bool Account::withdraw(float amount)
{
    if (amount > 0 && amount <= balance) 
    {
        balance -= amount;
        return true;
    } 
    else
    {
        std::cout << "Withdrawal failed: Insufficient funds" << std::endl;
        return false;
    }
}

// Display the current balance
void Account::displayBalance() 
{
std::cout << "Current balance: $" << balance << std::endl;
}

// Apply interest to the account balance
void Account::applyInterest(float annualRate, int timeYears, float interest) 
{
    for (size_t i = 0 ; i < timeYears; ++i)
    {
        float interest = balance * (annualRate / 100);
        balance += interest;
    }
}

// Record a transaction in the transaction history
void Account::recordTransaction(const std::string& transaction)
{
    transactionHistory.push_back(transaction);
}

// Display all the transactions made in this account
void Account::displayTransactionHistory() const 
{
    for (const auto& transaction : transactionHistory) 
    {
        std::cout << transaction << std::endl;
    }
}
