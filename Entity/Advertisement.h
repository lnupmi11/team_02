#include <iostream>
#include "Base.h"
using namespace std;

class Advertisement :public Base
{
private:
	string title;
	string mainText;
	bool status;
	string rubric;
	string email;
	string time;

public:
	Advertisement();
	Advertisement(string title, string mainText, bool status,  string rubric, string email, string time);
	Advertisement(const Advertisement&x);
	
	string getTitle();
	void setTitle(string title);
	void setStatus(bool status);
	bool getStatus();
	void setId(string id);
	string getId();
	void setMainText(string mainText);
	string getMainText();
	void setRubric(string rubric);
	string getRubric();
	void setEmail(string email);
	string getEmail();
	string getTime();
	void setTime(string time);

	friend istream &operator >> (istream &cin, Advertisement &advert);
	friend ostream &operator << (ostream &cout, Advertisement &advert);
};