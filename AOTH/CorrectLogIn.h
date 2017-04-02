#pragma once
#include"../Utils/HelperFunctions.h"
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
   // get all adv of this user	
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
			for (Advertisement obj : advertOfThisUser)
			{
				cout << obj;
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
		//here we need to separate advertisements
		system("cls");
		cout << "here you can edit your advertisements , which you does not published  . \n";
		cout << "\t\t\n Advertisements \n ";
		makeVectAdvWithStatus1(advertOfThisUser);
		for (int i = 0;i < advertOfThisUser.size();i++)
		{
			cout << advertOfThisUser[i];
		}
		system("PAUSE>>NULL");
	
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
