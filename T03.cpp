#include <iostream>
using namespace std;

class Complex {
public:
    Complex(double r = 0, double i = 0): real(r), imag(i) {
        z = real * real + imag * imag;
    }

    bool operator>(const Complex &other) const {
        if (this->z > other.z)
            return true;
        return false;
    }

private:
    double real; //实部
    double imag; //虚部
    double z; //模的平方
};

int main() {
    double r1, i1, r2, i2;
    cout << boolalpha;
    while (true) {
        cin >> r1 >> i1 >> r2 >> i2;
        if (r1 != 0 || i1 != 0 || r2 != 0 || i2 != 0) {
            Complex complex1(r1, i1);
            Complex complex2(r2, i2);
            cout << (complex1 > complex2) << endl;
        } else break;
    }
}
