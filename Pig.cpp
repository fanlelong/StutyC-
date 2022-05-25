#include "Pig.h"

// 实现静态属性
int Pisssssg::id = 878;

Pig::Pig() {
    cout << "无参构造函数" << endl;
}

Pig::Pig(char *name) {
    cout << "一个参构造函数" << endl;
}

Pig::Pig(char *name, int age) {
    cout << "二个参构造函数" << endl;
}

//析构函数
Pig::~Pig() {
    cout << "析构函数" << endl;
}

//拷贝构造函数
Pig::Pig(const Pig &pig) {
    cout << "拷贝构造函数" << endl;
}

//普通的set和get
int Pig::getAge() {
    return this->age;
}

char *Pig::getName() {
    return this->name;
}

void Pig::setAge(int age) {
    this->age = age;
}

void Pig::setName(char *name) {
    this->name = name;
}

void Pig::showPigInfo() const {//常量指针常量，只读的

}

//静态函数申明 不需要static关键字
void Pig::changeTag(int age) {

}

//友元函数申明 不需要关键字， 也不需要对象：： 只需要保证 函数名一样
void changeAge(int age) {

}

