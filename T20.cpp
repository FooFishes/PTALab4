#include <iostream>
using namespace std;
constexpr double PI = 3.1415;

class Shape {
public:
    virtual ~Shape() = default;

    virtual double area() = 0;
};

class Circle : public Shape {
public:
    double area() override {
        return PI * r * r;
    }

    explicit Circle(double r): r(r) {
    }

private:
    double r;
};

class Rectangle : public Shape {
public:
    double area() override {
        return width * height;
    }

    Rectangle(const double width, const double height): width(width), height(height) {
    }

private:
    double width;
    double height;
};

class Triangle : public Shape {
public:
    double area() override {
        return height * bottom / 2;
    }

    Triangle(const double height, const double bottom): height(height), bottom(bottom) {
    }

private:
    double height;
    double bottom;
};

int main() {
    double r, h, w, hei, b;
    cin >> r >> h >> w >> hei >> b;
    Circle circle(r);
    Rectangle rectangle(w, h);
    Triangle triangle(hei, b);
    cout << fixed << setprecision(2);
    cout << circle.area() << endl << rectangle.area() << endl << triangle.area();
}
