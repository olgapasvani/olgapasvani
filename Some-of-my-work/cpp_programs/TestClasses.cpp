#include "secretary.h"
#include <iostream>
using namespace std;

// Initializing the static member

int main(){
    Person object1 = Person("Nikos", "Papas", "6989784532", "1115202100", 20, "student");;
    cout <<"example:"<<endl;
    cout << object1;
    cout <<"Enter your data"<<endl;

    Secretary obj3 = Secretary(); //we use the constructor that makes an empty object
    cin >> obj3;
    obj3 = obj3 + &object1; //we add another person in the object of the Secretary class
    cout << "Data added with the example's data:"<<endl;
    cout << obj3;
    cout << "Enter an academic ID to check if this person belongs in the class"<<endl;
    string id;
    bool check;
    cin >> id;
    check = obj3.Secretary::FindPerson(id);
    if (check == true)
    {
        cout <<"This Person belongs to the class"<<endl;
    }else
    {
        cout <<"This Person doesn't belong to the class"<<endl;
    }
    //we make a copy of obj3 to obj2 with the copy constructor
    cout << "Here is a copy object of our previous object of the Secret class" <<endl;
    Secretary obj2 = Secretary(obj3);
    cout <<obj2;


    //Person::NumberOfPeople();
    
    
    return 0;
}