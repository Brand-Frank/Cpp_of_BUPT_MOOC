#include <iostream>
using namespace std;

/* 有参默认构造函数 */
class Circle{
private:
    double radius;

public:
    double getArea(){
        return radius * radius *3.14;
    }
};

/* 无默认构造函数 */
class Square{
private:
    double side;

public:
    double getArea(){
        return side*side;
    }

};


class Combo{
    public:
        Circle c;
        Square s;

};


int main(){
    Combo o{};
    cout << o.c.getArea() << endl;
    cin.get();
    return 0;
}