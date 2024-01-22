#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>

class Account {
private:
    std::string name; // Name of the account holder
    int accountNumber; // Unique account number
    float balance; // Current balance in the account
    std::vector<std::string> transactionHistory; // History of all transactions

public:
    Account(const std::string &name, const int accountNumber, float initialBalance);

    // Account operations
    void deposit(float amount);
    bool withdraw(float amount);
    void displayBalance();
    void applyInterest(float annualRate, int timeYears, float interest);

    // Transaction history management
    void recordTransaction(const std::string& transaction);
    void displayTransactionHistory() const;

    // Getters for account details
    int getAccountNumber() const
     { 
        return accountNumber; 
     }
    float getBalance() const 
    { 
        return balance; 
    }
    std::string getName() const 
    { 
        return name; 
    }
};

#endif // ACCOUNT_H