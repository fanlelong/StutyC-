// todo 命名空间
#include <iostream>
// 声明std 我们的main函数就可以直接使用里面的成员，不需要std::
using namespace std; // 全局的所有函数都可以用

// 自定义命名空间
namespace ancely {
    int age = 18;
    char *name = "Lucy";

    void show() {
        cout << "name: " << name << ".age: " << age << endl;
    }

    void action() {
        cout << "ancely1 的 action" << endl;
    }
}

namespace ancely0 {
    int age0 = 18;
    char *name0 = "Lucy";

    void show0() {
        cout << "name: " << name0 << ".age: " << age0 << endl;
    }

    void action0() {
        cout << "ancely1 的 action" << endl;
    }
}

// 命名空嵌套怎么办
namespace ancely3 {
    namespace ancely3Inner {
        namespace ancely3Inner2 {
            namespace ancely3Inner3 {
                void out() {
                    cout << "1111111111111111111" << endl;
                }
            }
        }
    }
}

namespace ancely2 {
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

int mainT5() {
    // 我们在打印日志的时候需要用到std::cout 这个std::就是一个命名空间，但是我们也可以省略
    std::cout << "Hello Work " << std::endl;

    // 如何省略std:: 可以先将std声明出来 代码： using namespace std;
    // 打印
    cout << "Hello Work " << std::endl;

    // std是系统的

    // 如果有声明以下二行代码输出都一样
    int ageValue = ancely::age;
    int ageValue1 = age;

    // 局部声明也是可以打
    using namespace ancely0;
    int ageValue2 = ancely0::age0;
    show0();
    ancely0::show0();

    // 命名空间重复函数怎么办 再定义一个ancely2

    using namespace ancely2;
//    action() 如果直接这样的话就系统就不知道用哪个会报错
    ancely2::action();

    // todo 命名空间嵌套
    using namespace ancely3::ancely3Inner::ancely3Inner2::ancely3Inner3;
    // 使用
    out();
    // 直接使用
    ancely3::ancely3Inner::ancely3Inner2::ancely3Inner3::out();
    return 0;
}