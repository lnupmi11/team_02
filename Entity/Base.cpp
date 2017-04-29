#pragma once
#include"../Entity/Base.h"
#include<ctime>

Base::Base()
{
	this->id = "";
}

Base::Base(string id)
{
	this->id = id;
}

string Base::generateId()
{
	srand((unsigned int)(time(0)));
	string id;
	int length;
	length = 10;
	string symbols;
	symbols = "abcdefghijklmnopqrstuvwxyzABCEDFGHIJKLMNOPQRSTUVWXYZ1234567890";

	for (int i = 0; i < length; i++)
	{
		id += symbols[(int)(rand() * symbols.length())];
	}
	return id;
}
