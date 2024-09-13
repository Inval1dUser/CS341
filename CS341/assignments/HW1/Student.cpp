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
/*
string Student::getID() const {
    return id;
}

int Student::getGradePoints() const {
    return gradePoints;
}

int Student::getCreditHours() const {
    return creditHours;
}

double Student::getGPA() const {
    return gpa;
}

char Student::getLetterGrade() const {
    return letterGrade;
}
*/