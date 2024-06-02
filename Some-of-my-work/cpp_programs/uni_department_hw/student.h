#ifndef _STUDENT_
#define _STUDENT_

#include <iostream>
#include <string>
#include <vector>

#include "struct.h"
#include "professor.h"

using namespace std;

int SkipSpaces(int CurOffset, string buffer);

//struct Student_Courses;
class Course;

class Student: public Person {
        vector<Student_Courses> RegisteredCourses;
        int year;
    public:
    Student();
    Student(long long int id, string n, string s, string a, string p, string e, int age, int y) : Person(id, n, s, a, p, e, age), year(y) {
            //cout << "Constructed student 2" << endl;
        }
    ~Student();

    void RegisterToCourses();
    Course* GetRegisteredCourse(int i);
    void InsertCourse(Course* c);
    
    void InsertGrade(Course* c, int grade);
    int GetRegisteredGrade(int i);
    int GetAmountRegisteredCourses();

    int GetYear();
    void SetYear();
    void Setyear(int a);

    void DisplayDetails(ostream& str);
    void SetDetails(istream& str);

    void ShowSemesterGrades(bool sem);
    void ShowAllGrades();
    void PrintAllCourses();

    friend ostream &operator<<(ostream &str, Student &obj);
        //friend istream &operator>>(istream &str,Student &obj);
};
#endif