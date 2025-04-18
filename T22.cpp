#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>
class Person;
using namespace std;

bool CompareAll(const Person &a, const Person &b);

class Person {
public:
    Person(const int room, string name, const int height, const int weight)
        : room(room),
          name(std::move(name)),
          height(height),
          weight(weight) {
    }

    int getRoom() const {
        return room;
    }

    int getHeight() const {
        return height;
    }

    void display() const {
        cout << setw(6) << setfill('0') << right << room
                << " " << name << " " << height << " " << weight
                << endl;;
    }

private:
    int room;
    string name;
    int height;
    int weight;
};

int main() {
    int n;
    cin >> n;
    vector<Person> persons;
    int r, h, w;
    string name;
    for (int i = 0; i < n; i++) {
        cin >> r >> name >> h >> w;
        Person person(r, name, h, w);
        persons.push_back(person);
    }
    sort(begin(persons), end(persons), CompareAll);
    vector<Person> selected_persons;
    int num = persons[0].getRoom();
    selected_persons.push_back(persons[0]);
    for (int i = 1; i < n; i++) {
        if (persons[i].getRoom() != num) {
            selected_persons.push_back(persons[i]);
            num = persons[i].getRoom();
        }
    }
    for (const Person &person: selected_persons) {
        person.display();
    }
}

bool CompareAll(const Person &a, const Person &b) {
    if (a.getRoom() != b.getRoom()) {
        return a.getRoom() < b.getRoom();
    }
    return a.getHeight() > b.getHeight();
}
