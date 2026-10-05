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
public:
    Node *head;
    int count;
    SLL()
    {
        head = NULL;
        count = 0;
    }
    void createList()
    {
        head = NULL;
        count = 0;
        cout << "Created" << endl;
    }
    void insert(int d)
    {
        Node *newnode = new Node(d);
        if (head==NULL)

        {
            head = newnode;
        }
        else
        {
            Node *temp = head;
            while (temp->link != NULL)
            {
                temp = temp->link;
            }
            temp->link = newnode;
        }
        count++;
        cout << "Inserted" << endl;
    }
    void disp()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->link;
        }
    }
};
int main()
{
    SLL s;
    s.createList();
    s.insert(10);
    s.insert(20);
    s.disp();
    s.insert(50);
    s.disp();
}