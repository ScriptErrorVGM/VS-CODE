#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <set>
#include <list>

class Book
{
public:
    std::string title;
    std::string author;
    int pageNumber;
    Book();
    Book(std::string title, std::string author, int pageNumber);
    void info() const; // для обращения через элемент контейнера set метод должен быть константным
    bool operator < (Book b) const; // для размещения элементов в контейнере set нужно определить оператор <
};

std::set<Book> getBooksOfAuthor(std::list<Book> listOfBook, std::string author);

#endif // BOOK_H
