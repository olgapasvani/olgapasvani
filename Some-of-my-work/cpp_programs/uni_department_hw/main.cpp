#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "struct.h"
#include "person.h"
#include "professor.h"
#include "course.h"
#include "student.h"
#include "secretary.h"

int main(){
    cout <<"Are you a student or a professor?" << endl;
    cout << "1. Student" << endl;
    cout << "2. Professor" << endl;
    Person *p;
    int choice;
    cin >> choice;
    if (choice == 1){
        cout << "Wellcome student! Please enter your academic data" << endl;
        cout << "Please enter your ID" << endl;
        long long int id;
        cin >> id;
        cin.clear();
        cin.ignore(1000, '\n');
        p = new Student();
        p->SetID(id);
        cout << "Please enter your name" << endl;
        string name;
        cin >> name;
        p->SetName(name);
        cout << "Please enter your surname" << endl;
        cin >> name;
        p->SetSurname(name);
        cout << "Please enter your address" << endl;
        cin >> name;
        p->SetAddress(name);
    }
    else if (choice == 2){
        cout << "Wellcome professor! Please enter your academic data" << endl;
        p = new Professor();
        cout << "Please enter your ID" << endl;
        long long int id;
        cin >> id;
        cin.clear(); // Καθαρίζει το fail state
        cin.ignore(1000, '\n');
        p->SetID(id);
        cout << "Please enter your name" << endl;
        string name;
        cin >> name;
        p->SetName(name);
        cout << "Please enter your surname" << endl;
        cin >> name;
        p->SetSurname(name);
        cout << "Please enter your address" << endl;
        cin >> name;
        p->SetAddress(name);
    }
    else{
        cout << "Invalid choice" << endl;
        return 0;
    }
    cout << "Thank you for your data!" << endl;
    Secretary *secr;
    secr = new Secretary();

    return 0;
}