#include <iostream>
#include <string>
using namespace std;

class BigInt {
private:
    static constexpr int MAX = 100;
    int digits[MAX];
    int length;

public:
    BigInt() {
        for (int & digit : digits) {
            digit = 0;
        }
        length = 1;
    }

    friend istream &operator>>(istream &in, BigInt &num) {
        string s;
        in >> s;
        num.length = s.length();
        for (int i = 0; i < num.length; i++) {
            num.digits[i] = s[num.length - 1 - i] - '0';
        }
        return in;
    }

    friend ostream &operator<<(ostream &out, BigInt &num) {
        for (int i = num.length - 1; i >= 0; i--) {
            out << num.digits[i];
        }
        return out;
    }

    BigInt operator+(const BigInt& other) const {
        BigInt result;
        int carry = 0;
        int maxLen = max(length, other.length);

        for (int i = 0; i < maxLen || carry; i++) {
            int sum = carry;
            if (i < length) sum += digits[i];
            if (i < other.length) sum += other.digits[i];

            result.digits[i] = sum % 10;
            carry = sum / 10;
            result.length = i + 1;
        }

        return result;
    }
};

int main() {
    BigInt a, b, c;
    cin >> a >> b;
    c = a + b;
    cout << a << "+" << b << "=" << c << endl;
    return 0;
}
