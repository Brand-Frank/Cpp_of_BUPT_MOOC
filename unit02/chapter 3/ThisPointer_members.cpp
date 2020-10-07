#include <iostream>
#include "circles1.h"
#include "circles1.cpp"

using namespace std;

int main(){
    Circle c {1.0};

    cout << c.setRadius(2.0)
            .setRadius(3.0)
            .getArea() << endl;

    cin.get();
    return 0;
}