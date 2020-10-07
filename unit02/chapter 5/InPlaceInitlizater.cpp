#include <iostream>

class X{
    /* 基础数据类型初始化 */
    int a = 1;  //拷贝初始化
    int b {2};      //列表初始化
    int c {3};

    /* 对象类型成员就地初始化 */
    std::string s {'H','e','l','l','o'};
    std::string s1 {"hello"};       //列表初始化
    std::string s2 = "Hello";   //拷贝初始化

    /* 数据类型成员初始化 */
    int arr1 [3] = {1,2,3};
    int arr2[4] {1};
    // int arr3[] {12.0, 30.2};    //需要初始化数组元素个数/double
    // auto arr4[] {1,2};  //auto类型不能出现在顶级数组类型中
}; 


int main(){

    std::cin.get();
    return 0;
}