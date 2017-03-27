#pragma once

bool checkIfCorrect(string email, string pass);


bool checkIfCorrect(string email,string pass)
{
	DTOUser userDTO;
	
	vector<User> passAndEmailOfAllUsers = userDTO.getAllUsers();

	bool checkIflog_PasCorrect = false;


	for (int i = 0; i < passAndEmailOfAllUsers.size(); i++)
	{
		if (passAndEmailOfAllUsers[i].getEmail() == email && passAndEmailOfAllUsers[i].getPassword() == pass)
		{
			checkIflog_PasCorrect = true;
			break;
		}
	}
	if (passAndEmailOfAllUsers.size() != 0 && checkIflog_PasCorrect==false)
	{
		cout << "this user does not exist at our base =(";
	}

	return checkIflog_PasCorrect;
}
