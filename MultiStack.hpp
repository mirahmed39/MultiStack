/**
    * @file - MultiStack.hpp
    * @Author - Mir Ahmed.
    * @Description- The MultiStack class is a type of container that is
    able to hold characters in it and do some operations with them using
    its member functions.
    *@Date_Created - 11/18/2015

*/
#ifndef MULTI_STACK_H
#define MULTI_STACK_H
#include "MultiStackInterface.hpp"
#include "Node.hpp"
#include "List.hpp"
class MultiStack: public MultiStackInterface
{
private:
    List A_List;
public:
    /** Default Constructor */
    MultiStack();


    /**- Copy Constructor: copies an instance of MultiStack to a MuliStack that will be
          created.
    @pre- anotherMultiStack has to be initialized.
    */
    MultiStack(const MultiStack& anotherMultiStack);


    /** Destructor - the entire MultiStack is deleted with the use of this destructor*/
    ~MultiStack();


    /**- operator Overloading: copies an instance of MultiStack to a MuliStack that will be
          created.
    @pre- anotherMultiStack has to be initialized.
    @return - returns the reference to the current list object.
    */
    MultiStack& operator =(MultiStack& anotherMultiStack);


    /**- checks if the MultiStack is empty or not.
    @return - returns true if the MultiStack is empty; false otherwise.
    */
    bool isEmpty();


    /** - adds a character to the MultiStack.
    @param - char ch - the item that is to be added to the MultiStack.
    */
    void push(char ch);


    /** - removes the last character added to the stack.
    @return - returns the character that is removed.*/
    char pop();


    /** - Pops off the last character from the stack, and remove all instances
    of that  character from the entire stack. The order of the other characters
    in the stack should remain intact. Throws an exception if the stack is empty.
    @return - returns the character that is multiPopped. */
    char multiPop();


    /** @return - Returns a count of the number of times the last character in the
    MultiStack appears. Returns 0 if the MultiStack is empty. */
    int getRepeatCounts();


    /** @return - returns the number of characters in the MultiStack. */
    int getSize();


    /** @return - returns the number of the unique characters in the MultiStack. */
    int getUniqueCount();
};

#endif // MULTI_STACK_H

