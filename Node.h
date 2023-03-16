#ifndef NODE_H
#define NODE_H

#include <memory>

class Node {
    public:

    Node(int data, std::shared_ptr<Node> next);
    Node(Node& other);

    int data;
    std::shared_ptr<Node> next;
};

#endif //NODE_H
