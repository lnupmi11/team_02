#include <fstream> 
#include <vector>
#include <string>
#include <cstdio>
#include "../Entity/Advertisement.h"
#include "../Entity/User.h"
#include "../DTO/DTOAdvertisement.h"

void DTOAdvertisement::saveAdvertisement(User& obj)
{
	Advertisement advertisement;
	cin>>advertisement;
	ofstream putAdvIntoFile("advertisements.txt", ios_base::app);
	advertisement.setEmail(obj.getEmail());
	putAdvIntoFile << "\n";
	putAdvIntoFile << advertisement.getTitle();
	putAdvIntoFile << "\n";
	putAdvIntoFile << advertisement.getMainText();
	putAdvIntoFile << "\n";
	putAdvIntoFile << advertisement.getStatus();
	putAdvIntoFile << "\n";
	putAdvIntoFile << advertisement.getEmail();
	putAdvIntoFile << "\n";
	putAdvIntoFile << advertisement.getRubric();
	putAdvIntoFile.close();
}

void DTOAdvertisement::getAllAdv(vector<Advertisement>& allAdvWithStatus1)
{
	ifstream advertisement;
	advertisement.open("../Lnu/advertisements.txt");
	if (!advertisement.is_open())
	{
		cout << "\nData base is empty! ...";
	}
	else 
	{
		string s;
		int lineNumber;
		lineNumber = 0;

		Advertisement obj;

		bool checkStatus;
		checkStatus = false;

		while (!advertisement.eof())
		{
			getline(advertisement, s);

			if (lineNumber != 0)
			{
				if (lineNumber % 5 == 1)
				{
					obj.setTitle(s);

				}
				if (lineNumber % 5 == 2)
				{
					obj.setMainText(s);
				}

				if (lineNumber % 5 == 3)
				{
					if (s == "1")
					{
						obj.setStatus(1);
					}
					else
					{
						obj.setStatus(0);
					}
				}
				if (lineNumber % 5 == 4)
				{
					obj.setEmail(s);
				}
				if (lineNumber % 5 == 0)
				{
					obj.setRubric(s);
					allAdvWithStatus1.push_back(obj);
				}
			}
			lineNumber++;
		}
	}
}

vector<Advertisement> DTOAdvertisement::getAllAdvOfThis(User user)
{
	vector<Advertisement> vect;

	DTOAdvertisement::getAllAdv(vect);
	
	int iterator;
	iterator = 0;
	
	int vectSize;
	vectSize = vect.size();
	while(iterator<vectSize)
	{
		if (vect[iterator].getEmail() != user.getEmail())
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
	 
		int size = vect.size();
        for (size_t i = 0; i < size; i++)
		{
			inFile << vect[i];
			
			if (i != (size - 1))
			{
				inFile << "\n";
			}
		
		}
		inFile.close();
}

