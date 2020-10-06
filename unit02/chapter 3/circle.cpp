#include <iostream>
using namespace std;
#include "circle.h"

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