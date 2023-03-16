#include "lab09LinkedList.h"
#include <iostream>
#include <exception>

LinkedList::LinkedList() {
    head = nullptr;
}
LinkedList::~LinkedList() {
    clear();
}
   
int LinkedList::size() {
    
    int length = 0;
    std::shared_ptr<Node> current = head;
    while (current != nullptr) {
        ++length;
        current = current->next;
    }

    return length;
}
void LinkedList::clear() {
    std::shared_ptr<Node> current = head;

    while (current != nullptr) {
        std::shared_ptr<Node> tempNode = current;
        current = current->next;
    }
    
    head = nullptr;    
}

int LinkedList::get(std::shared_ptr<Node> node, int i) {
    int retVal = 0;
    int counter = 0;
    int currentData = std::numeric_limits<int>::min();

    if (node == nullptr) {
        retVal = 0;
    } else if (counter == i) {
        retVal = currentData;
    } else {
        retVal = get(node->next, i);
        counter++;
    }

    return retVal;
}

int LinkedList::get(int i) {
    return get(head, i);

    /* int currentData = std::numeric_limits<int>::min();

    if (i >= 0 && i < size()) {

        int counter = 0;

        std::shared_ptr<Node> current = head;

        while (counter < i) {
            ++counter;
            current = current->next;
        }

        currentData = current->data;
    }
    
    return currentData; */
}

void LinkedList::addFront(int data) {
    std::shared_ptr<Node> n = std::make_shared<Node>(data, nullptr);

    n->next = head;
    head = n;
}

void LinkedList::addBack(int data) {
    std::shared_ptr<Node> n = std::make_shared<Node>(data, nullptr); 

    if (head == nullptr) {
        head = n;
    } else {
        std::shared_ptr<Node> current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = n;
    }

}
   
void LinkedList::deleteFront() {
   
    if (head != nullptr) {
        std::shared_ptr<Node> current = head;
        head = current->next;
    } else {
        throw std::runtime_error("Cannot delete from an empty linked list");
    }
}

void LinkedList::deleteBack() {

    if (head != nullptr) {
        std::shared_ptr<Node> current = head;
        std::shared_ptr<Node> prev = nullptr;
        
        while (current->next != nullptr) {
                prev = current;
                current = current->next;
            }

        if (prev == nullptr) {
            head = nullptr;
        } else {
            prev->next = nullptr;
        }
        
    }
}

void LinkedList::addAt(int data, int index) {
    if (index < 0 || index > size()) {  
        std::cout << "Invalid index" << std::endl;
    } else {      
        std::shared_ptr<Node> n = std::make_shared<Node>(data, nullptr);
        if (head == nullptr) {
            head = n;
        } else {
            std::shared_ptr<Node> current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            
            if (index == 0) {
                n->next = head;
                head = n;
            } else {
                n->next = current->next;
                current->next = n;
            }
        }
    }
    
}

void LinkedList::deleteAt(int index) {
    if (index < 0 || index >= size()) {
        std::cout << "Invalid index" << std::endl;
    } else {
        if (head != nullptr) {
            std::shared_ptr<Node> current = head;
            std::shared_ptr<Node> prev = nullptr;

            for (int i = 0; i < index; ++i) {
                prev = current;
                current = current->next;
            }
            
            if (prev == nullptr) {
                head = current->next;
            } else {
                std::shared_ptr<Node> tempNode = prev;
                prev = current->next;
                tempNode->next = nullptr;
            }
        }
    }
}

void LinkedList::printList() {
    for (int i = size() - 1; i < size(); ++i) {
        std::cout << "head->";
        for (int j = 0; j < i+1; ++j) {
            std::cout << "|" << get(j) << "|";
        }
    std::cout << std::endl;
    }
}