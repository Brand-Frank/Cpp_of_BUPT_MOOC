#include <iostream>
#include <string>
using namespace std;

/* 模板类型 */
template <typename T>
auto max(T x, T y)
{
    return x > y ? x : y;
}

/* auto max(int x, int y)
{
    return x > y ? x : y;   //Overloading Function()
} */

/* auto max(int a, int b, int c)
{
    return max(a, max(b,c));    //Overloading Function()
} */

/* auto max(double x, double y)
{
    return x > y ? x : y;   //Default Argument
} */
template <typename T>
auto max(T a, T b, T c )
{
    return max(a, max(b, c));    //Default Argument
}


int i = 20;
int main()
{
    //Variable Scope
    //int i{100};
    // for(int i = 1; i < 5; i++)
    // {
    //     cout << "i = " << i << " " << endl;
    //     //C++11 std::to_string();
    //     cout << std::to_string(i) + "  到此一游";
    //     cout << endl << "全局空间::i = " << ::i << endl;
    // }

    //Overloading Function()
    cout << max(1,2,3) << endl;
    cout << max('a', 'b', 'c') << endl;
    //Default Argument


    cin.get();
    return 0;
}