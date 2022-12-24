#pragma once
#include <iostream>
#include "TTable.h"
#include "STEK.h"

using namespace std;

class TPoliz
{
private:
	string* mem;
	int size;
	int count;
	TStack<TRecord>OPstack;
	TTable* tableOperations;
	TTable* tableOperand;

	void MadeTableOperations()
	{
		tableOperations = new TTable(6);
		tableOperations->Add(TRecord("+", 1));
		tableOperations->Add(TRecord("-", 1));
		tableOperations->Add(TRecord("*", 2));
		tableOperations->Add(TRecord("/", 2));
		tableOperations->Add(TRecord("^", 3));
	}
	void WorkLeft()
	{
		if (OPstack.isFull() == 0)
		{
			OPstack.Push(TRecord("(", 0));
		}
	}
	void WorkRight()
	{
		while (OPstack.Top().getName() != "(")
		{
			mem[count++] = OPstack.Pop().getName();
		}
		OPstack.Pop();
	}
	void WorkOperation(TRecord tmp)
	{
		while ((OPstack.isEmpty() != 1) && (OPstack.Top().getValue() >= tmp.getValue()))
		{
			mem[count++] = OPstack.Pop().getName();
		}
		OPstack.Push(tmp);
	}
	void WorkOperand(const string& tmp)
	{
		if (tmp[0] >= '0' && tmp[0] <= '9')
		{
			tableOperand->Add(TRecord(tmp, atof(tmp.c_str())));
		}
		else
		{
			tableOperand->Add(TRecord(tmp));
		}
		mem[count++] = tmp;
	}
	void WorkEnd()
	{
		while (OPstack.isEmpty() != 1)
		{
			mem[count++] = OPstack.Pop().getName();
		}
	}

	void MadePoliz(string& tmp)
	{
		string* lex;
		lex = new string[tmp.size() + 2];
		int k = 0;
		StringToWords(lex, tmp, "+-*/^)( ", k);
		count = 0;
		for (int i = 0; i <= k; i++)
		{
			if (lex[i] == "(") {
				WorkLeft();
			}
			else if (lex[i] == ")")
			{
				WorkRight();
			}
			else {
				int l = tableOperations->getNumber(lex[i]);
				if (l != -1)
				{
					WorkOperation(TRecord(lex[i], tableOperations->Search(lex[i])));
				}
				else
				{
					WorkOperand(lex[i]);
				}
			}
		}
		WorkEnd();
	}

	void StringToWords(string* lex, string mem, string str, int& lexCount)
	{
		int L;

		for (int i = 0; i < int(mem.size()); i++)
		{
			L = str.find(mem[i]);

			if ((L <= 0) && (L >= str.size()))
			{
				lex[lexCount] += mem[i];
			}
			else
			{
				if (lex[i] != " ")
				{
					if (lex[lexCount] != "")
					{
						lex[++lexCount] = mem[i];
					}
					else
					{
						lex[lexCount] = mem[i];
					}
					lex[++lexCount] = "";
				}
			}
		}
	}


public:
	TPoliz(string _mem = " ")
	{
		size = int(_mem.size() + 1);
		mem = new std::string[size];
		count = 0;
		MadeTableOperations();
		tableOperand = new TTable(size);
		OPstack = TStack<TRecord>(size);
		MadePoliz(_mem);
	}
	TPoliz(const TPoliz& tmp)
	{
		size = tmp.size;
		mem = new string[size];
		count = tmp.count;
		MadeTableOperations();
		tableOperand = new TTable(size);
		(*tableOperand) = (*(tmp.tableOperand));
		OPstack = TStack<TRecord>(size);
		for (int i = 0; i < count; i++)
		{
			mem[i] = tmp.mem[i];
		}
	}
	~TPoliz() {
		delete[] mem;
		delete tableOperations;
		delete tableOperand;
	}

	TPoliz& operator=(const TPoliz& tmp)
	{
		if (size != tmp.size)
		{
			if (size != 0)
			{
				delete[] mem;
			}
			size = tmp.size;
			mem = new string[size];
		}
		count = tmp.count;
		for (int i = 0; i < count; i++)
		{
			mem[i] = tmp.mem[i];
		}
		MadeTableOperations();
		delete tableOperand;
		tableOperand = new TTable(size);
		(*tableOperand) = (*(tmp.tableOperand));
		OPstack = TStack<TRecord>(size);

		return *this;
	}
	string operator[](const int k)
	{
		if (k >= 0 && k < count) return mem[k];
		else return "";
	}


	string getPoliz()
	{
		std::string res = "";
		for (int i = 0; i < count; i++)
		{
			if (mem[i] == "") continue;
			res += mem[i] + " ";
		}
		return res;
	}

	int getCount()
	{
		return count;
	}

	TTable* getTableOperand()
	{
		return tableOperand;
	}
};

