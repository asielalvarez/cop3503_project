#include <iostream>
#include <vector>

using namespace std;


/*
TODO:	creditMinimum ?
object ?
address ?
contents ?
calculatePayment ?
setLockBox ?
getLockBox ?
transferMoney ?
*/

// Account class
class Account {
private:
	string username;
	string password;
	int accountNumber;
	static vector<int> accountNumbers;
	int generateAccountNumber();
	bool checkAccountNumber(int accountNumber);
	static int counterTest;

protected:
	static vector<double*> accountsBalances;

public:
	virtual ~Account() = 0;
	Account(string username, string password);
	virtual double getBalance() = 0;
	string getUsername();
	string getPassword();
	void setUsername(string username);
	void setPassword(string password);
	int getAccountNumber();
	void transfer(int toAccountNumber, double amount);
};

// BankAccount class
class BankAccount : public Account {
private:
	double balance;
	bool checkValidAmount(double amount);
	vector<string> box;
public:
	virtual ~BankAccount() = 0;
	BankAccount(string username, string password);
	void deposit(double amount);
	double withdrawal(double amount);
	double getBalance();
	void setLockBox(string item);
	string getLockBox(string item);
};

// Checkings account class
class Checkings : public BankAccount {
public:
	Checkings(string username, string password);
};

//Savings account class
class Savings : public BankAccount {
public:
	Savings(string username, string password);
};

// CreditCard class
class CreditCard : public Account {
private:
	double creditMinimum;
	double balance;
public:
	CreditCard(string username, string password);
	double getBalance();
	void creditPayment(double amount);
	double getCreditMinimum();
	void setCreditMinimum(double amount);
};