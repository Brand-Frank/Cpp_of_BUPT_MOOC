#include <iostream>
int main() {
    bool isAlpha;
    isAlpha = false;    
    if (!isAlpha) {
       std::cout << "isAlpha=" << isAlpha << std::endl;
       std::cout << std::boolalpha <<       //输出字母false
              "isAlpha=" << isAlpha << std::endl;       //输出数字 0 
    }
    return 0;
}