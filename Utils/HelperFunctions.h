#pragma once


vector<Advertisement> leaveAdvWithStatus(vector<Advertisement> &vect, bool statToLeave)
{
	for (int i = 0;i < vect.size()  ;i++)
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

