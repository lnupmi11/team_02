#pragma once

#include"../Entity/Advertisement.h" 
#include <vector>

Advertisement::Advertisement()
{
	this->title = "";
	this->mainText = "";
	this->status = 0;
	this->email = "";
}

Advertisement::Advertisement(string title, string mainText, bool status , string email ) 
{
	this->title = title;
	this->mainText = mainText;
	this->status = status;
	this->email = email;
}

Advertisement::Advertisement(const Advertisement&x) 
{
	this->title = x.title;
	this->mainText = x.mainText;
	this->status = x.status;
	this->email = x.email;
}

string Advertisement::getTitle()
{
	return this->title;
}

string Advertisement::getMainText()
{
	return this->mainText;
}

void Advertisement::setStatus(bool status)
{
	this->status = status;
}

bool Advertisement::getStatus()
{
	return this->status;
}

string Advertisement::getEmail()
{
	return this->email;
}

void Advertisement::setEmail(string email)
{
	this->email = email;
}

void Advertisement::setTitle(string title)
{
	this->title = title;
}

void Advertisement::setMainText(string mainText)
{
	this->mainText = mainText;
}

istream &operator >> (istream &cin, Advertisement &advert)
{
	cout << " \t\t\t Welcome! \n" << "\t Here you can create an advertisement \n ";
	cout << "enter title: \n";
	cin.get();

	getline(cin, advert.title);
	cout << "enter advertisement : \n";
	cin.clear();

	_flushall();

	cin.get();

	getline(cin, advert.mainText);

	cout << "Do you want to save or send your advertisement to server? \n enter 1 or 2 :\n";

	cout << "Action :  ";
	char action;
	cin >> action;
	switch (action)
	{
	case '1':
	{
		advert.setStatus(0);
		break;
	}
	case '2':
	{
		advert.setStatus(1);
		break;
	}
	default:
	{
		cout << "\n You will be returned to previos page \n";
	}

	break;
	}

	return cin;
}

ostream &operator << (ostream &cout, Advertisement &advert)
{
	cout << "\n_________________________________\n";
	cout << "\t\t " << advert.title << "\n";
	cout << advert.mainText << "\n";
	//	cout << "\n" << this->status<<"\n";
	cout << advert.email << "\n";

	return cout;
}
