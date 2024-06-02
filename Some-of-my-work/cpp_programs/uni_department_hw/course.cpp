#include "course.h"
#include "professor.h"

Course::Course() {
   // cout << "Constructed course" << endl;
}

Course::~Course() {
    //cout << "Destructed course" << endl;
}

Professor Course::GetProfessor() {
    return *(ProfessorsInCourse.at(0));
}

Professor Course::GetAnyProfessor(int i) {
    return *ProfessorsInCourse.at(i);
}

int Course::AmountProfessorsInCourse() {
    return ProfessorsInCourse.size();
}

void Course::InsertProfessor(Professor* p) {
    ProfessorsInCourse.push_back(p);
}

void Course::DeleteProfessor() {
    ProfessorsInCourse.erase(ProfessorsInCourse.begin());
}

void Course::SetName() {
    cout << "Name: ";
    cin >> name;
    cout << endl;
}

void Course::SetName(string a) {
    name = a;
}

void Course::SetECTS() {
    cout << "ECTS: ";
    cin >> ECTS;
    cout << endl;
}

void Course::SetECTS(int a) {
    ECTS = a;
}

void Course::SetType() {
    cout << "Type: ";
    cin >> type;
    cout << endl;
}

void Course::SetType(bool a) {
    type = a;
}

void Course::SetSemester() {
    cout << "Semester";
    cin >> semester;
    cout << endl;
}

void Course::SetSemester(int a) {
    semester = a;
}

int Course::GetSemester() {
    return semester;
}

string Course::GetName() {
    return name;
}

bool Course::GetType() {
    return type;
}

int Course::GetECTS() {
    return ECTS;
}

void Course::PrintName() {
    cout << name;
}

istream &operator>>(istream &str, Course &obj) {
    string a;
    cout << "Give name: ";
    str >> obj.name;
    cout << "Give ECTS: ";
    str >> obj.ECTS;
    cout << "Give type: ";
    str >> a;
    if (a == "Mandatory" || a == "mandatory" || a == "MANDATORY") {
        obj.type = true;
    } else {
        obj.type = false;
    }
    cout << "Give semester: ";
    str >> obj.semester;

    return str;
}

ostream& operator<<(ostream& str, Course& obj) {
    str << "Name: ";
    str << obj.name;
    str << endl;
    str << "ECTS: ";
    str << obj.ECTS;
    str << endl;
    str << "Type: ";
    str << obj.type;
    str << endl;
    str << "Semester: ";
    str << obj.semester;
    str << endl;
    str << endl;

    return str;
}


//Συναρτήσεις βοηθητικής κλάσης//////////
CS::CS() {
    cout << "Constructed semester" << endl;
}

CS::CS(Secretary& s, int i) {
    bool WinterOrSpring = SetCurrentSemester(i);

    s.BeginningSemester(WinterOrSpring);
    s.EndSemester(WinterOrSpring, i);
}

CS::~CS() {
    //cout << "The semester is done" << endl;
}

bool CS::SetCurrentSemester(int i) {
    if (i % 2 == 1) {
        CurrentSemester = true;
    }
    else {
        CurrentSemester = false;
    }
    return CurrentSemester;
}