#pragma once


class DTOUser
{
public:
	static bool ifExist(User& myUser);
	static void save(User& user);
	static vector<User> getAllUsers();
	static void deleteUser(User& user);
	static void changePassword(User& user);
};
