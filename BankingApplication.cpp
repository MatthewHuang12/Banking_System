#include "BankingApplication.h"
#include <iostream>
#include <string>
void BankingApplication::run() 
{
    while (true) 
    {
        std::cout << std::endl;
        std::cout << "1. Create Account" << std::endl;
        std::cout << "2. Deposit" << std::endl;
        std::cout << "3. Withdraw" << std::endl;
        std::cout << "4. Display Balance" << std::endl;
        std::cout << "5. Transfer Money" << std::endl;;
        std::cout << "6. Display Transaction History" << std::endl;
        std::cout << "7. Apply Interest" << std::endl;
        std::cout << "8. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;

        if (choice == 8) break; // Exit condition

        int accountNumber, toAccountNumber;
        float amount;
        Account* account;
        switch (choice) 
        {
            case 1: 
            {
                std::string name;
                float initialBalance;
                std::cout << "Enter First and Last name ";
                std::cin.ignore(); // Ignore leftover newline
                std::getline(std::cin, name);
                std::cout << "Enter initial Balance ";
                std::cin >> initialBalance;
                if(initialBalance > 10000)
                {
                    std::cout << "Maximum initial deposit of $10000, please deposit less. " << std::endl;
                }  
                else
                {
                    createAccount(name, initialBalance);
                }
                break;
            }
            case 2:
            case 3:
            case 4: 
            {
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                account = getAccount(accountNumber);
                if (account == nullptr)
                {
                    std::cout << "Account not found." <<std::endl;
                    break;
                }
                if (choice == 2) 
                {
                    std::cout << "Enter deposit amount: ";
                    std::cin >> amount;
                    if(amount > 10000)
                    {
                        std::cout << "Maximum deposit of $10000 at a time, please deposit less. " << std::endl;
                        std:: cin >> amount;
                    }
                    account->deposit(amount);
                    account->recordTransaction("Deposited: " + std::to_string(amount));
                    std::cout << "Deposited: $" << amount << std::endl;
                } 
                else if (choice == 3) 
                {
                    std::cout << "Enter withdrawal amount: ";
                    std::cin >> amount;
                    if(amount > 10000)
                    {
                        std::cout << "Maximum deposit of $10000 at a time, please deposit less. " << std::endl;
                        std::cin >> amount;
                    }
                    else
                    {
                        if (account->withdraw(amount)) 
                        {
                            account->recordTransaction("Withdrawn: " + std::to_string(amount));
                            std::cout << "Withdrawn: $" << amount << std::endl;
                        }
                    }
                } 
                else if (choice == 4) 
                {
                    account->displayBalance();
                }
                break;
            }
            case 5: 
            {
                std::cout << "Enter your account number: ";
                std::cin >> accountNumber;
                std::cout << "Enter the account number to transfer to: ";
                std::cin >> toAccountNumber;
                std::cout << "Enter amount to transfer: ";
                std::cin >> amount;
                transferMoney(accountNumber, toAccountNumber, amount);
                account = getAccount(accountNumber);
                account->recordTransaction("Account " + std::to_string(accountNumber) + " transferred $" + std::to_string(amount) + " to Account " + std::to_string(toAccountNumber));
            }
            break;
            case 6: 
            {
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                account = getAccount(accountNumber);
                if (account == nullptr) 
                {
                    std::cout << "Account not found." << std::endl;
                } 
                else 
                {
                account->displayTransactionHistory();
                }
                break;
            }
            case 7: 
            {
                float annualRate, interest;
                int timeYears;
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                account = getAccount(accountNumber);
                if (account == nullptr) 
                {
                    std::cout << "Account not found." << std::endl;
                } 
                else 
                {
                    std::cout << "Enter annual interest rate (in %): ";
                    std::cin >> annualRate;
                    std::cout << "Enter time period in years: ";
                    std::cin >> timeYears;
                    account->applyInterest(annualRate, timeYears, interest);
                    account->recordTransaction("Interest applied at rate " + std::to_string(annualRate) + "% for " + std::to_string(timeYears) + " years.");
                    std::cout << "Interest applied at rate of " << annualRate <<  "% for " << timeYears << " years." << std::endl;
                }
                break;
            }
            default: 
            {
                std::cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    }
}