#include <iostream>
#include <iomanip>
using namespace std;

template<typename T>
class Operator {
public:
    Operator(const T &num1, const T &num2): num1(num1), num2(num2) {
    }

    void print() {
        T nmax = max(num1, num2);
        T nmin = min(num1, num2);
        T sum = num1 + num2;
        T de = num1 - num2;
        T root = num1 * num2;
        T sh = num1 / num2;
        char k = ' ';
        cout << nmax << k << nmin << k << sum << k << de << k << root << k << sh << endl;
    }

private:
    T num1;
    T num2;
};

int main() {
    int i1, i2;
    double d1, d2;
    cin >> i1 >> i2 >> d1 >> d2;
    Operator<int> o1(i1, i2);
    Operator<double> o2(d1, d2);
    o1.print();
    o2.print();
}
