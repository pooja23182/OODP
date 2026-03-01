#include <iostream>
#include <string>
using namespace std;

class StudentRecord {
    int roll;
    string name;
    int* marks; // Dynamic array

public:
    // Parameterized Constructor
    StudentRecord(int r, string n, int m1, int m2, int m3) : roll(r), name(n) {
        marks = new int[3]{m1, m2, m3};
    }

    // Copy Constructor (Deep Copy)
    StudentRecord(const StudentRecord &s) {
        roll = s.roll;
        name = s.name;
        marks = new int[3]; // Allocate new memory
        for(int i=0; i<3; i++) marks[i] = s.marks[i];
    }

    // Destructor
    ~StudentRecord() { delete[] marks; }

    void modify(int m1, int m2, int m3) {
        marks[0] = m1; marks[1] = m2; marks[2] = m3;
    }

    void show() {
        cout << name << " (Roll " << roll << "): " 
             << marks[0] << ", " << marks[1] << ", " << marks[2] << endl;
    }
};

int main() {
    StudentRecord s1(101, "Alice", 80, 85, 90);
    StudentRecord s2 = s1; // Calls Copy Constructor

    s2.modify(100, 100, 100);

    cout << "Original: "; s1.show();
    cout << "Copied  : "; s2.show();
    return 0;
}