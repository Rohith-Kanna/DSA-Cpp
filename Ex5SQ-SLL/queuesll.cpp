#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class Queue
{
private:
    Node *front;
    Node *rear;
    int count;

public:
    Queue()
    {
        front = rear = NULL;
        count = 0;
    }

    void enqueue(int value)
    {
        Node *newnode = new Node(value);
        if (rear == NULL)
        {
            front = rear = newnode; //only element 
        }
        else
        {
            rear->next = newnode;
            rear = newnode;
        }
        count++;
        cout << "Inserted " << value << endl;
    }

    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue is Empty!" << endl;
            return;
        }
        Node *temp = front;
        cout << "Dequeued element: " << front->data << endl;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        delete temp;
        count--;
    }

    void queueFront()
    {
        if (front == NULL)
        {
            cout << "Queue is Empty!" << endl;
        }
        else
        {
            cout << "Front element: " << front->data << endl;
        }
    }

    void queueRear()
    {
        if (rear == NULL)
        {
            cout << "Queue is Empty!" << endl;
        }
        else
        {
            cout << "Rear element: " << rear->data << endl;
        }
    }

    void isEmpty()
    {
        if (count == 0)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }

    void queueCount()
    {
        cout << "Count: " << count << endl;
    }
};

int main()
{
    Queue q;
    int choice, value;

    cout << "Queue Operations Menu:\n";
    cout << "1-Enqueue\n2-Dequeue\n3-Queue Front\n4-Queue Rear\n5-Is Full (always False in LL)\n6-Is Empty\n7-Queue Count\n8-Exit\n";

    do
    {
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter data: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.queueFront();
            break;
        case 4:
            q.queueRear();
            break;
        case 5:
            cout << "False" << endl; // Linked list queue never "full"
            break;
        case 6:
            q.isEmpty();
            break;
        case 7:
            q.queueCount();
            break;
        case 8:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 8);

    return 0;
}
