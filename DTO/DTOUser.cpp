#include <fstream> 
#include <vector>
#include <string>
#include "../Entity/User.h"
#include "../DTO/DTOUser.h"

bool DTOUser::ifExist(User myUser)
{
	ifstream emailAndPass("user password and email.txt", ios_base::in);
	if (!emailAndPass.is_open())
	{
		return false;
	}
	else 
	{
		vector<User> usersPassAndEmails;
		bool ifExist;
		ifExist = false;

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
				if (lineNumber % 2 != 0)
				{
					obj.setEmail(s);
				}
				else
				{
					obj.setPassword(s);
				}

				if (lineNumber % 2 == 0)
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
		string s;

		ofstream putInfoIntoFile("user password and email.txt", ios_base::app);

		if (!putInfoIntoFile.is_open())
		{
			cout << "problems with RegistrationAtOurSystem.h";
		}
		else
		{
			user.setId(user.generateId());
			putInfoIntoFile << "\n";
			putInfoIntoFile << user.getEmail();
			putInfoIntoFile << "\n";
			putInfoIntoFile << user.getPassword();
		//TODO
		//add field id to txt file
		}
		putInfoIntoFile.close();
}


vector<User> DTOUser::getAllUsers() // this function must be changed  , as we plan to add id field
{
	vector<User> usersPassAndEmails;
	ifstream emailAndPass;
	
	emailAndPass.open("../Lnu/user password and email.txt");
	if (!emailAndPass.is_open())
	{
		cout << "\tData base is empty ...";		
		return usersPassAndEmails;
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
				if (lineNumber % 2 != 0)
				{
					obj.setEmail(s);
				}
				else
				{
					obj.setPassword(s);
				}

				if (lineNumber % 2 == 0)
				{
					usersPassAndEmails.push_back(obj);
				}
			}
			lineNumber++;
		}
		return usersPassAndEmails;
	}
}