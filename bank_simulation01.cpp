#include <iostream>
#include <string>
using namespace std;

const int maxacc = 12;
const int maxAccountNumber = maxacc;

class Account {
private:
    int acc_no;
    string acc_name;
    double balance;

public:
    Account() : acc_no(0), acc_name(""), balance(0) {}

    void openAccount(int accnum, const string &accname, double initialBalance) {
        if (acc_no == 0) {
            acc_no = accnum;
            acc_name = accname;
            balance = initialBalance; 
            cout << "Account created" << endl;
        } else {
            cout << "Account already exists." << endl;
        }
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: Rs " << amount << endl;
        } else {
            cout << "Please deposit a valid amount" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: Rs " << amount << endl;
        } else {
            cout << "Insufficient Balance or invalid amount" << endl;
        }
    }

    void accountDetails() {
        cout << "Account no.: " << acc_no << endl;
        cout << "Account Holder's Name: " << acc_name << endl;
        cout << "Account Balance: Rs " << balance << endl;
    }
};

int main() {
    Account acc[maxacc];
    char choice;

    while (true) {
        cout << "Bank Simulation Menu:" << endl;
        cout << "1. Open Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Display Account Details" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                int accnum;
                string name;
                double initialBalance;
                cout << "Enter Account Number: ";
                cin >> accnum;
                cout << "Enter Account Holder's Name: ";
                cin >> name;
                cout << "Enter the initial balance: Rs ";
                cin >> initialBalance;
                if (accnum > 0 && accnum <= maxAccountNumber) {
                    acc[accnum - 1].openAccount(accnum, name, initialBalance);
                } else {
                    cout << "Invalid account number" << endl;
                }
                break;
            }

            case '2': {
                int accnum;
                double amount;
                cout << "Enter Account Number: ";
                cin >> accnum;
                cout << "Enter the deposit amount: Rs ";
                cin >> amount;
                if (accnum > 0 && accnum <= maxAccountNumber) {
                    acc[accnum - 1].deposit(amount);
                } else {
                    cout << "Invalid account number" << endl;
                }
                break;
            }

            case '3': {
                int accnum;
                double amount;
                cout << "Enter Account Number: ";
                cin >> accnum;
                cout << "Enter the withdrawal amount: Rs ";
                cin >> amount;
                if (accnum > 0 && accnum <= maxAccountNumber) {
                    acc[accnum - 1].withdraw(amount);
                } else {
                    cout << "Invalid account number" << endl;
                }
                break;
            }

            case '4': {
                int accnum;
                cout << "Enter Account Number: ";
                cin >> accnum;
                if (accnum > 0 && accnum <= maxAccountNumber) {
                    acc[accnum - 1].accountDetails();
                } else {
                    cout << "Invalid account number" << endl;
                }
                break;
            }

            case '5': {
                return 0;
            }

            default: {
                cout << "Enter a valid choice" << endl;
            }
        }
    }
    return 0;
}
