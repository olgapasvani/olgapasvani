#include <fstream>

#include "secretary.h"
#include "student.h"
#include "course.h"
#include "professor.h"
#include "struct.h"
#include "person.h"

using namespace std;

istream &operator>>(istream& str, Person& p);

ostream& operator<<(ostream& str, Person& p);

//Default constructor
Secretary::Secretary() {
    //cout << "Constructed secretary" << endl;
}

//Copy constructor: it creates a new vector that points to the same people as the old one
Secretary::Secretary(Secretary &s) {
    AllCourses = s.AllCourses;
    AllProfessors = s.AllProfessors;
    AllStudents = s.AllStudents;
}

//Destructor
Secretary::~Secretary() {
    for (int i = OwnedStudents.size() - 1; i >= 0; i--) {
        delete AllStudents.at(OwnedStudents[i]);
    }

    for (int i = OwnedProfessors.size() - 1; i >= 0; i--) {
        delete AllProfessors.at(OwnedProfessors[i]);
    }
    //cout<< "Destructed secretary" << endl;
}

int Secretary::AmountStudents() {
    return AllStudents.size();
}

void Secretary::setStudent(Student *s){
    AllStudents.push_back(s);
}

Student* Secretary::GetStudent(int i) {
    return AllStudents.at(i);
}

void Secretary::setProfessor(Professor *p){
    AllProfessors.push_back(p);
}

Professor* Secretary::GetProfessor(int i) {
    return AllProfessors.at(i);
}

void Secretary::BeginningSemester(bool sem) {
    int AmountProfs, WhichProfs, AmountCourses, WhichCourse;

    if (sem == true) {
        for (int i = 0; i < AllProfessors.size(); i++) {
            if (GetProfessor(i)->GetAmountTeachingCourses() == 0) {
            }
            else {
                for (int j = GetProfessor(i)->GetAmountTeachingCourses() - 1; j >= 0; j--) {
                    GetProfessor(i)->DeleteCourse(j);
                }
            }
        }
    }

    for (int i = 0; i < AllCourses.size(); i++) {
        if (AllCourses.at(i)->GetSemester() % 2 == sem) {
            //cout << "For the course " << AllCourses.at(i)->GetName() << " we assigned the following professors:" << endl;
            AmountProfs = (rand() % 2) + 1;
            while (1) {
                WhichProfs = rand() % AllProfessors.size();
                if (AllCourses.at(i)->AmountProfessorsInCourse() == 0) {
                    AllProfessors.at(WhichProfs)->InsertCourse(AllCourses.at(i));
                    AllCourses.at(i)->InsertProfessor(AllProfessors.at(WhichProfs));
                    AmountProfs--;
                    //cout << AllProfessors.at(WhichProfs)->GetName() << " " << AllProfessors.at(WhichProfs)->GetSurname() << endl;
                }
                else {
                    for (int j = 0; j < AllCourses.at(i)->AmountProfessorsInCourse(); j++) {
                        if (AllCourses.at(i)->GetAnyProfessor(j).GetID() == AllProfessors.at(WhichProfs)->GetID()) {
                            break;
                        }
                        if (j == AllCourses.at(i)->AmountProfessorsInCourse() - 1) {
                            AllProfessors.at(WhichProfs)->InsertCourse(AllCourses.at(i));
                            AllCourses.at(i)->InsertProfessor(AllProfessors.at(WhichProfs));
                            AmountProfs--;
                            //cout << AllProfessors.at(WhichProfs)->GetName() << " " << AllProfessors.at(WhichProfs)->GetSurname() << endl;
                            break;
                        }
                    }
                }
                if (AmountProfs == 0) {
                    break;
                }
            }
        }
    }

    for (int i = 0; i < AllStudents.size(); i++) {
        if (AllStudents.at(i)->GetYear() > 4 && AllStudents.at(i)->GetAmountRegisteredCourses() >= AllStudents.at(i)->GetYear() * 4) {
            //cout << "Student " << AllStudents.at(i)->GetName() << " " << AllStudents.at(i)->GetSurname() << " is on his final year he has already registered to his courses" << endl;
            continue;
        }
        if (AllStudents.at(i)->GetAmountRegisteredCourses() >= AllStudents.at(i)->GetYear() * 4) {
            //cout << "Student " << AllStudents.at(i)->GetName() << " " << AllStudents.at(i)->GetSurname() << " is not that old yet" << endl;
            continue;
        }
        else {
            //cout << "Student " << AllStudents.at(i)->GetName() << " " << AllStudents.at(i)->GetSurname() << " registered to the following courses: " << endl;
        }
        //AmountCourses = rand() % 8;
        AmountCourses = 2;
        while (1) {
            WhichCourse = rand() % AllCourses.size();
            if (AllCourses.at(WhichCourse)->GetSemester() % 2 == sem && AllCourses.at(WhichCourse)->GetSemester() <= AllStudents.at(i)->GetYear() * 2) {
                if (AllStudents.at(i)->GetAmountRegisteredCourses() == 0) {
                    AllStudents.at(i)->InsertCourse(AllCourses.at(WhichCourse));              
                    AmountCourses--;
                    //cout << AllCourses.at(WhichCourse)->GetName() << endl;
                }
                else {
                    for (int j = 0; j < AllStudents.at(i)->GetAmountRegisteredCourses(); j++) {
                        if (AllStudents.at(i)->GetRegisteredCourse(j)->GetName() == AllCourses.at(WhichCourse)->GetName()) {
                            break;
                        }
                        if (j == AllStudents.at(i)->GetAmountRegisteredCourses() - 1) {
                            AllStudents.at(i)->InsertCourse(AllCourses.at(WhichCourse));              
                            AmountCourses--;
                            //cout << AllCourses.at(WhichCourse)->GetName() << endl; 
                            break;
                        }
                    }
                }
            }
            if (AmountCourses == 0) {
                break;
            }
        }
    }
}

void Secretary::EndSemester(bool sem, int a) {
    int grade, start = 0;

    if (a == 1) {
        start = 0;
    }
    else {
        for (int i = 0; i < a - 1; i++) {
            start += 2;
        }
    }
    for (int i = 0; i < AllStudents.size(); i++) {
        if (AllStudents.at(i)->GetYear() * 2 < a) {
            continue;
        }
        //cout << "Grades for semester " << a << "  and for student " << AllStudents.at(i)->GetName() << " " << AllStudents.at(i)->GetSurname() << " are:" << endl;
        for (int j = start; j < start + 2; j++) {
            //cout << AllStudents.at(i)->GetRegisteredCourse(j)->GetName() << "->";
            grade = AllStudents.at(i)->GetRegisteredCourse(j)->GetProfessor().Grades();
            AllStudents.at(i)->InsertGrade(AllStudents.at(i)->GetRegisteredCourse(j), grade);
            //cout << AllStudents.at(i)->GetRegisteredGrade(j) << endl;
        }
    }

    for (int i = 0; i < AllCourses.size(); i++) {
        if (AllCourses.at(i)->GetSemester() % 2 == sem) {
            for (int j = AllCourses.at(i)->AmountProfessorsInCourse() - 1; j >= 0; j--) {
                AllCourses.at(i)->DeleteProfessor();
            }
        }
    }

}