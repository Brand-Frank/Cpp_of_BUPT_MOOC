#include <iostream>

#include "date.h"
#include "employee.h"

//����4������Employ�࣬���޸�������
int main() {
	Employee e;
	//1��setter
	e.setBirthday(Date(1999, 1, 1));
	std::cout << e.toString() << std::endl;

	//2��getter
	e.getBirthday()->setYear(1998);
	std::cout << e.toString() << std::endl;

	std::cin.get();
	return 0;
}