//
// Created by Rebecca DeLorey on 2024-10-30.
//

#include <fstream>
#include <limits>
#include <algorithm>
#include "Student.h"
#include "menus.h"

// Global variables
int studentId;

vector<Student> students;
Student student;

// Saves student file to vector
bool readStudentFile(vector<Student> &) {

    ifstream file("students.txt");

    if (file.fail()) {
        return false;
    } else {

        while (file >> student.studentId >> student.firstName >> student.lastName >>
                    student.gradeMidtermOne >> student.gradeMidtermTwo >> student.gradeFinal) {
            students.emplace_back(student);
        }
        file.close();
        return true;
    }
}

// Loads the students.txt file information to the vector on program start
void loadStudentVector() {

    try {
        if (!readStudentFile(students)) {
            throw runtime_error("Student list file does not exist. Please add student(s).**");
        }
    }
    catch (exception &e) {
        cout << "\n**Error: " << e.what() << endl;
        start();
    }
}

void printAllData() {

    sort(students.begin(), students.end(), byStudentId());

    for (auto& s : students) {
        cout << "\n";
        cout << "Student ID: " << s.studentId << endl;
        cout << "Name: " << s.firstName << " ";
        cout << s.lastName << endl;
        cout << "Midterm 1: " << s.gradeMidtermOne << endl;
        cout << "Midterm 2: " << s.gradeMidtermTwo << endl;
        cout << "Final: " << s.gradeFinal << endl;
    }

    startOrExit();
}

void orderAlphabetically() {

    sort(students.begin(), students.end(), byLastName());

    for (auto& s : students) {
        cout << "\n";
        cout << "Student ID: " << s.studentId << endl;
        cout << "Name: " << s.firstName << " ";
        cout << s.lastName << endl;
        cout << "Midterm 1: " << s.gradeMidtermOne << endl;
        cout << "Midterm 2: " << s.gradeMidtermTwo << endl;
        cout << "Final: " << s.gradeFinal << endl;
    }

    startOrExit();
}

void addStudent() {

    cout << "\n";
    cout << "Enter a Student ID: ";
    cin >> student.studentId;

    while (true) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input must be a number. Please enter a Student ID: ";
            cin >> student.studentId;
        }
        if (!cin.fail()) {
            break;
        }
    }

    cout << "Enter Student's first name: ";
    cin >> student.firstName;

    cout << "Enter Student's last name: ";
    cin >> student.lastName;

    cout << "Enter Student's midterm 1 grade (0 - 100): ";
    cin >> student.gradeMidtermOne;

    while (true) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input must be a number. Please enter Student's midterm 1 grade: ";
            cin >> student.gradeMidtermOne;
        }
        if (!cin.fail()) {
            break;
        }
    }
    while (student.gradeMidtermOne < 0 || student.gradeMidtermOne > 100) {
        cout << "Grade must be between 0 and 100. Please enter Student's midterm 1 grade: ";
        cin >> student.gradeMidtermOne;
    }

    cout << "Enter Student's midterm 2 grade (0 - 100): ";
    cin >> student.gradeMidtermTwo;

    while (true) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input must be a number. Please enter Student's midterm 2 grade: ";
            cin >> student.gradeMidtermTwo;
        }
        if (!cin.fail()) {
            break;
        }
    }
    while (student.gradeMidtermTwo < 0 || student.gradeMidtermTwo > 100) {
        cout << "Grade must be between 0 and 100. Please enter Student's midterm 2 grade: ";
        cin >> student.gradeMidtermTwo;
    }

    cout << "Enter Student's final grade (0 - 100): ";
    cin >> student.gradeFinal;

    while (true) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input must be a number. Please enter Student's final grade: ";
            cin >> student.gradeFinal;
        }
        if (!cin.fail()) {
            break;
        }
    }
    while (student.gradeFinal < 0 || student.gradeFinal > 100) {
        cout << "Grade must be between 0 and 100. Please enter Student's final grade: ";
        cin >> student.gradeFinal;
    }

    try {
        // Adds student to end of txt file
        ofstream file;
        file.open("students.txt", ios_base::app);

        if (!file.is_open()) {
           throw runtime_error("Unable to open file.**");
        }
        file << student.studentId << " " << student.firstName << " " << student.lastName << " " <<
        student.gradeMidtermOne << " " << student.gradeMidtermTwo << " " << student.gradeFinal << endl;
        file.close();
    }
    catch (exception &e) {
        cout << "\n**Error: " << e.what() << endl;
        start();
    }

    // Adds new student to end of vector
    students.emplace_back(student);

    addMoreStudents();
}

// Global variables for editing student information
int idEditInput, changeMenuInput;

void editStudentInfo() {
    string firstNameReplace;
    string lastNameReplace;
    int gradeMidOneReplace, gradeMidTwoReplace, gradeFinalReplace;

    // Iterator to find the specified student in the vector by student id
    auto iter = find_if(students.begin(), students.end(),
                        [&](Student const & student) {
                            return student.studentId == idEditInput;
                        });

    // Switch statement to edit specific value of specified student using the iterator
    try {
        if (iter != students.end()) {

            cout << "\nWhich value would you like to change? Please enter the number of your selection." << endl;
            cout << "--------------------------------------------------" << endl;
            cout << "1) First name" << endl;
            cout << "2) Last name" << endl;
            cout << "3) Midterm 1 grade" << endl;
            cout << "4) Midterm 2 grade" << endl;
            cout << "5) Final grade" << endl;
            cout << "> ";
            cin >> changeMenuInput;

            switch (changeMenuInput) {
                case 1:
                    cout << "\nEnter new first name: ";
                    cin >> firstNameReplace;
                    iter->firstName = firstNameReplace;
                    break;
                case 2:
                    cout << "\nEnter new last name: ";
                    cin >> lastNameReplace;
                    iter->lastName = lastNameReplace;
                    break;
                case 3:
                    cout << "\nEnter new midterm 1 grade (0 - 100): ";
                    cin >> gradeMidOneReplace;

                    while (gradeMidOneReplace < 0 || gradeMidOneReplace > 100) {
                        cout << "Grade must be between 0 and 100. Please enter Student's midterm 1 grade: ";
                        cin >> gradeMidOneReplace;
                    }
                    iter->gradeMidtermOne = gradeMidOneReplace;
                    break;
                case 4:
                    cout << "\nEnter new midterm 2 grade (0 - 100): ";
                    cin >> gradeMidTwoReplace;

                    while (gradeMidTwoReplace < 0 || gradeMidTwoReplace > 100) {
                        cout << "Grade must be between 0 and 100. Please enter Student's midterm 2 grade: ";
                        cin >> gradeMidTwoReplace;
                    }
                    iter->gradeMidtermTwo = gradeMidTwoReplace;
                    break;
                case 5:
                    cout << "\nEnter new final grade (0 - 100): ";
                    cin >> gradeFinalReplace;

                    while (gradeFinalReplace < 0 || gradeFinalReplace > 100) {
                        cout << "Grade must be between 0 and 100. Please enter Student's final grade: ";
                        cin >> gradeFinalReplace;
                    }
                    iter->gradeFinal = gradeFinalReplace;
                    break;
                default:
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    throw runtime_error("Invalid input. Please try again.**");
            }
        } else {
            throw runtime_error("Student does not exist. Please try again.**");
        }
    }
    catch (exception &e) {
        cout << "\n**Error: " << e.what() << "\n" << endl;
        cin.clear();
        editStudentInfoMenu();
    }

    try {
        // Rewrites the students.txt file with the information from the vector
        ofstream file;
        file.open("students.txt");

        if (file.is_open()) {
            for(const auto &s : students) {
                file << s.studentId << " " << s.firstName << " " << s.lastName << " " <<
                     s.gradeMidtermOne << " " << s.gradeMidtermTwo << " " << s.gradeFinal << endl;
            }
        } else {
            throw runtime_error("Unable to open file.**");
        }
        file.close();
    }
    catch (exception &e) {
        cout << "\n**Error: " << e.what() << endl;
        start();
    }

    cout << "\nStudent information successfully edited!" << endl;

    editAnotherValue();
}

void editStudentInfoMenu() {

    cout << "\nWhich student's information would you like to edit?" << endl;
    cout << "Enter Student ID: ";
    cin >> idEditInput;

    editStudentInfo();
}

void printOneStudent() {

    cout << "\nWhich student's information would you like to view?" << endl;
    cout << "Enter Student ID: ";
    cin >> studentId;

    // Iterator to find the desired student in the vector
    auto iter = find_if(students.begin(), students.end(),
                        [&](Student const & student) {
                            return student.studentId == studentId;
                        });

    try {
        if (iter != students.end()) {
            cout << "\n";
            cout << "Student ID: " << iter->studentId << endl;
            cout << "Name: " << iter->firstName << " ";
            cout << iter->lastName << endl;
            cout << "Midterm 1: " << iter->gradeMidtermOne << endl;
            cout << "Midterm 2: " << iter->gradeMidtermTwo << endl;
            cout << "Final: " << iter->gradeFinal << endl;
        } else {
            throw runtime_error("Student does not exist. Please try again.**");
        }
    }
    catch (exception &e) {
        cout << "\n**Error: " << e.what() << endl;
        cin.clear();
        printOneStudent();
    }

    startOrExit();
}

void removeStudent() {

    cout << "\nWhich student would you like to remove?" << endl;
    cout << "Enter Student ID: ";
    cin >> studentId;

    // Removes the student by ID from the vector
    students.erase(remove_if(students.begin(), students.end(), [](Student const & student) {
        return student.studentId == studentId;
    }), students.end());

    try {
        // Rewrites the students.txt file with the information from the vector
        ofstream file;
        file.open("students.txt");

        if (file.is_open()) {
            for(const auto &s : students) {
                file << s.studentId << " " << s.firstName << " " << s.lastName << " " <<
                     s.gradeMidtermOne << " " << s.gradeMidtermTwo << " " << s.gradeFinal << endl;
            }
        } else {
            throw runtime_error("Unable to open file.**");
        }
        file.close();
    }
    catch (exception &e) {
        cout << "\n**Error: " << e.what() << endl;
        start();
    }

    cout << "\nStudent successfully removed." << endl;

    startOrExit();
}

void deleteAll() {

    students.clear();
    remove("students.txt");

    cout << "\nStudent list successfully deleted." << endl;

    startOrExit();
}