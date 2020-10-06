#include <iostream>
#include "circle.h"
#include "circle.cpp"

using namespace std;

int main(){
    Circle* c1 = new Circle{2.0};   //创建匿名对象，并赋值给c1对象指针
    Circle c3 {2.0};
    Circle* c2 = &c3;

    cout << c1->getArea() << endl;
    cout << c2->getArea() << endl;
    cout << c3.getArea() << endl;
    cin.get();
    return 0;
}