#include <iostream>
using namespace std;

enum COLOR { WHITE, RED, BROWN, BLACK, KHAKI };

class Mammal {
public:
    Mammal() = default;

    explicit Mammal(int age) {
        itsAge = age;
    }

    ~Mammal() = default;

    int getAge() const {
        return itsAge;
    }

    void setAge(const int age) {
        itsAge = age;
    }

    int getWeight() const {
        return itsWeight;
    }

    void setWeight(const int weight) {
        itsWeight = weight;
    }

    void speak() const {
        cout << "Mammal is speaking..." << endl;
    }

    void sleep() const {
        cout << "Mammal is sleeping..." << endl;
    }

protected:
    int itsAge{};
    int itsWeight{};
};

class Dog : public Mammal {
public:
    Dog() = default;

    Dog(const int age)
        : Mammal(age),
          age_(age) {
    }

    Dog(const int age, const int weight)
        : Mammal(age),
          age_(age),
          weight_(weight) {
    }

    Dog(const int age, const COLOR color)
        : Mammal(age),
          age_(age),
          color_(color) {
    }

    Dog(const int age, const int weight, const COLOR color)
        : Mammal(age),
          age_(age),
          weight_(weight),
          color_(color) {
    }

    ~Dog() = default;

    COLOR getColor() const {
        return color_;
    }

    void setColor(const COLOR color) {
        color_ = color;
    }

    void WagTail() {
        cout << "The dog is wagging its tail..." << endl;
    }

    int getWeight() {
        return weight_;
    }
private:
    int age_;
    int weight_;
    COLOR color_;
};

int main() {
    Dog Fido;
    Dog Rover(5);
    Dog Buster(6,8);
    Dog Yorkie(3, RED);
    Dog Dobbie(4, 20, KHAKI);
    Fido.speak();
    Rover.WagTail();
    cout << "Yorkie is " << Yorkie.getAge() << " years old." << endl;
    cout << "Dobbie weighs " << Dobbie.getWeight() << " pounds." << endl;
    return 0;
}