#pragma once
#include "Poliz.h"
#include "STEK.h"

using namespace std;

class TArithmetic
{
private:
    string STR;
    TPoliz poliz;

public:
    TArithmetic(string _STR = "")
    {
        STR = _STR;
        poliz = TPoliz(STR);
    }

    TArithmetic(const TArithmetic& tmp)
    {
        STR = tmp.STR;
        poliz = tmp.poliz;
    }

    TArithmetic& operator=(TArithmetic tmp)
    {
        STR = tmp.STR;
        poliz = tmp.poliz;
        return *this;
    }

    ~TArithmetic() {}

    TPoliz getPoliz()
    {
        return poliz;
    }

    void setTableOperandValue()
    {
        for (int i = 0; i < (poliz.getTableOperand()->getCount()); i++)
        {
            if ((poliz.getTableOperand()->getRecord(i).getName() >= "0") && (poliz.getTableOperand()->getRecord(i).getName() <= "9"))
            {
                continue;
            }
            else
            {
                string nameOperand;
                int valueOperand;

                nameOperand = poliz.getTableOperand()->getRecord(i).getName();
                cout << nameOperand << " = ";
                cin >> valueOperand;
                poliz.getTableOperand()->setRecordValue(i, valueOperand);
            }
        }
    }

    int calculate()
    {
        setTableOperandValue();
        TStack<double> stack(20);
        double right;
        double left;
        for (int i = 0; i < poliz.getCount(); i++)
        {
            double l = poliz.getTableOperand()->getNumber(poliz[i]);

            if (l == -2) continue;

            if (l != -1)
            {
                double value = poliz.getTableOperand()->Search(poliz[i]);
                stack.Push(value);
            }
            else
            {
                right = stack.Pop();
                left = stack.Pop();
                if (poliz[i] == "+")
                {
                    stack.Push(left + right);
                }
                if (poliz[i] == "-")
                {
                    stack.Push(left - right);
                }
                if (poliz[i] == "*")
                {
                    stack.Push(left * right);
                }
                if (poliz[i] == "/")
                {
                    stack.Push(left / right);
                }
                if (poliz[i] == "^")
                {
                    stack.Push(pow(left, right));
                }
            }
        }
        return stack.Pop();
    }
};

