#include "student.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

void saveToFile(const vector<Student>& students, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file for writing.\n";
        return;
    }

    for (const auto& student : students) {
        file << student.getName() << "," << student.getYear() << ","
             << student.getEngGrade() << "," << student.getCompSciGrade() << "\n";
    }

    file.close();
    cout << "Data saved to " << filename << endl;
}

void loadFromFile(vector<Student>& students, const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening file for reading: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        istringstream stream(line);
        string name;
        int year, engGrade, csGrade;

        if (getline(stream, name, ',') &&
            (stream >> year) && (stream.ignore(1, ',')) &&
            (stream >> engGrade) && (stream.ignore(1, ',')) &&
            (stream >> csGrade)) {
            
            students.emplace_back(name, year, engGrade, csGrade);
        } else {
            cerr << "Error parsing line: " << line << endl;  // Debugging line
        }
    }

    file.close();
    cout << "Data loaded from " << filename << endl;
}

