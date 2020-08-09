// INFO450SaveMore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "cd.h"
#include "checkingAccount.h"
#include "savings.h"
#include <iostream>
#include "stdio.h"

using namespace std;

int main()
{
	string answer = "";
	BankAccount *pBA = NULL;

	cout << "Welcome to the SaveMore Banking and Trust Console Interface (tm) \n" << endl;

	while (answer != "exit")
	{
		cout << "Would you like to view your 'Checking', 'Savings' or 'CD' Account? ('exit' to quit): ";
		getline(cin, answer);										// Error - If you enter "exit" as your first input then the program crashes. Why?

		if (answer == "checking" || answer == "Checking")
		{
			pBA = new CheckingAccount();			//goes to Checking
			pBA->GetInput();						
			pBA->Display();
		}

		else if (answer == "savings" || answer == "Savings")
		{
			pBA = new Savings();				//goes to the savings account
			pBA->GetInput();
			pBA->Display();
		}
		else if (answer == "cd" || answer == "CD")
		{
			pBA = new CD();					//goes to CD account
			pBA->GetInput();
			pBA->Display();
		}

		else if (answer == "exit")		//For when you want to exit the program.
		{
			cout << "\n Thank you for choosing SaveMore! \n "<< endl;
		}

		else
		{
			cout << "Error - " << answer << " is not an option. Please enter the correct keyphrase." << endl;
		}
	}
	return 0;
}

