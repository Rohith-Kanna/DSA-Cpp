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
        next = prev = NULL;
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
        front = rear = NULL;
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
    void insert(int d) //ordered (ascending)
    {
        Node *NN = new Node(d);
         Node *temp = head->front;
        if (head->front == NULL)
        {
            head->front = head->rear = NN;
            NN->next = NN->prev = NN; // first element
        }

        else if (temp->data > d) // insert before first element
        {
            NN->next = head->front;
            NN->prev = head->rear;
            head->rear->next = NN;
            head->front->prev = NN;
            head->front = NN;
        }
        else
        { // middle or last (ascending order)
           // Node *temp = head->front;
            while (temp->next != head->front && temp->next->data <= d)
            {
                temp = temp->next;
            }
            NN->next = temp->next;
            NN->prev = temp;
            temp->next = NN;

            if (NN->next == head->front) // last element
                head->rear = NN;
            else
                NN->next->prev = NN;
            head->front->prev = head->rear;
            head->rear->next = head->front;
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
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head->front);
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
        do
        {
            cout << temp->data << " ";
            temp = temp->prev;
        } while (temp != head->rear);
        cout << endl;
    }

    Node *search(int key)
    {
        if (head->front == NULL)
        {
            cout << "LIST EMPTY" << endl;
        }
        Node *temp = head->front;
        do
        {
            if (temp->data == key)
                return temp;
            temp = temp->next;
        } while (temp != head->front);
        return NULL;
    }

    void Delete(int v)
    {
        Node *t = search(v); // getting the value address;
        if (t != NULL)
        {
            if (t->prev == t && t->next == t)
            {
                // only node
                head->front = head->rear = NULL;
            }
            else
            {
                t->prev->next = t->next;
                t->next->prev = t->prev;

                if (t == head->front)
                    head->front = t->next;
                if (t == head->rear)
                    head->rear = t->prev;

                head->front->prev = head->rear;
                head->rear->next = head->front;
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
