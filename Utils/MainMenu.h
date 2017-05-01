#pragma once
void mainMenu()
{
	system("cls");
	cout << " \tIf you want to create a new profile ,  enter 1 . \n ";
	cout << " \tIf you want to log in ,  enter 2 . \n ";
	cout << " \tIf you want to view all advertisements ,  enter 3 . \n ";
	cout << " \tIf you want to exit ,  enter 4 . \n ";
	cout << " \t Action : ";
	
	char symbol;
	cin >> symbol;

		switch (symbol)
		{
			case '1':
			{
				system("cls");
				cout << " \t\t\t\t Welcome! \n" << "\t \t You need to fill a few fields to create an account. "<<endl;
				User user;
				cin >> user;
				DTOUser::save(user);	
				cout << " \n \t Registration successfully completed ! Press any key to continue.\n";		
				system("pause>>null");
				mainMenu();
			}
			case '2':
			{
				system("cls");
				cout << " \t\t\t Log in "<<endl;
				User user;
				cin >> user;
				if (checkIfCorrect(user))
				{
					correctLogin(user);
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
				viewAllBeforeLogin();
				mainMenu();
				break;
			}

			case '4':
			{
			  break;
			}
			default:
			{
				cout << "Enter action (1,2,3,4) : ";
			}

		}
}