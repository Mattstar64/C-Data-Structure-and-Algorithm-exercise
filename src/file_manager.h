
#include <vector>
#include "student.h"
#include "file_manager.cpp"

#ifndef FILEMANAGER_H
#define FILEMANAGER_H


void saveToFile(const vector<Student>& students, const string& filename);
void loadFromFile(vector<Student>& students, const string& filename);

#endif
