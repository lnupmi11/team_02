#pragma once


enum Rubrics {
	ForSale,
	WantToBuy,
	SomethingDisappeared,
	Meetings,
	Advertising
};

string static getRubric(int i)
{
	string result;
	result = "";
	switch (i) {
	case ForSale: 
	{
		result = "ForSale";
		break;
	}
	case WantToBuy:
	{
		result = "WantToBuy";
		break;
	}
	case SomethingDisappeared:
	{ 
		result = "SomethingDisappeared";
		break;
	}
	case Meetings:
	{
		result = "Meetings";
		break;
	}
	case Advertising: 
	{
		result = "Advertising";
		break;
	}
	}

	return result;
}
