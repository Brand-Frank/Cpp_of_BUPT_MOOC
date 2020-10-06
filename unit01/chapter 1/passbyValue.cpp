#include <stdio.h>
#include <iostream>

using namespace std;

//g++ reference.cpp -o reference -std=c++11

/* 通过值传参 */

void swap (int x,int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main()
{
    int a = 5, b = {10};        //C++11特性
    std::cout << "Before: a = " << a << " b = " << b << endl;
    swap(a, b);     //a和b的值传给swap函数，但是函数里的地址和a,b不同，在x,y所在的地址内容会发生改变
    std::cout << "After: a = " << a << " b = " << b << endl;

    return 0;
}