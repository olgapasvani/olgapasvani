#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person {
    protected:
        long long int ID;
        string name;
        string surname;
        string address;
        string phonenumber;
        string email;
        int age;
    public:
        Person();
        Person(long long int id, string n, string s, string a, string p, string e, int age) : ID(id), name(n), surname(s), address(a), phonenumber(p), email(e), age(age) {
            //cout << "Constructed person 2" << endl;
        }
        virtual ~Person();
        string GetName();
        string GetSurname();
        long long int GetID();
        void SetID();
        void SetID(int id);
        void SetName();
        void SetName(string a);
        void SetSurname();
        void SetSurname(string a);
        void SetAddress();
        void SetAddress(string a);
        void SetPhonenumber();
        void SetPhonenumber(string a);
        void SetEmail();
        void SetEmail(string a);
        void SetAge();
        void SetAge(int a);
        virtual void DisplayDetails(ostream& str) = 0;
        virtual void SetDetails(istream& str) = 0;
};

#endif