#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

struct BankAccount {
    int accountNumber;     
    string Name;      
    double balance;        
};

void updateBalance(BankAccount& account, double newBalance) {
    account.balance = newBalance;
}

int main() {
    setlocale(0, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    BankAccount account;  

    cout << "Введите номер счёта: ";
    cin >> account.accountNumber;

    cout << "Введите имя владельца: ";
    cin.ignore();  
    getline(cin, account.Name);

    cout << "Введите баланс: ";
    cin >> account.balance;

    double newBalance;
    cout << "Введите новый баланс: ";
    cin >> newBalance;

    updateBalance(account, newBalance);

    cout << "Ваш счёт: " << account.Name << ", "
        << account.accountNumber << ", " << account.balance << endl;

  
}