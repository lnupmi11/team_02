#pragma once
#include "../Entity/Advertisement.h" 
#include <vector>

Advertisement::Advertisement()
{
	this->title = "";
	this->mainText = "";
	this->status = 0;
	this->rubric = "";
}

Advertisement::Advertisement(string title, string mainText, bool status , string rubric)
{
	this->title = title;
	this->mainText = mainText;
	this->status = status;
	this->rubric = rubric;
}

Advertisement::Advertisement(const Advertisement& x)
{
	this->title = x.title;
	this->mainText = x.mainText;
	this->status = x.status;
	this->id = x.id;
	this->rubric = x.rubric;
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


	vector<string> allRubrics(5);
	allRubrics[0] = "For sale";
	allRubrics[1] = "Want to buy";
	allRubrics[2] = "Something disappeared";
	allRubrics[3] = "Meetings";
	allRubrics[4] = "Advertising";

	
	cout << "Choose the rubric for your advertisement(enter number) :\n";
	for (int i = 0; i < 5; i++)
	{
		cout <<i + 1<< " - " << allRubrics[i] << "\n";
	}

	char action0;
	cin >> action0;
	switch (action0)
	{
	case '1':
	{
		advert.setRubric(allRubrics[0]);
		break;
	}
	case '2':
	{
		advert.setRubric(allRubrics[1]);
		break;
	}
	case '3':
	{
		advert.setRubric(allRubrics[2]);
		break;
	}
	case '4':
	{
		advert.setRubric(allRubrics[3]);
		break;
	}
	case '5':
	{
		advert.setRubric(allRubrics[4]);
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
	cout << "\t\t " << advert.title << "\n";
	cout << advert.mainText << "\n";
//	cout << advert.email << "\n";
	cout << "\n_________________________________\n";
	return cout;
}
