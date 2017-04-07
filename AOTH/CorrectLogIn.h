#pragma once
#include"../Utils/HelperFunctions.h"

#include"Edit.h"

using namespace std;
void correctLogIn(User user)
{
	system("cls");

	cout << "\n\t\tYou successfully logined !\n";
	cout << "\nIf you want to view all your advertisement , enter 1 ";
	cout << "\nIf you want to create new advertisement ,enter 2 ";
	cout << "\nIf you want to edit your advertisement  , enter 3 ";
	cout << "\nIf you want to return to the main menu , enter 4 ";
	cout << " \n Action : ";

	char action;
	cin >> action;
	vector<Advertisement> advertOfThisUser;
	advertOfThisUser = DTOAdvertisement::getAllAdvertisementsOfThis(user);

	switch (action)
	{
	case '1':
	{
		system("cls");

		if (advertOfThisUser.size() == 0)
		{
			cout << "You don't have any advertisements yet .\n";
			cout << "\nIf you want to create new advertisement , select this option in menu of your profile .\n ";

			system("pause>>null");
		}
		else
		{
			for each (Advertisement advertisement in advertOfThisUser)
			{
				cout << advertisement;
			}
			system("pause>>null");
		}
		correctLogIn(user);
		break;
	}
	case '2':
	{
	
		system("cls");

		DTOAdvertisement::saveAdvertisement(user);
		correctLogIn(user);
		break;
	
	}
	case '3':
	{
		system("cls");

		vector<Advertisement> advWith0;
		advWith0 = leaveAdvWithStatus(advertOfThisUser, 0);

		if (advWith0.size() == 0)
		{
			cout << "You don't have any advertisements to edit. \n" ;
			system("pause>null");
		}
		else
		{
			editAdvertisement(advWith0);
		}

		correctLogIn(user);
		break;


	}
	case '4':
	{
		break;
	}
	default:
	{
		cout << "enter action (1,2,3) : ";
		cin >> action;
	}
	}

}
