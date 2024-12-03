#include <iostream>
#include "Student.h"
#include "menus.h"
#include "Grades.h"

using namespace std;

int main() {

    loadStudentVector();
    checkGradingScheme();
    loadWeightVector();

    cout << "\n";
    cout << "Welcome to the Student Information System!" << endl;
    start();

    return 0;
}


