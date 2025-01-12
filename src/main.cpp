#include <iostream>
#include "student.h"
#include "student_manager.h"
#include "sorter.h"
#include "file_manager.h"

using namespace std;

void menu(){
    cout << "\n--- Student Management System ---\n";
    cout << "1. Display All Students\n";
    cout << "2. Add Student\n";
    cout << "3. Update Student\n";
    cout << "4. Remove Student\n";
    cout << "5. Find Student\n";
    cout << "6. Sort Students by Year\n";
    cout << "7. Sort Students by Name\n";
    cout << "8. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    StudentManager manager;
    vector<Student> students;
    const string filename = "students.txt";

    // Load data from file at the start
    loadFromFile(students, filename);
    for (const auto& student : students) {
        manager.addStudent(student);  // Populate the manager's vector with data from file
    }

    int choice;

    do {
        menu();
        cin >> choice;

        switch (choice) {
        case 1:
            manager.displayAll();
            break;

        case 2: {
            string name;
            int year, engGrade, compSciGrade;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter year: ";
            cin >> year;
            cout << "Enter English grade: ";
            cin >> engGrade;
            cout << "Enter CS grade: ";
            cin >> compSciGrade;

            manager.addStudent(Student(name, year, engGrade, compSciGrade));
            saveToFile(manager.getStudents(), filename);
            break;
        }
        
        case 3: {
            string name;
            int year, engGrade, compSciGrade;
            cout << "Enter name to update: ";
            cin >> name;
            cout << "Enter new year: ";
            cin >> year;
            cout << "Enter new English grade: ";
            cin >> engGrade;
            cout << "Enter new CS grade: ";
            cin >> compSciGrade;

            if (manager.updateStudent(name, year, engGrade, compSciGrade)) {
                saveToFile(manager.getStudents(), filename);
            } else {
                cout << "Student not found.\n";
            }
            break;
        }

        case 4: {
            string name;
            cout << "Enter name to remove: ";
            cin >> name;
            if (manager.removeStudent(name)) {
                saveToFile(manager.getStudents(), filename);
            }
            break;
        }

        case 5: {
            string name;
            cout << "Enter name to find: ";
            cin >> name;
            Student* student = manager.findStudent(name);
            if (student) {
                student->display();
            } else {
                cout << "Student not found.\n";
            }
            break;
        }

        case 6: {
            // Sort students by year using mergeSort
            mergeSort(manager.getStudents(), 0, manager.getStudents().size() - 1);
            cout << "Students sorted by year.\n";
            
            // Save the sorted list to the file
            saveToFile(manager.getStudents(), filename);
            break;
        }

        case 7: {
            // Sort students by name using mergeSortByName
            mergeSortByName(manager.getStudents(), 0, manager.getStudents().size() - 1);
            cout << "Students sorted by name.\n";
            
            // Save the sorted list to the file
            saveToFile(manager.getStudents(), filename);
            break;
        }

        case 8:
            cout << "Exiting...\n";
            break;


        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 8);
}
