// INFO450PIGGoreCameron.cpp : Defines the entry point for the console application.
// Words starting with consonants have the first letter moved to the end of the word, appended with 'ay'
// Words starting with vowels keep the first letter and append 'ay'
// Safely rejects intergers and character strings over the length of 47 (to prevent chrashes!)

#include "stdafx.h"
#include <iostream>
#include <stdio.h>						

using namespace std;

	bool errorCheck(char english[50]);
	void translateToPigLatin(char english[50]);
	void asciiArt();

	int main()
	{
		char english[50] = "";						//user entered sentence or 0 to quit
		char trans = 'y';
		cout << "Welcome to the Pig Latin Translater!" << endl;
		
		do
		{
			bool passFail;
			
			cout << "\nPlease enter your word for translation.\n";
			cin.getline(english, 50);						// Get a sentence from the user.
			passFail = errorCheck(english);					//checks to see if first character is alpha
			
			if (passFail == 0)
			{				
					translateToPigLatin(english);			//goes to the translate function
			}
			else
			{
				
			}
			cout << "Do you want to contiune? (y or n) ";	//asking for if they want to translate another word
			cin >> trans;									// gets the users y or n
			cin.ignore();									//ignores the return character
		} 
		while (trans != 'n');			//need to fix this, as of now entering 0 outputs "No Numbs!" so at least error checking works!
		{
			cout << "\nEnd of program.\n" << endl;			// all done!
			asciiArt();										//jump to the pig
		}
		return 0;
	}

	bool errorCheck(char english[50])
	{
		if (strlen(english) <= 47 )			// checks for string length
		{
			if (isalpha(english[0]))
			{
				return 0;					// ***********************************************************************//
			}								//**************************  Returns  ***********************************//
			else							//****************************   0   *************************************//
			{								//****************************   or  *************************************//
				cout << "No Nums!" << endl;
				return -1;					//****************************   -1  *************************************//
			}								//************************************************************************//
		}
		else
		{
			cout << "\nYou have entered to many charatcers!\n" << endl;			//because formating...
			cout << "...Please hit \n " << "     The Return Key \n " << "       and try something less than 47 charaters..." << endl << endl;
			cin.ignore();
			return -1;						//you have failed my program, try again
		}	
	}

	void translateToPigLatin(char english[50])
	{
		char vowel[50];							// to hold english word for "vowel" computation
		char pigLatin[50];

		strcpy_s(vowel, english);				// saves the english word to "vowel" to check for first letter
		strcpy_s(pigLatin, english);			// saves the english word for later manipulation

		//if statment for first char = vowel
		if (vowel[0] == 'a' || vowel[0] == 'e' || vowel[0] == 'i' || vowel[0] == 'o' || vowel[0] == 'u' || vowel[0] == 'y')
		{
			strcat_s(pigLatin, "ay");		//Keeps first letter and appends "ay"
		}
		
		else					
		{
			strcpy(pigLatin, english + 1);				//copys english word starting from the second letter to pigLatin
			strncat(pigLatin, english, 1);				//strcat_s does not work here but now adds frist letter to end of piglatin
			strcat_s(pigLatin, "ay");					//Appends "ay"
		}
		
		cout << "That in Pig Latin is : " << pigLatin << endl << endl;			//outputs message and word to console
	}

	void asciiArt()
	{
		cout << " Oinkay!                           " << endl;
		cout << "      v    (,|/,)_______    _      " << endl;
		cout << "       __ o o``-'        `.'-)     " << endl;
		cout << "      ('')                 :/      " << endl;
		cout << "       `-j                 |       " << endl;
		cout << "         `-._(             /        " << endl;
		cout << "             | _  |--^.   /         " << endl;
		cout << "            /_]'|_|  /_)_/          " << endl;
		cout << "                /_]    /_]         " << endl << endl;
	}
