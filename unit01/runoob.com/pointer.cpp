/* 
auto  a1[] { 1, 3, 5, 7 };  //有问题，应该为int a[] = {1,3,5,7};
std::array<int, 4> a2 { 2, 4, 6, 8};  //广义集合：int：数据类型 / 4：元素个数 / a2：集合名
std::vector< int > v = { 42, 7, 5 };  //可变数组
std::vector< std::string > s { "Hello", "World", "!"};  //存储字符串的可变数组
 */

#include <iostream>
 
using namespace std;
const int MAX = 3;
 
int main ()
{
   int  var[MAX] = {10, 100, 200};
//    std::array<int,4> a2 {2,4,6,8};
   int  *ptr;
 
   // 指针中的数组地址
   ptr = var;
   for (int i = 0; i < MAX; i++)
   {
      cout << "Address of var[" << i << "] = ";
      cout << ptr << endl;
 
      cout << "Value of var[" << i << "] = ";
      cout << *ptr << endl;
 
      // 移动到下一个位置
      ptr++;
   }
   return 0;
}