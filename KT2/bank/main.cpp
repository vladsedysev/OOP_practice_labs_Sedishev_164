#include <iostream>
#include <string>

using namespace std;

class BankAccount {
protected:
    string ownerName;
    string accountNumber;
    double balance;

public:
    BankAccount(const string& ownerName, const string& accountNumber, double balance)
        : ownerName(ownerName), accountNumber(accountNumber), balance(balance) {}

    virtual void deposit(double amount) {
        if (isValidAmount(amount)) {
            balance += amount;
        } else {
            cerr << "Invalid deposit amount: " << amount << endl;
        }
    }

    virtual bool withdraw(double amount) {
        if (!isValidAmount(amount)) {
            cerr << "Invalid withdrawal amount: " << amount << endl;
            return false;
        }
        if (balance >= amount) {
            balance -= amount;
            return true;
        } else {
            cerr << "Insufficient funds for withdrawal: " << amount << endl;
            return false;
        }
    }

    virtual void displayInfo() const {
        cout << "Owner: " << ownerName << ", Account Number: " << accountNumber << ", Balance: " << balance << endl;
    }

    bool isValidAmount(double amount) const {
        return amount > 0;
    }

    BankAccount& operator+=(double amount) {
        deposit(amount);
        return *this;
    }

    BankAccount& operator-=(double amount) {
        if (!withdraw(amount)) {
            cerr << "Failed to withdraw " << amount << endl;
        }
        return *this;
    }

    bool operator>(const BankAccount& other) const {
        return balance > other.balance;
    }

    const string& getOwnerName() const { return ownerName; }
    const string& getAccountNumber() const { return accountNumber; }
    double getBalance() const { return balance; }

    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(const string& ownerName, const string& accountNumber, double balance, double interestRate)
        : BankAccount(ownerName, accountNumber, balance), interestRate(interestRate) {}

    void deposit(double amount) override {
        if (isValidAmount(amount)) {
            balance += amount;
            balance += amount * interestRate / 100;
        } else {
            cerr << "Invalid deposit amount: " << amount << endl;
        }
    }

    void displayInfo() const override {
        BankAccount::displayInfo();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

void processTransaction(BankAccount& account, double amount) {
    account.deposit(amount);
    cout << "Deposited " << amount << " to account " << account.getAccountNumber() << endl;
}

void processTransaction(BankAccount& from, BankAccount& to, double amount) {
    if (from.withdraw(amount)) {
        to.deposit(amount);
        cout << "Transferred " << amount << " from account " << from.getAccountNumber()
             << " to account " << to.getAccountNumber() << endl;
    } else {
        cerr << "Failed to transfer " << amount << " from account " << from.getAccountNumber() << endl;
    }
}

int main() {
    const int numAccounts = 2;
    BankAccount* accounts[numAccounts];

    accounts[0] = new BankAccount("Ivan Ivanov", "123456789", 1000.0);
    accounts[1] = new SavingsAccount("Petr Petrov", "987654321", 2000.0, 5.0);

    for (int i = 0; i < numAccounts; ++i) {
        accounts[i]->displayInfo();
    }

    BankAccount* account1 = accounts[0];
    *account1 += 500.0;
    cout << "After depositing 500: ";
    account1->displayInfo();

    *account1 -= 200.0;
    cout << "After withdrawing 200: ";
    account1->displayInfo();

    processTransaction(*account1, 400.0);
    processTransaction(*account1, *accounts[1], 100.0);

    account1->displayInfo();

    for (int i = 0; i < numAccounts; ++i) {
        delete accounts[i];
    }

    return 0;
}
