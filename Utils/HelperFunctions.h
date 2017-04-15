#pragma once

vector<Advertisement> leaveAdvWithStatus(vector<Advertisement>& vect, bool statToLeave)
{
	for (int i = 0; i < vect.size(); i++)
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

vector<string> getRubrics()
{
	vector<string> vectRubrics(5);
	vectRubrics[0] = "For sale";
	vectRubrics[1] = "Want to buy";
	vectRubrics[2] = "Something disappeared";
	vectRubrics[3] = "Meetings";
	vectRubrics[4] = "Advertising";

	return vectRubrics;
}