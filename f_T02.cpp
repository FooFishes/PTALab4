#include <iostream>
using namespace std;

struct Student {
    int id;
    float gpa;
};

template<typename T>
class Store {
private:
    T elem_;
    bool isInit;

public:
    Store() {
        isInit = false;
    }

    T getElem() {
        if (isInit) {
            return elem_;
        }
        cout << "No item present!" << endl;
        throw runtime_error("");
    }

    void putElem(T elem) {
        this->elem_ = elem;
        isInit = true;
    }
};

int main() {
    try {
        Store<int> s1, s2; //定义两个Store<int>类对象，其中数据成员item为int类型
        s1.putElem(3); //向对象S1中存入数据（初始化对象S1）
        s2.putElem(-7); //向对象S2中存入数据（初始化对象S2）
        cout << s1.getElem() << "  " << s2.getElem() << endl; //输出对象S1和S2的数据成员

        Student g = {1000, 23}; //定义Student类型结构体变量的同时赋以初值
        Store<Student> s3; //定义Store<Student>类对象s3，其中数据成员item为Student类型
        s3.putElem(g); //向对象D中存入数据（初始化对象D）
        cout << "The student id is " << s3.getElem().id << endl; //输出对象s3的数据成员

        Store<double> d; //定义Store<double>类对象s4，其中数据成员item为double类型
        cout << "Retrieving object d... ";
        cout << d.getElem() << endl; //输出对象D的数据成员
        //由于d未经初始化,在执行函数D.getElement()过程中导致程序终止
    } catch (...) {
        cout << "get item error!";
    }

    return 0;
}
