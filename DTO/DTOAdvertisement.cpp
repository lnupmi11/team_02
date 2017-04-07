#include <fstream> 
#include<vector>
#include<string>
#include<cstdio>
#include"../Entity/Advertisement.h"
#include"../Entity/User.h"
#include"../DTO/DTOAdvertisement.h"

void DTOAdvertisement::saveAdvertisement(User& obj)
{
	Advertisement advertisement;
	cin>>advertisement;
	ofstream putAdvertisementInformationIntoFile("advertisements.txt", ios_base::app);
	advertisement.setEmail(obj.getEmail());
	putAdvertisementInformationIntoFile << "\n";
	putAdvertisementInformationIntoFile << advertisement.getTitle();
	putAdvertisementInformationIntoFile << "\n";
	putAdvertisementInformationIntoFile << advertisement.getMainText();
	putAdvertisementInformationIntoFile << "\n";
	putAdvertisementInformationIntoFile << advertisement.getStatus();
	putAdvertisementInformationIntoFile << "\n";
	putAdvertisementInformationIntoFile << advertisement.getEmail();
	putAdvertisementInformationIntoFile.close();
}

void DTOAdvertisement::getAllAdvertisements(vector<Advertisement>& allAdvertisementWithStatus1)
{
	ifstream advertisement;
	advertisement.open("../Lnu/advertisements.txt");
	if (!advertisement.is_open())
	{
		cout << "\ndata base is empty!!! ...";
	}
	else {
		string s;
		int lineNumber = 0;

		Advertisement obj;

		bool checkStatus = false;

		while (!advertisement.eof())
		{

			getline(advertisement, s);

			if (lineNumber != 0)// бо перша строка в файлі пуста/first line at file is empty
			{
				if (lineNumber % 4 == 1)
				{
					obj.setTitle(s);

				}
				if (lineNumber % 4 == 2)
				{
					obj.setMainText(s);
				}

				if (lineNumber % 4 == 3)
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
				if (lineNumber % 4 == 0)
				{
					obj.setEmail(s);
					allAdvertisementWithStatus1.push_back(obj);
				}
			}
			lineNumber++;
		}
	}


}

vector<Advertisement> DTOAdvertisement::getAllAdvertisementsOfThis(User user)
{
	vector<Advertisement> vect;

	DTOAdvertisement::getAllAdvertisements(vect);
	
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
	
	if (! fileStream.is_open() )
	{
		cout << "\ndata base is empty!!! ...";
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
	 
		for each (line in vect)
		{
			inFile  << line<<"\n";
		}
		inFile.close();
	}
}
