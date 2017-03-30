#include <fstream> 
#include<vector>
#include<string>
#include"../Entity/Advertisement.h"
#include"../Entity/User.h"
#include"../DTO/DTOAdvertisement.h"

/*
void DTOAdvertisement::input(Advertisement& advert)
{
	system("cls");
	cout << " \t\t\t Welcome! \n" << "\t Here you can create an advertisement \n ";
	cout << "enter title: \n";
	cin.get();

	getline(cin, advert.getTitle());
	cout << "enter advertisement : \n";
	cin.clear();

	_flushall();

	cin.get();

	getline(cin, advert.getMainText());

	cout << "Do you want to save or send your advertisement to server? \n enter 1 or 2 :\n";

	cout << "Action :  ";
	char action;
	cin >> action;
	switch (action)
	{
	case '1':
	{
		advert.setStatus(0);
		break;
	}
	case '2':
	{
		advert.setStatus(1);
		break;
	}
	default:
	{
		cout << "\n You will be retnrned to previos page \n";
	}

	break;
	}

}

void DTOAdvertisement::print(Advertisement& advert)
{
	cout << "\n_________________________________\n";
	cout << "\t\t " << advert.getTitle() << "\n";
	cout << advert.getMainText() << "\n";
	//	cout << "\n" << this->status<<"\n";
	cout << advert.getEmail() << "\n";

}
*/
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
						checkStatus = true;
					}
					else
					{
						checkStatus = false;
					}
				}
				if (lineNumber % 4 == 0 && checkStatus == 1)
				{
					obj.setEmail(s);
					allAdvertisementWithStatus1.push_back(obj);
				}
			}
			lineNumber++;
		}
	}


}
