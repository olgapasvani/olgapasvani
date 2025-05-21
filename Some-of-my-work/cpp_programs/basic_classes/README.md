# Person & Secretary Management System – C++ OOP Project

This project implements a simple Object-Oriented System in C++ to manage people (students and teachers) and organize them using a Secretary class. It demonstrates key C++ OOP principles such as:

Class Design & Encapsulation

Static Members

Operator Overloading (>>, <<, =, +)

Copy Constructor

Vectors of Pointers

User Input Validation

The program allows the user to:

Input and display personal data

Add people to a list via the Secretary class

Search for a person using their academic ID

Track the number of people created

## Classes
### Person
Represents a single individual (either student or teacher). Includes:

Private fields for name, surname, phone, ID, age, and status

A static variable to count total instances

Constructors (default & parameterized)

Destructor that decrements count and outputs info

Setters & Getters

Input (>>) and output (<<) operator overloads

Assignment operator overload (=)

Also includes validation for the status field to ensure only "student" or "teacher" is accepted.

### Secretary
Manages a dynamic list of Person pointers:

Stores people in a std::vector

Overloads:

>> to add multiple people interactively

<< to print all data

+ to add a person dynamically

Assignment and copy constructors

FindPerson() method searches by academic ID

## How It Works
The main() function showcases:

Creation of a Person object using a parameterized constructor

Instantiation and data entry via the Secretary class

Use of the + operator to add a person

Searching for a person by ID

Copying a Secretary object to test deep/shallow copying

Counting the number of active Person objects

## How to Compile and Run:
g++ -o main person_secr.cpp

./main
