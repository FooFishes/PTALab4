#include <iostream>
#include<iomanip>
using namespace std;
constexpr double PI = 3.14;

class Point {
public:
    Point(const float x, const float y): x(x), y(y) {
        cout << "Point constructor called" << endl;
    }

    ~Point() {
        cout << "Point destructor called" << endl;
    };

private:
    float x;
    float y;
};

class Circle : public Point {
public:
    Circle(const float x, const float y, const float r): Point(x, y), r(r) {
        cout << "Circle constructor called" << endl;
    }

    ~Circle() {
        cout << "Circle destructor called" << endl;
    }

    float getCircumference() {
        return PI * 2 * r;
    }

private:
    float r;
};

int main() {
    float x, y, r;
    cin >> x >> y >> r;
    Circle c(x, y, r);
    cout << fixed << setprecision(2) << c.getCircumference() << endl;
    return 0;
}
