#include <iostream>
using namespace std;

#define MAX 5   // Maximum size of stack

// Stack class definition
class Stack {
private:
    int arr[MAX];  // Array to store stack elements
    int top;       // Index of top element

public:
    // Constructor
    Stack() {
        top = -1; // Initially stack is empty
    }

    bool EmptyStack() {
        return (top == -1);
    }

    bool FullStack() {
        return (top == MAX - 1);
    }

    bool PushStack(int data) {
        if (FullStack()) {
            cout << "Stack Overflow! Cannot insert " << data << endl;
            return false;
        }
        arr[++top] = data; //top++;arr[top]=data;
        cout << "Inserted: " << data << endl;
        return true;
    }

    bool PopStack(int &dataOut) {
        if (EmptyStack()) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return false;
        }
        dataOut = arr[top--];//dataOut=arr[top];top--;
        cout << "Popped element: " << dataOut << endl;
        return true;
    }

    bool StackTop(int &dataOut) {
        if (EmptyStack()) {
            cout << "Stack is Empty" << endl;
            return false;
        }
        dataOut = arr[top];
        cout << "Top element: " << dataOut << endl;
        return true;
    }

    int StackCount() {
        if (EmptyStack()) {
            cout << "Stack is Empty. Count: 0" << endl;
            return 0;
        }
        int count = top + 1;
        cout << "Count: " << count << endl;
        return count;
    }
};

// Main program
int main() {
    Stack s;
    int choice, value, dataOut;

    cout << "--- Stack Operations Menu ---\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. StackTop\n";
    cout << "4. FullStack\n";
    cout << "5. EmptyStack\n";
    cout << "6. StackCount\n";
    cout << "7. Exit\n";

    do {
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
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
