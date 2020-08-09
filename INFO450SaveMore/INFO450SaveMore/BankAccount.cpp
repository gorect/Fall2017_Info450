//This will act as the Parent Class to the three sub classes (Checking CD and Savings)
#include "stdafx.h"
#include <string>
#include "bankAccount.h"

using namespace std;

BankAccount::BankAccount()
{
	accountNum = 0;
	interestRate = 0;
	balance = 0;

}

BankAccount::BankAccount(int a, double i, double b)
{
	accountNum = a;
	interestRate = i;
	balance = b;
}


