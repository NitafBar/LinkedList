#include "lab09Node.h"
#include "lab09LinkedList.h"
#include <iostream>

int main (void) {

    LinkedList list;

    list.addBack(1);
    list.printList();

    list.addBack(2);
    list.printList();

    list.addBack(3);
    list.printList();
    
    list.addFront(4);
    list.printList();

    list.deleteFront();
    list.printList();

    list.deleteBack();
    list.printList();

    list.addAt(5,1);
    list.printList();
    
    list.get(1);

    return EXIT_SUCCESS;
}