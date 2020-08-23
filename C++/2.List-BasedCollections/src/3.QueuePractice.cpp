/*Make a Queue class using a list!
Hint: You can use any Python list method
you'd like! Try to write each one in as 
few lines as possible.
Make sure you pass the test cases too!*/
#include <iostream>
#include <vector>
using namespace std;

class Element
{
public:
    int data;
    Element *next;

    Element(int data)
    {
        Element::data = data;
        next = NULL;
    }
};

class LinkedList
{
public:
    Element *head;
    LinkedList()
    {
        head = NULL;
    }

    LinkedList(Element *head)
    {
        LinkedList::head = head;
    }

    void append(Element *newNode)
    {

        Element *current = head;
        if (head != NULL)
        {
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newNode;
        }
        else
        {
            LinkedList::head = newNode;
        }
    }

    void insertFirst(Element *newNode)
    {
        newNode->next = head;
        head = newNode;
    }

    int deleteFirst()
    {
        if (head != NULL)
        {
            Element *deletedElement = head;
            Element *temp = deletedElement->next;
            head = temp;
            return deletedElement->data;
        }
        else
        {
            return -1;
        }
    }
};

class Stack
{
public:
    Element *top;
    LinkedList *ll;
    Stack(Element *top)
    {
        Stack::top = top;
        ll = new LinkedList(top);
    }

    void push(Element *newNode)
    {
        ll->insertFirst(newNode);
    }
    ||
        int pop()
    {
        return ll->deleteFirst();
    }
};

class Queue
{
public:
    Stack *storage;
    int head;
    Queue(int head)
    {
        Queue::storage = [head];
    }

    void enqueue(int newElement)
    {
        Queue::storage->push_back(newElement);
    }

    int peek()
    {
        return head;
    }

    int dequeue()
    {
    }
};

int main()
{

    return 0;
}