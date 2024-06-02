#ifndef SECRETARY_H
#define SECRETARY_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student;
class Professor;
class Course;

class Secretary {
        vector<Student*> AllStudents;
        vector<Professor*> AllProfessors;
        vector<Course*> AllCourses;
        vector<int> OwnedStudents;
        vector<int> OwnedProfessors;
    public:
        Secretary();
        Secretary(Secretary& s);
        ~Secretary();
        int AmountStudents();
        void setStudent(Student *s);
        Student* GetStudent(int i);
        void setProfessor(Professor *p);
        Professor* GetProfessor(int i);
        void BeginningSemester(bool sem);
        void EndSemester(bool sem, int i);
};

#endif