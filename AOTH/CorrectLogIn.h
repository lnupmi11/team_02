#pragma once
#include"../Utils/HelperFunctions.h"

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
		vector<Advertisement> advWith0;

		advWith0 = leaveAdvGivenStatus(advertOfThisUser, 0);

		system("cls");

		if (advWith0.size() == 0)
		{
			cout << "You don't have any advertisements to edit. " << endl;
			system("pause>null");
			break;
		}

		cout << "Here you can edit your advertisements , which you has not published .";
		cout << endl;
		cout << "Advertisements: \n \n ";
		for (int i = 0; i < advWith0.size(); i++)
		{
			cout << advertOfThisUser[i].getTitle() << endl;
		}
		cout << endl;
		int number;

		cout << "Enter the number of advertisement which you want to edit: \n";
		cin >> number;

		if (number > advWith0.size())
		{
			cout << "Enter correct number: " << endl;
			cin >> number;
		}
		system("cls");
		cout << "Now you can edit this advertisement: \n\n";
		cout << endl;
		cout << "title: " << advertOfThisUser[number - 1].getTitle() << endl << endl;
		cout << "main text: " << advertOfThisUser[number - 1].getMainText() << endl << endl;

		char nextAction;
		cout << "What do you want to do now?" << endl;
		cout << "1 - change title" << endl;
		cout << "2 - add new text" << endl;
		cout << "3 - send this advertisement to the server" << endl;
		cin >> nextAction;

		switch (nextAction)
		{
		case'1':
		{
			system("cls");
			cout << "Enter new title:\n";
			string newTitle;


			break;
		}
		case'2':
		{
			system("cls");
			cout << "Enter new text: \n";

			string newText;

			break;
		}
		case'3':
		{
			system("cls");
			advertOfThisUser[number - 1].setStatus(1);
			cout << "Thank you! Now you can return to the main menu.\n\n Press any key to back to the main menu\n";
			break;

		}

		}

		system("pause>null");
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
