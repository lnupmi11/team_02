#pragma once

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

	bool checkCorrectInput = false;

	while (!checkCorrectInput)
	{
		switch (action)
		{
		case '1':
		{
			checkCorrectInput = true;

			system("cls");				
			vector<Advertisement> advertOfThisUser;
			advertOfThisUser = DTOAdvertisement::getAllAdvertisementsOfThis(user);
			if (advertOfThisUser.size() == 0)
			{
				cout << "You don't have any advertisements yet .";
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
			break;
		}
		case '2':
		{
			checkCorrectInput = true;

			DTOAdvertisement::saveAdvertisement(user);

			break;
		}
		case '3':
		{
			checkCorrectInput = true;
			
			
			break;

		}
		case '4':
		{
			checkCorrectInput = true;
			break;
		}
		default:
		{
			cout << "enter action (1,2,3) : ";
			cin >> action;
		}
		}
	}

}
