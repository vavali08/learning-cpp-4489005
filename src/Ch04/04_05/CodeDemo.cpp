// Learning C++ 
// Challenge 04_05
// Calculate a GPA, by Eduardo Corpeño 

#include <iostream>
#include <vector>
#include "records.h"

int main(){
    float GPA = 0.0f;
    int id;
    
    std::vector<Student> students = {Student(1, "George P. Burdell"),
                                    Student(2, "Nancy Rhodes")};

    std::vector<Course> courses = {Course(1, "Algebra", 5),
                                Course(2, "Physics", 4),
                                Course(3, "English", 3),
                                Course(4, "Economics", 4)};

    std::vector<Grade> grades = {Grade(1, 1, 'B'), Grade(1, 2, 'A'), Grade(1, 3, 'C'),
                                Grade(2, 1, 'A'), Grade(2, 2, 'A'), Grade(2, 4, 'B')};

    std::cout << "Enter a student ID: " << std::flush;
    std::cin >> id;

    // Calculate the GPA for the selected student.
    // Write your code here

    float total_points = 0;
    int total_credits = 0;
    int course_credits;
    int grade_num;

    for (Grade grade : grades) {
    // Instead use for (Grade& grd : grades) to only copy address, not the entire grade. References to objects use thesame syntax as the objects themselves
        if (grade.get_student_id() == id) {
            course_credits = courses[grade.get_course_id() - 1].get_credits();

            switch(grade.get_grade()) {
                case 'A': 
                    grade_num = 4;
                    break;
                case 'B': 
                    grade_num = 3;
                    break;
                case 'C': 
                    grade_num = 2;
                    break;
                case 'D': 
                    grade_num = 1;
                    break;
                case 'F': 
                    grade_num = 0;
                    break;
            }
            total_credits += course_credits;
            total_points += course_credits * grade_num;
                    
        }
    }

    GPA = total_points / total_credits;

    std::string student_str;
    student_str = students[id - 1].get_name(); // Change this to the selected student's name

    std::cout << "The GPA for " << student_str << " is " << GPA << std::endl;
    
    std::cout << std::endl << std::endl;
    return (0);
}
