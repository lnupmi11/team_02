#include <iostream>
using namespace std;

#include "Base.h"

class Advertisement :public Base
{
private:
	string title;
	string mainText;
	bool status;
	string rubric;
	string email;

public:
	Advertisement();
	Advertisement(string title, string mainText, bool status,  string rubric, string email);
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


	friend istream &operator >> (istream &cin, Advertisement &advert);
	friend ostream &operator << (ostream &cout, Advertisement &advert);
};