#pragma once
void mainMenu()
{
	system("cls");
	cout << " \tif you want to create a new profile ,  enter 1 . \n ";
	cout << " \tif you want to log in ,  enter 2 . \n ";
	cout << " \tif you want to view all advertisements ,  enter 3 . \n ";
	cout << " \tif you want to exit ,  enter 4 . \n ";
	cout << "  Action : ";
	
	char symbol;
	cin >> symbol;

		switch (symbol)
		{
		case '1':
		{
			system("cls");
			cout << " \t\t\t Welcome! \n" << "\t You need to fill a few fields to create an account \n ";
			User user;
			cin >> user;
			DTOUser::save(user);	
			cout << " \n \t\t Registration successfully completed ! Press any key to continue.\n";		
			system("pause>>null");
			mainMenu();

		}
		case '2':
		{
			system("cls");
			cout << " \t\t\t Log in \n ";
			User user;
			cin >> user;
			if (checkIfCorrect(user))
			{
				correctLogIn(user);
				mainMenu();
			}
			else
			{		
				cout << "\n Incorrect email or password .";
				system("pause>>null");
			}	
			mainMenu();
			break;
		}
		case '3':
		{
			
			viewAllBeforeLogIn();
			mainMenu();
			break;
		}

		case '4':
		{
		  break;
		}
		default:
		{
			cout << "enter action (1,2,3,4) : ";
		}

		}
}