/*
Определить класс «Книга», данные которого включают название книги, автора и число
страниц. Написать функцию, формирующую по заданному списку (шаблонный класс list)
объектов класса «Книга» множество (шаблонный класс set) из элементов списка.
В множество включаются книги определенного автора
*/


#include <iostream>
#include "book.h"

using namespace std;

int main()
{
    Book b1;
    Book b2("Hyperion", "Dan Simmons", 250);
    Book b3("Endimion", "Dan Simmons", 200);
    Book b4("Dune", "Frank Herbert", 500);
    Book b5("I, robot", "Isaak Asimov", 450);


    std::list<Book> bookList;
    std::set<Book> bookSet;

    bookList.push_back(b1);
    bookList.push_back(b2);
    bookList.push_back(b3);
    bookList.push_back(b4);
    bookList.push_back(b5);

    for (std::list<Book>::iterator it = bookList.begin(); it != bookList.end(); it++)
    {
        it->info();
    }

    std::cout << "----------------" << "\n";

    bookSet = getBooksOfAuthor(bookList, "Dan Simmons");

    for (std::set<Book>::iterator it = bookSet.begin(); it != bookSet.end(); it++)
    {
        it->info();
    }


    return 0;
}

