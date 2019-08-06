// Queue is a data structure that follows a first-in first-out policy
// Any element that is enqueued into the queue first
// will also be the first element to be dequeued

#define DEFAULT_LENGTH 100

template <class queueType>
class Queue {
private:
    int head, tail, length;
    queueType* queueArray;

    int increment(int index)
    {
        if (index >= length-1) return 0;
        return index + 1;
    }
public:
    Queue()
    {
        queueArray = new queueType[DEFAULT_LENGTH];
        head = 0;
        tail = 0;
        length = DEFAULT_LENGTH;
    }

    Queue(int len)
    {
        queueArray = new queueType[len];
        head = 0;
        tail = 0;
        length = len;
    }

    bool enqueue(queueType var)
    {
        if (isFull()) return false;

        queueArray[tail] = var;
        tail = increment(tail);

        return true;
    }

    queueType dequeue()
    {
        if (isEmpty()) return queueArray[head];

        queueType var = queueArray[head];
        head = increment(head);

        return var;
    }

    queueType first()
    {
        return queueArray[head];
    }

    bool isFull()
    {
        return increment(tail) == head;
    }

    bool isEmpty()
    {
        return head == tail;
    }
};
