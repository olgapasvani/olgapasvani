#include <iostream>
#include <vector>

using namespace std;

class Person{
private:
    static int count;
    string Name;
    string Surname;
    string PhoneNumber;
    string AcID;
    int Age;
    string Status;
public:
    static void NumberOfPeople();

    //Constructors
    Person(){
        Name = " ";
        Surname = " ";
        PhoneNumber = " ";
        AcID = " ";
        Age = 0;
        Status = " "; 
        count++;
    }

    Person(string name, string surname, string pn, string id, int age, string status)
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
        count++;
    }

    //Destructor
    ~Person(){
        count--;
        //cout << Name <<count<<endl;
    }

    //Setters
    void setName(string name){
        Name = name;
    }
    void setSurname(string surname){
        Surname = surname;
    }
    void setPhoneNumber(string pn){
        PhoneNumber = pn;
    }
    void setAcID(string ID){
        AcID = ID;
    }
    void setAge(int age){
        Age = age;
    }
    void setStatus(string status){
        while (status != "student" && status != "teacher" && status!="Student" && status!="Teacher")
        {
            cout<<"If you are a student enter 'student', if you are a teacher enter 'teacher' "<<endl;
            cin>> status;
            cout<<endl;
        }
        Status = status;
    }

    //Getters
    string getName(){
        return Name;
    }
    string getSurname(){
        return Surname;
    }
    string getPhoneNumber(){
        return PhoneNumber;
    }
    string getAcID(){
        return AcID;
    }
    int getAge(){
        return Age;
    }
    string getStatus(){
        return Status;
    }

    friend ostream &operator<<(ostream &str, Person &obj);
    friend istream &operator>>(istream &str, Person &obj);

    // Overloading assignment operator
    Person operator=(const Person &op2);
};

// Initializing the static member
int Person::count = 0;

void Person::NumberOfPeople(){
    cout<<"Number of people is:"<<count<<endl;
}

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
    cin.clear();
    cin.ignore(100, '\n');
    cout<<endl;
    cout<<"If you are a student enter 'student', if you are a teacher enter 'teacher' "<<endl;
    str >> obj.Status;
    while (obj.Status != "student" && obj.Status != "teacher" && obj.Status!="Student" && obj.Status!="Teacher")
    {
        cout<<"If you are a student enter 'student', if you are a teacher enter 'teacher' "<<endl;
        cin>> obj.Status;
        cout<<endl;
    }
    obj.count++; 
    return str;
}

// Overloading assignment operator
Person Person::operator=(const Person &op2){
    Name = op2.Name;
    Surname = op2.Surname;
    PhoneNumber = op2.PhoneNumber;
    AcID = op2.AcID;
    Age = op2.Age;
    Status = op2.Status;
    return *this;
}


class Secretary
{
    vector<Person*> PeopleData;
    Person PersObj;
public:

    //Constructors
    Secretary(){
        PersObj = Person();
        PeopleData.push_back(&PersObj);
    }

    Secretary(vector<Person*> newVector){
        PeopleData = newVector;
    }
    //Destructor
    ~Secretary(){
        PeopleData.clear();
    }

    // Overloading output and input operators
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

//Copy constructor
Secretary::Secretary(const Secretary &s){
    PeopleData = s.PeopleData;
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

bool Secretary::FindPerson(string id){
    for(int i=0; i<PeopleData.size(); ++i){
        if (PeopleData[i]->getAcID() == id)
        {
            return true;
        }
    }
    return false;
}


int main(){
    Person object1;
    object1 = Person("Nikos", "Papas", "6989784532", "1115202100", 20, "student");
    cout <<"These are a person's data example:"<<endl;
    cout << object1;
    cout <<"Please enter your data"<<endl;

    Secretary obj3;
    obj3 = Secretary(); //we use the constructor that makes an empty object
    cin >> obj3;
    obj3 = obj3 + &object1; //we add another person in the object of the Secretary class
    cout << "Here are your data added with the example's data:"<<endl;
    cout << obj3;
    cout << "Give me an academic ID to check if the person who has it belongs in the class"<<endl;
    //we check the function of o person's existance
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
    Secretary obj2;
    obj2 = Secretary(obj3);
    cout <<obj2;

    Person::NumberOfPeople();
    
    
    return 0;
}




