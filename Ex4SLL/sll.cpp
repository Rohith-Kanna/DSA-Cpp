#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *link;

    Node(int d)
    {
        data = d;
        link = NULL;
    }
};

class SLL
{
private:
    Node *head;
    int count;

public:
    SLL()
    {
        head = NULL;
        count = 0;
    }

    // Create list (initialize metadata)
    void createList()
    {
        head = NULL;
        count = 0;
        cout << "List created" << endl;
    }

    void insertNode(int val, int pos) // insert by position
    {
        Node *NN = new Node(val);
        if (pos < 1 || pos > count + 1)
        {
            cout << "Invalid Position" << endl;
            return;
        }
        if (pos == 1)
        {
            NN->link = head;
            head = NN;
        }
        else
        {
            Node *temp = head;
            for (int i = 1; i < pos - 1; i++)
            {
                temp = temp->link; // prev node
            }
            NN->link = temp->link;
            temp->link = NN;
        }
        count++;
        cout << "Inserted " << val << " at position : " << pos << endl;
    }

    /*void insertNode(int val) //inserting ordered SLL
    {
        Node *NN = new Node(val);

        // Case 1: Empty list or insert at beginning
        if (head == NULL || val < head->data)
        {
            NN->link = head;
            head = NN;
        }
        else
        {
            Node *temp = head;
            // Traverse until we find the correct position
            while (temp->link != NULL && temp->link->data < val)
            {
                temp = temp->link;
            }
            // Insert between temp and temp->link
            NN->link = temp->link;
            temp->link = NN;
        }

        count++;
        cout << "Inserted " << val << " in sorted order" << endl;
    }*/

    /*void insertNode(int val)  //inserting at last
    {
        Node *newnode = new Node(val);
        if (head == NULL)
        {
            head = newnode; // empty sll
        }
        else
        {
            Node *temp = head;
            while (temp->link != NULL) //inserts at last
            {
                temp = temp->link;
            }
            temp->link = newnode;
        }
        count++;
        cout << "Inserted: " << val << endl;
    }*/

    // Delete node by value
    void deleteNode(int val)
    {
        Node *temp = head;
        Node *prev = NULL;

        while (temp != NULL && temp->data != val)
        {
            prev = temp;
            temp = temp->link;
        }

        if (temp == NULL)
        {
            cout << "Element not found" << endl;
            return;
        }

        if (prev == NULL)
        { // deleting head
            head = head->link;
        }
        else
        {
            prev->link = temp->link;
        }

        cout << "Deleted: " << temp->data << endl;
        delete temp;
        count--;
    }

    // Search by value
    void searchNode(int val)
    {
        Node *temp = head;
        while (temp != NULL && temp->data != val)
        {
            temp = temp->link;
        }
        if (temp == NULL)
        {
            cout << "Not found" << endl;
        }
        else
        {
            cout << "Data found: " << temp->data << endl;
        }
    }

    // Retrieve by position
    void retrieveNode(int pos)
    {
        if (pos <= 0 || pos > count)
        {
            cout << "Invalid position" << endl;
            return;
        }
        Node *temp = head;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->link;
        }
        cout << "Data found at position " << pos << ": " << temp->data << endl;
    }

    // Count nodes
    void listCount()
    {
        cout << "There are " << count << " elements" << endl;
    }

    // Display list
    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data;
            if (temp->link != NULL)
                cout << " -> ";
            temp = temp->link;
        }
        cout << endl;
    }

    // Destroy list
    void destroyList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            Node *next = temp->link;
            delete temp;
            temp = next;
        }
        head = NULL;
        count = 0;
        cout << "List destroyed" << endl;
    }
};

int main()
{
    SLL list;
    int choice, val, pos;

    cout << "Singly Linked List Operations Menu:\n";
    cout << "1. Create List\n2. Insert\n3. Delete\n4. Search\n5. Retrieve\n";
    cout << "6. Count\n7. Display\n8. Destroy\n9. Exit\n";

    do
    {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            list.createList();
            break;
        case 2:
            cout << "Enter data: ";
            cin >> val;
            cout << "Enter position:";
            cin >> pos;
            list.insertNode(val, pos);
            break;
        case 3:
            cout << "Enter data to delete: ";
            cin >> val;
            list.deleteNode(val);
            break;
        case 4:
            cout << "Enter data to search: ";
            cin >> val;
            list.searchNode(val);
            break;
        case 5:
            cout << "Enter position: ";
            cin >> pos;
            list.retrieveNode(pos);
            break;
        case 6:
            list.listCount();
            break;
        case 7:
            list.display();
            break;
        case 8:
            list.destroyList();
            break;
        case 9:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 9);

    return 0;
}
