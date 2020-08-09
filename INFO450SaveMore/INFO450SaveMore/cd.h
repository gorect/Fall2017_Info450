#pragma once
#include "bankAccount.h"
class CD : public BankAccount
{
private:
	int accountNum;
	double interestRate;
	int balance;
	int term;
	double withdrawFee;
	string answer;
	double withDrawAmount;
	double depositAmount;

public:
	CD();
	CD::CD(int a, double i, double b, int t, string ans, double wda, double dpa);
	void GetInput();
	void Display();
	double CD::AssessTerm(double ir, int t);
	double CD::AssessInterest(double bal, double ir);
	double CD::Withdraw(double b, int t);
	double CD::Deposit(double bal);
};
