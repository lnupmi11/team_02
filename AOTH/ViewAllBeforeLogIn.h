#pragma once
#include "../Utils/HelperFunctions.h"

void viewAllBeforeLogin()
{
	system("cls");
	cout << "\t\tHere you can find all available advertisement \n";
	vector<Advertisement> vectWithAllInformation;

	DTOAdvertisement::getAllAdv(vectWithAllInformation);

	HelperFunction::leaveAdvWithStatus(vectWithAllInformation, 1);

	for (int i = 0; i < 5; i++)
	{
		int counterPrintedRubrics = 0;
		for (size_t j = 0; j < vectWithAllInformation.size(); j++)
		{
			if (vectWithAllInformation[j].getRubric() == getRubric(i) )
			{
				if (counterPrintedRubrics == 0)
				{
					cout << "\n********************************************************************\n";

					cout << "\nRubric:  ";
					cout << vectWithAllInformation[j].getRubric() << "\n\n";
				}
				counterPrintedRubrics++;
				cout <<"User: "<< vectWithAllInformation[j].getEmail() << endl;
				cout << "\n";
				cout << vectWithAllInformation[j];
				cout << "\n";
			}
		}
	}
	cout << "\n********************************************************************\n";
	cout << "\n " << "\t\tPress any key to back to main menu ....";
	system("pause>>null");
}


void viewAllBeforeLoginByRubric()
{
	system("cls");
	vector<Advertisement> vectWithAllInformation;

	DTOAdvertisement::getAllAdv(vectWithAllInformation);

	HelperFunction::leaveAdvWithStatus(vectWithAllInformation, 1);

	if (vectWithAllInformation.empty())
	{
		cout << "There aren't any advertisement yet";
	}
	else
	{
		cout << "\t\tHere you can find  advertisement \n";
		cout << "Choose the rubric , which you are looking for(enter number) :\n";
		

		for (int i = 0; i < 5; i++)
		{
			cout << i + 1 << " - " << getRubric(i) << "\n";
		}
		string action;
		cin >> action;

		string rubric;
		while (true)
		{
			if (action == "1" || action == "2" || action == "3" || action == "4" || action == "5")
			{
				break;
			}
			else
			{
				cout << "Enter correct number \n";
				action.clear();
				cin >> action;
			}
		}
		switch (stoi(action) - 1)
		{
		case ForSale:
		{
			rubric = "ForSale";
			break;
		}
		case WantToBuy:
		{
			rubric = "WantToBuy";
			break;
		}
		case SomethingDisappeared:
		{
			rubric = "SomethingDisappeared";
			break;
		}
		case Meetings:
		{
			rubric = "Meetings";
			break;
		}
		case Advertising:
		{
			rubric = "Advertising";
			break;
		}
		}

		system("cls");

		for (int i = 0; i < 5; i++)
		{
			int counterPrintedRubrics = 0;
			for (size_t j = 0; j < vectWithAllInformation.size(); j++)
			{
				if (vectWithAllInformation[j].getRubric() == getRubric(i) && rubric == getRubric(i))
				{
					if (counterPrintedRubrics == 0)
					{
						cout << "\n********************************************************************\n";

						cout << "\nRubric:  ";
						cout << vectWithAllInformation[j].getRubric() << "\n\n";
					}
					counterPrintedRubrics++;
					cout << "User: " << vectWithAllInformation[j].getEmail() << endl;
					cout << "\n";
					cout << vectWithAllInformation[j];
					cout << "\n";
				}
			}
		}
		cout << "\n********************************************************************\n";
	}
	cout << "\n " << "\t\tPress any key to back to main menu ....";
	system("pause>>null");

}