#include <iostream>

class Rectangle {
private:
    double width_ = 1;
    double height_ = 1;

public:
    Rectangle();

    Rectangle(double width, double height) {
        width_ = width;
        height_ = height;
    }

    double getArea() const {
        return width_ * height_;
    }

    double getPerimeter() const {
        return 2 * (width_ + height_);
    }
};

int main() {
    using namespace std;
    double width, height;
    cin >> width >> height;
    Rectangle rectangle = Rectangle(width, height);
    cout << rectangle.getArea() << endl;
    cout << rectangle.getPerimeter() << endl;
}
