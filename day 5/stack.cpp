//Implementation of Stack
#include <iostream>
#include <climits>
#include <malloc.h>

//Default size of a stack
#define MAX_SIZE 100

class stack
{
public:
    //Create a stack with given size or MAX_SIZE by default
    stack(size_t size = MAX_SIZE);
    //Method to push item to the stack
    bool push(const int value);
    //Method to pop an item from the stack
    bool pop();
    //Method to see the top most element
    int peek();
    //Method to check if the stack is empty or not
    bool isEmpty();
    //Method to print all items of the stack to the screen
    void show();
private:
    //Index of the top most element
    int top;
    //Capacity of the stack (100 by default)
    size_t capacity;
    //Pointer to the array used to store items
    int* array;
};

int main()
{
    stack first, second(2);
    first.push(1);
    first.push(2);
    first.push(3);

    while (!first.isEmpty())
    {
        std::cout << first.peek() << ' ';
        first.pop();
    }
    std::cout << std::endl;

    second.push(4);
    second.push(5);
    second.push(6);

    while (!second.isEmpty())
    {
        std::cout << second.peek() << ' ';
        second.pop();
    }
    std::cout << std::endl;

}

stack::stack(size_t size)
{
    capacity = size;
    top = -1;
    array = (int*) malloc(capacity * sizeof(int));
}

bool stack::push(const int value)
{
    if (top > -1 && top >= (capacity - 1))
    {
        std::cerr << "Unable to push! Stack Overfollow!\n";
        return false;
    }
    else
    {
        array[++top] = value;
        return true;
    }
}

bool stack::pop()
{
    if (isEmpty())
    {
        std::cerr << "Pop failed! Stack Underfollow!\n";
        return false;
    }
    else
    {
        top--;
        return true;
    }
}

int stack::peek()
{
    if (isEmpty())
    {
        std::cerr << "Stack is empty!\n";
        return INT_MIN;
    }
    else
    {
        return array[top];
    }
}

bool stack::isEmpty()
{
    return (top < 0);
}

void stack::show()
{
    for (int i = 0; i <= top; i++)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}