#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person() {
        name = "";
        age = 0;
    }

    Person(const string &p_name, int p_age) {
        name = p_name;
        age = p_age;
    }

    void display() const {
        cout << name << ":" << age << endl;
    }
};

class Student : Person {
private:
    int ID{};
    float cpp_score{};
    float cpp_count{};
    float cpp_grade{};

public:
    Student();

    Student(const string &name, const int id, const int age, const float cs, const float cc) {
        this->name = name;
        this->ID = id;
        this->age = age;
        cpp_score = cs;
        cpp_count = cc;
        cpp_grade = cpp_score * 0.9f + cpp_count * 2;
    }

    void print() const {
        cout << fixed << setprecision(1);
        cout << ID << " " << name << " " << cpp_grade << endl;
    }
};

int main() {
    string name;
    int id, age;
    float cs, cc;
    while (true) {
        cin >> name;
        if (name == "0") break;
        cin >> id >> age >> cs >> cc;
        Student stu(name, id, age, cs, cc);
        stu.print();
    }
    return 0;
}
