#pragma once
#include "TRecord.h"
#include <iostream>

using namespace std;

class TTable
{
private:
	TRecord* mem;
	int size;
	int count;

public:
	TTable(int _size = 0)
	{
		size = _size;
		count = 0;

		mem = new TRecord[size];

		for (int i = 0; i < size; i++)
		{
			mem[i] = TRecord("", 0);
		}
	}

	TTable(const TTable& tmp)
	{
		size = tmp.size;
		count = tmp.count;

		mem = new TRecord[size];

		for (int i = 0; i < size; i++)
		{
			mem[i] = tmp.mem[i];
		}
	}

	~TTable()
	{
		if (size != 0)
		{
			delete[] mem;
		}
	}

	TTable& operator=(const TTable& tmp)
	{
		if (size != tmp.size)
		{
			if (size != 0)
			{
				delete[] mem;
			}
			size = tmp.size;
			mem = new TRecord[size];
		}
		count = tmp.count;
		for (int i = 0; i < size; i++)
		{
			mem[i] = tmp.mem[i];
		}
		return *this;
	}

	void Add(TRecord tmp)
	{
		int pos = getNumber(tmp.getName());

		if (pos == -1)
		{
			if (count == size) throw 1;
			mem[count++] = tmp;
		}
		else
		{
			mem[pos] = tmp;
		}
	}

	void Del(const string& name)
	{
		int pos = getNumber(name);
		if (pos == -1) throw 1;
		mem[pos] = mem[--count];
	}

	int Search(const string& name)
	{
		int pos = getNumber(name);
		if (pos == -1) throw - 1;
		return mem[pos].getValue();
	}

	int getNumber(const string& name)
	{
		int pos = -1;
		int i = 0;
		while ((i < count) && (pos == -1))
		{
			if (name == mem[i].getName())
			{
				pos = i;
			}
			++i;
		}
		if (name == "") return -2;
		return pos;
	}

	TRecord& operator[](const int k) {
		if (k < 0 || k >= size) throw 1;
		return mem[k];
	}

	int getCount() {
		return count;
	}
	int getSize() {
		return size;
	}
	TRecord getRecord(int k)
	{
		return mem[k];
	}
	void setRecordValue(int k, int _value)
	{
		mem[k].setValue(_value);
	}

	bool isEmpty() {
		return count == 0;
	}

	bool isFull() {
		return count == size;
	}
};

