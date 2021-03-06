#include <iostream>
#include "../Entity/Base.h"
using namespace std;


class User : public Base 
{
private:
	string email;
	string password;
public:
	User();
	User(string email, string password);
	User(string email, string password,string id);
	User(const User& obj);
	void input();
	string getEmail();
	string getPassword();
	void setEmail(string s);
	void setPassword(string s);
	void setId(string id);
	string getId();

	friend istream& operator >> (istream& is, User& user);
	friend ostream& operator << (ostream& os, User& user);
};





