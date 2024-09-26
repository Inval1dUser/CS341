//Pledge: all work in this file is my own and is not the work of somebody else

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Student.h"
#include <iomanip>

using namespace std;

int main() {

    cout << "<============= Welcome to the #1 GPA Calculator =============>" << endl;

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

            string id, gradePointsStr, creditHoursStr;

            //Find the first space
            size_t firstSpace = line.find(' ');
            id = line.substr(0, firstSpace); // Extract ID from the beginning to the first space

            //Find the second space
            size_t secondSpace = line.find(' ', firstSpace + 1); 
            gradePointsStr = line.substr(firstSpace + 1, secondSpace - firstSpace - 1); 

            //Extract credit hours (everything after the second space)
            creditHoursStr = line.substr(secondSpace + 1);

        //end of parsing

            int gradePoints = stoi(gradePointsStr);
            int creditHours = stoi(creditHoursStr);

            double gpa = static_cast<double>(gradePoints) / creditHours; //todo: find a way to do this using methods

            //TODO: figure out assigning letter grades

            char letterGrade;

            /*
                 _._     _,-'""`-._
                (,-.`._,'(       |\`-/|
                    `-.-' \ )-`( , o o)
                        `-    \ `_ `"'- - cat
            */
           
            //assign letter grade 
            if (gpa >= 4.0) letterGrade = 'A';                                              
            else if (gpa >= 3.0) letterGrade = 'B';
            else if (gpa >= 2.0) letterGrade = 'C';
            else if (gpa >= 1.0) letterGrade = 'D';
            else letterGrade = 'F';

            
            Student* student = new Student(id, gradePoints, creditHours, gpa, letterGrade);
            //student->printInfo();

            //add object to list to be sorted
            students.push_back(*student);
            student->~Student();
        }

        myfile.close();
        
        //bubble sort implimentation
        for (int i = 0; i < 30 - 1; i++) 
        {
            for (int j = 0; j < 30 - i - 1; j++)
            {
                if(students[j].getGPA() < students[j + 1].getGPA()) {
                    swap(students[j], students[j + 1]);
                }
            }
        }
        
        //setting GPA precision to 3
        for (int i = 0; i < 30; i++)
        {
            students[i].getGPA();
            cout << setprecision(3);
        } 
        
        //printing out the organized list 
        for (int i = 0; i < 30; i++) students[i].printInfo();

        
    } else {
        cout << "Unable to open file." << endl;
        return 1;
    }

    return 0;
}