#include <fstream> 
#include <vector>
#include <string>
#include "../Entity/User.h"
#include "../DTO/DTOUser.h"

bool DTOUser::ifExist(User& myUser)
{
	ifstream emailAndPass("users.txt", ios_base::in);
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
	return 0;
}


 void DTOUser::save(User& user)
{
		while (ifExist(user))
		{
			cout << "Enter another email and password \n";
			cin >> user;
		}
		
		ofstream saveInfo("users.txt", ios_base::app);

		if (!saveInfo.is_open())
		{
			cout << "problems with RegistrationAtOurSystem.h";
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
	
	emailAndPass.open("../Lnu/users.txt");
	if (!emailAndPass.is_open())
	{
		cout << "\tData base is empty ...";		
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
}