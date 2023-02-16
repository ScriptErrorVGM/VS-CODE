#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <set>
#include <deque>

class Book
{
public:
    std::string title;
    std::string author;
    int pageNumber;
    Book();
    Book(std::string title, std::string author, int pageNumber);
    void info() const; 
    bool operator < (Book b) const; 
};

std::set<Book> getBooksOfAuthor(std::deque<Book> dequeOfBook, std::string author);

#endif // BOOK_H
