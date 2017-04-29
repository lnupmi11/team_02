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
				if (lineNumber % 3 ==1)
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
			putInfoIntoFile << "\n";
			putInfoIntoFile << user.getId();
		}
		putInfoIntoFile.close();
}


vector<User> DTOUser::getAllUsers()
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
					usersPassAndEmails.push_back(obj);
				}
			}
			lineNumber++;
		}
		return usersPassAndEmails;
	}
}