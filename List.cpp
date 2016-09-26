#include "List.hpp"
#include "Node.hpp"
#include <iostream>
#include <cstddef>
#include <stdexcept>
#define nullptr 0
using namespace std;

List::List()
{
    //intially points to nothing. So size is 0.
    Top = nullptr;
    size = 0;
}

List::List(const List& anotherList)
{
    if(anotherList.Top == nullptr)
    {
        Top = nullptr;
        size = 0;
    }
    else
    {
        /** anotherList has one or more pointers. We first
        add copy the first Node from anotherList to the
        current (this) list. */
        Top = new Node();
        Top->setItem(anotherList.Top->getItem());
        Top->setNext(nullptr);
        size++;
        /** these two helper pointers will help adding Nodes to the
        current list and traversing anotherList. */
        Node *thisListPtr = Top;
        Node *otherListPtr = anotherList.Top;
        // we have already copied the first Node. So, otherPtr point to the next node.
        for(otherListPtr = anotherList.Top->getNext(); otherListPtr != nullptr; otherListPtr = otherListPtr->getNext())
        {
            // addition in the beginning is done in this block.
            Node *temp = new Node();
            temp->setItem(otherListPtr->getItem());
            temp->setNext(nullptr);
            thisListPtr->setNext(temp);
            thisListPtr = temp;
            size++;
        }
        thisListPtr, otherListPtr = nullptr;
    }
}

List::~List()
{
    while(Top != nullptr)
        removeNode();
}

List& List::operator=(const List& anotherList)
{
    // In case the list has Nodes in it, we want to delete them before copying begins.
    while(Top != nullptr)
        removeNode();

    // the follwing code till the end of this function has the exact functionality
    // of a copy constructor.
    if(anotherList.Top == nullptr)
    {
        Top = nullptr;
        size = 0;
    }
    else
    {
        Top = new Node();
        Top->setItem(anotherList.Top->getItem());
        Top->setNext(nullptr);
        size++;
        Node *thisListPtr = Top;
        Node *otherListPtr = anotherList.Top;

        for(otherListPtr = anotherList.Top->getNext(); otherListPtr != nullptr; otherListPtr = otherListPtr->getNext())
        {
            Node *temp = new Node();
            temp->setItem(otherListPtr->getItem());
            temp->setNext(nullptr);
            thisListPtr->setNext(temp);
            thisListPtr = temp;
            size++;
        }
        thisListPtr, otherListPtr = nullptr;
    }

    return *this;

}

bool List::isEmpty()
{
    if(Top == nullptr)
        return true;
    else
        return false;
}

void List::addNode(char ch)
{
    /** @note- we are adding at the beginning of the list. */
    Node* nodeToAdd = new Node();
    nodeToAdd->setItem(ch);
    if(isEmpty())
    {
        nodeToAdd->setNext(nullptr);
        Top = nodeToAdd;
        size++;
    }
    else
    {
        nodeToAdd->setNext(Top);
        Top = nodeToAdd;
        size++;
    }
}

char List::removeNode()
{
    /** @note- we are removing Node from the beginning of the list. */
    char result;
    if(isEmpty())
    {
        throw runtime_error("The list is already empty. Nothing to pop!!!");
    }
    else if(size == 1)
    {
        result = Top->getItem();
        delete Top;
        Top = nullptr;
        size--;
    }
    else // size 2 or more.
    {
        result = Top->getItem();
        Node* temp = Top;
        Top = temp->getNext();
        delete temp;
        temp = nullptr;
        size--;
    }
    return result;
}

char List::removeMultiNodes()
{
    char result = Top->getItem();
    if(isEmpty())
        throw runtime_error("The list is already empty. Nothing to pop!!!");
    else if(size == 1)
    {
        result = Top->getItem();
        delete Top;
        Top = nullptr;
        size--;
    }
    else //size 2 or more
    {
        // *temp check for the duplicate Node and *duplicate points to the duplicate Node.
        Node *temp = Top, *duplicate;
        while(temp->getNext() != nullptr)
        {
            if(temp->getNext()->getItem() == Top->getItem())
            {
                // Duplicate Node found!!! We delete it.
                duplicate = temp->getNext();
                temp->setNext(temp->getNext()->getNext());
                delete duplicate;
                duplicate = nullptr;
                size--;
            }
            else // duplicate Node not found. Move to the next Node.
                temp = temp->getNext();
        }
    }
    /** we haven't removed the very last Node that Top is pointing to
    So, we remove it if the size is not zero.*/
    if(size > 0)
    {
        removeNode();
    }
    return result;
}

int List::getRepeatCounts()
{
    int count = 1; // the Node that Top points to needs to be included.
    if(isEmpty())
        count = 0;
    else if(size == 1)
        return count;
    else
    {
        // checkPtr will traverse the list to see is the last Node is repeated elsewhere.
        Node* checkPtr = Top->getNext();
        while(checkPtr != nullptr)
        {
            if(checkPtr->getItem() == Top->getItem())
            {
                count++;
                checkPtr = checkPtr->getNext();
            }
            else
                checkPtr = checkPtr->getNext();
        }
    }
    return count;
}

int List::getSize()
{
    return size;
}

int List::getUniqueCount()
{
    int uniqueCount;
    /** We will copy all the nodes in the DuplicateList. To accomplish its task, this
    algorithm requires deletion of Nodes. That's why we will do the deletion in the DuplicateList
    so that the original List stays unharmed. The Unique List will contain all the unique Nodes from
    the original List. */
    List DuplicateList, uniqueList;
    Node *curr = Top;
    while(curr != nullptr)
    {
        //copying into DuplicateList
        DuplicateList.addNode(curr->getItem());
        curr = curr->getNext();
    }
    curr = nullptr;
    delete curr;
    while(DuplicateList.getSize() != 0)
    {
        char ch = DuplicateList.removeMultiNodes();
        uniqueList.addNode(ch);
    }

    uniqueCount = uniqueList.getSize();

    return uniqueCount;
}

void List::printList()
{
    // Prints starting from last Node added.
    Node* curr = Top;
    while(curr != nullptr)
    {
        cout << curr->getItem() << " ";
        curr = curr->getNext();
    }
}





