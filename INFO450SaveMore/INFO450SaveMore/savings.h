#pragma once
#include "bankAccount.h"
class Savings : public BankAccount
{
private:
	double withdrawFee;		//$2 fee everytime you withdraw money from savings account
	double withDrawAmount;
	double depositAmount;
	string answer;

public:
	Savings();
	Savings(int a, double i, double b, int w, double wda, double dpa, string ans);
	void GetInput();
	void Display();
	double InterestRateCalc(double bal);
	double AssessInterest(double bal, double ir);
	double Withdraw(double b);
	double CheckBal(double bal, double wda);
	double Deposit(double bal);
};
