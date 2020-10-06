#include <iostream>
using namespace std;
void print(int n)
{
    int* p = &n;//
    cout << "*p = " << *p << endl;//这里的结果显然会输出：1024；
    //此时我们使用：reinterpret_cast；
    double* pp = reinterpret_cast<double*>(&n);
    cout << "*pp = " << pp << endl;//这里输出的结果将是double类型的值；但是地址指针的地址并未发生改变，仅仅是解释的方法发生了改变
}

int main()  {
    //const_cast用于去除指针变量的常量属性。
    int b = 4;
    const int* a = &b;
    cout << "a = " << a << endl;
    // int* p = a;//此时是报错的，报错原因是："const int *" 类型的值不能用于初始化 "int *" 类型
    //因此为了解决这个问题：const_cast便派上用场
    //我们这里可以这样
    int* pr = const_cast<int*>(a);//此时便能获取成功，也就是所说的：去除指针变量的常量属性
    cout << "*pr = " << *pr << endl;   
    //reinterpret_cast，翻译下来就是重新解释转型（主要是指针）
    //reinterpret_cast的作用是，不改变指针地址，仅仅是使编译器改变解释属性
    //举个例子：
    int n = 1024;
    print(n);
    
    return 0;
}