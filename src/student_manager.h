#include <vector>
#include "student.h"

using namespace std;

//definitions
#ifndef STUDENT_MANAGER_H
#define STUDENT_MANAGER_H


//
class StudentManager {
private:
    vector<Student> students;

public:
    // Add student
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    // Retrieve student by name
    Student* findStudent(const string& name) {
        for (auto& student : students) {
            if (student.getName() == name)
                return &student;
        }
        return nullptr; //Will return an error message if the student is not found, nullptr is a special return that makes the pointer null
    }

    // Update student details
    bool updateStudent(const string& name, int year, int engGrade, int compSciGrade) {
        Student* student = findStudent(name);
        if (student) {
            student->setYear(year);
            student->setEngGrade(engGrade);
            student->setCompSciGrade(compSciGrade);
            return true;
        }
        return false; //Will return an error message if the student is not found
    }

    // Remove student by name
    bool removeStudent(const string& name) {
        for (auto it = students.begin(); it != students.end(); ++it) { //"auto" lets the compiler deduce the type of the element in the vector, which is Student
            if (it->getName() == name) {
                students.erase(it);
                return true;
            }
        }
        return false; // //Will return an error message if the student is not found
    }

    // Display all studentsthat have been created
    void displayAll() const {
        cout << "Displaying All Students:\n";
        cout << "=========================\n";
        for (const auto& student : students) {
            student.display();
            cout << "\n";  
    }
}

    // Get all students (needed for sorting)
    vector<Student>& getStudents() { return students; }
};

#endif
