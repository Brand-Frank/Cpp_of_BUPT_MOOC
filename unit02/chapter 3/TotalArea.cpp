#include <iostream>
#include "circle.h"
#include "circle.cpp"
using namespace std;

int main()
{   
    Circle c1[] = {Circle{1.0}, Circle{2.0}, Circle{3.0}};
    Circle c2[] = {11.0, 12.0, 13.0};
    c1[2].setRadius(2.0);
    c2[1].setRadius(100.0);

    for(int i; i < static_cast<int>((sizeof(c1) / sizeof(c1[0]))); i++)
    {
        cout << c1[i].getArea() << endl;
    }

    for(auto x : c2)
    {
        cout << x.getArea() << endl;
    }
    return 0;
}