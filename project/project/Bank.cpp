#include <iostream>
#include "Bank.h"

Account::~Account() {}

//double Account::~getBalance() {}

vector<int> Account::accountNumbers;
vector<double*> Account::accountsBalances;

Account::Account(string username, string password) {
	this->username = username;
	this->password = password;

	accountNumber = generateAccountNumber();
	cout << "Account Number " << accountNumber << endl;
	accountNumbers.push_back(accountNumber);
}

string Account::getUsername() {
	return username;
}

string Account::getPassword() {
	return password;
}

void Account::setUsername(string username) {
	this->username = username;
}

void Account::setPassword(string password) {
	this->password = password;
}

int Account::getAccountNumber() {
	return accountNumber;
}

void Account::transfer(int toAccountNumber, double amount) {

	if (checkAccountNumber(toAccountNumber)) {
		vector<int>::iterator iterAccountNumber = accountNumbers.begin();
		vector<double*>::iterator iterBalance = accountsBalances.begin();

		while (iterAccountNumber != accountNumbers.end()) {
			if (this->getAccountNumber() == *iterAccountNumber) {
				**iterBalance -= amount;
			}
			if (toAccountNumber == *iterAccountNumber) {
				**iterBalance += amount;
			}

			iterAccountNumber++;
			iterBalance++;
		}
	}
	else {
		cout << "Unable to find Account Number" << endl;
	}
}

int Account::generateAccountNumber() {
	int randomNumber = 0;

	do {

		randomNumber = rand() % 9000000 + 1000000;

	} while (checkAccountNumber(randomNumber) && accountNumbers.size() < 8999999);

	return randomNumber;
}

bool Account::checkAccountNumber(int accountNumber) {
	vector<int>::iterator iter;
	for (iter = accountNumbers.begin(); iter != accountNumbers.end(); iter++) {
		if (accountNumber == *iter) {
			return true;
		}
	}

	return false;
}


// CONSTRUCTORS
BankAccount::~BankAccount() {}

BankAccount::BankAccount(string username, string password) : Account(username, password) {
	balance = 0;
	accountsBalances.push_back(&balance);
}

// PUBLIC METHODS --------------------------------------------------------------------------------

// deposit method
void BankAccount::deposit(double amount) {
	if (checkValidAmount(amount)) {
		balance += amount;
	}
	else {
		cout << "Deposits of negative amounts are not permitted" << endl;
	}
}
// withdrawal method
double BankAccount::withdrawal(double amount) { // check for overdraft
	if (checkValidAmount(amount)) {
		balance -= amount;
	}
	else {
		cout << "Withdrawals of negative amounts are not permitted" << endl;
	}

	return amount;
}
// GETTERS
double BankAccount::getBalance() {
	return balance;
}

string BankAccount::getLockBox(string item) {
	vector<string>::iterator iter;

	for (iter = box.begin(); iter != box.end(); iter++) {
		if (*iter == item) {
			return item;
		}
	}
	cout << "No item found" << endl;
	return item;
}

// SETTERS
void BankAccount::setLockBox(string item) {
	box.push_back(item);		
}

// PRIVATE METHODS  --------------------------------------------------------------------------------
bool BankAccount::checkValidAmount(double amount) {
	return amount >= 0 ? true : false;
}

//	CONSTRUCTOR
Checkings::Checkings(string username, string password) : BankAccount(username, password) {}


//	CONSTRUCTOR
Savings::Savings(string username, string password) : BankAccount(username, password) {}


//	CONSTRUCTOR
CreditCard::CreditCard(string username, string password) : Account(username, password) {
	balance = 0;
	accountsBalances.push_back(&balance);
}

double CreditCard::getBalance() {
	return balance;
}

double CreditCard::getCreditMinimum() {
	return creditMinimum;
}

void  CreditCard::setCreditMinimum(double amount) {
	this->creditMinimum = amount;
}

void CreditCard::creditPayment(double amount) {
	balance -= amount;
}