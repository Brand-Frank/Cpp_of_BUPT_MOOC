#include <iostream>
#include "circle.h"
#include "circle.cpp"

using namespace std;

int main(){
    auto* c1 = new Circle{1.0};   //创建匿名对象，并赋值给c1对象指针
    Circle c3 {2.0};
    auto c2 = &c3;

    cout << (*c1).getArea() << endl;
    cout << c2->getArea() << endl;
    cout << c3.getArea() << endl;

    auto c4 = new Circle[3] {2.0, 3.0, 4.0};
    for(int i =0; i < 3; i++)
    {
        cout << c4[i].getArea() << endl;
    }
    /* for(auto x : c4)
    {
        cout << x.getArea() << endl;
    } */

    delete c1;
    delete[] c4;
    c1 = c4 = nullptr;

    delete c1;  //可以删除空指针

    cin.get();
    return 0;
}