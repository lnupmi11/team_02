#pragma once

#include "../Entity/User.h"

User::User()
{
	email = "";
	password = "";
}

User::User(string email, string password)
{
	this->email = email;
	this->password = password;
}


string User::getEmail()
{
	return email;
}

string User::getPassword()
{
	return password;
}

void User::setEmail(string s)
{
	this->email = s;
}

void User::setPassword(string s)
{
	this->password = s;
}

void User::input()
{
	cout << "Email : ";
	cin >> email;
	cout << "Password : ";
	cin >> password;
}
 istream& operator>>(istream& is, User& user)
{
	 cout << "Email : ";
	 is >> user.email;
	 cout << "Password : ";
	 is >> user.password;

	 return is;
}

 ostream& operator<< (ostream& os,  User& user)
 {
	 os << "Email : ";
	 os << user.email;
	 os << "Password : ";
	 os << user.password;
	
	 return os;
 }

