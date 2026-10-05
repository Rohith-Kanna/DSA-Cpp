#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

class Head
{
public:
    int count;
    Node *front;
    Node *rear;

    Head()
    {
        count = 0;
        front = NULL;
        rear = NULL;
    }
};

class DLL
{

    Head *head;
    // Node* next;
    // int count;

public:
    void create()
    {
        head = new Head();
        head->count = 0;
    }
    void insert(int d) //ordered dll
    {
        Node *NN = new Node(d);
        Node *temp = head->front;
        if (head->front == NULL)
        {
            head->front = head->rear = NN; // first element
        }

        else if (temp->data > d) // insert at beginning
        {
            NN->next = head->front;
            head->front->prev = NN;
            head->front = NN;
        }
        else
        { // middle or last (ascending order)

            while (temp->next != NULL && temp->next->data <= d)
            {
                temp = temp->next;
            }
            NN->next = temp->next;
            NN->prev = temp;
            temp->next = NN;

            if (NN->next == NULL) // last element
                head->rear = NN;
            else
                NN->next->prev = NN;
        }
        head->count += 1;
        cout << d << " inserted in order" << endl;
    }
    void dispF()
    {
        if (head->front == NULL)
        {
            cout << "LIST EMPTY" << endl;
        }
        cout << "Displaying forward: ";
        Node *temp = head->front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void dispR()
    {
        if (head->front == NULL)
        {
            cout << "LIST EMPTY" << endl;
        }
        cout << "Displaying backward: ";
        Node *temp = head->rear;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    Node *search(int key)
    {
        if (head->front == NULL)
        {
            cout << "LIST EMPTY" << endl;
        }
        Node *temp = head->front;
        while (temp != NULL && temp->data != key)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            return temp;
        }
        else
        {
            return temp;
        }
    }

    void Delete(int v)
    {
        Node *t = search(v); // getting the value address;
        if (t != NULL)
        {
            if (t->prev == NULL && t->next == NULL)
            {
                // only node
                head->front = head->rear = NULL;
            }
            else if (t->prev == NULL) // first node
            {
                head->front = t->next;
                t->next->prev = NULL;
            }
            else if (t->next == NULL) // last node
            {
                head->rear = t->prev;
                t->prev->next = NULL;
            }
            else
            {
                // deleting middle node
                t->prev->next = t->next;
                t->next->prev = t->prev;
            }
            head->count--;
            cout << v << " is deleted" << endl;
        }
        else
        {
            cout << "Element not present" << endl;
        }
    }
};

int main()
{
    DLL d;
    d.create();
    d.insert(10);
    d.dispF();
    d.insert(5);
    d.dispF();
    //  d.search(30);
    d.insert(30);
    d.insert(30);
    d.dispF();
    d.insert(40);
    d.dispF();
    d.dispR();
    // d.search(30);
    d.Delete(30);
    d.dispF();
    d.dispR();
}
