/*
Описать класс «Студент». Написать программу моделирования работы студенческого
офиса. Программа должна обеспечивать начальное формирование данных о всех
студентах в университете. Кроме того, программа должна обеспечивать имитацию
отчисления студента: вводится номер студента, программа удаляет данные о нем из
списка учащихся и записывает данные в список отчисленных. Для представления
необходимых списков использовать шаблонный класс map.
*/

#include <iostream>
#include "student.h"
#include "student.cpp"
#include <map>

using namespace std;

int main()
{
    map<string, Student> inStudents;
    map<string, Student> inExpelled;

    inStudents.insert(pair<string, Student>("Timmy", Student("Timmy", "First")));
    inStudents.insert(pair<string, Student>("Tom", Student("Tom", "Second")));
    inStudents.insert(pair<string, Student>("Danny", Student("Danny", "Third")));
    inStudents.insert(pair<string, Student>("Rose", Student("Rose", "Third")));
    inStudents.insert(pair<string, Student>("Lana", Student("Lana", "Fourth")));
    inStudents.insert(pair<string, Student>("Leon", Student("Leon", "Third")));
    inStudents.insert(pair<string, Student>("Marry", Student("Marry", "First")));

    cout << "Input name to expelled student\n";
    std::string studentName;
    cin >> studentName;

    map<string, Student>::iterator studentIterator = inStudents.find(studentName);
    if(studentIterator != inStudents.end())
    {
        inExpelled.insert(pair<string, Student>(studentIterator->first, studentIterator->second));
        inStudents.erase(studentIterator->first);
    }

    cout << "----Students---\n";
    for (map<string, Student>::iterator it = inStudents.begin(); it != inStudents.end(); it++)
    {
        it->second.info();
    }
    cout << "----Expelled----\n";
    for (map<string, Student>::iterator it = inExpelled.begin(); it != inExpelled.end(); it++)
    {
        it->second.info();
    }

    return 0;
}