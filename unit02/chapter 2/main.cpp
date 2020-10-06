/* 
    @调用
 */
#include <iostream>
using namespace std;
#include "circle.h"
#include "Circle.cpp"

int main() {
    Circle circle1; //创建一个对象
    Circle circle2 {5.0};  //创建一个带参数的对象
    
    cout << "The area of the circle of radius " << " is " << circle1.getArea() << endl;
    cout << "The area of the circle of radius " << " is " << circle2.getArea() << endl;
    
    cin.get();
    return 0;
}
