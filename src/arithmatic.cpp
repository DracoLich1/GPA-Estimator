#include "include/arithmatic.hpp"

//
// utility functions
//
bool isInputValid()
{
    if(!std::cin.fail())
    {
        return true;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Nuh uh, Try again.\n";
    return false;
}

bool isInputLogical(int val, int max)
{
    if(val >= 0 && val <= max)
    {
        return true;
    }
    std::cout << "Nuh uh, Try again.\n";
    return false;
}

void roundUp(float& val)
{
    if(val - std::floor(val) > 0)
    {
        val = std::ceil(val);
    }
}

int getGradePoint(int marks)
{
    int y = marks%10;
    int x = marks/10;

    switch(x)
    {
    case 9: return 10;
    case 8: return 9;
    case 7: return 8;
    case 6: return 7;
    case 5: return 6;
    case 4: return (y != 0? 5 : 4); // 5 for (40, 50) and 4 for eggsactly 40
    case 3: case 2: case 1: case 0: return 0; // for marks [0, 40)
    }
    return 10; // when marks are eggsactly 100
}

float getGradePointAverage(float totalGradePoints, int totalCredits)
{
    return totalGradePoints/totalCredits;
}

//
// class functions
//
float Arithmatic::calculateSubjectGradePoints(detailedSubject& subject)
{
    clear();

    std::cout << "----------------------------INPUT SUBJECT MARKS---------------------------\n\n";

    while(true) // mst1 input
    {
        std::cout << "Enter MST1 marks out of 24: ";
        std::cin >> subject.mst1;
        if(!isInputValid()) continue;
        if(!isInputLogical(subject.mst1, 24)) continue;
        roundUp(subject.mst1);
        break;
    }

    while(true) // mst2 input
    {
        std::cout << "Enter MST2 marks out of 24: ";
        std::cin >> subject.mst2;
        if(!isInputValid()) continue;
        if(!isInputLogical(subject.mst2, 24)) continue;
        roundUp(subject.mst2);
        break;
    }

    while(true) // quiz1 input
    {
        std::cout << "Enter Quiz1 marks out of 6: ";
        std::cin >> subject.quiz1;
        if(!isInputValid()) continue;
        if(!isInputLogical(subject.quiz1, 6)) continue;
        roundUp(subject.quiz1);
        break;
    }

    while(true) // quiz2 input
    {
        std::cout << "Enter Quiz2 marks out of 6: ";
        std::cin >> subject.quiz2;
        if(!isInputValid()) continue;
        if(!isInputLogical(subject.quiz2, 6)) continue;
        roundUp(subject.quiz2);
        break;
    }

    while(true) // assignment input
    {
        std::cout << "Enter assignment marks out of 10: ";
        std::cin >> subject.assignment;
        if(!isInputValid()) continue;
        if(!isInputLogical(subject.assignment, 10)) continue;
        roundUp(subject.assignment);
        break;
    }

    while(true) // finals input
    {
        std::cout << "Enter Finals marks out of 60: ";
        std::cin >> subject.finals;
        if(!isInputValid()) continue;
        if(!isInputLogical(subject.finals, 60)) continue;
        roundUp(subject.finals);
        break;
    }

    while(true) // subject credits
    {
        std::cout << "Enter subject credits: ";
        std::cin >> subject.subjectCredits;
        if(!isInputValid()) continue;
        if(subject.subjectCredits < 0)
        {
            std::cout << "Nuh uh, Try again.\n";
            continue;
        }
        break;
    }

    float subjectMarks = subject.getTotal();
    roundUp(subjectMarks);
    float gradePoints = (float)(subject.subjectCredits * getGradePoint((int)subjectMarks));
    return gradePoints;
}

float Arithmatic::calculateSubjectGPA()
{
    detailedSubject subject;
    int totalCredits = 0;
    
    while(true) // total credits
    {
        std::cout << "Enter total credits: ";
        std::cin >> totalCredits;
        if(!isInputValid()) continue;
        if(totalCredits < 0)
        {
            std::cout << "Nuh uh, Try again.\n";
            continue;
        }
        break;
    }

    return calculateSubjectGradePoints(subject) / totalCredits;
}

float Arithmatic::calculateLabGradePoints(detailedLab& lab)
{
    clear();

    while(true) // viva1 input
    {
        std::cout << "Enter Viva1 marks out of 18: ";
        std::cin >> lab.viva1;
        if(!isInputValid()) continue;
        if(!isInputLogical(lab.viva1, 18)) continue;
        roundUp(lab.viva1);
        break;
    }

    while(true) // viva2 input
    {
        std::cout << "Enter Viva2 marks out of 18: ";
        std::cin >> lab.viva2;
        if(!isInputValid()) continue;
        if(!isInputLogical(lab.viva2, 18)) continue;
        roundUp(lab.viva2);
        break;
    }

    while(true) // quiz1 input
    {
        std::cout << "Enter Quiz1 marks out of 9: ";
        std::cin >> lab.quiz1;
        if(!isInputValid()) continue;
        if(!isInputLogical(lab.quiz1, 9)) continue;
        roundUp(lab.quiz1);
        break;
    }

    while(true) // quiz2 input
    {
        std::cout << "Enter Quiz2 marks out of 9: ";
        std::cin >> lab.quiz2;
        if(!isInputValid()) continue;
        if(!isInputLogical(lab.quiz2, 9)) continue;
        roundUp(lab.quiz2);
        break;
    }

    while(true) // file input
    {
        std::cout << "Enter file marks out of 6: ";
        std::cin >> lab.file;
        if(!isInputValid()) continue;
        if(!isInputLogical(lab.file, 6)) continue;
        roundUp(lab.file);
        break;
    }

    while(true) // finals input
    {
        std::cout << "Enter Finals marks out of 40: ";
        std::cin >> lab.finals;
        if(!isInputValid()) continue;
        if(!isInputLogical(lab.finals, 40)) continue;
        roundUp(lab.finals);
        break;
    }

    while(true) // subject credits
    {
        std::cout << "Enter subject credits: ";
        std::cin >> lab.labCredits;
        if(!isInputValid()) continue;
        if(lab.labCredits < 0)
        {
            std::cout << "Nuh uh, Try again.\n";
            continue;
        }
        break;
    }

    float labMarks = lab.getTotal();
    roundUp(labMarks);
    float gradePoints = (float)(lab.labCredits * getGradePoint((int)labMarks));
    return gradePoints;
}

float Arithmatic::calculateLabGPA()
{
    detailedLab lab;
    int totalCredits = 0;

    while(true) // total credits
    {
        std::cout << "Enter total credits: ";
        std::cin >> totalCredits;
        if(!isInputValid()) continue;
        if(totalCredits < 0)
        {
            std::cout << "Nuh uh, Try again.\n";
            continue;
        }
        break;
    }

    return calculateLabGradePoints(lab) / totalCredits;
}

float Arithmatic::calculateTotalGPA()
{
    int theorySize = 0;
    int labSize = 0;
    while(true) // number of theory subjects input
    {
        std::cout << "Enter number of theory subjects: ";
        std::cin >> theorySize;
        if(!isInputValid()) continue;
        break;
    }
    while(true) // number of lab subjects input
    {
        std::cout << "Enter number of lab subjects: ";
        std::cin >> labSize;
        if(!isInputValid()) continue;
        break;
    }
    
    std::vector<detailedSubject> theorySubjects(theorySize);
    std::vector<detailedLab> labSubjects(labSize);

    int totalGradePoints = 0;

    for(detailedSubject& subject : theorySubjects)
    {
        totalGradePoints += calculateSubjectGradePoints(subject);
    }
    for(detailedLab& lab : labSubjects)
    {
        totalGradePoints += calculateLabGradePoints(lab);
    }
    
    int totalCredits = 0;
    while(true) // total credits
    {
        std::cout << "Enter subject credits: ";
        std::cin >> totalCredits;
        if(!isInputValid()) continue;
        if(totalCredits < 0)
        {
            std::cout << "Nuh uh, Try again.\n";
            continue;
        }
        break;
    }

    return (float)totalGradePoints / totalCredits;
    // return getGradePointAverage(totalGradePoints, totalCredits);
}

