/*Add a couple methods to our LinkedList class,
and use that to implement a Stack.
You have 4 functions below to fill in:
insert_first, delete_first, push, and pop.
Think about this while you're implementing:
why is it easier to add an "insert_first"
function than just use "append"?*/
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

    int pop()
    {
        return ll->deleteFirst();
    }
};

int main()
{
    Element *zero = new Element(0);
    Element *a = new Element(1);
    Element *b = new Element(2);
    Element *c = new Element(3);
    Element *d = new Element(4);
    Element *e = new Element(5);
    cout << a->data << endl;

    LinkedList *ll = new LinkedList();
    ll->append(a);
    ll->append(b);
    ll->append(c);
    ll->append(d);
    ll->insertFirst(zero);
    cout << ll->head->data << endl;
    ll->deleteFirst();
    cout << ll->head->data << endl;

    //Stack
    Stack *stack = new Stack(a);
    stack->push(b);
    stack->push(c);

    cout << stack->pop() << endl;
    cout << stack->pop() << endl;
    return 0;
}