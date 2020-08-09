#include "stdafx.h"
#include <iostream>
#include <string>
#include "bankAccount.h"
#include "checkingAccount.h"

using namespace std;

CheckingAccount::CheckingAccount() : BankAccount()
{
	answer = "";
	purchaseChecks = 0;																		//There is no interest rate for checking accounts.
	lowBalFee = 0;
	withDrawAmount = 0;
	depositAmount = 0;
	boxsOfChecks = 0;
}

CheckingAccount::CheckingAccount(int a, double i, double b, int c, double l, double w, string ans, double dpa, int boc) : BankAccount(a, i, b)			//Bank account variables here will not change.
{																							//add vars to CheckingAccount as they will be added to BA()
	purchaseChecks = c;
	lowBalFee = l;
	withDrawAmount = w;
	answer = ans;
	depositAmount = dpa;
	boxsOfChecks = boc;
}

void CheckingAccount::Display()
{
	//There is no interest rate for checking accounts.
	cout << "" << endl;
	cout << "Checking Account Number: ";
	cout << accountNum << endl;
	cout << "Checking Account Balance: $";
	cout << balance << endl;
	cout << "One book of checks : $";
	cout << purchaseChecks << endl;

	cout << "\nWould you like to make a Withdraw? ('Y') ";
	getline(cin, answer);
	if (answer == "Y" || answer == "y")
	{
		CheckingAccount::Withdraw(balance);
	}
	else
	{
		cout << "\nWould you like to make a deposit? ('Y') ";
		getline(cin, answer);
		if (answer == "y" || answer == "Y")
		{
			CheckingAccount::Deposit(balance);
		}
		else
		{
			cout << "\nWould you like to buy some checks? ('Y') ";
			getline(cin, answer);
			if (answer == "y" || answer == "Y")
			{
				CheckingAccount::PurchaseChecks(balance, purchaseChecks);
			}
		}
	}
	cout << "" << endl;
}

void CheckingAccount::GetInput()
{
	accountNum = 2345;
	balance = 10000;
	interestRate = 0;
	purchaseChecks = 15;
	//lowBalFee = CheckingAccount::CheckBal(balance);
}

double CheckingAccount::Withdraw(double b)
{
	cout << "\nHow Much would you like to withdraw today? $";					//somewhere in here need to go cin.ignore/clear
	cin >> withDrawAmount;
	cin.ignore();
	cin.clear();

	if (withDrawAmount <= balance)
	{
		CheckingAccount::CheckBal(b, withDrawAmount);
	}
	else
	{
		cout << "\nYou do not have enough funds to complete this trans action." << endl;
	}
	return balance;
}

double CheckingAccount::CheckBal(double bal, double wda)
{
	if (bal >= 500)
	{
		balance = balance - withDrawAmount;
		cout << "Here's your money! $";
		cout << withDrawAmount << endl;
	}
	else
	{
		cout << "Low Balance alert: "; 
		bal = (bal - withDrawAmount) - 5;
	}
	return bal;
}

double CheckingAccount::Deposit(double bal)
{
	cout << "\nHow Much would you like to deposit today? $";					//somewhere in here need to go cin.ignore/clear
	cin >> depositAmount;
	cin.ignore();
	cin.clear();
	
	bal += depositAmount;
	cout << "Your new balance is: $" << bal;

	return bal;
}

double CheckingAccount::PurchaseChecks(double bal, int purchecks)
{
	cout << "\nHow many boxs of checks do you want today? ";					//somewhere in here need to go cin.ignore/clear
	cin >> boxsOfChecks;
	cin.ignore();
	cin.clear();

	if ((boxsOfChecks * 15) <= (balance - (15 * boxsOfChecks)))
	{
		
		if (bal >= 500)
		{
			boxsOfChecks *= purchaseChecks;
			cout << "\nYour checks will cost: $" << boxsOfChecks << endl;
			bal -= boxsOfChecks;
			cout << "\nYour remaining balance is: $" << bal << endl;
		}
		else
		{
			boxsOfChecks *= purchaseChecks;
			cout << "\nYour checks will cost: $" << boxsOfChecks << endl;
			bal -= boxsOfChecks;
			
			cout << "\nLow Balance alert: Remaining Balance: $";
			bal -= 5;
			cout << bal << endl;
			return bal;
		}
	}
	else
	{
		cout << "\nYou do not have enough funds to complete this trans action." << endl;
	}
	return balance;
}
