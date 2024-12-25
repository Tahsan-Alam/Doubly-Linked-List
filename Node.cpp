//
// Created by taalam on 12/10/2024.
//
#include <iostream>
#include "Node.h"

Node::Node(const int data, Node *next, Node *previous)
{
    setData(data); //set value for data
    setNext(next); //set next pointer
    setPrevious(previous); //set previous pointer
}

void Node::setData(const int data)
{
    this -> data = data; //set data
}

int Node::getData() const
{
    return data; //return node value
}

void Node::setNext(Node* next)
{
    this -> next = next; //assign the next pointer
}

Node* Node::getNext() const
{
    return next; //return next pointer
}

void Node::setPrevious(Node* previous)
{
    this -> previous = previous; //assign previous pointer
}

Node* Node::getPrevious() const
{
    return previous; //return previous pointer
}

void Node::print() const
{
    std::cout << data << std::endl; //print interger for the node
}


