#include <iostream>
using namespace std;

class Complex {
public:
    Complex(double r = 0, double i = 0): real(r), imag(i) {
    }

    Complex operator+(const Complex &other) const {
        Complex result;
        result.real = this->real + other.real;
        result.imag = this->imag + other.imag;
        return result;
    }; //重载双目运算符'+'
    Complex &operator-=(const Complex &other) {
        this->real -= other.real;
        this->imag -= other.imag;
        return *this;
    }; //重载双目运算符'-='
    friend Complex operator-(const Complex &lhs, const Complex &rhs) {
        Complex result = lhs;
        result -= rhs;
        return result;
    }; //重载双目运算符'-'
    void Display() const;

private:
    double real; //实部
    double imag; //虚部
};

void Complex::Display() const {
    cout << "(" << real << ", " << imag << ")" << endl;
}

int main() {
    double r, m;
    cin >> r >> m;
    Complex c1(r, m);
    cin >> r >> m;
    Complex c2(r, m);
    Complex c3 = c1 + c2;
    c3.Display();
    c3 = c1 - c2;
    c3.Display();
    c3 -= c1;
    c3.Display();
    return 0;
}
