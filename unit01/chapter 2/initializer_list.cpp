#include <iostream>
void print(std::initializer_list<int> list) {                    
    for (auto it = list.begin(); it != list.end(); it++) {
        std::cout << *it << " "; 
    }
    std::cout << std::endl;
}
  
int main() {
    print({ 1, 2, });
}