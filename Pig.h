//
// Created by admin on 2022/5/10.
//

#include <iostream>
using namespace std;
#ifndef PIG_H  // 你有没有这个宏（JAVA  宏==常量）
#define PIG_H  //定义这个宏

class Pig {
private:
    int age;
    char *name;
public:
    //静态申明
    static int id;

//构造函数的声明
    Pig();

    Pig(char *);

    Pig(char *, int);

    //析构函数
    ~Pig();

    //拷贝构造函数
    Pig(const Pig & pig);

    //普通的set和get
    int getAge();
    char * getName();
    void setAge(int age);
    void setName(char * name);

    void showPigInfo () const; //常量指针常量，只读的

    //静态函数申明
    static void changeTag(int age);

    //友元函数申明
    friend void changeAge(int age);

};

#endif //PIG_H //关闭
