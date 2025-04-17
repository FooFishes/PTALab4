#include <iostream>
using namespace std;

class Polygon {
protected:
    int number; //边数,不大于100
private:
    int side_length[100]; //边长数组
public:
    Polygon() {
    } //构造函数根据需要重载
    //计算多边形边长
    int perimeter() {
        int sum = 0;
        for (int i = 0; i < number; i++) {
            sum += side_length[i];
        }
        return sum;
    }

    void setNumber(int num) {
        number = num;
    }

    void setSides(int *arr, int i) {
        side_length[i] = *arr;
    }

    //输出多边形边数和周长
    void display() {
        cout << number << " " << perimeter() << endl;
    }
};

class Rectangle : public Polygon {
public:
    Rectangle();

    Rectangle(int width, int height): Polygon() {
        this->width = width;
        this->height = height;
        this->number = 4;
    }

    int perimeter() {
        return 2 * (width + height);
    }

    void display() {
        cout << number << " " << perimeter() << endl;
    }

private:
    int width;
    int height;
};

class EqualPolygon : public Polygon {
public:
    EqualPolygon();

    EqualPolygon(int side_len, int number): Polygon() {
        this->side_len = side_len;
        this->number = number;
    }

    int perimeter() {
        return side_len * number;
    }

    void display() {
        cout << number << " " << perimeter() << endl;
    }

private:
    int side_len;
};

int main() {
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int type = 0;
        cin >> type;
        switch (type) {
            case 0: {
                int j = 0;
                int *arr = new int[100];
                int *original_arr = arr;
                Polygon polygon;
                while (true) {
                    int side = 0;
                    cin >> side;
                    if (side == -1) break;
                    *arr = side;
                    polygon.setSides(arr, j);
                    arr++;
                    j++;
                }
                polygon.setNumber(j);
                polygon.display();
                delete[] original_arr;
                break;
            }
            case 1: {
                int height, width;
                cin >> height >> width;
                Rectangle rectangle(height, width);
                rectangle.display();
                break;
            }
            case 2: {
                int number, length;
                cin >> number >> length;
                EqualPolygon equal_polygon(length, number);
                equal_polygon.display();
                break;
            }
        }
    }
}
