#pragma once
#include "../Entity/Advertisement.h" 
#include <vector>
#include"../Utils/EnumWithRubrics.h"
Advertisement::Advertisement()
{
	this->title = "";
	this->mainText = "";
	this->status = 0;
	this->rubric = "";
	this->email = "";
}

Advertisement::Advertisement(string title, string mainText, bool status , string rubric, string email)
{
	this->title = title;
	this->mainText = mainText;
	this->status = status;
	this->rubric = rubric;
	this->email = email;
}

Advertisement::Advertisement(const Advertisement& x)
{
	this->title = x.title;
	this->mainText = x.mainText;
	this->status = x.status;
	this->id = x.id;
	this->rubric = x.rubric;
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

string Advertisement::getRubric()
{
	return this->rubric;
}

void Advertisement::setId(string id)
{
	this->id = id;
}

string Advertisement::getId()
{
	return this->id;
}

void Advertisement::setTitle(string title)
{
	this->title = title;
}

void Advertisement::setMainText(string mainText)
{
	this->mainText = mainText;
}

void Advertisement::setRubric(string rubric)
{
	this->rubric = rubric;
}

void Advertisement::setEmail(string email)
{
	this->email = email;

}
string Advertisement::getEmail()
{
	return this->email;
}

istream& operator >> (istream& cin, Advertisement& advert)
{
	cout << " \t\t\t Welcome! \n" << "\t Here you can create an advertisement \n ";
	cout << "enter title: \n";
	
	cin.get();
	getline(cin, advert.title);
	
	cout << "enter advertisement : \n";
	
	cin.clear();
	_flushall();
	getline(cin, advert.mainText);

	cout << "Choose the rubric for your advertisement(enter number) :\n";
	for (int i = 0; i < 5; i++)
	{
		cout <<i + 1<< " - " <<  getRubric(i) << "\n";
	}

	int action0 ;
	cin >> action0;

	switch (action0)
	{
	case ForSale:
	{
		advert.setRubric(getRubric( ForSale));
		break;
	}
	case WantToBuy:
	{
		advert.setRubric(getRubric(WantToBuy) );
		break;
	}
	case SomethingDisappeared:
	{
		advert.setRubric(getRubric(SomethingDisappeared));
		break;
	}
	case Meetings:
	{
		advert.setRubric(getRubric(Meetings));
		break;
	}
	case Advertising:
	{
		advert.setRubric(getRubric(Advertising));
		break;
	}
	default:
	{
		cout << "\n Enter correct number \n";
	}

	break;
	}

	cout << "Do you want to save or send your advertisement to server? \n 1 - save ,  2 - send :\n";

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
		cout << "\n You will be returned to previous page \n";
	}

	break;
	}

	return cin;
}

ostream& operator << (ostream& cout, Advertisement& advert)
{
	cout << "title: " << advert.title << "\n";
	cout << "\n";
	cout << advert.mainText << "\n";
	cout << "\n_________________________________\n";
	return cout;
}
