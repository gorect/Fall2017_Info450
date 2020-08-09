#include "stdafx.h"
#include <iostream>
#include <string>
#include "bankAccount.h"
#include "CD.h"

using namespace std;

CD::CD() : BankAccount()
{
	interestRate = 0;
	answer = "";
	withDrawAmount = 0;
	depositAmount = 0;
	
}

CD::CD(int a, double i, double b, int t, string ans, double wda, double dpa) : BankAccount(a,i,b)
{
	term = t;
	answer = ans;
	withDrawAmount = wda;
	depositAmount = dpa;
}

void CD::Display()
{
	cout << "" << endl;
	cout << "CD Account Number: ";
	cout << accountNum << endl;
	cout << "CD Account Balance: $";
	cout << balance << endl;
	cout << "CD Interest Rate: ";
	cout << interestRate << endl;
	cout << "CD Term: ";
	cout << term << endl;

	cout << "\nWould you like to make a Withdraw? ('Y') ";
	getline(cin, answer);
	if (answer == "Y" || answer == "y")
	{
		balance = CD::Withdraw(balance, term);			//I want this to change that value of balance so that when you withdraw money it doesn't reset during loop.
	}
	else
	{
		cout << "\nWould you like to make a deposit? ('Y') ";
		getline(cin, answer);
		if (answer == "y" || answer == "Y")
		{
			CD::Deposit(balance);
		}
	}
	cout << "" << endl;
}

void CD::GetInput()
{
	accountNum = 1234;
	balance = 10000;							//Change this value to see the other parts of the program change accordingly 
	interestRate = 0.05;
	term = 3;
	
	interestRate = CD::AssessTerm(interestRate, term);
	balance = CD::AssessInterest(balance, interestRate);
}

double CD::AssessTerm(double ir, int t)
{
	if (t >= 5)
	{
		ir = 0.1;
	}
	else
	{
		ir = 0.05;
	}
	return ir;
}

double CD::AssessInterest(double bal, double ir)
{
	bal = ((ir / 12)*bal) + bal;
	
	return bal;
}

double CD::Withdraw(double b, int t)
{
	cout << "\nHow Much would you like to withdraw today? $";					//somewhere in here need to go cin.ignore/clear
	cin >> withDrawAmount;
	cin.ignore();
	cin.clear();

	if (t >= 0)
	{
		double fee = (b * 0.10);
		b -= fee;
	}

	if (withDrawAmount <= b)
	{
		b -= withDrawAmount;
		cout << "\nYour amount due: $" << withDrawAmount << endl;
		cout << "Your remaining balance: $" << b << endl;
	}
	else
	{
		cout << "\nYou do not have enough funds to complete this trans action." << endl;
	}
	return b;
}

double CD::Deposit(double bal)
{
	cout << "\nHow Much would you like to deposit today? $";					//somewhere in here need to go cin.ignore/clear
	cin >> depositAmount;
	cin.ignore();
	cin.clear();

	bal += depositAmount;
	bal = CD::AssessInterest(bal, interestRate);
	cout << "Your new balance is: $" << bal;
	cout << "" << endl;

	return bal;
}
