#include <iostream>

using namespace std;

void swap(int x, int y);


int main()
{
    int a = 1, b = 2;

    cout << "Before Value: " << "a = " << a << "b = " << b << endl; 
    swap(a, b);
    cout << "After Value: " << " a = " << a << "b = " << b << endl;
    return 0;
}

void swap(int& x, int& y)
{
    int temp;
    temp = x;
    x = y;
    y = x;    
}