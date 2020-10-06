#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main()
{
    //常量声明
    const int x = 42;

    //常量不可变
    // x = 21;  //error
    int y = 2;
    // int* p = &x; //&x为常量const，不可以用*p解引用
    const int* p = &x;
    cout << "*p = " << *p << endl;

    // (*p) = 24;
    const int* q = &y;
    // (*q) = 4;    //q指向的地址不可以改变，但是地址上的内容(y的值)可以改变
    cout << "*q = " << *q << endl;
    y = 10;
    cout << "*q = " << *q << endl;


    //常量指针所指向数据不可变

    //指针常量不可变
    int* const r = &y;
    int z = 5;
    // r = &z;  //r指向的地址不可变
    *r = 20;    //可以解引用
    cout << *r << "  " << y << endl;

    //常指针常量
    const int* const s = &y;
    // s = &z;

    const char* str = "Hello";
    // *str = 'P';
    cout << "str = " << str << endl;

    auto p1 = &y;
    auto p2 = "World";
    auto const p3 = "!";

    cin.get();
    return 0;
}