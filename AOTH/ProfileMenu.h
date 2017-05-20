#pragma once

using namespace std;
int menu2()
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
			draw("Delete profile");
		}
		else
		{
			printf("\nDelete profile");
		}
		if (key == 1)
		{
			draw("Delete all advertisements");
		}
		else
		{
			printf("\nDelete all advertisements");
		}
		if (key == 2)
		{
			draw("Change log in");
		}
		else
		{
			printf("\nChange log in");
		}
		
		if (key == 3)
		{
			draw("Previous page");
		}
		else
		{
			printf("\nPrevious page");
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
int profileMenu(User& user)
{

	system("cls");
	int answer;
	for (; ; )
	{
		answer = menu2();
		switch (answer)
		{
		case 0:
		{
			system("cls");
			string email;
			cout << "Eneter your email : ";
			cin >> email;
			if (user.getEmail() == email)
			{
				DTOUser::deleteUser(user);
				DTOAdvertisement::deleteAdvertisementsOf(user);
				cout << "your account was sucessfully deleted ..\n";
				system("pause>>null");
				mainMenu();
			}
			else
			{
				cout << "incorrect email ...\n";
				system("pause>>null");
			}
			break;
		}
		case 1:
		{
			system("cls");
			string email;
			cout << "Eneter your email : ";
			cin >> email;
			if (user.getEmail() == email)
			{
				DTOAdvertisement::deleteAdvertisementsOf(user);
				cout << "your advertisements were sucessfully deleted ..\n";
				system("pause>>null");
			}
			else
			{
				cout << "incorrect email ...\n";
				system("pause>>null");
				correctLogin(user);
			}

			break;
		}
		case 2:
		{
			system("cls");
			//TODO : add code wich wiil change email or pass or this user
			break;
		}
		case 3:
		{
			correctLogin(user);
			break;
		}
		}
	}
	return 0;
}