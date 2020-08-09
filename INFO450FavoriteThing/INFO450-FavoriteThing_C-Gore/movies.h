#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "stdafx.h"
#include <cstdlib>

using namespace std;

class Movies 
{
protected:
	string Title;
	int IMDB;					//No values here, just setting up the var
	string name;
	string rating;

public:
	Movies();
	Movies(string t, int i, string n, string r);
//	bool DuplicateMoive(Movies* t);
	int GetInput();
	void Display();
	
	friend ofstream& operator<<(ofstream &fs, Movies *item);
};