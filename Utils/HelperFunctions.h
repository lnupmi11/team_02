#ifndef HelperFunction_HEADER
#define HelperFunction_HEADER

#include <iostream>
#include <ctime>
#include<string>
using namespace std;


class HelperFunction
{
public:
	static	vector<Advertisement> leaveAdvWithStatus(vector<Advertisement>& vect, bool statToLeave);
	static string timeOfCreating();	
};

#endif