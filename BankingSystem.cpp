#include "BankingSystem.h"
#include <iostream>
#include <string>

int BankingSystem::nextAccountNumber = 1; // Initialize the static variable

BankingSystem::BankingSystem() 
{
    // Constructor can initialize the system, load data from files, etc.
}

// Create a new account with a unique account number
void BankingSystem::createAccount(const std::string &name, float initialBalance) 
{
    accounts.push_back(Account(name, nextAccountNumber++, initialBalance));
    std::cout << "Account created for " << name << " with account number " << accounts.back().getAccountNumber() << " and initial balance of $" << initialBalance << std::endl;
}

// Retrieve an account by its number
Account* BankingSystem::getAccount(int accountNumber) 
{ //Searches through "accounts" vector for an object with a matching accountnumber, if found it returns a pointer to that object, if not found nullptr is returned
    for (auto &account : accounts) 
    {
        if (account.getAccountNumber() == accountNumber) 
        {
            return &account;
        }
    }
    return nullptr; // Return nullptr if account not found
}

// Transfer money from one account to another
void BankingSystem::transferMoney(int fromAccountNumber, int toAccountNumber, float amount) 
{
    Account* fromAccount = getAccount(fromAccountNumber);
    Account* toAccount = getAccount(toAccountNumber);

    if (fromAccount && toAccount && fromAccount->withdraw(amount)) 
    {
        toAccount->deposit(amount);
        std::cout << "Transferred $" << amount << " from account " << fromAccountNumber << " to account " << toAccountNumber << std::endl;
    } 
    else 
    {
        std::cout << "Transfer failed." << std::endl;
    }
}

// Save account details to a file
void BankingSystem::saveAccountsToFile(const std::string& filename) 
{
    std::ofstream file(filename);
    if (!file) 
    {
        std::cerr << "Failed to open file for writing." << std::endl;
    }
    for (const auto& account : accounts) 
    {
        file << account.getName() << " " << account.getAccountNumber() << " " << account.getBalance() << std::endl;;
    }
    file.close();

}

// Load account details from a file
void BankingSystem::loadAccountsFromFile(const std::string& filename) 
{
    std::ifstream file(filename);
    if (!file) 
    {
        std::cerr << "Failed to open file for reading." << std::endl;
    }

    std::string name;
    int accountNumber;
    double balance;
    while (file >> name >> accountNumber >> balance)
    {
        accounts.push_back(Account(name, accountNumber, balance));
    }
    file.close();
}
