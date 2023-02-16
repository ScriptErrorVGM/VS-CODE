#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

class Student
{
public:
    std::string studentName;
    std::string studentYear;
    Student();
    Student(std::string studentName, std::string studentYear);
    bool operator < (Student b) const;
    void info() const;
};

#endif // STUDENT_H
