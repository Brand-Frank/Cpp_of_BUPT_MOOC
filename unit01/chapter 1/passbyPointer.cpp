#include <stdio.h>
#include <iostream>

using namespace std;

//g++ reference.cpp -o reference -std=c++11

/* 通过指针传参 */

void swap (int* x,int* y)   //x,y里面的是地址，加了*后用于解引用指针，得出地址上的值。swap函数操作主函数里的变量。
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int a = 5, b = {10};        //C++11特性
    std::cout << "Before: a = " << a << " b = " << b << endl;
    swap(&a, &b);   //传递a和b的地址
    std::cout << "After: a = " << a << " b = " << b << endl;

    return 0;
}