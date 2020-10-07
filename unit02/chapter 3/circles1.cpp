#include <iostream>
using namespace std;
#include "circles1.h"

/* 函数实现-定义 */
Circle::Circle(){
    radius = 1.0;
}

Circle::Circle(double radius_){
    radius = radius_;
}

double Circle::getArea(){
    return (radius * radius * 3.14);
}

double Circle::getRadius() const    //常函数，不改变当前对象的状态，
{
    return radius;
}

Circle& Circle::setRadius(double radius) //返回Circle类
{
    this -> radius = radius;
    // return (Circle{radius});
    return (*this);
}