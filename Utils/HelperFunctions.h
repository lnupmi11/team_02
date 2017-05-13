#ifndef HelperFunction_HEADER
#define HelperFunction_HEADER

#include <ctime>
#include<string>

class HelperFunction
{
public:
	static	vector<Advertisement> leaveAdvWithStatus(vector<Advertisement>& vect, bool statToLeave);
	static string timeOfCreating();	
};

#endif