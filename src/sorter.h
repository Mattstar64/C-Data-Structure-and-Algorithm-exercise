// includes
#include <vector>
#include "student.h"

using namespace std;

// definitions
#ifndef SORTER_H
#define SORTER_H


// Merge function for sorting by year
void merge(vector<Student>& students, int left, int mid, int right) {
    vector<Student> temp(right - left + 1);

    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (students[i].getYear() <= students[j].getYear()) {
            temp[k++] = students[i++];
        } else {
            temp[k++] = students[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = students[i++];
    }

    while (j <= right) {
        temp[k++] = students[j++];
    }

    for (int l = 0; l < temp.size(); ++l) {
        students[left + l] = temp[l];
    }
}

// Merge function for sorting by name
void mergeByName(vector<Student>& students, int left, int mid, int right) {
    vector<Student> temp(right - left + 1);

    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (students[i].getName() <= students[j].getName()) {
            temp[k++] = students[i++];
        } else {
            temp[k++] = students[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = students[i++];
    }

    while (j <= right) {
        temp[k++] = students[j++];
    }

    for (int l = 0; l < temp.size(); ++l) {
        students[left + l] = temp[l];
    }
}

// MergeSort function for sorting by year
void mergeSort(vector<Student>& students, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    mergeSort(students, left, mid);
    mergeSort(students, mid + 1, right);
    merge(students, left, mid, right);
}

// MergeSort function for sorting by name
void mergeSortByName(vector<Student>& students, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    mergeSortByName(students, left, mid);
    mergeSortByName(students, mid + 1, right);
    mergeByName(students, left, mid, right);
}

#endif
