## C++初步认识
```c++
#include <iostream>  // c++标准支持
using namespace  std; // 命名空间 C++的特性，相当于Java语言的内部类
int main() {
    // C++是面向对象  C语言是面向过程 函数+结构体
    // C++基于C，可以调用C语言，反之C不能调用C++

    // C++打印  << 这个是操作符重载 Kotlin里面这种语法会经常看到
    std::cout << "Hello, World!" << std::endl;

    // 调用c里面代码
    printf("Hello, World! C   \n");
    std::cout << "Hello, World!--- \n";

    std::cout << "Hello, World! \n"
    << "???????"
    << endl
    <<"???????";

//    常量 在C里面常量是个假常量，可以通过指针直接修改  但是在C++里面是不可以的 代码如下
//    const int number = 1000;
//    int * nump =  &number; // 这行代码在 C里面是没问题的，但是在C++里面就会报错
//    *nump =  1000;
    return 0;
```

## 函数
### 函数写法
```c++

void change2(int &num1, int &num2) {

    std::cout << "change2 " << "n1的地址： " << &num1 << ", n2的地址： " << &num2 << std::endl;
    int temp = 0;
    temp = num1;
    num1 = num2;
    num2 = temp;
}
```

### &符号的意义
```c++
void change2(int &num1, int &num2) {
	 std::cout << "change2 " << "n1的地址： " << &num1 << ", n2的地址： " << &num2 << std::endl; 
}

int main () {
    int num1 = 10;
    int num2 = 20;
    // 打印一下num1 和num2的地址看看是多少
    std::cout << "main " << "num1的地址： " << &num1 << ", num2的地址： " << &num2 << std::endl;
    // 打印结果： main num1的地址： 00CFFD64, num2的地址： 00CFFD58
    
    // 再调用一下change2方法 
    change2(num1, num2); // 直接传num1, num2就可以 
    // 打印结果： change2 n1的地址： 00CFFD64, n2的地址： 00CFFD58
    // todo 上面二个结果行出结论，当参数里面有&这个符号相当于C里面传地址 C++的叫法是引用

    // todo 再来个例子
    int n1 = 99;
    int n2 = n1;
    std::cout << "main " << "n1的地址： " << &n1 << ", n2的地址： " << &n2 << std::endl;
    // 打印结果：main n1的地址： 00CFFD4C, n2的地址： 00CFFD40
    // 二个地址不一样
    
    int  nn1 = 99;
    int & nn2 = nn1;
    std::cout << "main " << "nn1的地址： " << &nn1 << ", nn2的地址： " << &nn2 << std::endl;
    // 打印结果：main nn1的地址： 00CFFD34, nn2的地址： 00CFFD34 
    // 二个地址一样
    
    //todo 结论： &代表是一个引用 ，意思就是在nn1引用添加了一个nn2 二个指向的都是同一个地址
    //todo 就比如李白 名字叫李白， 他也叫诗仙。 其实指向是同一个人 他还可以叫酒仙等 其它小名
}

```
### C++在C上对函数的升级
比如我们要插入一个数据到数据库 C的写法

C写法
```c
// 插入数据库， Student的信息给插入数据库 下面C里面写法就可以随便改student里面值
void insertStudent(Student student) {
    // c里面 假如有内鬼
    strcpy(student.name, "Liyuanba");
}
// 当我们插入数据时就可以随便改，但是C++是不一样的 C++里面有常量引用这一说法
```
C++写法
```c++
//常量引用: C++里面可以使用常量引用来不让修改， === const Student &
void insertStudent2(const Student &student) {
    // 只读的 可以安心的插入数据库
    cout << student.name << endl;
}
```

### 函数重载
C++是支持函数重载的，但是C不支持
```c++
int add (int num1){
}

int add (int num1, int num2){
}

int add (int num1, int num2, int num3){
}

```

### 函数的高级写法
```c++
// 第二个参数int 是一个无形参数 
void uploadLog(char *logText, int) {  
	// int 这个值的作用是方便拓展，
	// 上传日志到服务器 前期没有考虑好，为了防止扩展功能，你必须传递一个int类型参数 方便拓展
	
}

// 半年后这个int忽然有用处了，我只需要重新改造一下这个方法就行
void uploadLog(char *logText, int model) {

}
```

### C++的一些规范
首先要创建一个对象时在声明一个头文件.h 然后再要有一个实现文件.cpp
eg：假如要创建一个Student这个对象
* 首先创建一个Student.h文件，在.h文件里只做声明不做任何实现
#ifndef THIRD_STUDENT1_H
#define THIRD_STUDENT1_H
#endif
上面三行代码是为了防止递归引用
```c++
#include <iostream>
#ifndef THIRD_STUDENT1_H 
#define THIRD_STUDENT1_H

// .h只写声明，不写实现
using namespace std;
class Student {
private:// 下面代码 成员 函数都是 私有
    char * name;
    int age;
public:// 下面代码 成员 函数都是 公开
    void setAge(int age);
    void setName(char * name);
    int getAge();
    char * getName();
};
#endif 
```

* 再创建一个实现文件Student.cpp

```c++
#include "Student.h"

void Student::setAge(int age) {
    // C++对象指向的是一个指针
    // ->调用一级指针的成员
    this->age = age;
}

int Student::getAge() {
    return this->age;
}

void Student::setName(char *name) {
    this->name = name;
}

char *Student::getName() {
    return this->name;
}


```

* 使用

```c++
#include "Student1.h"
int main () {
	Student student; // 栈区开辟空间
    // 赋值
    student1.setAge(33);
    student1.setName("李软衬材料");
    cout << "name:" << student1.getName() << ", age" << student1.getAge() << endl;

    // 堆空间
    Student1 *student11 = new Student1(); // new 对应delete
    student11->setName("liyuandni");
    if (student11) {
        delete student11;// 必须手动释放堆空间对象
        student11 = NULL;
    }
//    free(student11  // 不能这样写，不规范，会被鄙视

    return 0;
}

```

## 命名空间 关键字 namespace
在C++打印的时候我们会用到std::cont 但如果使用了命名空间std::就可以省去

* 没有使用命名空间写法
```c++
int main () {
    std::cout << "Hello Work " << std::endl;
}
```
* 加了命名空间写法
```c++
using namespace std; // 全局的所有函数都可以用
int main () {
    cout << "Hello Work " << std::endl;
}
// todo  std是系统为我们提供的，如何自己写一个呢??
```
* 自己实现一个命名空间写法
```c++
namespace ancely {
    int age = 18;
    char *name = "Lucy";

    void show() {
        cout << "name: " << name << ".age: " << age << endl;
    }

    void action() {
        cout << "ancely2 的 action" << endl;
    }
}

using namespace ancely; // 声明全局 不想全局也可以在函数里声明局部

int main () {
	int ageValue = age;
}
```

## 函数构造
### 对象构造写法
#### 空参与有参构造
```c++
using namespace std;  // C# .net也有命名空间
class Animation {
public:
    // 空参构造函数
    Animation() {
        cout << "空参数构造函数" << endl;
    }

    Animation(char *name) {
        cout << "一个参数构造函数" << endl;
        this->name = name;
    }

    Animation(char *name, int age) {
        cout << "二个参数构造函数" << endl;
        // 对象默认会有一个指针 指针可以用->来获取成员变量
        this->name = name;
        this->age = age;
    }
}
```

* 跟Java一样无参构造可以调用一个参数，一个参数调用二个参数

```c++
using namespace std;  // C# .net也有命名空间
class Animation {
public:
    // 空参构造函数
    Animation1() {
        cout << "Animation1 空参数构造函数" << endl;
    }
    
    Animation1(char *name) : Animation1(name, 0) {
        cout << "Animation1 一个参数构造函数" << endl;
        this->name = name;
    }
}

int main () {
    Animation animation("Dog1");//先会执行二个参数的构造方法，然后再执行一个参数的
    // 还有下面写法 (C工程师搞了五六年，改不了习惯就有下面写法，下面写法不会执行到构造方法里面的代码)
    Animation *ani2 = (Animation *) malloc(sizeof(Animation));
    // 系统源码中很多使用new关键字， 堆区，堆区必须手动释放 有new 就得有 delete成对出现
    Animation *ani = new Animation("Cat", 2);
    
    free(ani2);
    delete ani;
}

```

#### 析构函数
```c++
using namespace std;  // C# .net也有命名空间
class Animation {
public:
    // 空参构造函数
    Animation() {
        cout << "Animation1 空参数构造函数" << endl;
    }
    
    Animation(char *name){
        // 堆区创建了 name
        this->name = (char *) (malloc(sizeof(char *) * 10));
        strcpy(this->name, name);
        cout << "一参数构造函数 name: " << name << endl;
        this->name = name;
    }

    // 析构函数 要被回收了，要做一些释放工作
    ~Animation(){
        cout << "析构函数  name: " << name << endl;
        // 做释放工作 name在使用了malloc申请了，所以是在堆区
        if (this->name) {
            free(this->name);
            this->name = NULL;
        }
    }
private:
    char *name;
}
```
什么时候会调用到析构函数
1：栈区创建类，在弹栈时会调用,代码如下
```c++
int main () {
    Animation an2("Cat");
    return 0;
}
// todo 当上面main方法执行完时 会执行到析构函数
```
2: 在堆区创建后，执行了delete方法时
```c++
int main () {
    Animation *animation = new Animation("执行Delete");
    delete animation;
    
    Animation *animation1 = new Animation("不执行Delete");
    return 0;
}
// 上面的main方法 在main方法执行完了 只会执行一次析构方法，因为animation1没有执行delete
// C++中有析构函数 --
// Java中也有finalize()方法 代表这个类可能被回收， 只有GC了才会真的回收  回收的前兆
// Kotlin 需要自己重写一个Java类并实现Closeable，然后Kotlin类去继承
```

#### 拷贝构造函数

先来个案例
```c++
struct Cat {
    int age;
    char *name;
};

int main () {
	Cat cat1 = {12, "花猫 "};
	Cat cat2 = cat1; // 寻求cat1里面的值赋值给cat2`
	// = 看起来没什么特殊，但是有隐士的代码：我们是看不到的， C/C++编译器， 会把p1的成员值赋值给p2成员
	// 但是cat1 和 cat2 二个地址不一样。
	cout << &cat1 << "----" << &cat2 << endl;  // 00FAF7BC----00FAF7AC
	// todo  结论： 对象一  = 对象二  会有一个默认的拷贝过程，成员到成员
}

```

探求原理重写拷贝构造函数
```c++
#include <iostream>
#include <string.h>

using namespace std;

class Animation{
public:
    // 空参构造函数
    Animation() {
        cout << "空参数构造函数" << endl;
    }
    
    Animation(char *name) {
        cout << "一个参数构造函数" << endl;
        this->name = name;
    }
    
    Animation(char *name, int age) : name(name), age(age) {
     cout << "二个参数构造函数" << endl;
    }
    
    // 析构函数 没有参数
    ~Animation() {
     cout << "Animation delete 了" << endl;
    }
    
    // 拷贝构造函数，默认是会有，一量我们写拷贝构造函数，覆盖默认
    Animation(const Animation &animation) {
        cout << "拷贝构造函数" << endl;
        // 自己控制
        this->age = animation.age;
        this->name = animation.name;
    }
};
int main () {
    Animation ani1("111", 1); // 这是栈区内存
    Animation ani2 = ani1;  // 执行这里会调用自己重写的拷贝构造函数
    
    Animation ani3;
    ani3 = ani1; // 这种方式是不会调用自己重写的拷贝构造函数，但是会调用系统的，所以ani3里面也是有值。
    
    Animation ani4 = ani1; // 会调用拷贝构造函数
    Animation *animation = new Animation("333", 3); // 这是堆区内存
    Animation *animation1 = animation;//  这个也不会调用拷贝构造函数   因为这是指针的指向 animation1的地址指向Animation
    Animation1->setAge(4); // 这时animation的age也是4 改的是地址的值
}

```
## 指针常量，常量指针，常量指针常量
### 常量
```c++
int number = 9;
int number1 = 2;
```
### 常量指针 在类型前加上const修饰
```c++
const int * number_p = &number;
```
常量指针值是不允许被修改，如果修改会报红，例如下面代码
```c++
const int * number_p = &number;
* number_p = 100;
```
常量指针值不允许修改，但是可以重新指向，如下面代码
```c++
const int * number_p = &number;
number_p = &number2; // 这行代码可行， 允许重新指向【常量指针】存放的地址
```
### 指针常量 在指针变量前加上const修饰
```c++
int *const number2_p = &number;
```
指针常量值可以修改
```c++
int *const number2_p = &number;
*number2_p = 100;// 这行代码报可行， 允许修改  【指针常量】  存放地址所对应的值
```
但是不允许重新指向，如下面代码会出问题
```c++
int *const number2_p = &number;
number2_p = &number2; // 这行代码报错， 不允许 重新指向  【指针常量】存放的地址
```
### 常量指针常量
```c++
const int *const number_p_p = &number;
```
常量指针常量，值不可改，也不可重新指向,下面代码都会出问题
```c++
*number_p_p = 100;// 这行代码报错， 不允许修改【常量指针】存放地址所对应的值
number_p_p = &number2; // 这行代码报错， 不允许 重新指向  【指针常量】存放的地址
```

## 可变参数 符号...
java中的可变参数定义为int...  C++的可变参数写法： ...   记得导包 #include <stdarg.h>
### 书写规范
```c++
void sum(int count, ...) {
    // 第一步 定义一个可变参数的动作，用来接收可变参数里面的值
    va_list vp;
    
    // 第二步 调用va_start方法
        va_start(vp, count);
    //执行完va_start后 vp就会赋于值
    
    // 第三步，取vp值
    int numble = va_arg(vp, int);
    // 再取
    numble = va_arg(vp, int);
    // 最后关闭
        va_end(vp);
}

int main () {
    sum(333,  7,8,9);
    return 0;
}
```

## 静态关键字使用   关键字static
先来定义一个类
```c++
class Dog {
public
    char *name;
    int age;
    
    // 声明一个静态变量
    static int id;
    
    // 声明一个静态方法
    static void updata(){
        
    }
    
    // 声明一个普通方法
    void updata2(){
        
    }
};
```
静态变量的使用
如果没有对静态变量做声明，在Dog类里面对静态变量 id做一些操作是会出问题比如这样写是会有问题的
```c++
class Dog {
public
    char *name;
    int age;
    
    // 声明一个静态变量
    static int id;
    
    // 声明一个静态方法
    static void updata(){
        id+=100;
    }
    
    // 声明一个普通方法
    void updata2(){
        id = 200;
    }
};

```
正确使用方式
```c++
class Dog {
public
    char *name;
    int age;
    
    // 声明一个静态变量
    static int id;
    
    // 声明一个静态方法
    static void updata(){
        id+=100;
    }
    
    // 声明一个普通方法
    void updata2(){
        id = 200;
    }
};

// 对静态方法做一个实现
int Dog::id = 9;// 如果没有这行代码，那么 update函数就会报错
```
需要注意的是，静态方法是不能调用普通方法的，跟java一样。如下面代码
```c++
static void update() {
    update2(); 报错
}

void update2() {
    id = 13;
}
```
静态变量和方法的调用 类名加符号 :: 加变量/函数名
```c++
int main () {
    Dog dog;  // 会调用空参构造函数，
    cout << Dog::id << endl;
    dog.update2();
    cout << Dog::id << endl;
    Dog::update();
    dog.update();// 这样也可以，但是静态函数都是用：：调用。
    cout << Dog::id << endl;
    return 0;
}
```
## C++中this的作用
先定义一个类
```c++
class Student {
private:
    char *name;
    int age; // C++中如果不给默认值，会给一个系统值
public:
    static int id;// 先声明，要实现 才能用
    void setName(char *name){
        this->name  = name;
    }
    void setAge(int age){
        this->age = age;
    }

    Student(){
        // 默认的构造函数会执有一个this,会指向当前对象
    }
};
int Student::id = 9527; // 静态变量需要再实现
```
使用
```c++
    Student student;
    student.setAge(99);
    student.setName("sdfwef");

    Student student1;
    student1.setAge(88);
    student1.setName("sdf33wef"); // 设置值的时候怎么知道是给student1设置的值

    Student student2;
    student2.setAge(22);
    student2.setName("222"); // 设置值的时候怎么知道是给student2设置的值
```
为什么student  student1  student2在设置值的时候知道设置哪个值呢
C++内存区域分为 栈区，堆区，代码区，静态区，方法区 代码区
当执行Student student 进栈，这时会执行空参构造函数，在空参构造函数里面会有隐式代码，就是给this赋值这时this就有内存地址指向当前对象
调用setAge setName，这时就会在代码区有一个setAge副本 当多个Student调用时就有多个副本，都有this去指向他们，所以他们可以设置对应的值。
静态变量不一样，静态变量是在 静态区域，他没有this这一说法，是全局的，谁都可以拿到他们并修改他们。

再来研究下this
```c++
class Dog {
public
    char *name;
    int age;
    
    // 声明一个静态变量
    static int id;
    
    // 声明一个静态方法
    static void updata(){
        id+=100;
    }
    
    // 声明一个普通方法
    void updata2(){
        id = 200;
    }
};

// 对静态方法做一个实现
int Dog
```
来分析下面代码的updata2方法
```c++
    void updata2(){
        id = 200;
    }
```
在C++里面的函数会默认执行当前类的this也就是updatda2方法有一个这个的系统代码
```c++
    void updata2(){
        // int * const 指针常量    const int * 常量指针
        Dog *const this;// 指针常量，指针常量代表指针的地址不能修改  但指针的地址的值是可以修改
        id = 200;
        this->age = 100; //可以修改值
    }
```
函数后面再加个const

```c++
    void updata2() const{
        // int * const 指针常量    const int * 常量指针
        const Dog *const this;// this就是常量指针常量
        id = 200;
        this->age = 100; //可以修改值
    }
```
## 友元函数 关键字friend
示例代码
```c++
#include <iostream>
#include <string.h>
#include <stdarg.h>

class Person {
private:
    int age = 0;
public:
    Person(int age) {
        this->age = age;
    }
    friend void  updateAge1(Person * person, int age);
};

void updateAge(Person *person, int age) {
    // 不能修改私有的age 要想修改就得定义友元函数 friend
//    person.age = age; 不是友元这行代码报错
}

void updateAge1(Person *person, int age) {
    // 不能修改私有的age 要想修改就得定义友元函数 friend
    person->age = age; // 是友元这行代码不会报错
}

```
## 友元类
```c++
using namespace std;

class ImageView {
private:
    int viewSize;

    friend class Class; //友元类
};

// Java每个类，都会有一个Class, 此Class可以操作ImageView么有成员
class Class {
public:
    ImageView imageView;

    void changeViewSize(int size) {
        imageView.viewSize = size;
    }
};
```
## 运算符重载
自定义一个类的+号重载符
```c++
class Person {
public
    int age;
    Person(int age){
        this->age = age
    }
    
    // 放在类里面只需要传一个参数 基本是用这一种方式，因为外部是不能获取内部的私有成员。
    Person operator + (Person person1){
        int x = person1.age + this->age;
        Person res(x);
    return  res
}
};

Person operator + (Person person1, Person person2){
    int x = person1.age + person2.age;
    Person res(x);
return  res
```
系统写法
```c++
    //变成常量引用 不允许修改，只读模式  加入& 是为了性能提高 ， 如果没有这个person1就会是一个新的副本
    Person operator+(const Person &person1) const {
        Person person = Person();
        person.age = person1.age + this->age;
        return person;
    }
```
### 自定义输入操作符
```c++
class Person {
public
    int age;
    Person(int age){
        this->age = age
    }
    // 这个只能输出一次
    friend void operator<<(ostream &START, Person &person) {
        START << " 哥开始 输出了" << person.age << " @ " << endl;
    }

    // 可以多次调用，比如Retrofit里的链式调用
    friend ostream &operator>>(ostream &START, Person &person) {
        START << " 哥开始 输出了" << person.age << " ！ " << endl;
        return START;
    }
};
```

## 多继承
