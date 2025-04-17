#include <iostream>
using namespace std;

class Time {
public:
    void setTotal(int total) { this->total = total; }

    void getTotal(int total) {
        this->total = total;
    }

    Time(int m = 0, int s = 0): minute(m), second(s) {
        setTotal(minute * 60 + second);
    }

    int operator-(const Time &other) const {
        return (this->total - other.total);
    }

private:
    int minute;
    int second;
    int total;
};

int main() {
    int m1, s1, m2, s2;
    while (true) {
        cin >> m1 >> s1 >> m2 >> s2;
        if (m1 != 0 || m2 != 0 || s1 != 0 || s2 != 0) {
            Time time1(m1, s1);
            Time time2(m2, s2);
            cout << time2 - time1 << endl;
        }
        else break;
    }
}
