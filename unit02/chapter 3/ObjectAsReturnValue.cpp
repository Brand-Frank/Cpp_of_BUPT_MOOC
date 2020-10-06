#include <iostream>
#include "circles.h"
#include "circles.cpp"

using namespace std;



int main()  {
    Circle c {1.0};

    cout << c.setRadius(2.0).getArea() << endl;

    cin.get();
    return 0;
}