#include <iostream>
using namespace std;

class A {
public:
    virtual ~A() = default;

    explicit A(int i): i(i) {
        cout << "Call A:i=" << i << endl;
    }

    A() = default;

    virtual void display() {
        cout << "i=" << i << endl;
    }

protected:
    int i{};
};

class A1 : virtual public A {
public:
    A1(int i, int j)
        : A(i),
          j(j) {
        cout << "Call A1:i=" << i << endl;
    }

protected:
    int j;
};

class A2 : virtual public A {
public:
    A2(int i, int k)
        : A(i),
          k(k) {
        cout << "Call A2:i=" << i << endl;
    }

protected:
    int k;
};

class A3 : public A1, A2 {
public:
    A3(int i, int j, int k)
        : A(i),
          A1(i, j),
          A2(i, k) {
        cout << "Call A3:i=" << i << endl;
    }

    void disp() {
        display();
        cout << "j=" << j << endl << "k=" << k;
    }
};

int main() {
    int i, j, k;
    cin >> i >> j >> k;
    A3 a3(i, j, k);
    a3.disp();
}
