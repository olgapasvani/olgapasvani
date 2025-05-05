//File person.h
#ifndef _PERSON_H
#define _PERSON_H

#include <iostream>
using namespace std;

static int count;
class Person{
private:
    //static int count;
    string Name;
    string Surname;
    string PhoneNumber;
    string AcID;
    int Age;
    string Status;
public:
    Person();
    Person(string name, string surname, string pn, string id, int age, string status);
    ~Person();

    //Setters
    void setName(string name);
    void setSurname(string surname);
    void setPhoneNumber(string pn);
    void setAcID(string ID);
    void setAge(int age);
    void setStatus(string status);

    //Getters
    string getName();
    string getSurname();
    string getPhoneNumber();
    string getAcID();
    int getAge();
    string getStatus();

    // Overloading output and input operator
    friend ostream &operator<<(ostream &str, Person &obj);
    friend istream &operator>>(istream &str, Person &obj);

    //Prints how many objects of the class we have in a current brucket
    //static void NumberOfPeople();

    // Overloading assignment operator
   Person operator=(const Person &op2);
};
#endif