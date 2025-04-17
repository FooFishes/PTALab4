#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Vehicle {
protected:
    int wheels;
    int weight;

public:
    Vehicle(int wheels, int weight);

    int get_wheels() const { return wheels; }
    int get_weight() const { return weight; }
    double wheel_load() const { return get_weight() * 1.0 / get_wheels(); }

    void print() const;
};

class Car : public Vehicle {
private:
    int passenger_load;

public:
    Car(int wheels, int weight, int p_l);

    int get_passengers() const { return passenger_load; }

    void print() const;
};

class Truck : public Vehicle {
private:
    int passenger_load;
    int payload;

public:
    Truck(int wheels, int weight, int p_l, int payload);

    int get_passengers() const { return passenger_load; }

    double efficiency() const;

    void print() const;
};

Vehicle::Vehicle(int wheels, int weight) {
    this->wheels = wheels;
    this->weight = weight;
}

void Vehicle::print() const {
    cout << "weight " << get_weight() << " Kg and wheels " << get_wheels() << endl;
}

Car::Car(const int wheels, const int weight, int p_l) : Vehicle(wheels, weight) {
    this->passenger_load = p_l;
}

void Car::print() const {
    cout << "passenger_load " << get_passengers() << " weight " << get_weight() << " Kg and wheels " << get_wheels() <<
            endl;
}

Truck::Truck(int wheels, int weight, int p_l, int payload) : Vehicle(wheels, weight) {
    this->passenger_load = p_l;
    this->payload = payload;
}

double Truck::efficiency() const {
    return payload * 1.0 / (payload + weight);
}

void Truck::print() const {
    cout << fixed << setprecision(2);
    cout << "passenger_load " << get_passengers() << " weight " << get_weight() << " Kg wheels " << get_wheels() <<
            " and efficiency " << efficiency() << endl;
}

void printNum(int i) {
    string n[4] = {"st", "nd", "rd", "th"};
    if (i < 4) {
        cout << "The " << i << n[i - 1] << " object is ";
    } else cout << "The " << i << n[3] << " object is ";
}

int main() {
    string obj;
    int id, wheels, weight, p_l, payload;
    int i = 0;
    while (true) {
        cin >> obj;
        if (obj == "-1") break;

        cin >> id >> wheels >> weight;
        i++;
        if (obj == "vehicle") {
            Vehicle vehicle(wheels, weight);
            printNum(i);
            cout << "Vehicle No. " << id << ": ";
            vehicle.print();
        } else if (obj == "car") {
            cin >> p_l;
            Car car(wheels, weight, p_l);
            printNum(i);
            cout << "Car No. " << id << ": ";
            car.print();
        } else if (obj == "truck") {
            cin >> p_l >> payload;
            Truck truck(wheels, weight, p_l, payload);
            printNum(i);
            cout << "Truck No. " << id << ": ";
            truck.print();
        }
    }
}
