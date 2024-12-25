//
// Created by taalam on 12/10/2024.
//
#include <iostream>
#include "MyList.h"

MyList::MyList()
{
    current = nullptr; // creating an empty list
}

MyList::~MyList() //destructor
{
    clear(); //calling clear method to remove all nodes from the list
}

//to print each node in ascending order
void MyList::printAscending()
{
    //if the list is empty
    if(current == nullptr)
    {
        std::cout << "List is empty" << std::endl;
        return;
    }

    //moving current to the first Node of the list
    //if previous pointer of current is nullptr then it means
    //this is the first node
    while(current != nullptr && current -> getPrevious() != nullptr)
    {
        current = current ->getPrevious(); //moving from the middle of the list to the first node
    }
    const Node *temp = current; //created a temp pointer to avoid changing current pointer's location
    while(temp != nullptr)
    {
        std::cout << temp -> getData() << " "; //to print each node
        temp = temp -> getNext(); //move to next node
    }
    std::cout << std::endl;
}

//to print each node in descending order
void MyList::printDescending()
{
    //if list is empty
    if(current == nullptr)
    {
        std::cout << "List is empty" << std::endl;
        return;
    }

    //move current to the end of the list
    //if next pointer of current is nullptr then it means
    //this is the last node
    while(current != nullptr && current -> getNext() != nullptr)
    {
        current = current ->getNext(); //move to next pointer
    }
    const Node *temp = current; // temp to prevent changing current pointer's location
    while(temp != nullptr)
    {
        std::cout << temp -> getData() << " "; //print each node
        temp = temp -> getPrevious(); //moves to previous node
    }
    std::cout << std::endl;
}

//to insert a node in the list
void MyList::insert(const int value)
{
    Node *newNode = new Node(); //create a new node
    newNode->setData(value); //set the value of the node

    //case1: list is empty
    if(current == nullptr)
    {
        current = newNode; //newNode is the list
        return;
    }

    //if current pointer pointing to a smaller value
    //than the target value
    if(current -> getData() < value)
    {
        //move current from left to right
        // until current pointing to a data is not greater than the value
        // or next pointer from current is nullptr
        while(current != nullptr && (current -> getData() < value && current -> getNext() != nullptr))
        {
            current = current -> getNext(); //move to next node
        }
    }

    //if current pointer pointing to a larger value
    //than the target value
    else if(current -> getData() > value)
    {
        //move current from right to left
        // until current pointing to a data is not lesser than the value
        // or previous pointer from current is nullptr
        while(current != nullptr && (current -> getData() > value && current -> getPrevious() != nullptr))
        {
            current = current -> getPrevious(); //move to previous node
        }
    }

    //When list has only one node
    if(current -> getPrevious() == nullptr && current -> getNext() == nullptr)
    {
        //case 2: When list has only one node and inserts at the begining
        //if target is lesser than the current pointer data
        // then the node will be inserted before the current pointer
        if(current -> getData() > value)
        {
            // [previous(null) - newNode - next(current)], [previous (newNode) - current - next(null)]
            current -> setPrevious(newNode); //replacing current's previous pointer with newNode
            newNode -> setNext(current); // replacing newNode's next with current
            return;
        }
        //case 3: When list has only one node and inserts at the end
        //[previous(null) - current - next (newNode)],[previous(current) - newNode - next(null)]
        newNode -> setPrevious(current); // replacing newNode's previous with current
        current -> setNext(newNode); //replacing current's next with newNode
        return;
    }

    // case 4: at the begining when list has more than one node
    //current data is greaten than the value
    if(current -> getData() > value)
    {
        //check if this is the first node in the list
        if(current -> getPrevious() == nullptr && current -> getNext() != nullptr)
        {
            // [previous(null) - newNode - next(current)], [previous (newNode) - current - next(....)],[ ....]
            newNode -> setNext(current); //replacing current's previous pointer with newNode
            current -> setPrevious(newNode); // replacing newNode's next with current
            return;
        }
    }

    //case 5: When list has more than one node and inserts at the end
    if(current -> getData() < value)
    {
        //check if current is the last node
        if(current -> getPrevious() != nullptr && current -> getNext() == nullptr)
        {
            //...., [previous(...) - current - next (newNode)], [previous(current) - newNode - next(null)]
            current -> setNext(newNode); //replacing current's next with newNode
            newNode -> setPrevious(current); //replacing newNode's previous with current
            return;
        }
    }

    // case 6: when insertion happens at the middle of the list
    //if current is at the middle of the list and
    //current's value is lesser than the target
    //then move the current to the next node
    //I did this part to do the same type of
    //operations for both cases when current is at the middle
    // of the list and current's value is greater than or less
    //than the target value
    if(current ->getData() < value)
    {
        current = current -> getNext(); // move to next pointer
    }

    //...., [previous(...) - current -> previous - next(newNode)], [previous(current -> previous) - newNode - next(current)], [previous(newNode) - current - next(...)],...
    newNode -> setPrevious(current -> getPrevious()); // replacing newNode's previous with current's previous
    newNode -> setNext(current); //replacing newNode's next with currrent
    current -> getPrevious() -> setNext(newNode); //replacing current -> previous's next with newNode
    current ->setPrevious(newNode); //replacing current's previous with newNode
}

void MyList::remove(const int value)
{
    //case 1: if list is empty
    if(current == nullptr)
    {
        std::cout << "List is empty" << std::endl;
        return;
    }

    //if current's value less than the target
    if(current -> getData() < value)
    {
        //move current from left to right
        //until current's value matches the value
        while(current != nullptr && current -> getData() != value)
        {
            // case 2: if the target is not in the list
            if(current -> getNext() == nullptr)
            {
                std::cout << value << " is not in the list" << std::endl;
                return;
            }
            current = current -> getNext(); //move to next node
        }
    }

    //if current's value greater than the target
    else if(current -> getData() > value)
    {
        //move current from right to left
        //until current's value matches the target
        while(current != nullptr && current -> getData() != value)
        {
            if(current -> getPrevious() == nullptr)
            {
                std::cout << value << " is not in the list" << std::endl;
                return;
            }
            current = current -> getPrevious();
        }
    }
    // case 3: when there is only one node
    if(current -> getPrevious() == nullptr && current -> getNext() == nullptr)
    {
        delete current; //delete the current node
        return;
    }

    //case 4: First node of the list
    if(current -> getPrevious() == nullptr && current -> getNext() != nullptr)
    {
        current -> getNext() -> setPrevious(nullptr); //replace the current next's previous with nullptr
        const Node *temp = current; //temp stores the current pointer's address
        current = current -> getNext(); //moving current to next node so that deleting temp does not delete current
        delete temp; // deleting the target value node
        return;
    }
    // case 5: last node in the list
    if(current -> getNext() == nullptr && current -> getPrevious() != nullptr)
    {
        current -> getPrevious() -> setNext(nullptr); //replace current previous's next with nullptr
        const Node *temp = current; //temp stores the current pointer's address
        current = current -> getPrevious(); //moving current to previous node so that deleting temp does not delete current
        delete temp; //deleting the target value node
        return;
    }

    //case 6: if the node is at the middle of the list
    current -> getPrevious() -> setNext(current -> getNext()); //replace current previous's next with current next
    current -> getNext() -> setPrevious(current -> getPrevious()); //replace current next's previous with current previous
    const Node *temp = current; //temp stores the current pointer's address
    current = current -> getNext(); //moving current to next node so that deleting temp does not delete current
    delete temp; //deleting the target value node
}

void MyList::clear()
{
    //moving current to the first Node of the list
    while(current != nullptr && current -> getPrevious() != nullptr)
    {
        current = current ->getPrevious(); //moving from right to left
    }

    while(current != nullptr)
    {
        const Node *temp = current; //temp stores the current pointer's address
        std::cout<< "Deleted Node: " << temp->getData() << std::endl; //printing the nodes that are deleted
        current = current ->getNext(); //moving current to next node so that deleting temp does not delete current
        delete temp;
    }

}







