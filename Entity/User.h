#include <iostream>
#include <string>
using namespace std;

class User
{
private:
	string email;
	string password;
public:
	
	User();
	
	User(string email, string password);

	void input();

	string getEmail();

	string getPassword();

	void setEmail(string s);

	void setPassword(string s);

	friend  istream& operator >> (istream& is, User& user);

	friend  ostream& operator << (ostream& os,  User& user);

};





