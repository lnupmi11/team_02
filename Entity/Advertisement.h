#include <iostream>
#include <string>

using namespace std;


class Advertisement
{
private:
	string title;
	string mainText;
	bool status;
	string email;
	string rubric;
public:
	Advertisement();

	Advertisement(string title, string mainText, bool status, string email, string rubric);

	Advertisement(const Advertisement&x);

	string getTitle();

	string getMainText();

	void setStatus(bool status);

	bool getStatus();

	string getEmail();

	string getRubric();

	void setEmail(string email);

	void setMainText(string mainText);

	void setTitle(string title);

	void setRubric(string rubric);

	friend istream &operator >> (istream &cin, Advertisement &advert);

	friend ostream &operator << (ostream &cout, Advertisement &advert);
};