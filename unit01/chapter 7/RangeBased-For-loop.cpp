#include <iostream>
using namespace std;

int main()
{
    int a[] = { 2,1,4,3,5 };
    
    // 把存放a[]中的每个元素拷贝到 i 中，依次遍历
    for (auto i : a) {
        std::cout << i << std::endl;
    }
    // i 为数组里每个元素的别名（引用）
    for (auto& i : a) {
        i = 2 * i;
    }

    for(int i = 0; i < 5; i++)
    {
        cout << a[i] << "  ";
    }

    cin.get();
    return 0;
}