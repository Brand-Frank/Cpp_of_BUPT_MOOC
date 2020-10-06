#include <iostream>
using namespace std;

int main() {
    int b{0};
    if(3.2 > b) //会自动转换类型
    {
        cout << "3.2 > b is True!" << endl;
    }
    return 0;
}