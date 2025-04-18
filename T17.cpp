#include <iostream>
#include <cstring>
using namespace std;

class myString {
public:
    ~myString() {
        cout << "destruct" << endl;
        delete[] buf;
    }

    myString() {
        buf = new char[55];
        buf[0] = '\0';
        cout << "construct 0" << endl;
    }

    explicit myString(const char *str) {
        buf = new char[55];
        strcpy(buf, str);
        cout << "construct 1" << endl;
    }

    myString(const myString &other) {
        buf = new char[55];
        strcpy(buf, other.buf);
    }


    myString &operator=(const myString &other) {
        if (this == &other) { return *this; }
        delete[] buf;
        buf = new char[55];
        strcpy(buf, other.buf);
        if (buf) {
            char temp[55];
            strcpy(temp, buf);
            strcpy(buf, "c++");
            strcat(buf, temp);
        }
        return *this;
    }

    void display() const {
        cout << buf << endl;
    }

private:
    char *buf = nullptr;
};

int main() {
    char *ch = new char[51];
    cin.getline(ch, 51);
    myString str1(ch);
    str1.display();
    myString str2;
    str2 = str1;
    str2.display();
}
