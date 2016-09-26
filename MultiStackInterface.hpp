/**
    * @file - MultiStackInterface.hpp
    * @Author - Mir Ahmed.
    * @Description- The MultiStack class is a type of container that is
    able to hold characters in it and do some operations with them using
    its member functions.
    *@Date_Created - 11/18/2015

*/
#ifndef MULTI_STACK_INTERFACE_H
#define MULTI_STACK_INTERFACE_H

class MultiStackInterface
{

    /**- checks if the MultiStack is empty or not.
    @return - returns true if the MultiStack is empty; false otherwise.
    */
    virtual bool isEmpty() = 0;


    /** - adds a character to the MultiStack.
    @param - char ch - the item that is to be added to the MultiStack.
    */
    virtual void push(char ch) = 0;


    /** - removes the last character added to the stack.
    @return - returns the character that is removed.*/
    virtual char pop() = 0;


    /** - Pops off the last character from the stack, and remove all instances
    of that  character from the entire stack. The order of the other characters
    in the stack should remain intact. Throws an exception if the stack is empty.
    @return - returns the character that is multiPopped. */
    virtual char multiPop() = 0;


    /** @return - Returns a count of the number of times the last character in the
    MultiStack appears. Returns 0 if the MultiStack is empty. */
    virtual int getRepeatCounts() = 0;


    /** @return - returns the number of characters in the MultiStack. */
    virtual int getSize() = 0;


    /** @return - returns the number of the unique characters in the MultiStack. */
    virtual int getUniqueCount() = 0;
};

#endif // MULTI_STACK_INTERFACE_H
