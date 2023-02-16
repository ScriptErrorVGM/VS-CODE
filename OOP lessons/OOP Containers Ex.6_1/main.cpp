/*
Определить класс «Книга», данные которого включают название книги, автора и число
страниц. Написать функцию, формирующую по заданному множеству (шаблонный класс
set) объектов класса двустороннюю очередь (шаблонный класс deque) из элементов
множества. В двустороннюю очередь включаются книги определенного автора. 
*/

#include <iostream>
#include "book.h"
#include "book.cpp"

using namespace std;

int main()
{
    Book b1;
    Book b2("Hyperion", "Dan Simmons", 250);
    Book b3("Endimion", "Dan Simmons", 200);
    Book b4("Dune", "Frank Herbert", 500);
    Book b5("I, robot", "Isaak Asimov", 450);
    Book b6("1984", "George Orwell", 317);
  
    std::deque<Book> bookDeque;
    std::set<Book> bookSet;

    bookDeque.push_back(b1);
    bookDeque.push_back(b2);
    bookDeque.push_back(b3);
    bookDeque.push_front(b4);
    bookDeque.push_front(b5);
    bookDeque.push_back(b6);

    for (std::deque<Book>::iterator it = bookDeque.begin(); it != bookDeque.end(); it++)
    {
        it->info();
    }

    std::cout << "----------------" << "\n";

    bookSet = getBooksOfAuthor(bookDeque, "Dan Simmons");

    for (std::set<Book>::iterator it = bookSet.begin(); it != bookSet.end(); it++)
    {
        it->info();
    }


    return 0;
}