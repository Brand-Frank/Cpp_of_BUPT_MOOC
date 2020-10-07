#include <iostream>
using namespace std;

int main(){
    /* 创建字符串 */
    string s = "Hello";
    // string s{"hello"};

    /* clear */
    s.clear();

    /* 用数组为字符串赋值 */
    char arr[] {'w','o','r','l','d'};
    s += arr;
    cout << "s = " << s << endl;

    /* assign() */
    s.assign("1024");
    cout << "s = " << s << endl;

    /* append */
    s.append("  ");
    cout << "s = " << s << endl;

    s.append(5,' ');
    cout << "s = " << s << endl;

    s.append("!");
    cout << "s = " << s << endl;

    /* inset 空白 */
    s.insert(0, "   ");
    cout << "s = " << s << endl;

    /* 移动字符串前面的空白 */
    s.erase(0, s.find_first_not_of(" \t\r\n")); //空白/制表符/ /换行符
    cout << "s = " << s << endl;

    /* 移动字符串后面的空白 */
    s.erase(s.find_last_not_of(" \t\r\n")+1);
    cout << "s = " << s << endl;

    /* 把字符串转化为整数或浮点数 */
    s += '$';
    cout << "s = " << s << endl;

    int x = stoi(s);
    cout << "s = " << s << endl;
    cout << "x = " << x << endl;

    string s1 = to_string(x);
    cout << "s1 = " << s1 << endl;

    std::cout << s << std::endl;
    std::cin.get();
    return 0;
}