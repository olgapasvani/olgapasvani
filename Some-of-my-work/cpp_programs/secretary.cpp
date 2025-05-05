#include "secretary.h"

//Constructors
Secretary::Secretary(){
    PersObj = Person();
    PeopleData.push_back(&PersObj);
}

Secretary::Secretary(vector<Person*> newVector){
    PeopleData = newVector;
}
//Destructor
Secretary::~Secretary(){
    PeopleData.clear();
}

//Copy constructor
Secretary::Secretary(const Secretary &s){
    PeopleData = s.PeopleData;
}

bool Secretary::FindPerson(string id){
    for(int i=0; i<PeopleData.size(); ++i){
        if (PeopleData[i]->getAcID() == id)
        {
            return true;
        }
    }
    return false;
}

// Overloading output operator
ostream &operator<<(ostream &str, Secretary &obj){
    int sizeVector = obj.PeopleData.size();
    Person *person;
    for(int i = 0; i <=sizeVector -1; i++){
        person = obj.PeopleData[i];
        str << *person<< endl;
    }
    return str;
}

// Overloading input operator
istream &operator>>(istream &str, Secretary &obj){
    string stop;
    do{
        cout <<"Give me a person's data"<<endl;
        Person* newPerson = new Person();
        str >> *newPerson;
        obj.PeopleData.push_back(newPerson);
        cout << "If you want to add another person's data press the M, if you are done press S"<<endl;
        cin >> stop;
        while(stop!="M" && stop!="m" && stop!="S" && stop!="s")
        {
            cout<<"Press the M or the S key"<<endl;
            cin>>stop;
        }
    }while(stop == "M" || stop =="m");
    

    return str;
}

// Overloading addition operator
Secretary& Secretary::operator+(Person *person){
    PeopleData.push_back(person);
    return *this;
}

// Overloading assignment operator
Secretary Secretary::operator=(const Secretary &op2){
    PeopleData = op2.PeopleData;
    return *this;
}
