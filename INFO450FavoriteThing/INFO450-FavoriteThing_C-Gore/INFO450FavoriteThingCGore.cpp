// INFO450FavoriteThingCGore.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "movies.h"
#include "tv.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int LISTSIZE = 50;

int main()
{
	Movies **mylist;
	int count = 0;
	int i;
	string fileLocation;
	string response = "Y";

	mylist = new Movies*[LISTSIZE];

	cout << "Welcom to the program! \n Where would you like to save your file? ";
	getline(cin, fileLocation);

	// read from a file - get saved inventory itesm
	ifstream infile(fileLocation);
	if (infile)
	{
		while (!infile.eof())
		{
			string Title, IMDB, name, rate;
			getline(infile, Title, '|');
			if (Title.length())
			{
				getline(infile, IMDB, '|');
				getline(infile, name, '|');
				getline(infile, rate, '\n');
				mylist[count] = new Movies(Title, stoi(IMDB), name, rate);
				count++;
			}
		}
	}
	else
	{
		ofstream outfile(fileLocation);
		if (!outfile)
		{
			cout << "File could not be created. " << endl;
		}
	}

	// If the User wants to add more things to the list. (Provides specific outputs based on the number of movies saved in txt file)
	if (count == 0)
	{
		cout << "You do not have any favorite movies... How sad." << endl;
	}
	if (count == 1)
	{
		cout << "You currently have " << count << " favorite movie. Do you have anymore to add? (Y)" << endl;
	}
	else
	{
		cout << "You currently have " << count << " favorite movies.  Do you wish to add more? (Y)" << endl;
	}

	cin >> response;
	cin.ignore();
	cin.clear();

	// Gets favorite movies from user.
	while (response == "Y" || response == "y")
	{
		mylist[count] = new Movies();
		if (mylist[count]->GetInput() == 0)
		{
			count++;
		}
		
/*		if (mylist[i]->DuplicateMoive()
		{
			cout << "Error - You have entered a movie twice!" << endl;
		}
*/
		cout << "Do you have anymore favorites???" << endl;		//Option to continue loop
		cin >> response;
		cin.ignore();
		cin.clear();

	}
	
	// now that we have array populated w/ object, show them
	for (i = 0; i < count; i++)
	{
		mylist[i]->Display();
	}

	//Saving the File
	ofstream outfile(fileLocation);
	if (!outfile.good())
	{
		cout << "ERROR - Can not open file! " << endl;
		return -1;
	}
	// Print output file to console
	for (i = 0; i < count; i++)
	{
		outfile << mylist[i];
	}

	// For deleting hanging pointers and clearing memory :)
	for (i = 0; i < count; i++)
	{
		delete mylist[i];
	}
	delete mylist;

	return 0;
}
