#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *link;

    Node(int val)
    {
        data = val;
        link = NULL;
    }
};

class Stack
{
    Node *top;
    int count;

public:
    Stack()
    {
        top = NULL;
        count = 0;
    }

    bool EmptyStack()
    {
        return (count == 0);
    }

    bool PushStack(int val)
    {
        Node *newnode = new Node(val);
        newnode->link = top; //takes the prev top element and connecting (reverse sll)
        top = newnode;
        count++;
        cout << "Inserted: " << val << endl;
        return true;
    }

    bool PopStack(int &dataOut)
    {
        if (EmptyStack())
        {
            cout << "Stack Underflow! Cannot pop." << endl;
            return false;
        }
        dataOut = top->data;
        Node *temp = top;
        top = top->link;//links to prev node
        delete temp; 
        count--;
        cout << "Popped element: " << dataOut << endl;
        return true;
    }

    bool StackTop(int &dataOut)
    {
        if (EmptyStack())
        {
            cout << "Stack is Empty" << endl;
            return false;
        }
        dataOut = top->data;
        cout << "Top element: " << dataOut << endl;
        return true;
    }

    int StackCount()
    {
        if (EmptyStack())
        {
            cout << "Stack is Empty. Count: 0" << endl;
            return 0;
        }
        cout << "Count: " << count << endl;
        return count;
    }

    void DestroyStack()
    {
        while (top != NULL)
        {
            Node *temp = top;
            top = top->link;
            delete temp;
        }
        count = 0;
    }

    // For linked list stack, no size limit → always false
    bool FullStack()
    {
        return false;
    }
};

int main()
{
    Stack s;
    int choice, value, dataOut;

    cout << "--- Stack Operations using Linked List ---\n";
    cout << "1. PushStack\n";
    cout << "2. PopStack\n";
    cout << "3. StackTop\n";
    cout << "4. FullStack\n";
    cout << "5. EmptyStack\n";
    cout << "6. StackCount\n";
    cout << "7. Exit\n";

    do
    {
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data: ";
            cin >> value;
            s.PushStack(value);
            break;

        case 2:
            s.PopStack(dataOut);
            break;

        case 3:
            s.StackTop(dataOut);
            break;

        case 4:
            cout << (s.FullStack() ? "True" : "False") << endl;
            break;

        case 5:
            cout << (s.EmptyStack() ? "True" : "False") << endl;
            break;

        case 6:
            s.StackCount();
            break;

        case 7:
            cout << "Exiting" << endl;
            break;

        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
