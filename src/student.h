//includes
#include <string>
#include <iostream>

//retrieve the std
using namespace std;

//definitions
#ifndef STUDENT_H
#define STUDENT_H


class Student {

public:
    // Constructors
    Student() : name(""), year(0), engGrade(0), compSciGrade(0) {}
    Student( string n, int y, int eng, int comp) 
        : name(n), year(y), engGrade(eng), compSciGrade(comp) {}

    // Getters
    string getName() const { return name; }
    int getYear() const { return year; }
    int getEngGrade() const { return engGrade; }
    int getCompSciGrade() const { return compSciGrade; }

    // Setters
    void setName(const  string& n) { name = n; }
    void setYear(int y) { year = y; }
    void setEngGrade(int g) { engGrade = g; }
    void setCompSciGrade(int g) { compSciGrade = g; }

    // Display function
    void display() const {
         cout << "Name: " << name <<"\n"
                  << "_____________________________________" << "\n"
                  << ", Year: " << year <<"\n"
                  << ", English Grade: " << engGrade <<"\n"
                  << ", CS Grade: " << compSciGrade <<  endl;
    }

private:
    string name;
    int year;
    int engGrade;
    int compSciGrade;

};

#endif
