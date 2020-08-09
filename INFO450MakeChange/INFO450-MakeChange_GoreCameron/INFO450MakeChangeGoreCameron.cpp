// INFO450-MakeChange-GoreCameron
//This program acts like a vending machine would.
//It takes an input ($) and despences change based on the cost of purchased item.

#include "stdafx.h"
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
	float itemCost;
	float amountPaid;
	float moreMoney;
	int checkIf;													//stands in as a float to int conversion variable for % operator
	int dollars, quarters, dimes, nickels;							//Variables for output value
	int changeDue;		
	float floatChangeDue;
	int rDollars, rQuarters, rDimes, rNickels;						//These stand in as placeholders for "value" remainders
	
	do
	{
		cout << "\nPlease enter the cost of the item: ";									//Begining of code
		cin >> itemCost;																	//User input

		if (itemCost != 0)																	//First loop. Checks to see if user wants to continue
		{
			cout << "Please insert your money now: ";										//User enters "their money"
			cin >> amountPaid;		// <<-- here
			checkIf = amountPaid * 100;														//This line changes float point value to int for % 5 checker later on
			//something needs to happen here to fix the float point error that is happening 2 lines above me.


			if (checkIf % 5 == 0)
			{
				while (amountPaid < itemCost)													//Checks for sufficient funds.
				{
					cout << amountPaid << " is not enough, please insert more money: ";
					cin >> moreMoney;
					amountPaid += moreMoney;													//adds money to total until satisfactory
				}

				cout << "You have entered $" << amountPaid << endl;								//There is enough money, continues...


				amountPaid = amountPaid - itemCost;												//ChangeDue is the difference between 
				changeDue = amountPaid * 100;													//Brings amountPaid up to integers so that "%" will work.
				floatChangeDue = changeDue;
				floatChangeDue = floatChangeDue / 100;
				std::cout << "Your change is: $" << floatChangeDue << endl;						//Begins the change return process
					
				dollars = round(changeDue / 100);												//Looks to see how many dollars are due back.
				rDollars = round(changeDue % 100);												//Calculates leftover change.
				if ((dollars == 0) || (dollars < 0))											//if no dollars, skips to next denomination
				{
	
				}
				else
				{
					cout << dollars << " Dollar(s) " << endl;									//Prints change due back
				}

				quarters = round(rDollars / 25);														//Looks to see how many Quarters to give back
				rQuarters = round(rDollars % 25);
				if ((quarters == 0) || (quarters < 0))											//if no quarters, skips to next denomination
				{
	
				}
				else
				{
					cout << quarters << " Quarter(s)" << endl;									//Prints change due back
				}

				dimes = round(rQuarters / 10);
				rDimes = round(rQuarters % 10);
				if ((dimes == 0) || (dimes < 0))												//if no dimes, skips to next denomination
				{
	
				}
				else
				{
					cout << dimes << " Dime(s)" << endl;										//Prints change due back
				}

				nickels = round(rDimes / 5);
				rNickels = round(rDimes % 5);
				if ((nickels == 0) || (nickels < 0))											//if no nickels, skips to next segment
				{
	
				}
				else
				{
					cout << nickels << " Nickel(s)" << endl;									//Prints change due back
				}
			}
			else
			{
				cout << "This machine does not accept pennies." << endl;
				cout << "Please use correct change." << endl;
			}
		}
	} 
	while (itemCost != 0);
	{
		cout << "\nThank you for using this program.\n" << endl;
	}
	
	return 0;
}

