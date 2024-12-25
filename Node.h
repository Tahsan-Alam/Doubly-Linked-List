//
// Created by taalam on 12/10/2024.
//

#ifndef NODE_H
#define NODE_H

class Node
{
public:
    //Constructor with default values
    Node(const int data = 0, Node *next = nullptr, Node *previous = nullptr);

    void setData(const int data); // setter for data
    int getData() const; //getter for data
    void setNext(Node *next); //setter for next
    Node *getNext() const; //getter for next
    void setPrevious(Node *previous); //setter for previous
    Node *getPrevious() const; //getter for previous
    void print() const; //print
private:
    int data; //integer value
    Node *next; //pointer to point to the next data in the list
    Node *previous; //pointer to point to the previous data in the list
};
#endif //NODE_H
