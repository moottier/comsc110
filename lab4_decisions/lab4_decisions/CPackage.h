/*****************************************************************************************
Problem:
Description:

Name: Andre Mottier
ID:   1742339
Date:

Status: in progress
*****************************************************************************************/

#ifndef CPackage_H
#define CPackage_H

#include <string>
//#include <map>

using namespace std;


class CPackage
{
public:
	CPackage(const char & newPackageName);
	CPackage();
	void setPlan(const char & newPackageName);
	char getPlan() const;
	float getOwed() const;
private:
	char packageName;
	string promptForPlan();
	string promptForHours();
	char validatePlan(const string & userInput);
	float validateHours(const string & userInput);
	float calculateOwed(const float & rate, const float & hours)
};

#endif