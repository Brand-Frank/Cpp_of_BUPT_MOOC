#include <iostream>

#include "Date.h"
#include "employee.h"

//任务4：创建Employ类，并修改其生日
int main(){
    Employee e;
    //1：setter
    e.setBirthday(Date(1999, 1, 1));
    std::cout << e.toString() << std::endl;

    //2：getter
    e.getBirthday() ->setYear(1998);
    std::cout << e.toString() << std::endl;

    std::cin.get();
    return 0;
}

