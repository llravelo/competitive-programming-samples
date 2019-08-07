// Stack is a data structure that follows a first-in last-out policy
// An element that is pushed into the stack first
// will be the last element to be popped

#define DEFAULT_LENGTH 100

template <class type> class Stack {
private:
  type *stackArray;
  int stackSize = 0;
  int topIndex = 0;

public:
  Stack() {
    stackArray = new type[DEFAULT_LENGTH];
    stackSize = DEFAULT_LENGTH;
  }

  Stack(int length) {
    stackArray = new type[length];
    stackSize = length;
  }

  bool push(type var) {
    if (isFull())
      return false;

    stackArray[topIndex++] = var;
    return true;
  }

  type pop() {
    if (isEmpty())
      return stackArray[0];
    return stackArray[--topIndex];
  }

  type top() {
    if (isEmpty())
      return stackArray[0];
    return stackArray[topIndex - 1];
  }

  bool isFull() { return topIndex >= stackSize; }

  bool isEmpty() { return topIndex <= 0; }
};
