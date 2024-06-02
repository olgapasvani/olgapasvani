#include "person.h"

using namespace std;

Person::Person() {
    //cout << "Constructed person" << endl;
}

Person::~Person() {
    //cout << "Destructed person" << endl;
}

void Person::SetID() {
    cout << "New ID: ";
    cin >> ID;
    cout << endl;
}

void Person::SetID(int id) {
    ID = id;
}

void Person::SetName() {
    cout << "New name: ";
    cin >> name;
    cout << endl;
}

void Person::SetName(string a) {
    name = a;
}

void Person::SetSurname() {
    cout << "New surname: ";
    cin >> surname;
    cout << endl;
}

void Person::SetSurname(string a) {
    surname = a;
}

void Person::SetAddress() {
    cout << "New address: ";
    cin >> address;
    cout << endl;
}

void Person::SetAddress(string a) {
    address = a;
}

void Person::SetPhonenumber() {
    cout << "New phone number: ";
    cin >> phonenumber;
    cout << endl;
}

void Person::SetPhonenumber(string a) {
    phonenumber = a;
}

void Person::SetEmail() {
    cout << "New e-mail: ";
    cin >> email;
    cout << endl;
}

void Person::SetEmail(string a) {
    email = a;
}

void Person::SetAge() {
    cout << "New age: ";
    cin >> age;
    cout << endl;
}

void Person::SetAge(int a) {
    age = a;
}

string Person::GetName() {
    return name;
}

string Person::GetSurname() {
    return surname;
}

long long int Person::GetID() {
    return ID;
}