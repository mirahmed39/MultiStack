# MultiStack
An implementation of the Stack ADT with additional features(check readme for more details).
MultiStack Specifications:

MultiStack() -- Default constructor

MultiStack(const MultiStack& anotherMultiStack) -- Copy constructor
void push(char c)-- Pushes a character c into the stack.

char pop()
Pops off the last character from the stack and remove it from the stack. Throws an exception if the stack is empty.

char multiPop()-- Pops off the last character from the stack, and remove all instances of that  character from the entire stack. 
The order of the other characters in the stack should remain intact. Throws an exception if the stack is empty.

bool isEmpty() -- Returns true if the stack is empty; false otherwise

int getSize() -- Returns the total number of characters in the stack, irrespective of repeats. Returns 0 if the stack is empty.

int getUniqueCount() -- Returns the unique number of characters in the stack. So if the current stack has the following
[b a z z z a c ], this should return 4. 
