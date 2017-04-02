#pragma once
void makeVectAdvWithStatus1(vector<Advertisement> &vect)
{

	int countDeleted = 0;

	for (int i = 0;i < vect.size()- countDeleted;i++)
	{
		while (vect[i].getStatus() == true)
		{
			vect.erase(vect.begin() + i);
			countDeleted++;
		}
	}
	

}