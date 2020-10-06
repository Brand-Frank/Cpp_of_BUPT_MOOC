#include <iostream>
using namespace std;
/*  声明一个类     */
class Circle {
    public:
        // The radius of this circle
        double radius;
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
};
  
int main() {
    Circle circle1; //创建一个对象
    Circle circle2(5.0);  //创建一个带参数的对象
    
    cout << "The area of the circle of radius " <<
            circle1.radius << " is " << circle1.getArea() << endl;
    cout << "The area of the circle of radius " <<
            circle2.radius << " is " << circle2.getArea() << endl;
    
    // Modify circle radius
    circle2.radius = 100.0;
    cout << "The area of the circle of radius " <<
            circle2.radius << " is " << circle2.getArea() << endl;
    
    cin.get();
    return 0;
}