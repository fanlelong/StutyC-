#include "Pig.h"

// ʵ�־�̬����
int Pisssssg::id = 878;

Pig::Pig() {
    cout << "�޲ι��캯��" << endl;
}

Pig::Pig(char *name) {
    cout << "һ���ι��캯��" << endl;
}

Pig::Pig(char *name, int age) {
    cout << "�����ι��캯��" << endl;
}

//��������
Pig::~Pig() {
    cout << "��������" << endl;
}

//�������캯��
Pig::Pig(const Pig &pig) {
    cout << "�������캯��" << endl;
}

//��ͨ��set��get
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

void Pig::showPigInfo() const {//����ָ�볣����ֻ����

}

//��̬�������� ����Ҫstatic�ؼ���
void Pig::changeTag(int age) {

}

//��Ԫ�������� ����Ҫ�ؼ��֣� Ҳ����Ҫ���󣺣� ֻ��Ҫ��֤ ������һ��
void changeAge(int age) {

}

