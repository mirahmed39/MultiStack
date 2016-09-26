/**
    * @file - List.hpp
    * @Author - Mir Ahmed.
    * @Description- The list class used Node objects to create a linked list.
    The Node class has a two private member variables. 1) Top, that point to
    the first Node on the linked list. 2) The size tells us number the number
    of Nodes that a list contains.
    *@Date_Created - 11/14/2015

*/
#ifndef LIST_H
#define LIST_H
#include <stdexcept>
#include "Node.hpp"

class List
{
private:
    Node* Top;
    int size;
public:
    /** Default Constructor. */
    List();


    /**- Copy Constructor: copies an instance of list to a list that will be created.
    @pre- anotherList has to be initialized.
    */
    List(const List& anotherList);


    /** Destructor
    @note - the destructor is overridden so that every single
    @param - anotherList - another instance of a list.
    Node in the list gets deleted.*/
    ~List();


    /**- operator Overloading: copies an instance of list to a list that will be
          created.
    @pre- anotherList has to be initialized.
    @return - returns the reference to the current list object.
    */
    List& operator=(const List& anotherList);


    /**- checks if the List is empty or not.t.
    @return - returns true if the list is empty; false otherwise.
    */
    bool isEmpty();


    /** - adds a Node at the beginning of the list.
    @note - adds at the beginning.
    @param - char ch - the item that is to be added inside the Node.
    @post - the size of the list increases by 1.
    */
    void addNode(char ch);


    /** - removes a node from the beginning of the list.
    @note - removes from the beginning.
    @post - the size of the list decreases by 1.
    @return - returns the character held by the last Node.
    */
    char removeNode();


    /** - removes the last Node from the list, and remove all
    instances of that  character inside the Node from the entire List.
    @post - size of the list deceases by the number of times the last
    Node appear elsewhere inside the List.
    @return - returns the character held by the last Node.
    */
    char removeMultiNodes();


    /** @return - returns the number of times the character inside the last Node
    repeats elsewhere.
    */
    int getRepeatCounts();


    /** - @return - returns the size of the list.*/
    int getSize();


    /** - @return - returns the number of unique node(s) that is(are) in the List. */
    int getUniqueCount();


    /** @note - prints the list starting from the last Node. */
    void printList();
};



#endif //LIST_H

