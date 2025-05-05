//secretary.h
#include <iostream>
#include "person.h"
#include <vector>
using namespace std;

class Secretary
{
    vector<Person*> PeopleData;
    Person PersObj;
public:
    Secretary();
    Secretary(vector<Person*> newVector);
    ~Secretary();

    friend ostream &operator<<(ostream &str, Secretary &obj);
    friend istream &operator>>(istream &str, Secretary &obj);

    //Copy constructor
    Secretary(const Secretary &s);

    // Overloading addition operator
    Secretary& operator+(Person *person);

    // Overloading assignment operator
    Secretary operator=(const Secretary &op2);

    bool FindPerson(string id);
};

