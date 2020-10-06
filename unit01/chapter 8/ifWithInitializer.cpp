/* 
Description:带有初始化器的if/switch语句
电脑随机生成一个 0-100 之间的数字，用户输入一个整数，由电脑判断用户输入的整数大小，提示用户“猜大了/小了/中了”
 */

#include <iostream>
using namespace std;

int main()
{
    cout << "正在生产从0-100之间的数字" << endl;
    cout << "请输入你猜测的整数：" ;
    auto x{0};
    cin >> x;
    // while(1)
    // {
        if (int z = rand() % 100; z < x)
        {
            cout << "你猜大了，我的数是：" << z << endl;
            // continue;
        }
        else if(z > x)
        {
            cout << "你猜小了，我的数是：" << z << endl;
            // continue;    
        }
        else
        {
            cout << "你猜对了" << endl;
            // break;
        }
    // }
    

    cin.get();
    return 0;
}