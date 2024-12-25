/****
Name: Tahsan Ul Alam
Date: 12/13/2024

Description: Implemented a doubly linked list with two classes, Node and MyList.
****/

#include <iostream>

#include "Node.h"
#include "MyList.h"

int main()
{
    //testing list
    MyList A;
    A.insert(4);
    A.insert(2);
    A.insert(6);
    A.insert(8);
    A.insert(1);
    A.insert(3);
    A.insert(7);
    A.insert(5);
    A.insert(-1);
    A.insert(20);
    A.remove(3);
    A.remove(-1);
    A.remove(8);
    A.remove(10);
    A.printAscending();
    A.printDescending();
    A.clear();

    std::cout << std::endl;

    MyList B;
    B.remove(9);
    B.insert(3);
    B.insert(1);
    B.insert(5);
    B.insert(4);
    B.printAscending();
    B.printDescending();
    B.remove(3);
    B.remove(1);
    B.printAscending();
    B.printDescending();

    std::cout << std::endl;

    //testing Node
    Node C(3);
    C.print();
    std::cout << "previous: " << C.getPrevious() << std::endl;
    std::cout << "next: " << C.getNext() << std::endl;
    return 0;
}
