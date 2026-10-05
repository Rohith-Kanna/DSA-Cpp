#include <iostream>
using namespace std;

#define MAX 5 // Maximum size of Queue

// Queue class
class Queue
{
private:
    int arr[MAX];
    int front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool EmptyQueue()
    {
        return (front == -1 && rear == -1);
    }

    bool FullQueue()
    {
        return (rear == MAX - 1);
    }

    bool Enqueue(int data)
    {
        if (FullQueue())
        {
            cout << "Queue Overflow! Cannot insert " << data << endl;
            return false;
        }
        if (front == -1)
            front++;
        arr[++rear] = data;// rear++; arr[rear]=data;
        cout << "Inserted: " << data << endl;
        return true;
    }

    bool Dequeue(int &dataOut)
    {
        if (EmptyQueue())
        {
            cout << "Queue Underflow! Cannot dequeue." << endl;
            return false;
        }
        dataOut = arr[front];
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
        cout << "Dequeued element: " << dataOut << endl;
        return true;
    }

    bool QueueFront(int &dataOut)
    {
        if (EmptyQueue())
        {
            cout << "Queue is Empty" << endl;
            return false;
        }
        dataOut = arr[front];
        cout << "Front element: " << dataOut << endl;
        return true;
    }

    bool QueueRear(int &dataOut)
    {
        if (EmptyQueue())
        {
            cout << "Queue is Empty" << endl;
            return false;
        }
        dataOut = arr[rear];
        cout << "Rear element: " << dataOut << endl;
        return true;
    }

    int QueueCount()
    {
        if (EmptyQueue())
        {
            cout << "Queue is Empty. Count: 0" << endl;
            return 0;
        }
        int count = rear - front + 1;
        cout << "Count: " << count << endl;
        return count;
    }
};

// Main program
int main()
{
    Queue q;
    int choice, value, dataOut;

    cout << "--- Queue Operations Menu ---\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Queue Front\n";
    cout << "4. Queue Rear\n";
    cout << "5. Full Queue\n";
    cout << "6. Empty Queue\n";
    cout << "7. Queue Count\n";
    cout << "8. Exit\n";

    do
    {
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data: ";
            cin >> value;
            q.Enqueue(value);
            break;

        case 2:
            q.Dequeue(dataOut);
            break;

        case 3:
            q.QueueFront(dataOut);
            break;

        case 4:
            q.QueueRear(dataOut);
            break;

        case 5:
            cout << (q.FullQueue() ? "True" : "False") << endl;
            break;

        case 6:
            cout << (q.EmptyQueue() ? "True" : "False") << endl;
            break;

        case 7:
            q.QueueCount();
            break;

        case 8:
            cout << "Exiting" << endl;
            break;

        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 8);

    return 0;
}
