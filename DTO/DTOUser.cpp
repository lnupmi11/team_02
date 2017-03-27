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
		vector<User> passAndEmailOfAllUsers;// містить логіни та паролі/ for log and pas
		bool ifExist = false;

		string s;
		int lineNumber = 0;
		int vectorIterator = 0;
		
		User obj;// в цей обєки записуємо логін і паролі а поітм його зьерігаємо у вектор, тобто це тимчасовоа змінна/
				 //it is a temporary variable for log and pass , we just put and save it at our vector  

		while (!emailAndPassword.eof())
		{
			getline(emailAndPassword, s);

			if (lineNumber != 0)// бо перша строка в файлі пуста/first line at file is empty
			{
				if (lineNumber % 2 != 0)// на не парних позиціях мейли/email 
				{
					obj.setEmail(s);
				}
				else// парні то тут паролі /pass
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


void DTOUser::saveInformation(User user)
{
		while (ifExist(user))
		{
			cout << "Enter another email\n";
			user.inputInformationAboutUser();
		}

		string s;

		ofstream putInformationIntoFile("user password and email.txt", ios_base::app);

		if (!putInformationIntoFile.is_open())
		{
			cout << "problems with RegistrationAtOurSystem.h ";
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
	// містить логіни та паролі/ for log and pas
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

			if (lineNumber != 0)// бо перша строка в файлі пуста/first line at file is empty
			{
				if (lineNumber % 2 != 0)// на не парних позиціях мейли/email 
				{
					obj.setEmail(s);
				}
				else// парні то тут паролі /pass
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