#ifndef LAB09LINKEDLIST_H
#define LAB09LINKEDLIST_H

#include "lab09Node.h"
#include <limits>
#include <memory>

class LinkedList {
public:
   LinkedList();
   ~LinkedList();
   
   int size();
   void clear();
   int get(int i);
   
   void printList();

   void addFront(int data);
   void addBack(int data);
   void addAt(int data, int index);
   
   void deleteFront();
   void deleteBack();
   void deleteAt(int index);

private:
   std::shared_ptr<Node> head;
   int get(std::shared_ptr<Node> node, int i);
};

#endif // LAB09LINKEDLIST_H