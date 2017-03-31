#include <fstream> 
#include<vector>
#include<string>

#include"../Entity/User.h"
#include"../DTO/DTOUser.h"

bool DTOUser::ifExist(User myUser)
{
	
	ifstream emailAndPassword("user password and email.txt", ios_base::in);
	if (!emailAndPassword.is_open())
	{
		return false;
	}
	else 
	{
		vector<User> passAndEmailOfAllUsers;
		bool ifExist = false;

		string s;
		int lineNumber = 0;
		int vectorIterator = 0;
		
		User obj; 

		while (!emailAndPassword.eof())
		{
			getline(emailAndPassword, s);

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
					passAndEmailOfAllUsers.push_back(obj);
				}

			}
			lineNumber++;
		}
		for (int i = 0; i < passAndEmailOfAllUsers.size(); i++)
		{
			if (myUser.getEmail() == passAndEmailOfAllUsers[i].getEmail())
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

		ofstream putInformationIntoFile("user password and email.txt", ios_base::app);

		if (!putInformationIntoFile.is_open())
		{
			cout << "problems with RegistrationAtOurSystem.h";
		}
		else {
			putInformationIntoFile << "\n";
			putInformationIntoFile << user.getEmail();
			putInformationIntoFile << "\n";
			putInformationIntoFile << user.getPassword();
		}
		putInformationIntoFile.close();
}


vector<User> DTOUser::getAllUsers()
{

	vector<User> passAndEmailOfAllUsers;
	ifstream emailAndPassword;
	
	emailAndPassword.open("../Lnu/user password and email.txt");
	if (!emailAndPassword.is_open())
	{
		cout << "\tData base is empty ...";		
		return passAndEmailOfAllUsers;

	}
	else {
		string s;
		int lineNumber = 0;
		int vectorIterator = 0;

		User obj;

		while (!emailAndPassword.eof())
		{
			getline(emailAndPassword, s);

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
					passAndEmailOfAllUsers.push_back(obj);
				}
			}
			lineNumber++;
		}
		return passAndEmailOfAllUsers;
	}
}