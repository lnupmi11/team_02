#pragma once
#include "Edit.h"
#include"../Utils/EnumWithRubrics.h"
#include "../Utils/HelperFunctions.h"
using namespace std;


void correctLogin(User& user)
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
	vector<Advertisement> advertOfUser;
	advertOfUser = DTOAdvertisement::getAllAdvert(user);

	switch (action)
	{
		case '1':
		{
			system("cls");

			if (advertOfUser.size() == 0)
			{
				cout << "You have no advertisements yet .\n";
				cout << "\nIf you want to create new advertisement , select this option in menu of your profile .\n ";
				system("pause>>null");
			}
			else
			{
				for (int i = 0;i < 5;i++)
				{
					int counterPrintedRubrics = 0;
					for (size_t j = 0; j < advertOfUser.size(); j++)
					{
						if (advertOfUser[j].getRubric() == getRubric(i) )
						{
							if (counterPrintedRubrics == 0)
							{
								cout << "\n*********************************************************************\n";

								cout << "\nRubric:  ";
								cout << advertOfUser[j].getRubric() << "\n\n";
							}
							counterPrintedRubrics++;

							cout << advertOfUser[j];
						}
					}
				}
				system("pause>>null");
			}
			correctLogin(user);
			break;
		}
		case '2':
		{
			system("cls");
			DTOAdvertisement::saveAdvertisement(user);
			correctLogin(user);
			break;
		}
		case '3':
		{
			system("cls");

			vector<Advertisement> advWith0;
			advWith0 = HelperFunction::leaveAdvWithStatus(advertOfUser, 0);

			if (advWith0.size() == 0)
			{
				cout << "You have no advertisements to edit. \n" ;
				system("pause>null");
			}
			else
			{
				editAdvertisement(advWith0);
			}
			correctLogin(user);
			break;
		}
		case '4':
		{
			break;
		}
		default:
		{
			cout << "Enter action (1,2,3) : ";
			cin >> action;
		}
	}

}
