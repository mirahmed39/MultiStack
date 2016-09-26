#include "MultiStack.hpp"
#include "Node.hpp"
#include "List.hpp"

MultiStack::MultiStack()
{
    //initialy creates an empty list.
}

MultiStack& MultiStack::operator =(MultiStack& anotherMultiStack)
{
    A_List = anotherMultiStack.A_List;
    return *this;
}

MultiStack:: MultiStack(const MultiStack& anotherMultiStack)
{
    A_List = anotherMultiStack.A_List;
}

MultiStack::~MultiStack()
{
    A_List.~List();
}

bool MultiStack::isEmpty()
{
    return A_List.isEmpty();
}

void MultiStack::push(char ch)
{
    A_List.addNode(ch);
}

char MultiStack::pop()
{
    char output = A_List.removeNode();
    return output;
}

char MultiStack::multiPop()
{
    char output = A_List.removeMultiNodes();
    return output;
}

int MultiStack::getRepeatCounts()
{
    int count = A_List.getRepeatCounts();
    return count;
}

int MultiStack::getSize()
{
    return A_List.getSize();
}

int MultiStack::getUniqueCount()
{
    int uniqueCount = A_List.getUniqueCount();
    return uniqueCount;
}




