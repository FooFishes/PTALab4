#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Date {
public:
    Date(int year, int month, int day)
        : year(year), month(month), day(day) {
    }

protected:
    int year;
    int month;
    int day;
};

class Time {
public:
    Time(int hour, int minute, int second)
        : hour(hour), minute(minute), second(second) {
    }

protected:
    int hour;
    int minute;
    int second;
};

class Schedule : public Date, Time {
public:
    Schedule(int id, int year, int month, int day, int hour, int minute, int second)
        : Date(year, month, day), Time(hour, minute, second), ID(id) {
    }

    int ID;

    void display() {
        char slash = '/';
        char mh = ':';
        cout << year << slash << month << slash << day << " " << hour << mh << minute << mh << second;
    }

    bool operator<(const Schedule &s2) const {
        if (this->year != s2.year) {
            return this->year < s2.year;
        }
        if (this->month != s2.month) {
            return this->month < s2.month;
        }
        if (this->day != s2.day) {
            return this->day < s2.day;
        }
        if (this->hour != s2.hour) {
            return this->hour < s2.hour;
        }
        if (this->minute != s2.minute) {
            return this->minute < s2.minute;
        }
        if (this->second != s2.second) {
            return this->second < s2.second;
        }
    }
};


int main() {
    int id, y, m, d, h, min, s;
    char slash = '/';
    char mh = ':';
    vector<Schedule> schedules;
    while (true) {
        cin >> id;
        if (id == 0) break;
        cin >> y >> slash >> m >> slash >> d >> h >> mh >> min >> mh >> s;
        Schedule schedule(id, y, m, d, h, min, s);
        schedules.push_back(schedule);
    }
    sort(begin(schedules), end(schedules), [](const Schedule &a, const Schedule &b) {
        return a < b;
    });
    cout << "The urgent schedule is No." << schedules[0].ID << ": ";
    schedules[0].display();
}
