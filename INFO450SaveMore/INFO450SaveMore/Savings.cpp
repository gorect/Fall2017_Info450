#include "stdafx.h"
#include <iostream>
#include <string>
#include "bankAccount.h"
#include "Savings.h"

using namespace std;

Savings::Savings() : BankAccount()
{
	withdrawFee = 0;
	withDrawAmount = 0;
	depositAmount = 0;
	answer = "";
}

Savings::Savings(int a, double i, double b, int w, double wda, double dpa, string ans) : BankAccount(a, i, b)
{
	withdrawFee = w;
	withDrawAmount = wda;
	depositAmount = dpa;
	answer = ans;
}

void Savings::Display()
{
	cout << "" << endl;
	cout << "Savings Account Number: ";
	cout << accountNum << endl;
	cout << "Savings Account IR ";
	cout << interestRate << endl;
	cout << "Savings Account Balance: $";
	cout << balance << endl;
	cout << "Fee for withdrawing money: $";
	cout << withdrawFee << endl;

	cout << "\nWould you like to make a Withdraw? ('Y') ";
	getline(cin, answer);
	if (answer == "Y" || answer == "y")
	{
		Savings::Withdraw(balance);
	}
	else
	{
		cout << "\nWould you like to make a deposit? ('Y') ";
		getline(cin, answer);
		if (answer == "y" || answer == "Y")
		{
			Savings::Deposit(balance);
		}
	}

	cout << "" << endl;
}

void Savings::GetInput()
{
	accountNum = 3456;
	balance = 10000;
	interestRate = 0.01;
	withdrawFee = 2;
	
	interestRate = Savings::InterestRateCalc(balance);
	balance = Savings::AssessInterest(balance, interestRate);
}

double Savings::InterestRateCalc(double bal)
{
	double ir = 0;

	if (bal >= 10000)
	{
		ir = 0.02;
	}
	else
		ir = 0.01;
	return ir;
}

double Savings::AssessInterest(double bal, double ir)
{
	bal = ((ir / 12)*bal) + bal;

	return bal;
}

double Savings::Withdraw(double b)
{
	cout << "How Much would you like to withdraw today? $";					//somewhere in here need to go cin.ignore/clear
	cin >> withDrawAmount;
	cin.ignore();
	cin.clear();

	if (withDrawAmount <= balance)
	{
		Savings::CheckBal(b, withDrawAmount);
	}
	else
	{
		cout << "\nYou do not have enough funds to complete this trans action." << endl;
	}
	return balance;
}

double Savings::CheckBal(double bal, double wda)
{
	if (bal >= 1)
	{
		bal = bal - withDrawAmount;
		bal = Savings::AssessInterest(bal, interestRate);
		withDrawAmount = withDrawAmount - withdrawFee;
		cout << "\nYour amount due: $" << withDrawAmount << endl;
		cout << "Your remaining balance: $" << bal << endl;
	}
	else
	{
		cout << "\nLow Balance alert: You can not withdraw that much." << endl;
		
	}
	return withDrawAmount;
}

double Savings::Deposit(double bal)
{
	cout << "\nHow Much would you like to deposit today? $";					//somewhere in here need to go cin.ignore/clear
	cin >> depositAmount;
	cin.ignore();
	cin.clear();

	bal += depositAmount;
	bal = Savings::AssessInterest(bal, interestRate);
	cout << "Your new balance is: $" << bal;

	return bal;
}
