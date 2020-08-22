/* The LinkedList code from before is provided below.
Add three functions to the LinkedList.
"get_position" returns the element at a certain position.
The "insert" function will add an element to a particular
spot in the list.
"delete" will delete the first element with that
particular value.
Then, use "Test Run" and "Submit" to run the test cases
at the bottom. */

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

    int getPosition(int position)
    {
        /*  Get an element from a particular position.
        Assume the first position is "1".
        Return "None" if position is not in the list. */
        Element *current = head;
        int count = 0;

        while (current != NULL)
        {
            if (count == position)
            {
                return current->data;
            }
            current = current->next;
            count++;
        }
        return -1;
    }

    void insert(Element *newNode, int position)
    {
        /*  Insert a new node at the given position.
        Assume the first position is "1".
        Inserting at position 3 means between
        the 2nd and 3rd elements. */
        int counter = 1;
        Element *current = head;
        if (position > 1)
        {
            while (current != NULL && counter < position)
            {
                if (counter == position - 1)
                {
                    newNode->next = current->next;
                    current->next = newNode;
                }
                current = current->next;
                counter++;
            }
        }
        else if (position == 1)
        {
            newNode = head->next;
            head = newNode;
        }
    }

    void deleteNode(int value)
    {
        /* Delete the first node with a given value. */
        Element *current = head;
        Element *previous = NULL;

        while (current->data != value && current->next != NULL)
        {
            previous = current;
            current = current->next;
        }
        if (current->data == value)
        {
            if (previous != NULL)
            {
                previous->next = current->next;
            }
            else
            {
                head = current->next;
            }
        }
    }
};

int main()
{
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
    cout << ll->getPosition(3) << endl;
    ll->insert(e, 2);
    cout << ll->getPosition(1) << endl;
    ll->deleteNode(5);
    cout << ll->getPosition(1) << endl;

    return 0;
}
