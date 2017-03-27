#pragma once
void mainMenu()
{
	system("cls");
	cout << " \tif you want to create a new profile ,  enter 1 . \n ";
	cout << " \tif you want to log in ,  enter 2 . \n ";
	cout << " \tif you want to view all adverrisement ,  enter 3 . \n ";
	cout << " \tif you want to exit ,  enter 4 . \n ";
	cout << "  Action : ";
	
	
	char symbol;
	vector<char> SymbolsList;
	bool checkCorrectInput = false;
	while (!checkCorrectInput)
	{
		do
		{
			cin.get(symbol);

			SymbolsList.push_back(symbol);
		} while (symbol != '\n');
	
		if (SymbolsList.size() == 2)
		{
			symbol = SymbolsList[0];
		}
		
		SymbolsList.clear();


		switch (symbol)
		{
		case '1':
		{
			checkCorrectInput = true;
			//registration
			
			system("cls");
			cout << " \t\t\t Welcome! \n" << "\t You need to fill a few fields to create an account \n ";

			User user;
			//user.inputInformationAboutUser();
			cin >> user;
			DTOUser userDTO;
			userDTO.saveInformation(user);

			cout << " \n \t\t Registration successfully completed ! \n";
			
			
			
			mainMenu();

		}
		case '2':
		{
			checkCorrectInput = true;

			system("cls");
			cout << " \t\t\t Log in \n ";
			User user;
			string pass, email; 
			cout << " enter your email  : \n";
			cout << "\t";
			cin >> email;
			cout << " enter your password : \n\t";
			cin >> pass;


			
			if (checkIfCorrect(email, pass) == true)
			{
				User user(email, pass);
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
			checkCorrectInput = true;
			viewAllBeforeLogIn();
			mainMenu();
			break;
		}

		case '4':
		{
			checkCorrectInput = true;
			return ;
			
		}
		default:

		{
			cout << "enter action (1,2,3,4) : ";
		}


		}
	}
}