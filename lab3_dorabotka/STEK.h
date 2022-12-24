#pragma once
#include <iostream>

using namespace std;

template <class T>
class TStack
{
private:
	T* mem;
	int size;
	int count;

public:
	TStack<T>(int _size = 0)
	{
		size = _size;
		count = 0;
		mem = new T[size];

		for (int i = 0; i < size; i++)
		{
			mem[i] = T(0);
		}
	}

	TStack(const TStack<T>& tmp)
	{
		size = tmp.size;
		count = tmp.count;
		mem = new T[size];

		for (int i = 0; i < size; i++)
		{
			mem[i] = tmp.mem[i];
		}
	}

	~TStack() {
		delete[]mem;
	}

	TStack<T>& operator=(const TStack<T>& tmp)
	{
		if (size != tmp.size)
		{
			if (size)
			{
				delete[]mem;
			}
			size = tmp.size;
			mem = new T[size];
		}
		count = tmp.count;
		for (int i = 0; i < size; i++)
		{
			mem[i] = tmp.mem[i];
		}
		return *this;
	}

	void Push(const T tmp)
	{
		if (count < size)
		{
			mem[count++] = tmp;
		}
		else throw - 1;
	}

	T Pop()
	{
		if (count > 0)
		{
			return mem[--count];
		}
		else throw - 1;
	}

	T Top()
	{
		if (!isEmpty())
		{
			return mem[count - 1];
		}
		else throw - 1;
	}

	int isEmpty()
	{
		if (count == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	int isFull()
	{
		if (count < (size - 1))
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}

	void getData()
	{
		for (int i = 0; i < count; i++)
		{
			cout << mem[i].getName();
		}
	}

	void showData()
	{
		for (int i = 0; i < count; i++)
		{
			cout << mem[i];
		}
	}

	int getCount()
	{
		return count;
	}

};