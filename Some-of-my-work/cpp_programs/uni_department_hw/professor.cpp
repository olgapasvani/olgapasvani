#include "professor.h"
#include "secretary.h"
#include "course.h"
#include "student.h"

Professor::Professor()
{
}

Professor::~Professor()
{
}

//setters
void Professor::MaxGrade(Secretary s) {
    int grade, max_grade = -1;
    int WhichStudent;

    for (int k = 0; k < TeachingCourses.size(); k++) {
        for (int i = 0; i < s.AmountStudents(); i++) {
            //cout << "i = " << i << endl;
            for (int j = 0; j < s.GetStudent(i)->GetAmountRegisteredCourses(); j++) {
                if (TeachingCourses.at(k)->GetName() == s.GetStudent(i)->GetRegisteredCourse(j)->GetName()) {
                    //cout << "Is registered\n";
                    grade = s.GetStudent(i)->GetRegisteredGrade(j);
                    if (grade > max_grade) {
                        //cout << grade << endl;
                        max_grade = grade;
                        WhichStudent = i;
                    }
                }
            }
        }
        cout << "For the course: ";
        cout << TeachingCourses.at(k)->GetName() << endl;
        cout << "The hightest score was scored by the student: ";
        cout << s.GetStudent(WhichStudent)->GetName() << " " << s.GetStudent(WhichStudent)->GetSurname() << endl;
        cout << "And it was " << max_grade << endl;
        max_grade = -1;
    }
}

void Professor::MinGrade(Secretary s) {
    int grade, min_grade = 11;
    int WhichStudent;

    for (int k = 0; k < TeachingCourses.size(); k++) {
        for (int i = 0; i < s.AmountStudents(); i++) {
            for (int j = 0; j < s.GetStudent(i)->GetAmountRegisteredCourses(); j++) {
                if (TeachingCourses.at(k)->GetName() == s.GetStudent(i)->GetRegisteredCourse(j)->GetName()) {
                    grade = s.GetStudent(i)->GetRegisteredGrade(j);
                    if (grade < min_grade) {
                        min_grade = grade;
                        WhichStudent = i;
                    }
                }
            }
        }
        cout << "For the course: ";
        cout << TeachingCourses.at(k)->GetName() << endl;
        cout << "The lowest score was scored by the student: ";
        cout << s.GetStudent(WhichStudent)->GetName() << " " << s.GetStudent(WhichStudent)->GetSurname() << endl;
        cout << "And it was " << min_grade << endl;
        min_grade = 11;
    }
}

void Professor::AverageGrade(Secretary s) {
    int average_grade;
    int count = 0;

    for (int k = 0; k < TeachingCourses.size(); k++) {
        average_grade = 0;
        count = 0;
        for (int i = 0; i < s.AmountStudents(); i++) {
            for (int j = 0; j < s.GetStudent(i)->GetAmountRegisteredCourses(); j++) {
                if (TeachingCourses.at(k)->GetName() == s.GetStudent(i)->GetRegisteredCourse(j)->GetName()) {
                    average_grade += s.GetStudent(i)->GetRegisteredGrade(j);
                    count++;
                }
            }
        }
        if (count == 0) {
            cout << "mphka" << endl;
            continue;
        }
        else {
            average_grade /= count;
        }
        cout << "For the course you chose with the following details: ";
        cout << TeachingCourses.at(k)->GetName() << endl;
        cout << "The average score by all students that where redistered to that course was " << average_grade << endl;
    }
}

void Professor::InsertCourse(Course* c) {
    TeachingCourses.push_back(c);
}

int Professor::Grades() {
    return rand() % 11;
}

void Professor::SetOffice() {
    cout << "New office: ";
    cin >> office;
    cout << endl;
}

void Professor::setOffice(string Office){
    office = Office;
}

void Professor::DisplayDetails(ostream& str) {
    str << "ID: ";
    str << ID << endl;
    str << "Name: ";
    str << name << endl;
    str << "Surname: ";
    str << surname << endl;
    str << "Address: ";
    str << address << endl;
    str << "Phone number: ";
    str << phonenumber << endl;
    str << "E-mail: ";
    str << email << endl;
    str << "Age: ";
    str << age << endl;
    str << "Office: ";
    str << office << endl;
    str << endl;
}

void Professor::SetDetails(istream& str) {
    cout << "Give id: ";
    str >> ID;
    cout << "Give first name: ";
    str >> name;
    cout << "Give surename: ";
    str >> surname; 
    cout << "Give address(in Street Num format): ";
    str >> address;
    cout << "Give phone number: ";
    str >> phonenumber;
    cout << "Give email: ";
    str >> email;
    cout << "Give age: ";
    str >> age;
    cout << "Give office: ";
    str >> office;
}

int Professor::GetAmountTeachingCourses() {
    return TeachingCourses.size();
}

void Professor::DeleteCourse(int i) {
    TeachingCourses.erase(TeachingCourses.begin() + i);
}

void Professor::print() {
    cout << "Professor " << name << endl;
    for (int i = 0; i < TeachingCourses.size(); i++) {
        cout << TeachingCourses.at(i)->GetName() << endl;
    }
}