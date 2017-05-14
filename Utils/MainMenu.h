#pragma once
#include <stdio.h>
#include <conio.h>

void draw(char str[20])
{
	printf("\n");
	_cprintf(">%s", str);
	system("color F");
}

int menu()
{
	int key;
	key = 0;
	int code;
	do
	{
		system("cls");
		key = (key + 4) % 4;

		if (key == 0)
		{
			draw("Create a new profile");
		}
		else
		{
			printf("\nCreate a new profile");
		}
		if (key == 1)
		{
			draw("Log in");
		}
		else
		{
			printf("\nLog in");
		}
		if (key == 2)
		{
			draw("View all advertisements");
		}
		else
		{
			printf("\nView all advertisements");
		}
		if (key == 3)
		{
			draw("Search");
		}
		else
		{
			printf("\nSearch");
		}
		if (key == 4)
		{
			draw("Exit");
		}
		else
		{
			printf("\nExit");
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
	} while (code != 13);

	return key;
}

bool checkIfCorrect(User& user);
void viewAllBeforeLogin();
void viewAllBeforeLoginByRubric();
int correctLogin(User& user);

int mainMenu()
{
	int answer;
	for (; ;)
	{
		answer = menu();
		switch (answer)
		{
		case 0:
		{
			system("cls");
			cout << " \t\t\t\t Welcome! \n" << "\t \t You need to fill a few fields to create an account. " << endl;
			User user;
			cin >> user;
			DTOUser::save(user);
			cout << " \n \t Registration successfully completed ! Press any key to continue.\n";
			system("pause>>null");
			mainMenu();
		}
		break;
		case 1:
		{
			system("cls");
			cout << " \t\t\t Log in " << "\n";
			User user;
			cin >> user;
			if (checkIfCorrect(user))
			{
				correctLogin(user);
			}
			else
			{
				cout << "\n Incorrect email or password .";
				system("pause>>null");
			}
			mainMenu();
		}
		break;
		case 2:
		{
			viewAllBeforeLogin();
			mainMenu();
		}
		break;
		case 3:
		{
			viewAllBeforeLoginByRubric();
			mainMenu();
		}
		break;
		case 4:
		{
			exit(0);
		}
		break;
		}
		return 0;
	}
}