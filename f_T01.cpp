#include <iostream>
using namespace std;

template<typename T1, typename T2>
class Point {
public:
    Point(T1 first, T2 second) {
        first_ = first;
        second_ = second;
    }

    T1 getX() const { return first_; }
    T2 getY() const { return second_; }

private:
    T1 first_;
    T2 second_;
};

int main()
{
    Point<int, int> p1(10, 20);
    Point<int, float> p2(10, 20.5f);
    Point<float, float> p3(10.5f, 20.5f);
    Point<double, double > p4(10.5, 20.5);
    cout<<p1.getX()<<","<<p1.getY()<<endl;
    cout<<p2.getX()<<","<<p2.getY()<<endl;
    cout<<p3.getX()<<","<<p3.getY()<<endl;
    cout<<p4.getX()<<","<<p4.getY()<<endl;
    return 0;
}
