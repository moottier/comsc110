/*****************************************************************************************
Problem:     Lab 2.4 Working with Characters and Strings
Description: This program demonstrates the use of characters and strings

Name: Andre Mottier
ID:   1742339
Date: 6/22/18

Status: complete
*****************************************************************************************/

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

// Declaration of constants
const string FAVORITE_SODA = "Dr. Dolittle";     //  use double quotes for strings
const char BEST_RATING = 'A';					//  use single quotes for characters


int main()

{

	char rating;							// 2nd highest product rating 
	string favoriteSnack;					// most preferred snack
	int numberOfPeople;						// the number of people in the survey
	int topChoiceTotal;						// the number of people who prefer the top choice

											//  Fill in the code to do the following:
	favoriteSnack = "crackers";				//  Assign the value of "crackers" to favoriteSnack
	rating = 'B';							//  Assign a grade of 'B' to rating
	numberOfPeople = 250;					//  Assign the number 250 to the numberOfPeople
	topChoiceTotal = 148;					//  Assign the number 148 to the topChoiceTotal

											// Fill in the blanks of the following:
	cout << "The preferred soda is " << FAVORITE_SODA << endl;
	cout << "The preferred snack is " << favoriteSnack << endl;
	cout << "Out of " << numberOfPeople << " people "
		<< topChoiceTotal << " chose these items!" << endl;
	cout << "Each of these products were given a rating of " << BEST_RATING;
	cout << " from our expert tasters" << endl;
	cout << "The other products were rated no higher than a " << rating
		<< endl;

	cout << "\n\n" << "FOVIRTE_SODA cannot be changed by adding code to the main module or constant because it is declared as a constant. "
		<< "favoriteSnack *can* be changed by adding code to the program because it is declared as variable."
		<< endl;

	favoriteSnack = "cheese";

	cout << "\n" << "The newest preferred snack is " << favoriteSnack << endl;

	// the following line gives 'error C2678 ... no operator found which takes a left-hand operand of type const'
	//FAVORITE_SODA = "Spriit"; 

	return 0;

}
