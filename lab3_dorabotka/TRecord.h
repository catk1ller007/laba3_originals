#pragma once
#include <string>

using namespace std;

class TRecord
{
private:
	string name;
	int value;

public:
	TRecord(string _name, int _value = 0)
	{
		name = _name;
		value = _value;
	}

	TRecord(int _value = 0)
	{
		name = "";
		value = _value;
	}

	TRecord(const TRecord& tmp)
	{
		name = tmp.name;
		value = tmp.value;
	}

	~TRecord() {}

	string getName()
	{
		return name;
	}

	void setValue(int k)
	{
		value = k;
	}

	int getValue()
	{
		return value;
	}

	TRecord operator=(const TRecord& tmp)
	{
		name = tmp.name;
		value = tmp.value;
		return *this;
	}
};