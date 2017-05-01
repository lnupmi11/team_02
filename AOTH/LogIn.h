#pragma once

bool checkIfCorrect(User& user)
{
	vector<User> usersPassAndEmails = DTOUser::getAllUsers();

	bool IsLogPassCorrect;
	IsLogPassCorrect = false;

	for (size_t i = 0; i < usersPassAndEmails.size(); i++)
	{
		if (usersPassAndEmails[i].getEmail() == user.getEmail() && usersPassAndEmails[i].getPassword() == user.getPassword() )
		{
			IsLogPassCorrect = true;
			user = User(user.getEmail(), user.getPassword(), usersPassAndEmails[i].getId());
			break;
		}
	}
	if (usersPassAndEmails.size() != 0 && IsLogPassCorrect == false)
	{
		cout << "This user does not exist in our base .";
	}
	return IsLogPassCorrect;
}
