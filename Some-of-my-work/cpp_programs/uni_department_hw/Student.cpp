#include "student.h"
#include "person.h"
#include "struct.h"
#include "course.h"

Student::Student()
{
    //cout<<"A 'Student' object has been COnstructed"<<endl;
}

Student::~Student()
{
    //cout<<"A 'Student' object has been destructed"<<endl;
}

Course* Student::GetRegisteredCourse(int i) {
    return (RegisteredCourses.at(i).course);
}

void Student::InsertCourse(Course* c) {
    Student_Courses course;
    course.course = c;
    RegisteredCourses.push_back(course);
}


void Student::InsertGrade(Course* c, int grade) {
    for (int i = 0; i < GetAmountRegisteredCourses(); i++) {
        if (RegisteredCourses.at(i).course->GetName() == c->GetName()) {
            RegisteredCourses.at(i).grade = grade;
        } 
    }
}

int Student::GetRegisteredGrade(int i) {
    return RegisteredCourses.at(i).grade;
}


int Student::GetAmountRegisteredCourses() {
    return RegisteredCourses.size();
}

int Student::GetYear() {
    return year;
}

void Student::SetYear() {
    cout << "New year: ";
    cin >> year;
    cout << endl;
}

void Student::Setyear(int a) {
    year = a;
}

void Student::DisplayDetails(ostream& str) {
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
    str << "Year: ";
    str << year;
    str << endl;
    str << endl;
}

void Student::SetDetails(istream& str) {
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
    cout << "Give year: " << endl;
    str >> year;
}

void Student::ShowSemesterGrades(bool sem) {
    for (int i = 0; i < GetAmountRegisteredCourses(); i++) {
        if (RegisteredCourses.at(i).course->GetSemester() == (sem + 1) * year) {
            RegisteredCourses.at(i).course->PrintName();
            cout << ": " << RegisteredCourses.at(i).grade << endl;
        }
    }
}

void Student::ShowAllGrades() {
    for (int i = 1; i <= year; i++) {
        cout << "For year " << i << " we have: " << endl;
        for (int j = 0; j < GetAmountRegisteredCourses(); j++) {
            if ((RegisteredCourses.at(j).course->GetSemester() + 1) / 2 == i) {
                RegisteredCourses.at(j).course->PrintName();
                cout << ": " << RegisteredCourses.at(j).grade << endl;
            }
        }
    }
}

void Student::PrintAllCourses() {
    cout << name << " " << surname << endl;
    for (int i = 0; i < RegisteredCourses.size(); i++) {
        cout << GetRegisteredCourse(i)->GetName() << endl;
    }
}

//Overloading the "<<" operator so it prints all information for one person 
ostream &operator<<(ostream &str, Student &obj) {
    str << obj.ID << endl;
    str << obj.name << endl;
    str << obj.surname << endl;
    str << obj.address << endl;
    str << obj.phonenumber << endl;
    str << obj.email << endl;
    str << obj.age << endl;
    str << obj.year << endl;

    return str;
}
