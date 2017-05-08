#pragma once

bool checkIfCorrect(User& user)
{
	vector<User> usersPassAndEmails = DTOUser::getAllUsers();

	bool IsCorrect;
	IsCorrect = false;

	for (size_t i = 0; i < usersPassAndEmails.size(); i++)
	{
		if (usersPassAndEmails[i].getEmail() == user.getEmail() && usersPassAndEmails[i].getPassword() == user.getPassword() )
		{
			IsCorrect = true;
			user = User(user.getEmail(), user.getPassword(), usersPassAndEmails[i].getId());
			break;
		}
	}
	if (usersPassAndEmails.size() != 0 && IsCorrect == false)
	{
		cout << "This user does not exist in our base .";
	}
	return IsCorrect;
}
