#ifndef _PROFESSOR_
#define _PROFESSOR_

#include <iostream>
#include <vector>
#include "person.h"

using namespace std;

class Secretary;
class Course;

class Professor: public Person {
        vector<Course*> TeachingCourses;
        string office;
public:
    Professor();
    Professor(long long int id, string n, string s, string a, string p, string e, int age, string o) : Person(id, n, s, a, p, e, age), office(o) {
        //cout << "Constructed professor 2" << endl;
    }
    ~Professor();

    void MaxGrade(Secretary s);
    void MinGrade(Secretary s);
    void AverageGrade(Secretary s);

    void InsertCourse(Course* c);

    //setters
    void SetOffice();
    void setOffice(string Office);

    int Grades();
    void DisplayDetails(ostream& str);
    void SetDetails(istream& str);
    int GetAmountTeachingCourses();
    void DeleteCourse(int i);
    void print();
};
#endif 
