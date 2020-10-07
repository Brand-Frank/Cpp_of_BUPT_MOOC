/* from:https://www.icourse163.org/learn/BUPT-1003564002?tid=1450339466#/learn/content?type=detail&id=1214630919&cid=1218578936 */

#include <iostream>
using namespace std;

/* 有参默认构造函数 */
class Circle{
private:
    double radius;

public:
    Circle(){}  //手工添加默认构造函数
    //Circle() = default;

    Circle(double r){
        radius = r;
    }

    double getArea(){
        return radius * radius *3.14;
    }
};

/* 无默认构造函数 */
class Square{
private:
    double side;

public:
    Square() = delete;  //指示编译器不准生成默认构造函数
    Square(double side): side {side} {}
    /*或 
    Square(double side)
    { this->side = side; }    
     */
    double getArea(){
        return side*side;
    }

};


class Combo{
    public:
        Circle c;
        Square s;
    Combo():s{1.0}{};
    /*不可以 
    Combo() {
        s{1.0};
    }
     */
    /* 可行
    Combo() : s{1.0}    {
        s = {8.0}   //可以在此处赋值（只能拷贝赋值）
    }
    
     */
};


int main(){
    Combo o{};
    cout << o.c.getArea() << endl;
    cin.get();
    return 0;
}