#pragma once
#include <vector>

void input(Advertisement &advert)
{
	system("cls");
	cout << " \t\t\t Welcome! \n" << "\t Here you can create an advertisement \n ";
	cout << "enter title: \n";
	cin.get();

	getline(cin, advert.title);
	cout << "enter advertisement : \n";
	cin.clear();

	_flushall();

	cin.get();

	getline(cin, advert.mainText);

	cout << "Do you want to save or send your advertisement to server? \n enter 1 or 2 :\n";

	cout << "Action :  ";
	char action;
	cin >> action;
	switch (action)
	{
	case '1':
	{
		advert.status = 0;
		break;
	}
	case '2':
	{
		advert.status = 1;
		break;
	}
	default:
	{
		cout << "\n You will be retnrned to previos page \n";

	}
	
	break;
	}

}

void print(Advertisement &advert)
{
	cout << "\n_________________________________\n";
	cout << "\t\t " << advert.title << "\n";
	cout << advert.mainText << "\n";
	//	cout << "\n" << this->status<<"\n";
	cout << advert.email << "\n";

}

void putAdvertisementInformationIntoTxtFile(User &obj)
{
	Advertisement advertisement;
	input(advertisement);
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



void getAllAdvertisementWith1FromFile(vector<Advertisement> &allAdvertisementWithStatus1)
{
	

	ifstream advertisement;
	advertisement.open("../Lnu/advertisements.txt");
	if (!advertisement.is_open())
	{
		cout << "\ndata base is empty!!! ...";
	
	}
	else{
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

				if (lineNumber %4==3)
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
				if (lineNumber%4 == 0  && checkStatus==1 )
				{
					
					obj.setEmail(s);
					allAdvertisementWithStatus1.push_back(obj);
					
			
				}			
					
				
			}
			lineNumber++;

		
		
		}	
	}


}
