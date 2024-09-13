#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

class Student {
private:
    string id;
    int gradePoints;
    int creditHours;
    double gpa;
    char letterGrade;

public:
    Student(string id, int gradePoints, int creditHours, double gpa, char letterGrade);
    ~Student();
    double calculateGPA(int gradePoints, int creditHours);
    char assignLetterGrade(double gpa, char letterGrade);
    void printInfo() const;
 /*   String getID() const;
    int getGradePoints() const;
    int getCreditHours() const;
    double getGPA() const;
    char getLetterGrade() const; */
};

#endif // STUDENT_H