#include <iostream>

class School{
    private:
        char* teacher;
        char* student;
        School* ptr;
    public:
        void initialize(void);
        void output(School* ptr);
};

School Yali;

void School::initialize(void){
    Yali.ptr = &Yali;
    Yali.ptr->teacher = "John Ming";
    (*Yali.ptr).student = "Marry Jasmibe";
    Yali.output(Yali.ptr);
}

void School::output(School* ptr){
    std::cout << "teacher is " << ptr->teacher << std::endl;
    std::cout << "student is " << ptr->student << std::endl;
}

int main(){
    Yali.initialize();
    std::cin.get();
    return 0;
}