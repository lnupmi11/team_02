#pragma once
#include <string>
using namespace std;
#include <cmath>

class Base
{
protected:
	string id;
public:
	Base();
	Base(string id);
	virtual string getId() = 0;
	virtual void setId(string id) = 0;
	string generateId();
};