#pragma once

class DTOUser
{
public:

	bool ifExist(User myUser);

	void saveInformation(User user);

	vector<User> getAllUsers();
};
