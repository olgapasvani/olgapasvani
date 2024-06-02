#ifndef STRUCTS_H
#define STRUCTS_H

class Course;

typedef struct {
    int MinYears = 4;
    int NumCoreCourses = 2;
    int RequiredECTS = 2;    
}Degree;

typedef struct {
    Course* course;
    int grade;
}Student_Courses;

#endif