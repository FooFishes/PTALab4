#include <iostream>
#include <iomanip>
using namespace std;
constexpr float PI = 3.14159f;

class Shape {
public:
    virtual float getArea() = 0;

    virtual ~Shape() = default;
};

class Circle : public Shape {
public:
    float getArea() override {
        return PI * r * r;
    }

    explicit Circle(float r)
        : r(r) {
    }

private:
    float r;
};

class Square : public Shape {
public:
    float getArea() override {
        return side * side;
    }

    explicit Square(float side)
        : side(side) {
    }

private:
    float side;
};

class Triangle : public Shape {
public:
    float getArea() override {
        return height * bottom / 2;
    }

    Triangle(float height, float bottom)
        : height(height),
          bottom(bottom) {
    }

private:
    float height;
    float bottom;
};

class Trapezoid : public Shape {
public:
    float getArea() override {
        return (upside + downside) * height / 2;
    }

    Trapezoid(float upside, float downside, float height)
        : upside(upside),
          downside(downside),
          height(height) {
    }

private:
    float upside;
    float downside;
    float height;
};

class Rectangle : public Shape {
public:
    float getArea() override {
        return width * height;
    }

    Rectangle(float width, float height)
        : width(width),
          height(height) {
    }

private:
    float width;
    float height;
};

int main() {
    float r, side, r_width, r_height, upside, downside, tra_height, bottom, tri_height;
    cin >> r >> side >> r_width >> r_height >> upside >> downside >> tra_height >> bottom >> tri_height;
    Shape *ptrShapes[5];
    ptrShapes[0] = new Circle(r);
    ptrShapes[1] = new Rectangle(r_width, r_height);
    ptrShapes[2] = new Trapezoid(upside, downside, tra_height);
    ptrShapes[3] = new Triangle(tri_height, bottom);
    ptrShapes[4] = new Square(side);
    float sum = 0;
    for (auto &ptrShape: ptrShapes) {
        sum += ptrShape->getArea();
        delete ptrShape;
        ptrShape = nullptr;
    }
    cout << fixed << setprecision(3) << sum;
}
