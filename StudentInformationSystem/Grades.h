//
// Created by Rebecca DeLorey on 2024-11-22.
//

#ifndef STUDENTINFORMATIONSYSTEM_GRADES_H
#define STUDENTINFORMATIONSYSTEM_GRADES_H

void gradingScheme();
void calculateLetterGrade();
void changeGradeScheme();
void checkGradingScheme();
void loadWeightVector();

class Grades {

};

struct Weight {
    double midtermOneWeight;
    double midtermTwoWeight;
    double finalWeight;
};
extern vector<Weight> weights;
extern Weight weight;


#endif //STUDENTINFORMATIONSYSTEM_GRADES_H
