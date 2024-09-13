#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Student.h"
#include <list>

using namespace std;

int main() {
    ifstream myfile("students.txt");

    vector<Student> students; // store Students objects

    if (myfile.is_open()) {
        string line;

        /*
        while loop parses through each line and creates a student object 
        containing all relevent information
        */
        while (getline(myfile, line)) {

        //start of string parsing

            istringstream iss(line);
            string id, gradePointsStr, creditHoursStr;
            getline(iss, id, ' ');
            getline(iss, gradePointsStr, ' ');
            getline(iss, creditHoursStr, ' ');

        //end of parsing

            int gradePoints = stoi(gradePointsStr);
            int creditHours = stoi(creditHoursStr);

            double gpa = (double)(gradePoints/creditHours); //todo: find a way to do this using methods


            char letterGrade;

            if (gpa >= 4.0) letterGrade = 'A';
            else if (gpa >= 3.0) letterGrade = 'B';
            else if (gpa >= 2.0) letterGrade = 'C';
            else if (gpa >= 1.0) letterGrade = 'D';
            else letterGrade = 'F';

            
            Student* student = new Student(id, gradePoints, creditHours, gpa, letterGrade);
            student->printInfo();

            //add object to list to be sorted
            students.push_back(*student);
            student->~Student();
        }
        myfile.close();
        

    } else {
        cout << "Unable to open file." << endl;
    }

    return 0;
}