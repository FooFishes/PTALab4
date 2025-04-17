#include <iostream>
using namespace std;

class Fraction {
public:
    Fraction(int fz = 0, int fm = 1): fz(fz), fm(fm) {
    }

    static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    void simplify() {
        int g = gcd(abs(fz), abs(fm));
        fz /= g;
        fm /= g;
        if (fm < 0) {
            fz = -fz;
            fm = -fm;
        }
    }

    Fraction operator+(const Fraction &other) {
        Fraction result;
        result.fm = abs(this->fm) * abs(other.fm);
        result.fz = this->fz * other.fm + other.fz * this->fm;
        result.simplify();
        return result;
    }

    int getFm() {
        return fm;
    }

    int getFz() {
        return fz;
    }

private:
    int fz; //分子
    int fm; //分母
};

int main() {
    int n;
    cin >> n;
    char z = 'z';
    char m = 'm';
    int fz1, fm1, fz2, fm2;
    for (int i = 0; i < n; i++) {
        cin >> fz1 >> z >> fm1 >> m;
        cin >> fz2 >> z >> fm2 >> m;
        Fraction frac1(fz1, fm1);
        Fraction frac2(fz2, fm2);
        frac1.simplify();
        frac2.simplify();
        Fraction result = frac1 + frac2;
        cout << result.getFz() << z << result.getFm() << m << endl;
    }
}
