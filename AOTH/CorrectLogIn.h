#pragma once
#include "Edit.h"
#include"../Utils/EnumWithRubrics.h"
#include "../Utils/HelperFunctions.h"
#include "../Utils/MainMenu.h"
#include "../AOTH/Login.h"
#include"../AOTH/ProfileMenu.h"
 
using namespace std;

int menu_()
{
	int key;
	key = 0;
	int code;
	do
	{
		system("cls");
		key = (key + 7) % 7;

		if (key == 0)
		{
			draw("View all your advertisement");
		}
		else
		{
			printf("\nView all your advertisement");
		}
		if (key == 1)
		{
			draw("Create new advertisement");
		}
		else
		{
			printf("\nCreate new advertisement");
		}
		if (key == 2)
		{
			draw("Edit your advertisement");
		}
		else
		{
			printf("\nEdit your advertisement");
		}
		if (key == 3)
		{
			draw("View all advertisements");
		}
		else
		{
			printf("\nView all advertisements");
		}
		if (key == 4)
		{
			draw("Search");
		}
		else
		{
			printf("\nSearch");
		}
		if (key == 5)
		{
			draw("Main menu");
		}
		else
		{
			printf("\nMain menu");
		}
		if (key == 6)
		{
			draw("Profile menu");
		}
		else
		{
			printf("\nProfile menu");
		}

		code = _getch();
		if (code == 0)
		{
			code = _getch();
		}
		if (code == 80)
		{
			key++;
		}
		if (code == 72)
		{
			key--;
		}
	}while (code != 13);
	return key;
}

int correctLogin(User& user)
{
	system("cls");
	vector<Advertisement> advertOfUser;
	advertOfUser = DTOAdvertisement::getAllAdvert(user);

	vector<Advertisement> advWith1;
	advWith1 = HelperFunction::leaveAdvWithStatus(advertOfUser, 1);
	int answer;
	for (; ; )
	{
		answer = menu_();
		switch (answer)
		{
		case 0:
		{
			system("cls");

			if (advWith1.size() == 0)
			{
				cout << "You have no advertisements yet .\n";
				cout << "\nIf you want to create new advertisement , select this option in menu of your profile .\n ";
				system("pause>>null");
			}
			else
			{
				for (int i = 0; i < 5; i++)
				{
					int counterPrintedRubrics = 0;
					for (size_t j = 0; j < advWith1.size(); j++)
					{
						if (advWith1[j].getRubric() == getRubric(i))
						{
							if (counterPrintedRubrics == 0)
							{
								cout << "\n*********************************************************************\n";

								cout << "\nRubric:  ";
								cout << advWith1[j].getRubric() << "\n\n";
							}
							counterPrintedRubrics++;

							cout << advWith1[j];
						}
					}
				}
				system("pause>>null");
			}
			correctLogin(user);
			break;
		}
		case 1:
		{
			system("cls");
			DTOAdvertisement::saveAdvertisement(user);
			correctLogin(user);
			break;
		}
		case 2:
		{
			system("cls");
			vector<Advertisement> advert = DTOAdvertisement::getAllAdvert(user);
			vector<Advertisement> advWith0;
			advWith0 = HelperFunction::leaveAdvWithStatus(advert, 0);

			if (advWith0.size() == 0)
			{
				cout << "You have no advertisements to edit. \n";
				system("pause>null");
			}
			else
			{
				editAdvertisement(advWith0);
			}
			correctLogin(user);
			break;
		}
		case 3:
		{
			viewAllBeforeLogin();
			break;
		}
		case 4:
		{
			viewAllBeforeLoginByRubric();
			break;
		}
		case 5:
		{
			mainMenu();
			break;
		}
		case 6:
		{
			profileMenu(user);
			break;
		}
		}
	}
	return 0;
}
