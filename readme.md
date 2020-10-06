```
/*
 * @Author: codebug
 * @Date: 2020-10-05 16:40:03 
 * @Last Modified by: mikey.zhaopeng
 * @Last Modified time: 2020-10-05 21:30:59
 */
 ```
# C++学习笔记

<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [C++学习笔记](#c学习笔记)
  - [unit01：C语法的增强及对应的C++11特性](#unit01c语法的增强及对应的c11特性)
    - [chapter 1:引用、[C++11]空指针与动态内存分配](#chapter-1引用-c11空指针与动态内存分配)
      - [reference - 引用](#reference-引用)
        - [例子](#例子)
      - [nullptr and Dynamic Memory Allocation (空指针和动态内存分配)](#nullptr-and-dynamic-memory-allocation-空指针和动态内存分配)
        - [Dynamic memory management: Allocate/Release](#dynamic-memory-management-allocaterelease)
        - [new/delete 与 malloc/free 的区别](#newdelete-与-mallocfree-的区别)
    - [chapter 2:数据类型与转换、[C++11]列表初始化](#chapter-2数据类型与转换-c11列表初始化)
      - [布尔数据类型(Boolean data type)](#布尔数据类型boolean-data-type)
      - [List Initialization（列表初始化）](#list-initialization列表初始化)
      - [Type conversion (类型转换)](#type-conversion-类型转换)
    - [chapter 3:C++11的自动类型推导：类型系统、auto与decltype](#chapter-3c11的自动类型推导类型系统-auto与decltype)
      - [C++11 Enhancement for Type System (C++11 对类型系统的增强)](#c11-enhancement-for-type-system-c11-对类型系统的增强)
      - [Automatic Type Deduction: auto (C++11) 自动类型推导：auto关键字](#automatic-type-deduction-auto-c11-自动类型推导auto关键字)
      - [Almost Always Auto (AAA) （尽量使用auto）](#almost-always-auto-aaa-尽量使用auto)
      - [Automatic Type Deduction: decltype（自动类型推导：decltype关键字）](#automatic-type-deduction-decltype自动类型推导decltype关键字)
      - [小节导学:C++11的自动类型推导：类型系统、auto与decltype](#小节导学c11的自动类型推导类型系统-auto与decltype)
    - [chapter 4:简化的C++内存模型](#chapter-4简化的c内存模型)
      - [C++内存模型](#c内存模型)
      - [小结](#小结)
    - [chapter 4:简化的C++内存模型](#chapter-4简化的c内存模型-1)
      - [常量 （Constant）](#常量-constant)
    - [chapter 5:常量与指针](#chapter-5常量与指针)
      - [常量和指针（Constant and Pointer）](#常量和指针constant-and-pointer)
        - [思考](#思考)
      - [Usage of using, typedef, and #define （using, typedef, and #define的用法）](#usage-of-using-typedef-and-define-using-typedef-and-define的用法)
    - [chapter 6:特殊函数：重载、默认参数值与内联](#chapter-6特殊函数重载-默认参数值与内联)
      - [变量的作用域](#变量的作用域)
      - [Overloading Functions（重载函数）](#overloading-functions重载函数)
      - [带有默认参数值的函数](#带有默认参数值的函数)

<!-- /code_chunk_output -->





## unit01：C语法的增强及对应的C++11特性

### chapter 1:引用、[C++11]空指针与动态内存分配

#### reference - 引用

定义：A reference is an alias for another variable. (引用就是另一个变量的别名)
例子：

```cpp {.line-numbers}
int x;
int& rx = x;    //rx是x的别名
```

- 别名依附于变量

```cpp{.line-numbers}
int x, &x = rx;
```

- 通过引用所做的读写操作实际上是作用于原变量上
- 引用一旦初始化，引用名字就不能再指定给其它变量


##### 例子
- 通过值传参

```cpp{.line-numbers}
//pass by reference
void swap(int& x,  int& y){
  int  t;
  t=x;  x=y;  y=t;
}
int main() {
  auto a{5}, b{10};
  cout<< "Before: a=" << a << " b=" << b << endl;
  swap( a,  b );
  cout << "After: a=" << a << "b=" << b << endl;
  return 0;
}
```
结果：
```cpp {.line-numbers}
Before : a = 5 b = 10
After : a = 5 b = 10
```

- 通过指针传参

```cpp{line-numbers}
//pass by pointer
void swap(int* x,  int* y){
  int  t;
  t=*x;  *x=*y;  *y=t;
}
int main() {
  auto a{5}, b{10};
  cout<< "Before: a=" << a << " b=" << b << endl;
  swap( &a,  &b );
  cout<< "After: a=" << a << "b=" << b << endl;
  return 0;
}
```

#### nullptr and Dynamic Memory Allocation (空指针和动态内存分配)

- 空指针
- 0带来的二义性问题
> 1. C++03中，空指针使用 `0` 来表示。0既是一个**常量整数**，也是一个**常量空指针**（两种类型定义）。
> 2. C语言中，空指针使用 `(void *)0` 来表示
> 3. 有时候，用 `NULL` 来表示空指针(一种可能的实现方式是 `#define NULL 0`)
```cpp
void codeExample(){
  auto x{10}
  int* p nullptr;
  int* q{nullptr};
  q = &x;
}
```
- C++标准化委员会希望“空指针”是一个确定的东西。
> C++11中引入保留字 `nullptr` ”作为空指针

##### Dynamic memory management: Allocate/Release 
> 中译：(动态内存管理：分配/释放)
> C++中通过运算符new申请动态内存
```cpp
new <类型名> (初值) ;     //申请一个变量的空间,()可以为{}
new <类型名>[常量表达式] ;   //申请数组
```
- 如果申请成功，返回指定类型内存的地址；
- 如果申请失败，抛出异常，或者返回空指针 `nullptr`。(C++11)

> 动态内存使用完毕后，要用delete运算符来释放。
```cpp
delete   <指针名>;    //删除一个变量/对象
delete []  <指针名>;     //删除数组空间
```

##### new/delete 与 malloc/free 的区别
![img](E://Program//C++//Cpp_of_BUPT_MOOC//Image//C和C++动态内存分配区别.jpg)

1. `malloc` 与 `free` 是C++/C的标准库函数，`new` / `delete` 是C++的运算符，它们都可用于**申请动态内存**和**释放内存**。

2. 对于**非内部数据类型**的对象而言，只用 `malloc` / `free` 无法满足动态对象的要求。对象在创建的同时，要自动执行构造函数，对象在消亡之前要自动执行析构函数。而由于 `malloc` / `free` 是**库函数**而不是**运算符**，不在编译器控制权限之内，不能够把执行构造函数和析构函数的任务强加于 `malloc` / `free`

3. `malloc` 开辟空间的大小需自己计算，`new` 是编译器计算。

4. `malloc` 返回指针是 `void`，需要强制转换为对应类型的指针。`new` 直接返回对应类型指针。

5. `new` / `delete` 与 `malloc` / `free`申请内存位置说明，`malloc` 我们知道它是在堆上分配内存的，但 `new` 其实不能说是在堆上，C++中，对 `new` 申请内存位置有一个抽象概念，它为**自由存储区**，它可以在**堆**上，也可以在**静态存储区**上分配，这主要取决于 `operator new` 实现细节，取决与它在哪里为对象分配空间。

6. `new`/ `delete` 是c++中的保留字，*不需要头文件*，相反，`macoll` / `free` 在c语言中，需要头文件的支持

7. `new` / `delete` 可以执行构造函数，而 `macoll` 却不可以执行

8. `new` / `delete` 可以自动判断字节大小，`macoll` 必须自己指定大小；

9. `macoll` 的返回值是`void*`，因此在使用的时候必须进行强类型转换，比如说使用 `macoll` 申请一个 `int` 类型的空间就需要：`(int*)macoll(sizeodf(int))`,而在 `new` 中，则不需要这些东西；

10. 安全问题：`new` 是安全的，**会自己检测指针是否已经初始化**，而 `macoll` 不会进行这样的判断

11. 返回值问题：`macoll` 的返回值，如果申请成功 就会返回已经申请的内存地址，若申请失败，将会返回空指针：`NULL` 在 `new` 中，若申请失败，还可以发出异常

12. 对象方面:`delete` 会自己析构函数，但是 `free` 却不能完成。 `new` 在为对象申请时，可以自己执行构造函数，`macoll`却不能，如果是用户自定义的对象， `macoll` 不行去申请地址。

**结论**：相比之下，`new` / `delete` 更像是 `macoll` / `free` 的增强版，但是**消耗的的系统资源也会更多**

### chapter 2:数据类型与转换、[C++11]列表初始化

#### 布尔数据类型(Boolean data type)

1. 布尔类型的定义

>布尔（英语：Boolean）是计算机科学中的逻辑数据类型，以发明布尔代数的数学家乔治·布尔为名。它只有两种值，通常是真和假
>C++语言在其标准化过程中引入了bool、true和false关键字，增加了原生数据类型来支持布尔数据。
>布尔类型的大小（所占的存储空间）依赖于具体的编译器实现。也可以用 sizeof运算符得到其占用的空间
>(参见维基百科 https://zh.wikipedia.org/wiki/%E5%B8%83%E6%9E%97_(%E8%B3%87%E6%96%99%E9%A1%9E%E5%9E%8B) )

2. 布尔类型的用途

> 布尔数据类型主要与条件语句相关。条件语句用来更改程序控制流。

3. C++中的布尔类型
> C++ keyword:  `bool`,  `true`,  `false`
例如：
```cpp
bool  isMyBook;
bool  isRunning = {false};  //C++11 列表初始化方式
bool  isBoy( );
 
bool   hasLicense();
bool   canWork();
bool   shouldSort();
```

 

4. 布尔类型与整型的转换(Conversion between bool  and int)
- 转换规则：
```cpp
0 <--> false           // 整数0和布尔false互相转化

true <--> 1            // 布尔true转化为整数1

non-zero <--> true     // 任意非0整数转化为布尔true
```

问题：`'a' <--> ?`
 

5. 关系运算得到布尔值
> 关系运算(Relational Operation)包括：`==`, `!=`, `<=`, `>=`, `<`, `>`
例如:
```cpp
int  a=0, b={1}; //C++11
3 == a;
b < a;
3.2 >= b;

if (3 == a) {
    // blah blah
}
```

6. 逻辑运算得到布尔值
> 逻辑运算(Logical Operation)包括：`&&`, `||`, `!`
```cpp
int  a={0}, b{1}; //C++11
a && b;
b || 18;
!a;

while (!a) {
    // blah blah
}
```

7. 代码示例
```cpp
#include <iostream>
int main() {
    bool isAlpha;
    isAlpha = false;    
    if (!isAlpha) {
       std::cout << "isAlpha=" << isAlpha << std::endl;
       std::cout << std::boolalpha <<
              "isAlpha=" << isAlpha << std::endl;
    }
    return 0;
}
```
其中：

8. 编码规范
> 26. The prefix is should be used for boolean variables and methods.
> 26. 布尔变量/函数的命名应使用前缀“is”。例如：`isSet`, `isVisible`, `isFinished`, `isFound`, `isOpen`
> 39. The incompleteness of split lines must be made obvious.(断行必须很明显。)
> - 在逗号或运算符后换行，新行要对齐
> 也可以用`hasLicense`/`canWork`/`shouldSort` 命名布尔变量/函数

- 注意:
> `true`/`false`为整型变量

#### List Initialization（列表初始化）

1. Before C++11 (C++11标准之前的初始化方法)
```cpp
int x = 0;
int y(2);
char c('a');
int arr[] = { 1,2,3 };
char s[] = "Hello";
```

- C++11 also support the old ways (C++11标准仍然支持旧的初始化方法)

2. List Initialization (列表初始化)

> List initialization is a new feature for C++11 (列表初始化是C++11的一个新特性)
> List: braced-init-list (“列表”是用花括号括起来的一(些)值)
- 列表初始化的两个分类
- - Direct list initialization (直接列表初始化)
- - Copy list initialization (拷贝列表初始化)

```cpp
//直接列表初始化
/* Variable initialization */ 

int x{}; // x is 0; 

int y{ 1 }; // y is 1; 

/* Array initialization */ 

int array1[]{ 1,2,3 }; 

char s1[ 3 ] { 'o', 'k' }; 

char s3[]{ "Hello" }; 

 
//拷贝列表初始化 - "="

/* Variable initialization */ 

int z = { 2 }; 

/* Array initialization */ 

int array2[] = { 4,5,6 }; 

char s2[] = { 'y','e','s' }; 

char s4[] = { "World" };

char s5[] = "Aloha"; // Omit curly braces (省略花括号)
``` 

3. When do we use list initialization (何时使用列表初始化)
> List initialization is also called "unified initialization" (列表初始化也被称为“统一初始化方法”)
> Variables and arrays are initialized in the same form (变量和数组用同样的形式初始化)
- There are still some argues about when to use list-init (目前对于何时使用列表初始化仍然有一些争论)
https://stackoverflow.com/questions/18222926/why-is-list-initialization-using-curly-braces-better-than-the-alternatives

4. 初始化列表与 std::initializer_list有什么关系？

列表初始化是一个形象的说法，当我们使用{}的时候，实际上就是在使用列表初始化的功能，实际上当我们在使用花括号的时候，此时编译器会将这些内容传化成一个临时对象，initializer_list是一个类型，就向大家所说的那样，初始化列表会编译成initializer_list；

也许看着名字很生疏，但是其实在我们平常的使用中就曾涉及这个东西，请大家想想：在我们使用printf的时候，传递的变量参数不可能始终一只，这就给函数带来了形式参数的个数的不确定性，因此引入：initializer_list解决这个问题（当然initializer_list的作用不止如此）大家可以看一下这个例子：
```cpp
//initializer_list的作用：为解决传递参数数量不唯一，通过initailizer_list创建临时对象，将参数值传递给函数
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
```

#### Type conversion (类型转换)
 

> 编程时，经常会遇到数据类型转换的问题，比如将浮点数转换为整数，或者将一个整数转换为字符串后进一步处理。

1. 类型转换有两种
- 隐式类型转换
- - 由编译器按照数据类型的转换规则自动转换，无需程序员干预。
- - 可能导致数据精度损失，或者转换失败。
- - 应尽量避免使用隐式类型转换
 
- 显式类型转换（即：强制类型转换）
- - 由程序员用明确的类型转换语法写出类型转换代码。
- - 好处是，程序员知道自己要做什么并且把这个想法明确表达出来。

2. C风格强制类型转换
语法：`(type) value`
```cpp
printf("%d", (int) 2.5);
```
 
3. C++风格强制类型转换

语法：`static_cast<type> value`
```cpp
cout << static_cast<double>(1) / 2;

cout << 1 / 2; 
```
问题：下面代码的输出是什么？
cout << static_cast<double>(1 / 2);

4. 编码规范
> 45. Type conversions must always be done explicitly. Never rely on implicit type conversion.
> 45. 类型转换必须显式声明。永远不要依赖隐式类型转换
> 例如：
> ```cpp
> floatValue = static_cast<float>(intValue); // NOT: floatValue = intValue;
> ```

5. **reinterpret_cast和const_cast有什么用？**
```cpp
//const_cast用于去除指针变量的常量属性。
const int* a;
int* p = a;//此时是报错的，报错原因是："const int *" 类型的值不能用于初始化 "int *" 类型
//因此为了解决这个问题：const_cast便派上用场
//我们这里可以这样
int* pr = const_cast<int*>(a)//此时便能获取成功，也就是所说的：去除指针变量的常量属性
    
//reinterpret_cast，翻译下来就是重新解释转型（主要是指针）
//reinterpret_cast的作用是，不改变指针地址，仅仅是使编译器改变解释属性
//举个例子：
int n = 1024;
int* p = &n;//
cout << *p;//这里的结果显然会输出：1024；
//此时我们使用：reinterpret_cast；
double* pp = reinterpret_cast<double*>(&n);
cout << *pp;//这里输出的结果将是double类型的值；但是地址指针的地址并未发生改变，仅仅是解释的方法发生了改变
```

### chapter 3:C++11的自动类型推导：类型系统、auto与decltype

#### C++11 Enhancement for Type System (C++11 对类型系统的增强)
 
1. 类型(Type)是贯穿于计算机程序中的概念
- 数据类型 (Data type)
`int`, `long int`, `double`, `struct`, `char *`, `float []`, `int (*f)()` …

- 计算机程序构造块(Constructs of a Computer Program)

>计算机程序构造块是不同大小粒度的计算机程序组成部分，它包括变量、表达式、函数或者模块等。


2. 什么是类型系统(What is Type System)

>在编程语言中，“类型系统”是将“type”属性指定给不同计算机程序构造块的规则集。
>这些类型规范并强制程序员用于数据结构和组件的其它隐式类别(e.g. "string", "array of float", "function returning boolean").

3. 为什么使用类型系统(Why using Type System)
- 类型系统可以减少程序中可能出现的bug
- 类型系统减少BUG的方法是：
- - 定义不同程序块间的接口
- - 检查多个块之间是否以一致的方式连接在一起

4. 静态类型 v.s. 动态类型

> 程序设计语言的类型系统机制会检查连接在一起的多个块的一致性
- 上述检查若发生在编译期，称为静态类型
- 上述检查若发生在运行时，称为动态类型
- 上述检查若同时存在于编译期和运行时，称为混合类型


#### Automatic Type Deduction: auto (C++11) 自动类型推导：auto关键字
 

1. 关键字 auto

C++03及之前的标准种，auto放在变量声明之前，声明变量的存储策略。但是这个关键字常省略不写。
C++11中，auto关键字放在变量之前，作用是在声明变量的时候根据变量初始值的类型自动为此变量选择匹配的类型

例如：
```cpp
int a = 10;

auto au_a = a;  //自动类型推断，au_a为int类型 

cout << typeid(au_a).name() << endl;
```

2. auto的使用限制
- `auto` 变量必须**在定义时初始化**，这类似于`const`关键字
```cpp
auto a1 = 10;  //正确 

auto b1;   //错误,编译器无法推导b1的类型

b1 = 10;
```

- 定义在一个`auto`序列的变量必须始终推导成**同一类型**。
 
```cpp
auto a4 = 10, a5{20};   //正确 

auto b4{10}, b5 = 20.0; //错误,没有推导为同一类型
```

- 如果初始化表达式是`引用`或`const`，**则去除`引用`或`const`语义**。
 
```cpp
int a{10}; int &b = a;

auto c = b;   //c的类型为int而非int&（去除引用）

const int a1{10};

auto b1 = a1; //b1的类型为int而非const int（去除const） 
```

- 如果`auto`关键字带上`&`号，则不去除引用或`const`语意
 
```cpp
int a = 10; int& b = a;

auto& d = b;//此时d的类型才为int&

const int a2 = 10;

auto& b2 = a2;//因为auto带上&，故不去除const，b2类型为const in
```
 
- 初始化表达式为**数组**时，`auto`关键字推导类型为**指针**。
 
```cpp
int a3[3] = { 1, 2, 3 };

auto b3 = a3;

cout << typeid(b3).name() << endl; //输出 int * （输出与编译器有关）
```

- 若表达式为**数组**且`auto`带上`&`，则推导类型为**数组类型**。
 
```cpp
int a7[3] = { 1, 2, 3 };

auto& b7 = a7;

cout << typeid(b7).name() << endl; //输出int [3] （输出与编译器有关）
```

- C++14中，`auto`可以作为函数的**返回值类型**和**参数类型**。
- `auto`不能用于数组定义

#### Almost Always Auto (AAA) （尽量使用auto）
 

1. Why Almost Always Auto (为何尽量使用auto)? - **AAA原则**

> Using auto are for correctness, performance, maintainability, robustness—and convenience (使用auto是为了代码的正确性、性能、可维护性、健壮性，以及方便)，例如：保证在声明变量时即初始化
 
2. 特殊情况的处理

>我们在使用auto时有时会遇到一些特殊情况。

- "int x = 3;" 能变成auto形式吗？
当我们非常希望能够在变量定义的时候，【明确】地指出变量的类型，而且不希望随便更改其类型，那么我们可以使用下面的方法：
```cpp
auto x = int {3};  // 初始化列表

auto y = int {3.0}; // 编译器报错，初始化列表不能窄化

auto z = int (3.0);  // C风格的强制类型转换，z的值是整数3
```
- auto和初始化列表一起用
要避免在一行中使用直接列表初始化和拷贝列表初始化，也就是，下面的代码是有问题的：
```cpp
auto x { 1 }, y = { 2 };  // 不要同时使用直接和拷贝列表初始化
```
- 例子
```cpp
//Classic C++ Style (经典C++风格)
int x = 42;
float x = 42.;
unsigned long x = 42;
std::string x = "42";
chrono::nanoseconds x{ 42 };
int f(double);
```
```cpp
Modern C++ Style (现代C++风格)
auto x = 42;
auto x =42.f;
auto x = 42ul;
auto x = "42"s;      //c++14
auto x = 42ns;       //c++14
auto f (double) -> int;
auto f (double) { /*…*/ };
auto f = [](double) { /*… */ };  //匿名函数
```

- 注：关于AAA的内容，大部分来自“Guru of the Week (GotW)”

[Guru of the Week (GotW)](https://herbsutter.com/2013/08/12/gotw-94-solution-aaa-style-almost-always-auto/)


#### Automatic Type Deduction: decltype（自动类型推导：decltype关键字）
 

1. 关键字`decltype`的用法
`decltype`利用已知类型声明新变量。
- 有了`auto`，为什么还要整出一个`decltype`？
原因是，我们有时候想要从表达式的类型推断出要定义的变量类型，但不想用该表达式的值初始化变量。
`decltype`是在编译期推导一个表达式的类型，它只做静态分析，因此它**不会导致已知类型表达式执行**。
`decltype` 主要用于泛型编程（模板）
 

2. 代码示例
```cpp
#include<iostream>
using namespace std;
int  fun1()  { return 10;  }
auto fun2()  { return 'g'; }  // C++14
int main(){
    // Data type of x is same as return type of fun1()
    // and type of y is same as return type of fun2()
    decltype(fun1()) x;  // 不会执行fun1()函数
    decltype(fun2()) y = fun2();
    cout << typeid(x).name() << endl;
    cout << typeid(y).name() << endl;

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    return 0;
}
```
结果：
```bash
i
c
x = 16
y = g
```

3. `decltype`与`auto`的对比

> `decltype`和`auto`都是C++11自动类型推导的关键字。它们有很多差别：
- `auto`忽略最上层的`const`，`decltype`则保留最上层的`const`
- `auto`忽略原有类型的引用，`decltype`则保留原有类型的引用
- 对解引用操作，`auto`推断出原有类型，`decltype`推断出引用；

4. `auto`推断时会实际执行，`decltype`不会执行，只做分析。总之在使用中过程中和`const`、引用和指针结合时需要特别小心。

#### 小节导学:C++11的自动类型推导：类型系统、auto与decltype
 

- 小节内容
- - 类型系统的概念
- - C++11的类型推导关键字`auto`
- - C++11的类型推导关键字`decltype`

### chapter 4:简化的C++内存模型

#### C++内存模型

- Stack（栈）

>编译器自动分配与释放
>向低地址方向生长

- Heap（堆）

>程序员new/delete,或者OS回收
>向高地址方向生长
```cpp
pc = static_cast<char*> new char[8]
```

- Global/Static（全局区/静态区）

> 放在一起，程序启动时就在此处，结束时释放

- Constant（常量区）

> 所以的常量放在一起，不可更改。

#### 小结
> 1. 内存模型分为4个部分；
> 2. 每个部分中所存储的数据的特性；
> 3. 给出一段代码，指出这段代码中的变量、常量等实体的存储位置

### chapter 4:简化的C++内存模型


#### 常量 （Constant）
 
1. 常量
- 常量是程序中一块数据，这个数据**一旦声明后就不能被修改了**。

- 如果这块数据有一个名字，这个名字叫做命名常量；比如 `const int A = 42`; 其中`A`就是**命名常量**；
- 如果这块数据（这个常量）从字面上看就能知道它的值，那它叫做“字面常量”，比如上面例子中的“42”就是**字面常量**
 

2. 编码规范
> 5. Named constants (including enumeration values) must be all uppercase using underscore to separate words.
> 5. 符号常量(包括枚举值)必须**全部大写**并用**下划线分隔单词**
> 例如：`MAX_ITERATIONS`, `COLOR_RED`, `PI`


### chapter 5:常量与指针

#### 常量和指针（Constant and Pointer）
- Help:https://www.icourse163.org/learn/BUPT-1003564002?tid=1450339466#/learn/content?type=detail&id=1214630907&cid=1218578852

>常量和指针搅合在一起，成为一个比较麻烦的问题。就像你想分清楚“己巳已”不容易一样，想搞清楚“指针常量”、“常量指针”、“常量指针常量”这种拗口的东西，总得花点心思。
>问题还不是记性好不好，因为指针和常量搅合在一起，还涉及到**函数传参**、**C风格数组**、**字符串常量**这些应用场景，就更得仔细一些。所以，你应该仔细看看代码示例的演示视频。

1. 指针
> 指针是一个地址，它长得像 `0x8FFF` 这个样子。地址呢，就是某个内存位置的一个编号。那这个位置的内存是可以存放一些数据的。这些数据就叫做“**指针所指的数据**”或者“**指针指向的数据**”

2. 常量和指针
>我们把指针放到一个变量里面，就是**指针变量**；
>我们把指针放到常量中，就是**指针常量**；
>那如果一个指针（也就是地址，比如`0x8FFF`）所指的数据（也就是`0x8FFF`这个内存位置存放的数据）是常量，这个指针被称为**常量指针**。
>所以，有一种东西，叫做“**常量指针常量**”。就是说，一个常量中存着一个指针，这个指针又指向另外一个常量。
 
3. Pointer to Constant (常量指针/常指针)
- 特征：指针所指向的内容不可以通过指针的间接引用(`*p`)来改变。

```cpp
const int x = 1;
const int* p1;
p1 = &x;      //指针 p1的类型是  (const int*)
*p1 = 10;     // Error!
char* s1 = "Hello";     // Error!
const char* s2 = "Hello";     // Correct!
``` 

4. Pointer Constant (指针常量)
- “指针常量”的含义是：指针本身的内容是个常量（地址），不可以改变。
```cpp
int x = 1, y = 1;

int* const p2 = &x; //常量 p2的类型是  (int*)

*p2 = 10;     // Okay! x=10

p2 = &y;      // Error! p2 is a constant
```


5. 指针和常量的总结
```cpp
const int * x

int * const y
```
**在前先读，在前不变**
 
`*`（指针）和`const`（常量）谁在前先读谁；`*` 代表被指的数据，名字代表指针地址
 
6. const在谁前面谁就不允许改变。
```cpp
int* const x; //指针常量：可以解引用
int const* x; //常量指针：不可以解引用
```
下面的用法是对的：
```cpp
using ULInt = unsigned long int;
using PULInt = ULInt*;
```

##### 思考
请你尝试解释下面代码中的 pp 是个什么东西？
```cpp
int x = 0, * const px = &x;
const int* const &pp = px;
```
> 答：`pp`是常量指针常量的引用，是`px`的别名，但是`pp`的值不能修改，指向的值也不能修改。

##### 注意：
> 后置++运算符优先级高于解引用运算符:`*p++`先增后解引用


#### Usage of using, typedef, and #define （using, typedef, and #define的用法）
 
1. `using` 声明新的类型名称
 
当我们声明这样一些变量时：
```cpp
const unsigned long int * p;

const unsigned long int * q;

const unsigned long int * r;
```

我们会觉得很麻烦。
 
那有没有一种办法使得 `p`, `q`, `r`的类型声明简便一点呢？
 
我们在C语言里面学了`typedef`，它可以声明一个新的类型名。
```cpp
typedef const unsigned long int * MyPointer;

MyPointer p;
```

C++11中为 `using` 关键字赋予了一个类型声明的新功能
 
```cpp
using ConstPointer = const unsigned long int *;

ConstPointer p;

ConstPointer q;

ConstPointer r;
```

`using`的写法比`typedef`的写法更加直观，所以，我们应尽量使用`using`声明新类型名。而且当涉及到模版类型名时，只能使用using。

2. 编码规范
> 3. Names representing types must be in mixed case starting with upper case.
> 3. 代表类型的名字必须首字母大写并且其它字母大小写混合。例如：Line, SavingsAccount

3. 例子
```cpp
//类型名，等同于 typedef void (*FuncType)(int,int);
using FuncType = void(*)(int,int);
//名称'FuncType'现在指代指向函数的指针
void example(int,int){}
FuncType f = example;
```

### chapter 6:特殊函数：重载、默认参数值与内联

#### 变量的作用域
 

1. 变量的作用域分类
- a. 全局作用域：全局变量
- b. 局部作用域：局部变量

局部作用域可以分为：**文件作用域**、**函数作用域**以及**函数内部的块作用域**。

如果外部代码块与其内嵌代码块有同名的变量，那么会产生**同名覆盖**这种现象。此时要遵循“**就近原则**”来判断哪个同名变量起作用
 

2. Unary Scope Resolution (一元作用域解析运算符)
```
If a local variable name is the same as a global variable name, you can access the global variable using ::globalVariable. (局部变量名与全局变量名相同时，可使用 :: 访问全局变量)

The :: operator is known as the unary scope resolution.（:: 这个运算符被称为一元作用域解析运算符）
``` 

例子:
```cpp
#include <iostream>

int v1 = 10;

int main() {

    int v1 = 5;

    std::cout << "local variable v1 is "  << v1   << std::endl;

    std::cout << "global variable v1 is " << ::v1 << std::endl;

    return 0;

}
```

#### Overloading Functions（重载函数）
 

>**重载函数是在同一个名字空间中存在两个或者多个具有相同名字的函数所构成的语法现象。**

>调用重载函数的语句，是由编译器在编译期确定的。

>编译器判断某个函数调用语句所对应的重载函数时，判断依据是函数参数的**类型**、**个数**和**次序**。

>如果编译器无法判定（有**多个**匹配项），就会报告二义性错误。
```cpp
int max(int num1, int num2)
{
    if(num1 > num2)
      return num1;
    else
      return num2;
}
```
一个问题：如果是求两个输入的浮点型数值的更大值呢？
方法：生成一个同名不同参数的函数。
```cpp
double max(double num1, double num2)
{
    if(num1 > num2)
      return num1;
    else
      return num2;
}
```
> 编译器通过参数**个数**、**类型**、**顺序**来判断不同，而不看返回值。

#### 带有默认参数值的函数
 

>函数的参数可以指定默认值。
>指定默认值时，要保证带有默认值的参数要位于函数参数列表的右侧。
```cpp
/*   函数定义 - 默认参数后置 */
void t1 (int x, int y = 0, int z);  //错误
void t2 (int x, iny y =0, int z = 0); //正确
void t3 (int x = 0, iny y =0, int z = 0); //正确

/*   函数调用 - 参数列表前置*/
t3(1,  , 20); //Error
t4(1); //y,z:default value
t4(1, 2); //z:default value
```
>调用带有默认参数值的函数时，如果不指定带有默认值的参数，则该参数自动被赋为默认值
>无参调用函数时，默认值会被传递给形式参数
```cpp
int max(int x, int y = 0);

/*   调用 */
max();
```

```
C++规定(C++03/C++11)： A default argument shall not be redefined by a later declaration (not even to the same value). (函数重定义/声明时，不允许重定义默认参数)
```
```cpp
int Add (int a, int b = 3);  // 原型声明

//函数定义
int Add (int a, int b = 3) { // 错误！不能重定义默认参数值，尽管与原型声明相同
}
```
![Image](https://pic4.zhimg.com/80/v2-dbd8c644a8b694573bd04b7fa9ace8cb.png)

##### 题目
>如果函数带有默认参数值，那么说法正确的是(`D`)
>A.如果在函数的原型声明中指定了默认参数值，那么在函数定义时就不需要再声明参数了。
>B.如果调用带有默认参数值的函数，那么不能指定新值覆盖默认值
>C.带有默认值的参数可以放到不带默认值的参数的左侧
>D.函数如果有原型声明，那么默认参数值应该在原型声明中给出


#### Inline Function(内联函数)

1. 普通函数的优缺点
- Pros(优点): 易读易维护 
- Cons (缺点): 调用时有开销

>函数调用时：参数及部分CPU寄存器的内容进栈，控制流跳转
>函数返回时：返回值及寄存器值出栈，控制流跳转

2. 使用内联函数

- 目的：减小函数调用开销

- 方法：代码插入到调用处

- 结果：导致程序变大

- **以空间换时间**

3. 定义内联函数
>定义函数时，在函数类型前面加上 `inline` 关键字，则该函数就成为内联函数。
>一般而言，内联函数的声明和定义都在一起。我们很少将内联函数的声明和定义分开编写。

```cpp
// 定义内联函数
inline int max (int a, int b) {

    return (a > b ? a : b);

}

// Calling (调用内联函数)
int  x = max (3, 5);

int  y = max (0, 8);

// Inline expansion(内联展开)
int  x = (3 > 5 ? 3 : 5);

int  y = (0 > 8 ? 0 : 8);
``` 

4. 内联函数的使用
>编译器在遇到内联函数的调用时，会将内联函数的函数体展开到调用位置，从而避免函数调用的开销。
>一般来说，内联函数只有在需要考虑程序运行性能的环境中才使用。
>程序员所用的 `inline` 关键字，只是对编译器的一个请求。内联函数是否展开，是由编译器决定的。

5. 将内联函数的声明和定义分离
>在C++标准7.1.2.4节有如下说明
```cpp
An inline function shall be defined in every translation unit in which it is odr-used and shall have exactly the same definition in every case (3.2). [ Note: A call to the inline function may be encountered before its definition appears in the translation unit. —end note ]
```
内联函数应在每个翻译单元中定义。在该翻译单元中它遵循“单一定义规则（`ODR`）”，并且所有该内联函数定义必须完全相同。注释：在翻译单元中可能会在内联函数定义出现之前就有调用该内联函数的语句

因此，内联函数声明和定义分类的用法如下：
```cpp
#include <iostream>

inline void foo();

int main() {

  foo();

}

inline void foo() {

  std::cout << "Hi\n";

}
```
[stackoverflow](https://stackoverflow.com/questions/11428147)

##### 总结：特殊函数：重载、默认参数值与内联

>本小节主要介绍函数的一些特殊形态：
>a. 重载函数
>b. 带有默认参数值的函数
>c. 内联函数

- 变量的作用域决定着变量生存或者可见的范围。我们在给变量或者函数起名字的时候，除了循环变量等特殊情况，尽量不要用一两个字母的名字

- 重载函数就是名字完全一样，但是参数类型、个数或者顺序不一样的函数。重载函数主要用来对付不同类型的数据。

- 默认参数值则是给函数参数一个默认值，如果调用这个函数的时候不写这个参数，那么就用默认值。默认参数值必须按参数从右往左声明。

- 依靠参数个数来区分的重载函数，如果与函数默认参数值混合在一起会产生二义调用的问题，编译器搞不清楚你想调用哪个函数。所以，初学者避免将重载函数与函数默认参数一起用。

- 内联函数主要目的是减小函数调用时的开销。

### chapter 7：[C++11]基于范围的for循环

#### 小节导学：C++11的基于范围的for循环
 
>本节学习**基于范围**的`for`循环的用法
>基于范围的`for`循环与普通`for`循环的主要差别就在于没有循环变量和循环条件控制。
>基于范围的`for`循环中，如果要修改广义集合中的元素，那么必须将元素名变量定义为引用类型

#### Range-based for-loop （基于范围的for循环）
 
1. 基于范围的for循环的语法

语法
```cpp
for( 元素名变量 : 广义集合) { 循环体 }
```
- a.“元素名变量”可以是引用类型，以便直接修改集合元素的值；
- b. “元素名变量”也可以是const类型，避免循环体修改元素的值
- c. 其中“广义集合”就是“Range（范围）”，是一些元素组成的一个整体
 
>“广义集合”例子
```cpp
auto  a1[] { 1, 3, 5, 7 };  //有问题，应该为int a[] = {1,3,5,7};

std::array<int, 4> a2 { 2, 4, 6, 8};  //广义集合：int：数据类型 / 4：元素个数 / a2：集合名

std::vector< int > v = { 42, 7, 5 };  //可变数组

std::vector< std::string > s { "Hello", "World", "!"};  //存储字符串的可变数组
```

2. 用法
- 想要操作某个广义集合中的所有元素，那么只需要关心
- - a. 从集合中取出某个元素
- - b. 保证所有元素都被遍历

例：把数组a的元素都输出到屏幕上；然后把数组的元素翻倍
```cpp
int a[] = { 2,1,4,3,5 };
// 把存放a[]中的每个元素拷贝到 i 中，依次遍历
for (auto i : a) {
    std::cout << i << std::endl;
}
// i 为数组里每个元素的别名（引用）
for (auto& i : a) {
    i = 2 * i;
} 
```
上面的代码可以直接在a`auto`语句限制解引用
```cpp
int a[] = { 2,1,4,3,5 };
// 把存放a[]中的每个元素拷贝到 i 中，依次遍历
for (auto &i : a) {
    i = 2 * i;
    std::cout << i << std::endl;
}
// i 为数组里每个元素的别名（引用）
```
3. 限制
**基于范围的循环仅限于for语句**
`do…while();` 和 `while(){}` 不支持基于范围的循环

### chapter 8:[C++17]带有初始化器的if和switch语句

#### if and swtich Statement with an Initializer(带有初始化器的if和switch语句)
 
1. if statement with an initializer (带有初始化器的if语句)

- if without an initializer (不带初始化器的if语句)
```cpp
int foo(int arg) { // do something
  return (arg);
}

int main() {

  auto x = foo(42);

  if (x > 40) {
    // do something with x
  } 
  else  {
    // do something with x
  }
  // auto x  = 3;
}
```

- if with an initializer (带有初始化器的if语句)
 
```cpp
int foo(int arg) { // do something
  return (arg);
}

int main() {
  // auto x = foo(42);
  if (auto x = foo(42); x > 40) {
    // do something with x
  } 
  else {
    // do something with x
  }
  auto x  = 3; // 名字 x 可重用
} 
```
- 区别：
- - 带有初始化器的`if`语句中的某个变量作用域比无初始化器的变量作用域**小**。


2. Why we need if with a initializer? (为何要使用带有初始化器的if语句)
```cpp
The variable, which ought to be limited in if block, leaks into the surrounding scope (本应限制于if块的变量，侵入了周边的作用域)

The compiler can better optimize the code if it knows explicitly the scope of the variable is only in one if block (若编译器确知变量作用域限于if块，则可更好地优化代码)
```

3. "switch" statements with an initializer (带有初始化器的switch语句)
 
Synatx: `switch(initializer; variable)`

```cpp
switch (int i = rand() % 100; i) {
    case 1:
    // do something
    default:
      std::cout << "i = " << i << std::endl;
      break;
}
```

4. 注意
`if`语句中的初始化器只能使用新变量，不能使用之前已经出现过的变量。

## unit02:对象和类（基础）

### chapter 0：导学
>本单元内容，主要是**声明类**、**用类定义对象**，以及初步**使用对象编写程序**的方法。
>本单元中最容易让人迷惑的就是**对象的初始化**、**对象内部的数据成员的初始化问题**。
>本单元中难以理解的概念是`this`指针。这个特殊的指针，很难简单地用文字描述清楚它的含义。想要理解`this`指针，一定要看相关的代码，把`this`放到代码中理解。
>本单元介绍了两个C++的类，分别是`string`和`array`。
>在C++中，我们不应该再使用C风格的字符串，也不应再使用字符数组存储字符串，而应改为使用`string`对象。
>C++11 在标准库中添加了`array`这个类。今后我们在写C++代码时，除非有明确的理由，否则我们都应该使用`array`类，而避免使用C风格的**原生数组**。

### chapter 1:用类创建对象
#### Concepts of Class (类的概念)
1. OO Programming Concepts (面向对象编程的概念)
<span style='color:black;bachground:yellow;font-size:default;font-family:consolas;'>Object-Oriented Programming (OOP) involves programming using objects. (OOP利用对象进行程序设计)<br>An object represents an entity in the real world that can be distinctly identified. (一个对象表示现实世界中一个独一无二的实体)<br>For example, a student, a desk, a circle, a button, and even a loan can all be viewed as objects.例如，一个学生，一张桌子，一个圆圈，一个按钮，甚至一笔贷款都可以看成是对象<br></span>

2. Features of OO (面向对象的特征)
<span style='color:black;bachground:yellow;font-size:default;font-family:consolas;'>(1) Abstraction  (抽象)<br>(2) Polymorphism (多态)<br>(3) Inheritance  (继承)<br>(4) Encapsulation (封装)<br></span>我们将这四个单词的首字母放在一起： `A` `PIE` 。中文含义是：一块甜饼。 这样记忆就方便多了。

3. What does an object consist of? (对象由什么构成)
<span style='color:black;background:yellow;font-size:文字大小;font-family:consolas;'><br>1. An object has a unique identity, state, and behaviors.(对象具有唯一的标识、状态和行为)<br>2. The state of an object consists of a set of data fields (also known as properties) with their current values. (对象状态由数据域(也称为“属性”)及其当前值构成)<br>3. The behavior of an object is defined by a set of functions. (对象的行为由一组函数定义)<br></span>

4. How to define Objects (如何定义对象)
<span style='color:black;background:yellow;font-size:文字大小;font-family:consolas;'><br>
An object is an instance of a class (对象是类的实例) <br>
<br>A class includes (类包含)：<br>
(1) data fields，defined by variables(由变量定义的数据域)<br>
(2) Behaviors， defined by  functions(由函数定义的行为)<br>
A class has two special types of functions (类中有两种特殊的函数)<br>
(1) constructors : which are invoked automatically when constructing objects from the class. <br>
(构造函数：在创建对象时被自动调用)<br>
(2) destructors : : which are invoked automatically when the object is destroyed. <br>
(析构函数：在对象被销毁时被自动调用)<br></span>

- 析构/构造函数简写：ctor  和  dtor

##### 例子

```cpp
// 类
class C{
  int p;  //数据域
  int f();  //行为
};
// 对象
C ca, cb;
```
其中, `ca`/`cb`为两个对象,`C`为**类**类型。

#### Create Objects and Access the members 创建对象并访问对象成员

1. `Constructors`(构造函数)
```cpp
class Circle {
public:
  // The radius of this circle
  double radius;
  
  // Construct a circle object
  Circle() {    //可不带参数  可重载  与类同名
    radius = 1;
  }
  
  // Construct a circle object
  Circle(double newRadius) {    //自动调用  无返回值
    radius = newRadius;
  }
  
  // Return the area of this circle
  double getArea() {
    return radius * radius * 3.14159;
  }
};
```

- `Ctors`(构造函数)的特点:
<span style='color:black;background:yellow;font-size:文字大小;font-family:consolas;'>
(1) Automatic invocation(自动调用)<br>
(2) Has the same name as the defining class (与类同名)<br>
(3) NO return value (including "void"); (无返回值)<br>
(4) Can be overloaded (可重载)<br>
(5) May have no arguments (可不带参数)<br>
</span>

- `A class may be declared without ctors`(类可不声明构造函数)
<span style='color:black;background:yellow;font-size:文字大小;font-family:consolas;'>
(1) A no-arg constructor with an empty body is implicitly declared in the class.<br>
 (编译器会提供一个带有空函数体的无参构造函数)<br>
(2) This constructor, called a default constructor is provided automatically only if no constructors are explicitly declared in the class.<br>
 (只有当未明确声明构造函数时，编译器才会提供这个构造函数，并称之为“默认构造函数”)<br>
</span>

2. `Constructing Objects` (创建对象)

- Without Arguments: (无参数)
>创建一个对象，不传递参数。
```cpp
Circle circle1;   // 正确，但不推荐这样写
Circle  circle2(); // 错误！C++编译器认为这是一个函数声明
Circle  circle3{}; // 正确，推荐写法。这里面明确显示用空初始化列表初始化circle3对象（调用Circle默认构造函数）
```

- With Arguments: (带参数)
>创建一个对象，创建的同时传递参数，用于初始化该对象
```cpp
Circle circle2{ 5.5 }; // C++11 列表初始化
            // 带有窄化检查(narrowing check)
```

- Circle类的声明：
```cpp
class Circle {
public:
  double radius;
  Circle() {
    radius = 1;
  }
  Circle(double newRadius) {
    radius = newRadius;
  }
  //……
};
``` 
![image](E://Program//C++//Cpp_of_BUPT_MOOC//Image//创建对象.jpg)

3. `Object Member Access Operator`(对象访问运算符)
 
<span style='color:black;background:yellow;font-size:文字大小;font-family:consolas;'>
To access the data & functions of an object: (访问对象中的数据和函数)<br>
the dot operator (.),  namely, the object member access operator. ( .点运算符，也称为对象成员访问运算符)<br>
</span>

![image](E://Program//C++//Cpp_of_BUPT_MOOC//Image//对象访问运算符.jpg)

4. A Simple Circle Class

```cpp
#include <iostream>
using namespace std;
/*  声明一个类     */
class Circle {    //类名
    public:
        // The radius of this circle
        double radius;
        // Construct a circle object
        Circle() {    //构造函数1
            radius = 1;
        }
        // Construct a circle object
        Circle(double newRadius) {  //构造函数2
            radius = newRadius;
        }
        // Return the area of this circle
        double getArea() {    //构造函数3
            return radius * radius * 3.14159;
        }
};
  
int main() {
    Circle circle1; //创建一个对象
    Circle circle2(5.0);  //创建一个带参数的对象
    
    cout << "The area of the circle of radius " <<
            circle1.radius << " is " << circle1.getArea() << endl;
    cout << "The area of the circle of radius " <<
            circle2.radius << " is " << circle2.getArea() << endl;
    
    // Modify circle radius
    circle2.radius = 100.0;
    cout << "The area of the circle of radius " <<
            circle2.radius << " is " << circle2.getArea() << endl;
    
    cin.get();
    return 0;
}
```

### chapter 2:对象拷贝以及分离声明与实现

- `Object Copy & Anonymous Object` (对象拷贝和匿名对象)

1. `Class is a Type` (类是一种数据类型)。

> 用类声明一个实体的说法，与定义变量的说法有些不同：用**原生数据类型定义变量**，用**类名定义对象**。 

#### 定义变量的例子：
```cpp
// primitive data type -> variables
double d1;  //未初始化

double d2(3.3);  

int  x1{2.0}; //error: Narrowing

int  x2={4};

auto i{x};

decltype(d1) j;
``` 
#### 定义对象的例子：
```cpp
// class -> objects

Circle c1;      //调用Circle的默认ctor

Circle c2(5.5); //调用Circle的有参ctor

Circle c3{5.5}; // 直接列表初始化,调有参ctor

Circle c4 = {5.5}; // 拷贝列表初始化,调ctor

auto c5 = Circle{2.}; // auto类型推断

decltype(c1) c6;      // decltype类型推断
```
2. `Memberwise Copy` (成员拷贝)
<span style='color:black;background:yellow;font-size:文字大小;font-family:consolas;'><br>
How to copy the contents from one object to the other?(如何将一个对象的内容拷贝给另外一个对象)<br>
(1) use the assignment operator( 使用赋值运算符) ：  =<br>
(2) By default, each data field of one object is copied to its counterpart in the other object. ( 默认情况下，对象中的每个数据域都被拷贝到另一对象的对应部分)<br></span>
```cpp
Example:   circle2 = circle1;
```
<span style='color:black;background:white;font-size:文字大小;font-family:consolas;'>
(1) 将 circle1 的 radius 拷贝到 circle2 中<br>
(2) 拷贝后：circle1  和 circle2  是两个不同的对象，但是半径的值是相同的。( 但是各自有一个 radius 成员变量)<br>
</span>

3. `Anonymous Object` (匿名对象)
<span style='color:black;background:yellow;font-size:文字大小;font-family:consolas;'>
Occasionally, you may create an object and use it only once. (有时需要创建一个只用一次的对象)<br>
An object without name is called anonymous objects. (这种不命名的对象叫做匿名对象)<br>
</span>

```cpp
//Example:

int main() {

  Circle c1 = Circle{1.1};

  auto c2 = Circle{2.2}; // 用匿名对象做拷贝列表初始化

  Circle c3{};           // 直接列表初始化,调默认Ctor

  c3 = Circle{3.3};      // 用匿名对象赋值

  cout << "Area is " << Circle{4.2}.getArea() << endl;

  cout << "Area is " << Circle().getArea() << endl;  // 不推荐

  cout << "Area is " << Circle(5).getArea() << endl; // 不推荐

  return 0;

}
```

4. `class Replaces struct`
<span style='color:black;background:yellow;font-size:文字大小;font-family:consolas;'>
The C language has the struct type for representing records. (C语言中使用结构体类型来表示一组数据)<br>
In C++, class has replaced struct (在C++中，结构体已被类取代)<br>
</span>

5. `Local class & Nested class` (局部类和嵌套类)
- `Local class : a class declared inside a function` (局部类是在一个函数中声明的类)
```cpp
void f(){

  class C { // C及其对象只在f()中可用 

    void g() { // 成员函数必须在C中实现

      /* 访问f()的成员受限 ……. */

    }

  };

  C c1, c2;

}
```
- `Nested class: a class declared in another enclosing class` (嵌套类是在另一个类中声明的类)
```cpp
class E{

  class N { // N及其对象可访问E的成员 

    /* 声明N的成员 ……. */

    }

  };

  C c1, c2;
}
```
#### Separating Declaration from Implementation ( 将声明与实现分离)
 
1. `How do we do in C?` (在C语言中我们怎么做)
- 声明
```cpp
// GetArea.h:
float getArea (float radius);
```
- 定义/实现
```cpp
// GetArea.cpp:
#include "GetArea.h"
float getArea (float radius) {
    return radius*radius*3.14;
}
```
- 使用
```cpp
//Main.cpp:
#include "GetArea.h"
using namespace std;
int main() {
    cout << getArea(2.0) << endl;
    return 0;
}
```
2. `Separating Declaration from Implementation` (声明与实现分离)
<span style='color:black;background:white;font-size:文字大小;font-family:consolas;'><br>
C++ allows you to separate class declaration from implementation. (C++中，类声明与实现可以分离)<br>
(1) .h:      类声明，描述类的结构<br>
(2) .cpp:  类实现，描述类方法的实现<br>
</span>

```cpp
FunctionType ClassName :: FunctionName (Arguments) { //… }
```
>其中，`::` 这个运算符被称为`binary scope resolution operator`（二元作用域解析运算符），简称“域分隔符”

3. `Inline Declaration & Inline Function` (内联声明与内联函数)
<span style='color:black;background:white;font-size:文字大小;font-family:consolas;'><br>
When a function is implemented inside a class declaration, it automatically becomes an inline function. (当函数在类声明中实现，它自动成为内联函数)
</span>

```cpp
class A {
  public:
    A() = default; //C++11
    double f1() {  // f1自动称为内联函数：当函数在类声明中实现，它自动成为内联函数
      // do something
    } 
    double f2();
};

double A::f2() {  // f2不是内联函数
  //do something
}
```
```cpp
class A {
  public:
    A() = default; //C++11
    double f1();
    double f2();
};

double A::f2() {
  //do something
}

inline double A::f1() { // f1是内联函数，和上面示例中在类定义时直接定义函数的效果一样，需要inline关键字
  //do something
}
```

#### Avoiding Multiple Inclusion of Header Files (避免头文件被多次包含)

1. `Avoiding Multiple Inclusion of Header Files` (避免头文件被多次包含)

> C/C++使用**预处理指令**(`Preprocessing Directives`)保证头文件只被包含/编译一次

例1：
```cpp
#ifndef  MY_HEADER_FILE_H
 #define MY_HEADER_FILE_H
 //  头文件内容
 #endif
```

例2：
```cpp
#pragma once       // C++03, C90
``` 

例3
```cpp
_Pragma("once")  // C++11, C99;
```

### chapter 3：对象指针、对象数组以及函数参数

#### Object Pointer & Dynamic Object ( 对象指针与动态对象)

1. `Accessing Object Members via Pointers` (用指针访问对象成员)
<span style='color:black;background:yellow;font-size:文字大小;font-family:consolas;'><br>
Object pointers can be assigned new object names(对象指针可以指向新的对象名)<br>
Arrow operator ->  : Using pointer to access object members (箭头运算符 -> ：用指针访问对象成员)<br>
</span> 

```cpp
Circle circle1;

Circle* pCircle = &circle1;   //创建一个对象指针，区对象circle1的地址

cout << "The radius is " << (*pCircle).radius    << endl;

cout << "The area is "   << (*pCircle).getArea() << endl;

(*pCircle).radius = 5.5;

cout << "The radius is " << pCircle -> radius    << endl;

cout << "The area is "   << pCircle -> getArea() << endl;
```

2. `Creating Dynamic Objects on Heap` (在堆中创建对象)
<span style='color:black;background:yellow;font-size:文字大小;font-family:consolas;'><br>
Object declared in a function is created in the stack.(在函数中声明的对象都在栈上创建)<br>
When the function returns, the object is destroyed (函数返回，则对象被销毁).<br>
To retain the object, you may create it dynamically on the heap using the new operator. (为保留对象，你可以用new运算符在堆上创建它)<br>
</span>
 
```cpp
Circle *pCircle1 = new Circle{}; //用无参构造函数创建对象

Circle *pCircle2 = new Circle{5.9}; //用有参构造函数创建对象

//程序结束时，动态对象会被销毁，或者

delete pObject;  //用delete显式销毁
```
- 对象包括**数据成员**和**函数成员**

#### 实例：
<span style='color:black;background:yellow;font-size:文字大小;font-family:consolas;'>
1. 创建对象指针，指向对象<br>
1.1 展示解引用后用dot运算符访问成员<br>
1.2 展示用箭头访问成员<br>
2. 动态对象<br>
2.1 用new创建动态对象<br>
2.2 用delete删除动态对象<br>
2.3 将指针置空，用delete删除空指针<br>
</span>


#### Array of Objects (对象数组)

1. `Array of Objects` (对象数组)

(1) 声明方式1
```cpp
Circle ca1[10];
 ```

(2) 声明方式2

> 用匿名对象构成的列表初始化数组
```cpp
Circle ca2[3] = { // 注意：不可以写成： auto ca2[3]=     因为声明数组时不能用auto
       Circle{3}, 
       Circle{ }, 
       Circle{5} };  
```

(3) 声明方式3

> 用C++11列表初始化，列表成员为隐式构造的匿名对象
```cpp
Circle ca3[3] { 3.1, {}, 5 };

Circle ca4[3] = { 3.1, {}, 5 }; 
```

(4) 声明方式4

> 用`new`在堆区生成对象数组
```cpp
auto* p1 = new Circle[3];
auto p2 = new Circle[3]{ 3.1, {}, 5 };
delete [] p1;
delete [] p2;
p1 = p2 = nullptr;
```

上述代码第4行若是改为 delete [] p1，会发生什么情况？

#### Passing Objects to Functions (对象作为函数参数)

1. Objects as Function Arguments (对象作为函数参数)
```
You can pass objects by value or by reference. (对象作为函数参数，可以按值传递，也可以按引用传递)
```

(1) `Objects as Function Return Value`(对象作为**函数参数**)
```cpp
// Pass by value
void print( Circle c ) {  //作为函数参数
  /* … */
}

int main() {
  Circle myCircle(5.0);
  print( myCircle );  //作为函数参数
  /* … */
}
```

(2) `Objects Reference as Function Return Value`(**对象引用**作为**函数参数**)
```cpp
void print( Circle& c ) {
  /* … */
}

int main() {
  Circle myCircle(5.0);
  print( myCircle );
  /* … */
}
```

(3) `Objects Pointer as Function Return Value`(**对象指针**作为**函数参数**)
```cpp
// Pass by pointer
void print( Circle* c ) {
  /* … */
}

int main() {
  Circle myCircle(5.0);
  print( &myCircle );
  /* … */
}
```

2. `Objects as Function Return Value`(对象作为**函数返回值**)
```cpp
// class Object { ... };
Object f ( /*函数形参*/ ){
  // Do something
  return Object(args);
}

// main() {
Object o = f ( /*实参*/ );

f( /*实参*/ ).memberFunction();
``` 

3. Objects Pointer as Function Return Value(对象作为**函数返回值**)
```cpp 
// class Object { ... };
Object* f ( /*函数形参*/ ){
  Object* o = new Object(args) // 这是“邪恶”的用法，不要这样做
  // Do something
  return o;
}

// main() {
Object* o = f ( /*实参*/ );
f( /*实参*/ )->memberFunction();
// 记得要delete o
```

允许的用法
```cpp
// class Object { ... };
Object* f ( Object* p, /*其它形参*/ ){
  // Do something
  return p;
}

// main() {
Object* o = f ( /*实参*/ );
// 不应该delete o
``` 

- 实践:
>尽可能用`const`**修饰函数**返回值**类型**和**参数**,除非你有特别的目的（使用移动语义等）。
```cpp
const Object* f(const Object*  p, /* 其它参数 */) { }
```

4. `Objects Reference as Function Return Value`(对象**引用**作为**函数返回值**)
```cpp
// class Object { ... };
Object& f ( /*函数形参*/ ){
  Object o {args};
  // Do something
  return o;  //这是邪恶的用法
}
```

可行的用法1
```cpp
// class Object { ... };
class X {
  Object o;
  Object f( /*实参*/ ){
    // Do something
    return o;
  }
}
```

可行的用法2
```cpp
// class Object { ... };
Object& f ( Object& p, /*其它形参*/ ){
  // Do something
  return p;
}

// main() {
auto& o = f ( /*实参*/ );
f( /*实参*/ ).memberFunction();
```
- 实践:
用`const`修饰引用类型的函数返回值，除非你有特别目的（比如使用移动语义）
```cpp
const Object& f( /* args */) { }
``` 

5. 一些高阶问题

>传值，传址，传指针，传引用都是骗初学者的。C++中有意义的概念是传值和传引用

[Differences between a pointer variable and a reference variable](https://stackoverflow.com/a/57492)
[Difference between passing by reference vs. passing by value?](https://stackoverflow.com/a/430958)

