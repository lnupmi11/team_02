#pragma once
#include <ctime>
#include<string>

vector<Advertisement> leaveAdvWithStatus(vector<Advertisement>& vect, bool statToLeave)
{
	for (size_t i = 0; i < vect.size(); i++)
	{
			while (vect[i].getStatus() != statToLeave)
			{
				vect.erase(vect.begin() + i);
				if (i == vect.size())
				{
					break;
				}
			}
	}
	return vect;
}

static string timeOfCreating()
{
	char buffer[32];
	time_t seconds = time(NULL);
	tm timeinfo;
	localtime_s(&timeinfo, &seconds);
	asctime_s(buffer, 32, &timeinfo);
	string time = (string)buffer;
	return time;
}