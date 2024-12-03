//
// Created by Rebecca DeLorey on 2024-11-22.
//

#include <limits>
#include "menus.h"
#include "Student.h"
#include "Grades.h"

using namespace std;

// Global variables
int menuInput;

void start() {

    startMenu();

    try {
        switch (menuInput) {
            case 1:
                printAllData();
                break;
            case 2:
                orderAlphabetically();
                break;
            case 3:
                addStudent();
                break;
            case 4:
                calculateLetterGrade();
                break;
            case 5:
                editStudentInfoMenu();
                break;
            case 6:
                printOneStudent();
                break;
            case 7:
                removeStudent();
                break;
            case 8:
                deleteAll();
                break;
            case 9:
                changeGradeScheme();
                break;
            case 10:
                exit();
                break;
            default:
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                throw runtime_error("Invalid input. Please try again.**");
        }
    }
    catch (exception &e) {
        cerr << "\n**Error: " << e.what() << "\n" << endl;
        cin.clear();
        start();
    }
}

void startMenu() {

    cout << "\nPlease enter the number of your selection." << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "1) Print all Student data" << endl;
    cout << "2) Sort the list of students in alphabetical order by last name" << endl;
    cout << "3) Add new student" << endl;
    cout << "4) Calculate the letter grade of all students" << endl;
    cout << "5) Change the information of a specific student" << endl;
    cout << "6) Print the data of a specific student" << endl;
    cout << "7) Remove a student from the list" << endl;
    cout << "8) Delete ALL student data" << endl;
    cout << "9) Change grading scheme" << endl;
    cout << "10) Exit" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "> ";
    cin >> menuInput;
}

void addMoreStudents() {
    char addInput;

    cout << "\nWould you like to add another student? (y/n)" << endl;
    cout << "> ";
    cin >> addInput;

    try {
        if (addInput == 'Y' || addInput == 'y') {
            addStudent();
        } else if (addInput == 'N' || addInput == 'n') {
            start();
        } else {
            cin.clear();

            throw runtime_error("Invalid input. Please enter Y or N.**");
        }
    }
    catch (exception &e) {
        cerr << "\n**Error: " << e.what() << endl;
        cin.clear();
        addMoreStudents();
    }
}

void editAnotherValue() {
    char editInput;

    cout << "\nWould you like to edit another value for this student? (y/n)" << endl;
    cout << "> ";
    cin >> editInput;

    try {
        if (editInput == 'Y' || editInput == 'y') {
            editStudentInfo();
        } else if (editInput == 'N' || editInput == 'n') {
            editMoreStudents();
        } else {
            cin.clear();

            throw runtime_error("Invalid input. Please enter Y or N.**");
        }
    }
    catch (exception &e) {
        cerr << "\n**Error: " << e.what() << endl;
        cin.clear();
        editAnotherValue();
    }
}

void editMoreStudents() {
    char editInput;

    cout << "\nWould you like to edit another student? (y/n)" << endl;
    cout << "> ";
    cin >> editInput;

    try {
        if (editInput == 'Y' || editInput == 'y') {
            editStudentInfoMenu();
        } else if (editInput == 'N' || editInput == 'n') {
            start();
        } else {
            cin.clear();

            throw runtime_error("Invalid input. Please enter Y or N.**");
        }
    }
    catch (exception &e) {
        cout << "\n**Error: " << e.what() << endl;
        cin.clear();
        editMoreStudents();
    }
}

void startOrExit() {
    char exitInput;

    cout << "\nReturn to main menu -> m" << endl;
    cout << "Exit program -> e" << endl;
    cout << "> ";
    cin >> exitInput;

    try {
        if (exitInput == 'M' || exitInput == 'm') {
            start();
        } else if (exitInput == 'E' || exitInput == 'e') {
            exit();
        } else {
            cin.clear();

            throw runtime_error("Invalid input. Please enter M or E.**");
        }
    }
    catch (exception &e) {
        cout << "\n**Error: " << e.what() << "\n" << endl;
        cin.clear();
        startOrExit();
    }
}

void exit() {

    cout << "\nStudent Information Session Ended." << endl;

    exit(0);
}