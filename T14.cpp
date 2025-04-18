#include <iostream>
#include<iomanip>
using namespace std;

constexpr double PI = 3.14;

class Dot {
public:
    Dot(const float x, const float y): x(x), y(y) {
        cout << "Dot constructor called" << endl;
    }

    ~Dot() {
        cout << "Dot destructor called" << endl;
    };

private:
    float x;
    float y;
};

class Cir : public Dot {
public:
    Cir(const float x, const float y, const float r): Dot(x, y), r(r) {
        cout << "Cir constructor called" << endl;
    }

    ~Cir() {
        cout << "Cir destructor called" << endl;
    };

    double getArea() const {
        return PI * r * r;
    };

private:
    float r;
};

int main() {
    float x, y, r;
    cin >> x >> y >> r;
    Cir c(x, y, r);
    cout << fixed << setprecision(2) << c.getArea() << endl;
    return 0;
}
