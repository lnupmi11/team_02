#pragma once

bool checkIfCorrect(User& user)
{
	vector<User> passAndEmailOfAllUsers = DTOUser::getAllUsers();

	bool checkIflog_PasCorrect = false;

	for (int i = 0; i < passAndEmailOfAllUsers.size(); i++)
	{
		if (passAndEmailOfAllUsers[i].getEmail() == user.getEmail() && passAndEmailOfAllUsers[i].getPassword() == user.getPassword() )
		{
			checkIflog_PasCorrect = true;
			break;
		}
	}
	if (passAndEmailOfAllUsers.size() != 0 && checkIflog_PasCorrect==false)
	{
		cout << "This user does not exist at our base .";
	}
	return checkIflog_PasCorrect;
}
