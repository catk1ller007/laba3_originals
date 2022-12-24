#include <iostream>
#include "Poliz.h"
#include "Arifmetics.h"


int main()
{
    /*TPoliz poliz("a-b*c/d*k^(x+y*d^2)+17*a/b");


    cout << "a-b*c/d*k^(x+y*d^2)+17*a/b" << endl;
    cout << poliz.getPoliz() << endl;

    cout << "------------------------------" << endl;

    TPoliz Testik(poliz);
    cout << "Testik: " << Testik.getPoliz() << endl;

    cout << "--------------------------------" << endl;

    TPoliz poliz2("f*s+f*a");
    cout << "poliz2: " << poliz2.getPoliz() << endl;
    
    cout << "--------------------------------" << endl;

    poliz2 = poliz;
    cout << "poliz2: " << poliz2.getPoliz() << endl;

    cout << "---------------------------------" << endl;*/
    
    cout << "a-b*c/d*k^(x+y*d^2)+17*a/b"<<endl;
    TArithmetic viragenie("a-b*c/d*k^(x+y*d^2)+17*a/b");

    cout << viragenie.getPoliz().getPoliz() << endl;
    cout << viragenie.calculate() << endl;
}

