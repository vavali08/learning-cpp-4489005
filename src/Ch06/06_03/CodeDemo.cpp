// Learning C++ 
// Challenge 06_03
// Upgrade to work with files, by Eduardo Corpeño 

#include <iostream>
#include <vector>
#include <fstream>
#include "records.h"

void initialize(StudentRecords&);

int main(){
    int id;
    StudentRecords SR;
    
    initialize(SR);

    std::cout << "Enter a student ID: " << std::flush;
    std::cin >> id;

    SR.report_card(id);
    
    std::cout << std::endl << std::endl;
    return (0);
}

void initialize(StudentRecords& srec){
    std::ifstream inFile;
    std::string str;
    std::string name;
    int sid, cid;
    char grade;
    int credits;

    //Read in students

    inFile.open("students.txt");
    if (inFile.fail())
        return;
    else {
        while(!inFile.eof()) {
            getline(inFile, str);
            sid = stoi(str);
            getline(inFile, name);
            srec.add_student(sid, name);
        }
        inFile.close();
    }


    //Read in courses
    inFile.open("courses.txt");
    if (inFile.fail())
        return;
    else {
        while(!inFile.eof()) {
            getline(inFile, str);
            cid = stoi(str);

            getline(inFile, name);

            getline(inFile, str);
            credits = str[0];
            srec.add_course(cid, name, credits);
            
        }
        inFile.close();
    }

    //Read in grades

    inFile.open("grades.txt");
    if (inFile.fail())
        return;
    else {
        while(!inFile.eof()) {
            getline(inFile, str);
            sid = stoi(str);
            getline(inFile, str);
            cid = stoi(str);
            getline(inFile, str);
            grade = str[0];
            srec.add_grade(sid, cid, grade);
            
        }
        inFile.close();
    }
    
}
