#include "stdafx.h"
#include "movies.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Movies::Movies()
{
	Title = "";
	IMDB = 0;					//Initialize the variable to avoid carry overs from previously used memory
	name = "";
	rating = "";

}

Movies::Movies(string t, int i, string n, string r)
{
	Title = t;
	IMDB = i;					//Setup the var for overloaded functions
	name = n;
	rating = r;
}

int Movies::GetInput()
{
	cout << "What is the movie's title? ";				//This is where program gets user input for their favorite things
	getline(cin, Title);
	cout << "What is the movie's IMDB score? ";
	cin >> IMDB;
	cin.ignore();
	cin.clear();
	cout << "What is the director's name? ";
	getline(cin, name);
	cout << "What is the film Rated? (G - R) ";
	cin >> rating;
//	cin.ignore();
//	cin.clear();
	return 0;
}

void Movies::Display()
{
	cout << "" << endl;
	cout << "Movie Title: " << Title << endl;
	cout << "IMDB Score: " << IMDB << endl;
	cout << "Director's Name: " << name << endl;
	cout << "Film Rating: " << rating << endl;
}
/*
bool Movies::DuplicateMoive(Movies* t)			//This was supposed to be the duplicate detection function...
{
	if (Title == t->Title)
	{
		return 1;				//There needs to be a for loop to cycle through the txt file for this to work
	}
	else
	{
		return 0;
	}
}
*/
ofstream& operator<<(ofstream &fs, Movies *item)
{
	fs << item->Title << " | " << item->IMDB << " | " << item->name << " | " << item->rating << "." << endl;
	return fs;
}
