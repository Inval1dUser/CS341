//Pledge: all work in this file is my own and is not the work of somebody else

#include "Student.h"
#include <iostream>
#include <iomanip>  // For GPA formatting
#include <string>

Student::Student(string id, int gradePoints, int creditHours, double gpa, char letterGrade) 
    : id(id), gradePoints(gradePoints), creditHours(creditHours), gpa(gpa), letterGrade(letterGrade) {}

double Student::calculateGPA(int gradePoints, int creditHours) {
    return (double)(gradePoints / creditHours);
}

char Student::assignLetterGrade(double gpa, char letterGrade) {
    if (gpa >= 4.0) letterGrade = 'A';
    else if (gpa >= 3.0) letterGrade = 'B';
    else if (gpa >= 2.0) letterGrade = 'C';
    else if (gpa >= 1.0) letterGrade = 'D';
    else letterGrade = 'F';

    return letterGrade;
}

void Student::printInfo() const {
    cout << id << ": " << gpa << " " << letterGrade << endl;
}

Student::~Student() {}

double Student::getGPA() const {
    return gpa;
}
