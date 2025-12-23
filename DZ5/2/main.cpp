#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Student {
public:
    string name;
    int grade;

    Student(string name, int grade) : name(name), grade(grade) {}

    
    bool operator==(const Student& other) const {
        return name == other.name;
    }

 
    bool operator<(const Student& other) const {
        return grade < other.grade;
    }

    
    bool operator>(const Student& other) const {
        return grade > other.grade;
    }

    
    bool operator<=(const Student& other) const {
        return grade <= other.grade;
    }
};

int main() {
    vector<Student> students = {
        {"Alice", 95},
        {"Bob", 60},
        {"Charlie", 78}
    };

    
    sort(students.begin(), students.end());

    for (const auto& s : students) {
        cout << s.name << " - " << s.grade << endl;
    }

    return 0;
}
