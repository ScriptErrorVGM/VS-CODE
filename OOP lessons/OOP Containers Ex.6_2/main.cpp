/*
Описать класс «Клиент банка». При этом считать, что некоторые клиенты обладают
большим приоритетом по отношению к остальным (дети, инвалиды). Для этого в классе
хранить уровень приоритета. Объявить перечисление, включающее четыре уровня
приоритета. Определить для класса операцию сравнения < . Смоделировать поведение
очереди к специалистам с помощью шаблонного класса priority_queue. Программа
должна считывать данные о приходящих клиентах из обычной очереди (шаблонный класс
queue), помещать их в приоритетную очередь и выдавать на консоль информацию о
последовательности работы с клиентами.
*/

#include<iostream>
#include"bank_customer.h"
#include"bank_customer.cpp"
#include<queue>

using namespace std;

int main()
{   
    
    priority_queue<BankCustomer> Prior;
    queue<BankCustomer> inQueue;

    
    inQueue.push(BankCustomer("Maddy", BankCustomer::bankPrior::business));
    inQueue.push(BankCustomer("Susi", BankCustomer::bankPrior::child));
    inQueue.push(BankCustomer("Paul", BankCustomer::bankPrior::aged));
    inQueue.push(BankCustomer("Matt", BankCustomer::bankPrior::business));
    inQueue.push(BankCustomer("Chris", BankCustomer::bankPrior::invalid));
    inQueue.push(BankCustomer("Kate", BankCustomer::bankPrior::business));

    priority_queue<BankCustomer> ls ;
    
    while (!inQueue.empty())
    {
        BankCustomer temp = BankCustomer(inQueue.front());
        inQueue.pop();
        ls.push(temp);
    }

    while (!ls.empty())
    {
        ls.top().info();
        ls.pop();
    }

    cout << ls.size() << endl;


}