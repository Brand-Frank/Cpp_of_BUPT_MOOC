#include<iostream>
using namespace std;
int  fun1()  { return 10;  }
auto fun2()  { return 'g'; }  // C++14
int main(){
    // Data type of x is same as return type of fun1()
    // and type of y is same as return type of fun2()
    decltype(fun1()) x;  // 不会执行fun1()函数
    decltype(fun2()) y = fun2();
    cout << typeid(x).name() << endl;
    cout << typeid(y).name() << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    return 0;
}