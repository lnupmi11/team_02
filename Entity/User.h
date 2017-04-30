#include <iostream>
using namespace std;
#include "../Entity/Base.h"

class User : public Base 
{
private:
	string email;
	string password;
public:
	User();
	User(string email, string password);
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





