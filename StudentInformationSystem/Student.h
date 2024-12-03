//
// Created by Rebecca DeLorey on 2024-10-30.
//
#include <iostream>
#include <vector>

using namespace std;

#ifndef STUDENTINFORMATIONSYSTEM_STUDENT_H
#define STUDENTINFORMATIONSYSTEM_STUDENT_H

void printAllData();
void orderAlphabetically();
void addStudent();
void editStudentInfo();
void printOneStudent();
void removeStudent();
void deleteAll();
void loadStudentVector();
void editStudentInfoMenu();

struct Student {
    int studentId;
    string firstName;
    string lastName;
    int gradeMidtermOne;
    int gradeMidtermTwo;
    int gradeFinal;
};
extern vector<Student> students;
extern Student student;

// Called by the orderAlphabetically() function to sort by last name
struct byLastName {
    bool operator()(const Student& a, const Student& b) const {
        if (a.lastName == b.lastName) {
            return a.firstName < b.firstName;
        } else {
            return a.lastName < b.lastName;
        }
    }
};

// Called by the printAllData() function to sort by student ID
struct byStudentId {
    bool operator()(const Student& a, const Student& b) const {
        return a.studentId < b.studentId;
    }
};


#endif //STUDENTINFORMATIONSYSTEM_STUDENT_H
