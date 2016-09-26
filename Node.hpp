/**
    * @file - Node.hpp
    * @Author - Mir Ahmed.
    * @Description- The Node class is created in order to create a linked based list.
    A Node object consists of an item of type char and a pointer of type Node that is
    able to point to the next node when the link based list is created. The member functions
    of the Node class simply returns the sets the data member variables.
    *@Date_Created - 11/12/2015

*/
#ifndef NODE_H
#define NODE_H

class Node
{
private:
    char item;
    Node* next;
public:
    /** default constructor */
    Node();


    /** explicit constructor */
    Node(char newItem, Node* nextNodePtr);


    /** - sets the item inside the Node to newItem
    @param - char newItem - item that is to be inserted to the Node.
    */
    void setItem(const char &newItem);


    /** - sets the item inside the Node to newItem
    @param - Node *nextNodePtr - has the address of the next Node.
    */
    void setNext(Node* nextNodePtr);


    /** @return - returns the item at the from the Node. */
    char getItem() const;


    /** @return - returns the *next(address of the next Node) of the Node. */
    Node* getNext() const;
};


#endif // NODE_H


