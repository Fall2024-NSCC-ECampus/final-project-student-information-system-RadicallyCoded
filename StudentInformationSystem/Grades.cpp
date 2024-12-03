//
// Created by Rebecca DeLorey on 2024-11-22.
//

#include <limits>
#include <fstream>
#include <algorithm>
#include <cmath>
#include "menus.h"
#include "Student.h"
#include "Grades.h"

using namespace std;

// Global variables
int midtermOneWeight;
int midtermTwoWeight;
int finalWeight;

vector<Weight> weights;
Weight weight;

// Saves grade scheme file to vector
bool readSchemeFile(vector<Weight> &) {

    ifstream file("grade-scheme.txt");

    if (file.fail()) {
        return false;
    } else {

        while (file >> weight.midtermOneWeight >> weight.midtermTwoWeight >> weight.finalWeight) {
            weights.assign(weights.begin(), weights.end());
        }

        file.close();
        return true;
    }
}

// Loads the grade-scheme.txt file information to the vector on program start
void loadWeightVector() {

    try {
        if (!readSchemeFile(weights)) {
            throw runtime_error("Grade Scheme file does not exist.**");
        }
    }
    catch (exception &e) {
        cout << "\n**Error: " << e.what() << endl;
        start();
    }
}

void gradingScheme() {

    try {
        cout << "\n";
        cout << "Weight of Midterm 1: ";
        cin >> midtermOneWeight;

        cout << "Weight of Midterm 2: ";
        cin >> midtermTwoWeight;

        cout << "Weight of Final: ";
        cin >> finalWeight;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            throw runtime_error("Invalid input. Please enter a number.**");
        }
        if ((midtermOneWeight + midtermTwoWeight + finalWeight) != 100) {
            throw runtime_error("Total weight must equal 100.**");
        }

        ofstream file;
        file.open("grade-scheme.txt");
        if (!file.is_open()) {
            throw runtime_error("Could not open file.**");
        }
        file << midtermOneWeight << endl << midtermTwoWeight << endl << finalWeight;
        file.close();
        loadWeightVector();
    }
    catch (exception &e) {
        cout << "\n**Error: " << e.what() << endl;
        cin.clear();
        changeGradeScheme();
    }

    cout << "\n";
    cout << "Grade Scheme successfully changed!" << endl;

    start();
}

// Creates default txt file if it does not exist
void checkGradingScheme() {

    ofstream file;
    fopen("grade-scheme.txt", "x");

    if (!file.is_open()) {
        file << (midtermOneWeight = 25) << endl << (midtermTwoWeight = 25) << endl << (finalWeight = 50);
    }
    file.close();
}

void calculateLetterGrade() {

    sort(students.begin(), students.end(), byStudentId());

    for (auto& s : students) {

        // Divides the grade scheme to a decimal point for calculation
        double midtermOneWeightDecimal = weight.midtermOneWeight / 100;
        double midtermTwoWeightDecimal = weight.midtermTwoWeight / 100;
        double finalWeightDecimal = weight.finalWeight / 100;
        // Total grade calculation. Rounds to the nearest integer
        double totalGrade = round((s.gradeMidtermOne * midtermOneWeightDecimal) +
                                  (s.gradeMidtermTwo * midtermTwoWeightDecimal) +
                                  (s.gradeFinal * finalWeightDecimal));
        string letterGrade;

        // Gets letter grade from total calculated grade
        if (totalGrade >= 90 && totalGrade <= 100) {
            letterGrade = "A";
        } else if (totalGrade >= 80 && totalGrade <= 89) {
            letterGrade = "B";
        } else if (totalGrade >= 70 && totalGrade <= 79) {
            letterGrade = "C";
        } else if (totalGrade >= 60 && totalGrade <= 69) {
            letterGrade = "D";
        } else {
            letterGrade = "F";
        }

        cout << "\n";
        cout << "Student ID: " << s.studentId << endl;
        cout << "Name: " << s.firstName << " ";
        cout << s.lastName << endl;
        cout << "Total grade: " << totalGrade << "%" << endl;
        cout << "Letter grade: " << letterGrade << endl;
    }

    startOrExit();
}

void changeGradeScheme() {
    char schemeInput;

    ifstream inFile("grade-scheme.txt");
    inFile >> midtermOneWeight >> midtermTwoWeight >> finalWeight;

    cout << "\n";
    cout << "The following grading scheme is used for calculating the letter Grades:" << endl;
    cout << "Midterm 1: " << midtermOneWeight << "%" << endl;
    cout << "Midterm 2: " << midtermTwoWeight << "%" << endl;
    cout << "Final: " << finalWeight << "%" << endl;
    cout << "Do you want to change the grading scheme? (y/n)" << endl;
    cout << "> ";
    cin >> schemeInput;

    inFile.close();

    try {
        if (schemeInput == 'Y' || schemeInput == 'y') {
            gradingScheme();
        } else if (schemeInput == 'N' || schemeInput == 'n') {
            start();
        } else {
            cin.clear();

            throw runtime_error("Invalid input. Please enter Y or N.**");
        }
    }
    catch (exception &e) {
        cout << "\n**Error: " << e.what() << "\n" << endl;
        cin.clear();
        changeGradeScheme();
    }
}