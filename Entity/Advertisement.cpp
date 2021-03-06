#pragma once
#include "../Entity/Advertisement.h" 
#include"../Utils/EnumWithRubrics.h"

Advertisement::Advertisement()
{
	this->title = "";
	this->mainText = "";
	this->status = 0;
	this->rubric = "";
	this->email = "";
	this->time = "";
}

Advertisement::Advertisement(string title, string mainText, bool status , string rubric, string email, string time)
{
	this->title = title;
	this->mainText = mainText;
	this->status = status;
	this->rubric = rubric;
	this->email = email;
	this->time = time;
}

Advertisement::Advertisement(const Advertisement& x)
{
	this->title = x.title;
	this->mainText = x.mainText;
	this->status = x.status;
	this->id = x.id;
	this->rubric = x.rubric;
	this->email = x.email;
	this->time = x.time;
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

void Advertisement::setTime(string time)
{
	this->time = time;

}

string Advertisement::getTime()
{
	return this->time;
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
		cout << i + 1 << " - " << getRubric(i) << "\n";
	}


	string action;
	cout << "-> ";
	cin >> action;
	while (true)
	{
		if (action == "1" || action == "2" || action == "3" || action == "4" || action == "5")
		{
			break;
		}
		else
		{
			cout << "Enter correct number \n";
			action.clear();
			cin >> action;
		}
	}
	switch (stoi(action) - 1)
	{
	case ForSale:
	{
		advert.setRubric(getRubric(ForSale));
		break;
	}
	case WantToBuy:
	{
		advert.setRubric(getRubric(WantToBuy));
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
	}
	
	cout << "Do you want to save or send your advertisement to server? \n 1 - save ,  2 - send :\n";

	string newAction;
	cout << "Action :  ";
	cin >> newAction;
	while (true)
	{
		if (newAction == "1" || newAction == "2")
		{
			break;
		}
		else
		{
			cout << "Enter correct number \n";
			newAction.clear();
			cin >> newAction;
		}
	}
	switch (stoi(newAction))
	{
	case 1:
	{
		advert.setStatus(0);
		break;
	}
	case 2:
	{
		advert.setStatus(1);
		break;
	}
	}
	return cin;
}

ostream& operator << (ostream& cout, Advertisement& advert)
{
	cout << "\t" << advert.title << "\n";
	cout << "\n";
	cout << advert.mainText << "\n\n";
	cout << advert.time << "\n";
	cout << "\n_________________________________\n";
	return cout;
}
