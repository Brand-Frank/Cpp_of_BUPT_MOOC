/*
 * @Author: codebug 
 * @Date: 2020-10-05 15:18:10 
 * @Last Modified by: mikey.zhaopeng
 * @Last Modified time: 2020-10-05 22:01:06
 */
#include <iostream>
#include <typeinfo>
using namespace std;

auto max(int x, int y)
{
    return x > y ? x : y;
}

int main()  {
    //auto变量必须在定义时初始化
    auto x =3;
    auto y{42};
    auto z{' '};
    cout << typeid(y).name() << endl;
    cout << typeid(z).name() << endl;

    //定义在一个auto序列的变量必须始终推导成同一类型
    auto a{1},b{3};
    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;
    
    //如果初始化表达式是引用或const,则去除引用或const语义
    int A{42}, &B{A};
    auto C{B};  //去除引用
    cout << typeid(B).name() << endl;

    const int D = A;
    auto E{D};  //去除const语义
    cout << typeid(D).name() << endl;

    //如果auto关键字带上&号，则不去除引用或const语意
    int x1{42}, &y1{x1};
    auto z1{y1};  //仍然是引用
    cout << typeid(z1).name() << endl;

    //初始化表达式为数组时，auto关键字推导类型为指针
    int p[3]{1,2,3};
    auto q{p};
    cout << typeid(q).name() << endl;
    
    //若表达式为数组且auto带上&,则推导类型为数组类型
    auto& p2{p};    
    cout << typeid(p2).name() << endl;

    
    //C++14中，auto可以作为函数的返回值类型和参数类型
    cout << max(x,y) << endl;

    cin.get();
    return 0;
}