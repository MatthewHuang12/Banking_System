#ifndef BANKINGSYSTEM_H
#define BANKINGSYSTEM_H

#include "Account.h"
#include <vector>
#include <fstream>

class BankingSystem {
private:
    std::vector<Account> accounts; // List of all accounts in the bank
    static int nextAccountNumber; // Static variable for generating unique account numbers

public:
    BankingSystem();

    // Operations related to accounts
    void createAccount(const std::string &name, float initialBalance);
    Account* getAccount(int accountNumber); 
    void transferMoney(int fromAccountNumber, int toAccountNumber, float amount);

    // File I/O for persistent data
    void saveAccountsToFile(const std::string& filename);
    void loadAccountsFromFile(const std::string& filename);

};

#endif // BANKINGSYSTEM_H