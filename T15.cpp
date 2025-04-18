#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include <limits>    
using namespace std;

bool compareStringsByLength(const string& a, const string& b) {
    return a.length() < b.length();
}

int main() {
    int n;

    while (cin >> n) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<string> strings; 
        string current_string;

        for (int i = 0; i < n; ++i) {
            if (!getline(cin, current_string)) {
                break;
            }
            if (current_string == "stop") {
                break; 
            }
            strings.push_back(current_string);
        }

        stable_sort(strings.begin(), strings.end(), compareStringsByLength);
        for (const string& s : strings) {
            cout << s << endl;
        }
    }

    return 0;
}