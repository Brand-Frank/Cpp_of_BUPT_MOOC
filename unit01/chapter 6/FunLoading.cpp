#include <iostream>
using namespace std;

void printArea(double radius = 1);

int main()
{
    printArea();
    printArea(4);
    return 0;
}

void printArea(double radius = 2)
{
    cout << "Hello World!" << endl;
}
/*1.将“=1” 改为“=2” ×
 *2.将“=1”删除 ×
 *3.将整行删除 ×
 *4.将“=2” 改为“=1” ×
 *5.将“=2”删除  √
 */