#include <iostream>
using namespace std;

// --------------------- NODE CLASS ---------------------
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

// --------------------- HEAD / METADATA ---------------------
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

// --------------------- DLL CLASS ---------------------
class DLL
{
    Head *head;

public:
    // a. Creating an Empty DLL
    void createList()
    {
        head = new Head();
        cout << "List created successfully.\n";
    }

    // e. Check for Empty DLL
    bool emptyList()
    {
        return (head->count == 0);
    }

    // f. Counting number of nodes
    int dllCount()
    {
        return head->count;
    }

    // d. Searching for node and its predecessor
    Node *searchList(int key, Node *&pre)
    {
        pre = NULL;
        Node *loc = head->front;
        while (loc != NULL && key > loc->data)
        {
            pre = loc;
            loc = loc->next;
        }
        if (loc != NULL && key == loc->data)
            return loc; // found
        return NULL;   // not found
    }

    // b. Insert into DLL (in ascending order)
    int insertDLL(int dataIn)
    {
        Node *pre = NULL;
        Node *found = searchList(dataIn, pre);

        if (found != NULL)
            return 2; // duplicate

        Node *NN = new Node(dataIn);
        if (!NN)
            return 0; // memory overflow

        if (head->front == NULL)
        {
            head->front = head->rear = NN;
        }
        else if (pre == NULL)
        {
            // insert at beginning
            NN->next = head->front;
            head->front->prev = NN;
            head->front = NN;
        }
        else
        {
            NN->next = pre->next;
            NN->prev = pre;
            pre->next = NN;
            if (NN->next == NULL)
                head->rear = NN;
            else
                NN->next->prev = NN;
        }

        head->count++;
        cout << dataIn << " inserted.\n";
        return 1;
    }

    // c. Deleting an element
    void deleteDLL(int val)
    {
        Node *pre = NULL;
        Node *delNode = searchList(val, pre);

        if (delNode == NULL)
        {
            cout << "Element not found.\n";
            return;
        }

        if (delNode->prev == NULL && delNode->next == NULL)
        {
            head->front = head->rear = NULL;
        }
        else if (delNode->prev == NULL)
        {
            head->front = delNode->next;
            delNode->next->prev = NULL;
        }
        else if (delNode->next == NULL)
        {
            head->rear = delNode->prev;
            delNode->prev->next = NULL;
        }
        else
        {
            delNode->prev->next = delNode->next;
            delNode->next->prev = delNode->prev;
        }

        delete delNode;
        head->count--;
        cout << val << " deleted.\n";
    }

    // g. Display Head → Rear
    void displayHeadToRear()
    {
        if (emptyList())
        {
            cout << "List empty.\n";
            return;
        }

        cout << "Head to Rear: ";
        Node *p = head->front;
        while (p != NULL)
        {
            cout << p->data;
            if (p->next)
                cout << " -> ";
            p = p->next;
        }
        cout << endl;
    }

    // h. Display Rear → Head
    void displayRearToHead()
    {
        if (emptyList())
        {
            cout << "List empty.\n";
            return;
        }

        cout << "Rear to Head: ";
        Node *p = head->rear;
        while (p != NULL)
        {
            cout << p->data;
            if (p->prev)
                cout << " -> ";
            p = p->prev;
        }
        cout << endl;
    }

    // j. Search position from Head
    int searchDLLFromHead(int target)
    {
        Node *p = head->front;
        int pos = 1;
        while (p != NULL && target > p->data)
        {
            pos++;
            p = p->next;
        }
        if (p != NULL && p->data == target)
            return pos;
        return -1;
    }

    // k. Search position from Rear
    int searchDLLFromRear(int target)
    {
        Node *p = head->rear;
        int pos = 1;
        while (p != NULL && target < p->data)
        {
            pos++;
            p = p->prev;
        }
        if (p != NULL && p->data == target)
            return pos;
        return -1;
    }

    // i. Destroy entire DLL
    void destroyDLL()
    {
        Node *p = head->front;
        while (p != NULL)
        {
            Node *temp = p;
            p = p->next;
            delete temp;
        }
        head->front = head->rear = NULL;
        head->count = 0;
        cout << "List destroyed.\n";
    }
};

// --------------------- MAIN FUNCTION ---------------------
int main()
{
    DLL d;
    d.createList();
    int choice, val;

    while (true)
    {
        cout << "\n1.Insert  2.Delete  3.SearchFromHead  4.SearchFromRear  5.DestroyDLL\n";
        cout << "6.DisplayHeadToRear  7.DisplayRearToHead  8.Exit\n";
        cout << "Option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data: ";
            cin >> val;
            d.insertDLL(val);
            break;
        case 2:
            cout << "Enter data to delete: ";
            cin >> val;
            d.deleteDLL(val);
            break;
        case 3:
            cout << "Enter data to search from head: ";
            cin >> val;
            cout << "Position: " << d.searchDLLFromHead(val) << endl;
            break;
        case 4:
            cout << "Enter data to search from rear: ";
            cin >> val;
            cout << "Position: " << d.searchDLLFromRear(val) << endl;
            break;
        case 5:
            d.destroyDLL();
            break;
        case 6:
            d.displayHeadToRear();
            break;
        case 7:
            d.displayRearToHead();
            break;
        case 8:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid option.\n";
        }
    }
}
