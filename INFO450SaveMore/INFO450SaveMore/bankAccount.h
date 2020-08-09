#pragma once
#include <string>

using namespace std;

class BankAccount
{
protected:
	int accountNum;
	double interestRate;
	double balance;
	
public:
	BankAccount();
	BankAccount(int a, double i, double b);
	virtual void GetInput() = 0;
	virtual void Display() = 0;

};