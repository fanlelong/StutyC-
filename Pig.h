//
// Created by admin on 2022/5/10.
//

#include <iostream>
using namespace std;
#ifndef PIG_H  // ����û������꣨JAVA  ��==������
#define PIG_H  //���������

class Pig {
private:
    int age;
    char *name;
public:
    //��̬����
    static int id;

//���캯��������
    Pig();

    Pig(char *);

    Pig(char *, int);

    //��������
    ~Pig();

    //�������캯��
    Pig(const Pig & pig);

    //��ͨ��set��get
    int getAge();
    char * getName();
    void setAge(int age);
    void setName(char * name);

    void showPigInfo () const; //����ָ�볣����ֻ����

    //��̬��������
    static void changeTag(int age);

    //��Ԫ��������
    friend void changeAge(int age);

};

#endif //PIG_H //�ر�
