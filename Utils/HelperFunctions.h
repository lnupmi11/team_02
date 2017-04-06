#pragma once


vector<Advertisement> leaveAdvWith0(vector<Advertisement> &vect)
{
	for (int i = 0;i < vect.size();i++)
	{
		while (vect[i].getStatus() == true)
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

vector<Advertisement> leaveAdvWith1(vector<Advertisement> &vect)
{
	for (int i = 0;i < vect.size();i++)
	{
		while (vect[i].getStatus() == false)
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
