#include <iostream>
#include <array>
using namespace std;
using std::array;
void print(array<int,3>& a)
{
    for(auto x : a){
        cout << x << " " << endl;
    }
}
int search(array<int, 3>&a, int token) {
    bool exist = false;
    int i = 0;
    for(auto x : a){
        if(x == token)
        {
            exist = true;
            break;
        }
        i++;
    }
    if(exist){
        return i;
    }
    else
    {
        return -1;
    }
}



int main()  {
    //创建数组
    std::array a1 {1, 2, 4};    //  array<int, 3>
    print(a1);
    //为数组赋值
    std::array a2 = {7, 6, 9};
    print(a2);

    //交换数组
    array b1 {100, 200, 300};
    print (b1);
    a1.swap(b1);
    print (a1);
    print (b1);

    //求数组大小
    int a = a1.size();
    cout << a;

    //编写search函数，在数组中查找一个值
    cout << "search 100 :" << search(a1,100) << endl;
    cout << "search 1   :" << search(a1,1) << endl;
    
    //sort
    // std::sort(a1.rbegin(), a1.rend());
    // print (a1);

    //二维数组
    // std::array<std::array<int, 3>, 4> &q;

    return 0;
}