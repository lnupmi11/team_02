#pragma once
#include<vector>
#include"../Entity/Advertisement.h"
#include"../Utils/HelperFunctions.h"
vector<Advertisement> HelperFunction::leaveAdvWithStatus(vector<Advertisement>& vect, bool statToLeave)
{
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
}

string HelperFunction::timeOfCreating()
{
	return string();
}
