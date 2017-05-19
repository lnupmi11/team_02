#pragma once
#include "Edit.h"
#include"../Utils/EnumWithRubrics.h"
#include "../Utils/HelperFunctions.h"
#include "../Utils/MainMenu.h"
#include "../AOTH/Login.h"

using namespace std;

int menu_()
{
	int key;
	key = 0;
	int code;
	do
	{
		system("cls");
		key = (key + 6) % 6;

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
	int answer;
	for (; ; )
	{
		answer = menu_();
		switch (answer)
		{
		case 0:
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
				for (int i = 0; i < 5; i++)
				{
					int counterPrintedRubrics = 0;
					for (size_t j = 0; j < advertOfUser.size(); j++)
					{
						if (advertOfUser[j].getRubric() == getRubric(i))
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

			vector<Advertisement> advWith0;
			advWith0 = HelperFunction::leaveAdvWithStatus(advertOfUser, 0);

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
		}
	}
	return 0;
}
