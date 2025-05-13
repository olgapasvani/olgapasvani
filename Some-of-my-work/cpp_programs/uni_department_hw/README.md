# Secretary Management System (C++)

A simple university program management system implemented in C++, simulating the relationships between students, professors, the secretary, and courses.

## Main Components:
The project includes the following classes:

Person (abstract base class)
Student (inherits from Person)
Professor (inherits from Person)
Course (represents a university course)
Secretary (manages students, professors, and courses)
CS (relates to semester control via the secretary)
structs.h (helper structs for grades and degree requirements)

### Person (abstract):

Serves as the abstract base class for Student and Professor.
Fields:
ID, Name, Surname, Age, Email, Phone, Address
Methods:
Virtual DisplayDetails() and SetDetails() for polymorphic behavior

### Student:

A concrete implementation of Person, representing a university student.
Fields:
RegisteredCourses: Courses the student is enrolled in
year: the year of study
Functions:
RegisterToCourses(), InsertCourse(), InsertGrade()
ShowSemesterGrades(), ShowAllGrades(), PrintAllCourses()
Getters for year, grades, etc.

### Professor:
Inherits from Person, represents a university professor.
Fields:
TeachingCourses: List of courses the professor teaches
office: Office location
Functions:
MaxGrade(), MinGrade(), AverageGrade() (student stats via Secretary)
InsertCourse(), DeleteCourse(), Grades()

### Course:
Represents a university course.
Fields:
Name, ECTS, type (core/optional), semester
List of ProfessorsInCourse
Functions:
InsertProfessor(), DeleteProfessor()
Setters/Getters
Stream interaction via overloaded >> and << operators

### Secretary:
Acts as the administrative unit responsible for managing all entities.
Fields:
Lists of AllStudents, AllProfessors, AllCourses
Ownership tracking for each entity
Functions:
setStudent(), setProfessor(), GetStudent(), GetProfessor()
BeginningSemester(), EndSemester() for managing semester phases

### CS:
A small class responsible for tracking the current semester.
Functions:
SetCurrentSemester() which updates the state using the Secretary

### structs.h
Includes:
Student_Courses: Struct connecting a Course* to a grade
Degree: Basic requirements of a degree (ECTS, core courses, etc.)

### main
There is also a main function that demonstrates the functionality of the basic classes.

## How to Compile and Run:
make

./main
