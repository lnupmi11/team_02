#include <fstream> 
#include <vector>
#include <string>
#include <cstdio>
#include "../Entity/Advertisement.h"
#include "../Entity/User.h"
#include "../DTO/DTOAdvertisement.h"
#include "../Utils/HelperFunctions.h"


void DTOAdvertisement::saveAdvertisement(User& obj)
{
	Advertisement advertisement;
	cin>>advertisement;
	ofstream saveAdv("advertisements.txt", ios_base::app);
	advertisement.setId(obj.getId());
	advertisement.setTime(timeOfCreating());
	advertisement.setEmail(obj.getEmail());
	saveAdv << "\n";
	saveAdv << advertisement.getTitle();
	saveAdv << "\n";
	saveAdv << advertisement.getMainText();
	saveAdv << "\n";
	saveAdv << advertisement.getStatus();
	saveAdv << "\n";
	saveAdv << advertisement.getId();
	saveAdv << "\n";
	saveAdv << advertisement.getRubric();
	saveAdv << "\n";
	saveAdv << advertisement.getTime();
	saveAdv << "\n";
	saveAdv << advertisement.getEmail();
	
	saveAdv.close();
}

void DTOAdvertisement::getAllAdv(vector<Advertisement>& allAdv)
{
	ifstream advertisement;
	advertisement.open("../Lnu/advertisements.txt");
	if (!advertisement.is_open())
	{
		cout << "\nData base is empty! ...";
	}
	else 
	{
		string lineOfFile;
		int lineNumber;
		lineNumber = 0;

		Advertisement obj;

		while (!advertisement.eof())
		{
			getline(advertisement, lineOfFile);

			if (lineNumber != 0)
			{
				if (lineNumber % 7 == 1)
				{
					obj.setTitle(lineOfFile);

				}
				if (lineNumber % 7 == 2)
				{
					obj.setMainText(lineOfFile);
				}

				if (lineNumber % 7 == 3)
				{
					if (lineOfFile == "1")
					{
						obj.setStatus(1);
					}
					else
					{
						obj.setStatus(0);
					}
				}
				if (lineNumber % 7 == 4)
				{
					obj.setId(lineOfFile);
				}
				if (lineNumber % 7 == 5)
				{
					obj.setRubric(lineOfFile);
				}
				if (lineNumber % 7 == 6)
				{
					obj.setTime(lineOfFile);
				}
				if (lineNumber % 7 == 0)
				{
					obj.setEmail(lineOfFile);
					allAdv.push_back(obj);
				}
			}
			lineNumber++;
		}
	}
	advertisement.close();
}

vector<Advertisement> DTOAdvertisement::getAllAdvert(User user)
{
	vector<Advertisement> vect;

	DTOAdvertisement::getAllAdv(vect);
	
	int iterator;
	iterator = 0;
	
	int vectSize;
	vectSize = vect.size();
	while(iterator<vectSize)
	{
		if (vect[iterator].getId() != user.getId())
		{
			vect.erase(vect.begin() + iterator);
			vectSize = vect.size();
			continue;
		}
		iterator++;
	}
	return vect;
}

void  DTOAdvertisement::editAdvertisement(string oldLine , string newLine , string mainText)
{
	vector<string> vect;
	ifstream fileStream("advertisements.txt" );
	
	if (!fileStream.is_open() )
	{
		cout << "\nData base is empty! ...";
	}
	else
	{
		string line;
		bool isThisAdv = false;
		while (!fileStream.eof())
		{
			getline(fileStream, line);
			if (line == mainText)
			{
				isThisAdv = true;
			}
			else
			{
				if (line != "0")
				{
					isThisAdv = false;
				}
			}
			if ((oldLine=="0")&&(line == "0") && (isThisAdv))
			{
				line = newLine;
			}

			if (oldLine != "0")
			{
				if (line == oldLine)
				{
					line = newLine;
				}
			}

			vect.push_back(line);
		}
	}
		fileStream.close();
		ofstream inFile("advertisements.txt" , ios_base::out | ios_base::trunc);

		size_t vectSize;
		vectSize = vect.size();
        for (size_t i = 0; i < vectSize; i++)
		{
			inFile << vect[i];
			if (i != (vectSize - 1))
			{
				inFile << "\n";
			}
		}
		inFile.close();
}

