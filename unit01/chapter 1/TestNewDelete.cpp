#include <iostream>

int main(){
    /* 定义空指针并分配内存 */
    int* p = nullptr;
    int* q{nullptr};

    p = new int{42};
    q = new int[4];

    std::cout << "Before: *p = " << *p << std::endl;    //要用*号解引用
    *p = 24;        //重新赋值
    std::cout << "After: *p = " << *p << std::endl;

    for(int i = 0; i < 4; i++)
    {
        *(q + 1) = 10 + i;
        //
        std::cout << *(q + 1) << std::endl;
    }

    //因为上边只分配了5*4=20个字节的空间，可以不用delete内存空间
    delete p;
    delete[] q;

    std::cin.get();
    return 0;
}