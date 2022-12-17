#include "student.h"

Student::Student()
{
    studentName = "NO NAME";
    studentYear = "NO YEAR";
}

Student::Student(std::string studentName, std::string studentYear)
{
    this->studentName = studentName;
    this->studentYear = studentYear;
}

bool Student::operator < (Student s) const
{
    return (studentName < s.studentName);
}

void Student::info() const
{
    std::cout << studentName << ", " << studentYear << "\n";
}