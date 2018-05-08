//Implementation of Queue
#include <iostream>
#include <climits>

//Default size of a queue
#define MAX_SIZE 100

class queue
{
private:
    //Index of the front and rear and current size of the queue
    int frontIndex, rearIndex, size;
    //Capacity of the queue
    size_t capacity;
    //Pointer to the array used to store items
    int* array;
public:
    //Create a queue with given storage or capacity of MAX_SIZE by default
    queue(size_t storage = MAX_SIZE);
    //Method to check whether queue is empty or not
    bool isEmpty();
    //Method to check if queue is full
    bool isFull();
    //Method to put an item to the queue incase there is space
    bool enQueue(const int value);
    //Method to remove an element frome the queue
    bool deQueue();
    //Method to get value of the front item
    int front();
    //Method to get value of the rear item
    int rear();
    //Method to show all elements' value in one line
    void show();
};

int main()
{
    queue first, second(2);
    first.enQueue(1);
    first.enQueue(2);
    first.enQueue(5);
    first.show();
    second.enQueue(7);
    second.enQueue(8);
    second.enQueue(0);
    second.show();
}

queue::queue(size_t storage)
{
    capacity = storage;
    array = new int[capacity];
    frontIndex = 0;
    size = 0;
    rearIndex = capacity - 1;
}

bool queue::isEmpty()
{
    return (size == 0);
}

bool queue::isFull()
{
    return (size == capacity);
}

bool queue::enQueue(const int value)
{
    if (isFull())
    {
        std::cout << "Enqueue failed! Queue is full!\n";
        return false;
    }
    rearIndex = (rearIndex + 1) % capacity;
    array[rearIndex] = value;
    size++;
    return true;
}

bool queue::deQueue()
{
    if (isEmpty())
    {
        return false;
    }
    frontIndex = (frontIndex + 1) % capacity;
    size--;
    return true;
}

int queue::front()
{
    if (isEmpty())
    {
        return INT_MIN;
    }
    return array[frontIndex];
}

int queue::rear()
{
    if (isEmpty())
    {
        return INT_MIN;
    }
    return array[rearIndex];
}

void queue::show()
{
    int tmp = frontIndex;
    for (int i = 0; i < size; i++)
    {
        std::cout << array[tmp] << ' ';
        tmp = (tmp + 1) % capacity;
    }
    std::cout << std::endl;
}