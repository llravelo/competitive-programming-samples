// Queue is a data structure that follows a first-in first-out policy
// Any element that is enqueued into the queue first
// will also be the first element to be dequeued

#define DEFAULT_LENGTH 100

template <class type> class Queue {
private:
  int head, tail, length;
  type *queueArray;

  int increment(int index) {
    if (index >= length - 1)
      return 0;
    return index + 1;
  }

public:
  Queue() {
    queueArray = new type[DEFAULT_LENGTH];
    head = 0;
    tail = 0;
    length = DEFAULT_LENGTH;
  }

  Queue(int len) {
    queueArray = new type[len];
    head = 0;
    tail = 0;
    length = len;
  }

  bool enqueue(type var) {
    if (isFull())
      return false;

    queueArray[tail] = var;
    tail = increment(tail);

    return true;
  }

  type dequeue() {
    if (isEmpty())
      return queueArray[head];

    type var = queueArray[head];
    head = increment(head);

    return var;
  }

  type first() { return queueArray[head]; }

  bool isFull() { return increment(tail) == head; }

  bool isEmpty() { return head == tail; }
};
