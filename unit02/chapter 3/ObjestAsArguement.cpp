#include <iostream>
#include "circle.h"
#include "circle.cpp"

using namespace std;

/* 对象作为参数传递 */
/* void print(Circle c)    {
    std::cout << c.getArea() <<endl;
} */

/* 引用方式作为参数 */
void print(Circle& c)   {
    cout << c.getArea() << endl;
}

/* 指针对象作为参数 */
void print(Circle* c)   {
    cout << c->getArea() << endl;
}

int main()  {
    Circle a[] = {1.0, 2.0, 3.0};
    print(a[1]); 
    print(a[2]);
    print(a+2);

    cin.get();
    return 0;
}