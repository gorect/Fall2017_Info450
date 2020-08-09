#pragma once
#include "bankAccount.h"
class CheckingAccount : public BankAccount
{
private:
	int purchaseChecks;
	double lowBalFee;
	string answer;
	double withDrawAmount;
	double depositAmount;
	int boxsOfChecks;
	

public:
	CheckingAccount();
	CheckingAccount(int a, double i, double b, int c, double l, double w, string ans, double dpa, int boc);
	void GetInput();
	void Display();
	double Withdraw(double b);
	double CheckBal(double bal, double wda);
	double Deposit(double bal);
	double PurchaseChecks(double bal, int purchecks);
};
