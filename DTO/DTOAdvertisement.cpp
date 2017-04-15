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

			if (lineNumber != 0)// бо перший рядок в файлі пуста/first line at file is empty
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

void  DTOAdvertisement::editAdvertisement(string oldLine , string newLine)
{
	vector<string> vect;
	ifstream fileStream("advertisements.txt" );
	
	if (!fileStream.is_open() )
	{
		cout << "\nВata base is empty! ...";
	}
	else
	{
		string line;
		while (!fileStream.eof())
		{
			getline(fileStream, line);
			if (line == (string) oldLine)
			{
				line = (string) newLine;
			}
			vect.push_back(line);
		}
		fileStream.close();

		ofstream inFile("advertisements.txt" , ios_base::trunc);
	 
		for (int i = 0; i < vect.size(); i++)
		{
			inFile << line << "\n";
		}
		inFile.close();
	}
}
