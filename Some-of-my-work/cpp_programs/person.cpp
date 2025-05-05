#include "person.h"

//Constructors
Person::Person(){
    Name = " ";
    Surname = " ";
    PhoneNumber = " ";
    AcID = " ";
    Age = 0;
    Status = " ";
    //cout<<"A Person object has been COstructed"<<endl; 
    //count++;
}

Person::Person(string name, string surname, string pn, string id, int age, string status)
{
    Name = name;
    Surname = surname;
    PhoneNumber = pn;
    AcID = id;
    Age = age;
    while (status != "student" && status != "teacher" && status!="Student" && status!="Teacher")
    {
        cout<<"If you are student enter 'student', if you are a teacher enter 'teacher'"<<endl;
        cin>>status;
    }
    Status = status;
    //cout<<"A Person object has been COstructed"<<endl; 
    //count++;
}

//Destructor
Person::~Person(){
    //count--;
    //cout << Name <<count<<endl;
    //cout<<"A Person object has been destructed"<<endl;
}

//Setters
void Person::setName(string name){
    Name = name;
}
void Person::setSurname(string surname){
    Surname = surname;
}
void Person::setPhoneNumber(string pn){
    PhoneNumber = pn;
}
void Person::setAcID(string ID){
    AcID = ID;
}
void Person::setAge(int age){
    Age = age;
}
void Person::setStatus(string status){
    while (status != "student" && status != "teacher" && status!="Student" && status!="Teacher")
    {
        cout<<"If you are student enter 'student', if you are a teacher enter 'teacher'"<<endl;
        cin>>status;
    }
    Status = status;
}

    //Getters
string Person::getName(){
    return Name;
}
string Person::getSurname(){
    return Surname;
}
string Person::getPhoneNumber(){
    return PhoneNumber;
}
string Person::getAcID(){
    return AcID;
}
int Person::getAge(){
    return Age;
}
string Person::getStatus(){
    return Status;
}

/*void Person::NumberOfPeople(){
  cout<<"Number of people is:"<<count<<endl;
}*/

// Overloading output and input operator
ostream &operator<<(ostream &str, Person &obj){
    str << "Name: " << obj.Name<<endl;
    str <<"Surname: " << obj.Surname<<endl;
    str << "ID: " << obj.AcID<<endl;
    str << "Phone number: " << obj.PhoneNumber<<endl;
    str << "Age: " << obj.Age<<endl;
    str << "Status: " << obj.Status <<endl;
    return str;
}

istream &operator>>(istream &str, Person &obj){
    string speciality;
    cout<< "Enter name ";
    str >> obj.Name;
    cout<<endl;
    cout<< "Enter surname ";
    str >> obj.Surname;
    cout<<endl;
    cout<< "Enter phone number ";
    str >> obj.PhoneNumber;
    cout<<endl;
    cout<< "Enter your academic ID ";
    str >> obj.AcID;
    cout<<endl;
    cout<< "Enter your age ";
    str >> obj.Age;
    cout<<endl;
    cout<<"If you are a student enter 'student', if you are a teacher enter 'teacher' "<<endl;
    str >> obj.Status;
    while (obj.Status != "student" && obj.Status != "teacher" && obj.Status!="Student" && obj.Status!="Teacher")
    {
        cout<<"If you are a student enter 'student', if you are a teacher enter 'teacher' "<<endl;
        cin>> obj.Status;
        cout<<endl;
    } 
    return str;
}

Person Person::operator=(const Person &op2){
    Name = op2.Name;
    Surname = op2.Surname;
    PhoneNumber = op2.PhoneNumber;
    AcID = op2.AcID;
    Age = op2.Age;
    Status = op2.Status;

    return *this;
}