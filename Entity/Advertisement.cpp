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


