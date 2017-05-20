#include <fstream> 
#include <vector>
#include "../Entity/User.h"
#include "../DTO/DTOUser.h"


bool DTOUser::ifExist(User& myUser)
{
	ifstream emailAndPass("Users.txt", ios_base::in);
	if (!emailAndPass.is_open())
	{
		return false;
	}
	else 
	{
		vector<User> usersPassAndEmails;
		bool ifExist;
		ifExist = false;

		string lineOfFile;
		int lineNumber;
		lineNumber = 0;
		int vectorIterator;
		vectorIterator = 0;
		
		User obj; 

		while (!emailAndPass.eof())
		{
			getline(emailAndPass, lineOfFile);

			if (lineNumber != 0)
			{
				if (lineNumber % 3 ==1)
				{
					obj.setEmail(lineOfFile);
				}
				if (lineNumber % 3 == 2)
				{
					obj.setPassword(lineOfFile);
				}
				else
				{
					obj.setId(lineOfFile);
				}

				if (lineNumber % 3 == 0)
				{
					usersPassAndEmails.push_back(obj);
				}

			}
			lineNumber++;
		}
		for (size_t i = 0; i < usersPassAndEmails.size(); i++)
		{
			if (myUser.getEmail() == usersPassAndEmails[i].getEmail())
			{
				ifExist = true;
				break;
			}
		}
		return ifExist;
	}
	emailAndPass.close();
	return 0;
}


 void DTOUser::save(User& user)
{
		while (ifExist(user))
		{
			cout << "Enter another email and password \n";
			cin >> user;
		}
		
		ofstream saveInfo("Users.txt", ios_base::app);

		if (!saveInfo.is_open())
		{
			cout << "Problems with RegistrationAtOurSystem.h";
		}
		else
		{
			user.setId(user.generateId());
			saveInfo << "\n";
			saveInfo << user.getEmail();
			saveInfo << "\n";
			saveInfo << user.getPassword();
			saveInfo << "\n";
			saveInfo << user.getId();
		}
		saveInfo.close();
}


vector<User> DTOUser::getAllUsers()
{
	vector<User> users;
	ifstream emailAndPass;
	
	emailAndPass.open("../Lnu/Users.txt");
	if (!emailAndPass.is_open())
	{
		//cout << "\tData base is empty ...";	
		cout << " You should registrate before login !!! ";
		return users;
	}
	else 
	{
		string s;
		int lineNumber;
		lineNumber = 0;
		int vectorIterator;
		vectorIterator = 0;

		User obj;

		while (!emailAndPass.eof())
		{
			getline(emailAndPass, s);

			if (lineNumber != 0)
			{
				if (lineNumber % 3 == 1)
				{
					obj.setEmail(s);
				}
				if (lineNumber % 3 == 2)
				{
					obj.setPassword(s);
				}
				else
				{
					obj.setId(s);
				}

				if (lineNumber % 3 == 0)
				{
					users.push_back(obj);
				}
			}
			lineNumber++;
		}
		return users;
	}
	emailAndPass.close();
}

void DTOUser::deleteUser(User& user)
{
	vector<User> users;
    users = getAllUsers();
	for (size_t i = 0; i < users.size(); i++)
	{
		if (users[i].getEmail() == user.getEmail())
		{
			users.erase(users.begin()+i);
		}
	}

	ofstream saveInfo("Users.txt", ios_base::out | ios_base::trunc);

	if (!saveInfo.is_open())
	{
		cout << "Problems with RegistrationAtOurSystem.h";
	}
	else
	{
		for (size_t i = 0; i < users.size(); i++)
		{
			saveInfo << "\n";
			saveInfo << users[i].getEmail();
			saveInfo << "\n";
			saveInfo << users[i].getPassword();
			saveInfo << "\n";
			saveInfo << users[i].getId();
		}
	}
	saveInfo.close();
}

void DTOUser::changePassword(User& user)
{
	vector<User> users;
	users = getAllUsers();

	for (size_t i = 0; i < users.size(); i++)
	{
		if (users[i].getPassword() == user.getPassword())
		{
			string password;
			cout << "Enter your new password : ";
			cin >> password;
			users[i].setPassword(password);
			cout << "Please reload for further work \n ";
		}
	}

	ofstream saveInfo("Users.txt", ios_base::out | ios_base::trunc);

	if (!saveInfo.is_open())
	{
		cout << "Problems with RegistrationAtOurSystem.h";
	}
	else
	{
		for (size_t i = 0; i < users.size(); i++)
		{
			saveInfo << "\n";
			saveInfo << users[i].getEmail();
			saveInfo << "\n";
			saveInfo << users[i].getPassword();
			saveInfo << "\n";
			saveInfo << users[i].getId();
		}
	}
	saveInfo.close();
}
