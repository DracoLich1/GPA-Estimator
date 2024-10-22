#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include "clearConsole.hpp"

struct detailedSubject
{
    float mst1, mst2;
    float quiz1, quiz2;
    float assignment;
    float finals;
    int subjectCredits;

    detailedSubject(): mst1(0), mst2(0), quiz1(0), quiz2(0), assignment(0), finals(0), subjectCredits(0) {}

    float getTotal()
    {
        return (mst1+mst2)/2 + (quiz1+quiz2)/2 + assignment + finals;
    }
};

struct detailedLab
{
    float viva1, viva2;
    float quiz1, quiz2;
    float file;
    float finals;
    int labCredits;

    detailedLab(): viva1(0), viva2(0), quiz1(0), quiz2(0), file(0), finals(0), labCredits(0) {}

    float getTotal()
    {
        return viva1 + viva2 + quiz1 + quiz2 + file + finals;
    }
};

struct briefSubject
{
    float internal;
    float external;
    int subjectCredits;

    briefSubject(): internal(0), external(0), subjectCredits(0) {}

    float getTotal() { return internal + external; }
};

bool isInputValid();
bool isInputLogical(int val, int max);
void roundUp(float& val);
int getGradePoint(int marks);
float getGradePointAverage(int totalGradePoints, int totalCredits);

class Arithmatic
{
public:
    Arithmatic() {}
    ~Arithmatic() {}

    float calculateSubjectGradePoints(detailedSubject& subject);
    float calculateSubjectGPA();
    float calculateLabGradePoints(detailedLab& lab);
    float calculateLabGPA();
    float calculateTotalGPA();
    float estimateSubject();
    float estimateLab();
    float estimateTotal();
};