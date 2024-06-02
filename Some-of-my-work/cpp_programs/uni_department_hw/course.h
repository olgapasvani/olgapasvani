#ifndef COURSE_H
#define COURSE_H

#include "secretary.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Professor;

class Course {
        vector<Professor*> ProfessorsInCourse;
        string name;
        int ECTS;
        bool type;
        int semester;
    public:
        Course();
        Course(string n, int e, int t, int s) : name(n), ECTS(e), type(t), semester(s) {
            //cout << "Constructed course 2" << endl;
        }
        ~Course();
        Professor GetProfessor();
        Professor GetAnyProfessor(int i);
        int AmountProfessorsInCourse();
        void InsertProfessor(Professor* p);
        void DeleteProfessor();
        void SetName();
        void SetName(string a);
        void SetECTS();
        void SetECTS(int a);
        void SetType();
        void SetType(bool a);
        void SetSemester();
        void SetSemester(int a);
        int GetSemester();
        string GetName();
        bool GetType();
        int GetECTS();
        void PrintName();
        friend istream &operator>>(istream &str, Course &obj);
        friend ostream& operator<<(ostream& str, Course& obj);
};


class CS
{
    bool CurrentSemester;
public:
    CS();
    CS(Secretary& s, int i);
    ~CS();
    bool SetCurrentSemester(int i);
};
#endif