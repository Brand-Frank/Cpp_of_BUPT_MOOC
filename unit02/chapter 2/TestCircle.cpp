/* TODO: copy from CtorsFun.cpp */

#include <iostream>
using namespace std;
/*  声明一个类     */
class Circle {
    private:
        // The radius of this circle
        double radius;

    public:
        Circle();   /* 函数声明 */
        Circle(double newRadius);
        double getArea();
};

/* 函数实现 */
Circle::Circle(){
    radius = 1.0;
}

Circle::Circle(double radius_){
    radius = radius_;
}

double Circle::getArea(){
    return (radius * radius * 3.14);
}

int main() {
    Circle circle1; //创建一个对象
    Circle circle2 {5.0};  //创建一个带参数的对象
    
    cout << "The area of the circle of radius " << " is " << circle1.getArea() << endl;
    cout << "The area of the circle of radius " << " is " << circle2.getArea() << endl;
    
    cin.get();
    return 0;
}

/* 
        // Construct a circle object
        Circle() {
            radius = 1;
        }
        // Construct a circle object
        Circle(double newRadius) {
            radius = newRadius;
        }
        // Return the area of this circle
        double getArea() {
            return radius * radius * 3.14159;
        }
 */