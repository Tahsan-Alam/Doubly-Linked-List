//
// Created by taalam on 12/10/2024.
//

#ifndef MYLIST_H
#define MYLIST_H
#include "Node.h"
class MyList
{
public:
    MyList(); //default constructor
    void printAscending(); //print in ascending order
    void printDescending(); //print in reverse order
    void insert(int value); //insert a node in the list
    void remove(int value); //remove a node from the list
    void clear(); //delete each node from the list
    ~MyList(); //destructor
private:
    Node *current; //pointer to point to the current node to traverse the list
};
#endif //MYLIST_H
