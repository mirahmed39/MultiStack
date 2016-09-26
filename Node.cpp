#include "Node.hpp"
#include <cstddef>
#define nullptr 0

Node::Node()
{
    //initially points to nothing(NULL)
    next = nullptr;
}

Node::Node(char newItem, Node* nextNodePtr)
{
    item = newItem;
    next = nextNodePtr;
}

void Node::setItem(const char &newItem)
{
    item = newItem;
}

void Node::setNext(Node* nextNodePtr)
{
    next = nextNodePtr;
}

char Node::getItem() const
{
    return item;
}

Node* Node::getNext() const
{
    return next;
}





