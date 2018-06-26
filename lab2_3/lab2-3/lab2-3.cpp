/*****************************************************************************************
Problem:     Lab 2.3 Rectangle Area and Perimeter
Description: This program will output the perimeter and area of the rectangle with the given length and width

Name: Andre Mottier
ID:   1742339
Date: 6/22/18

Status: complete
*****************************************************************************************/


#include "stdafx.h"
#include <iostream>

using namespace std;

const  int LENGTH = 8;
const  int WIDTH = 4;


int main()

{
	int  area;			  	        // definition of area of circle

	int  perimeter;				    // definition of circumference

	perimeter = 2 * (LENGTH + WIDTH);	// computes circumference

	area = LENGTH * WIDTH;        // computes area

	cout << "The perimeter of the rectangle is " << perimeter << "\n";
	cout.width(1); cout << ""; cout << "The area of the rectangle is " << area << endl;

	return 0;
}
