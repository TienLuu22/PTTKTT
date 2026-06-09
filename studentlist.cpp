#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef struct {
    string name;
    int mark;
} Student;

int main() {
    vector<Student> L;
    
    Student harry;
    harry.name = "Harry Potter";
    harry.mark = 10;
    L.push_back(harry);

    Student hermione;
    hermione.name = "Hermione Granger";
    hermione.mark = 8;
    L.push_back(hermione);
    
    Student draco;
    draco.name = "Draco Malfoy";
    draco.mark = 7;
    L.push_back(draco);
    
    Student luna;
    luna.name = "Luna Lovegood";
    luna.mark = 8;
    L.push_back(luna);

    Student ron;
    ron.name = "Ron Weasley";
    ron.mark = 9;
    L.push_back(ron);

    
}

