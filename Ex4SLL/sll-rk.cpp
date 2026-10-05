// own code
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
    /*void insert(int d,int pos)
    {
        Node *NN=new Node(d);
        if(pos<0 || pos>count+1)
        {
            cout<<"Invalid"<<endl;return;
        }
        if(pos==1)
        {
            NN->link=head;
            head=NN;
        }
        else
        {
            Node *temp=head;
            for(int i=1;i<pos-1;i++)
            {
                //to get the prev node
                temp=temp->link;
            }
            NN->link=temp->link;
            temp->link=NN;
        }
        count++;
    }*/

    void insert(int d) // insert in sorted order
    {
        Node *NN = new Node(d);
        if (head == NULL || head->data > d)
        {
            NN->link = head;
            head = NN;
        }
        else
        {
            Node *temp = head;
            while (temp->link != NULL && temp->link->data < d)
            {
                temp = temp->link;
            }
            NN->link = temp->link;
            temp->link = NN;
        }
        count++;
    }
    void disp()
    {
        if (head == NULL)
        {
            cout << "SLL empty" << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data;
            if (temp->link != NULL)
                cout << "->";
            temp = temp->link;
        }
        cout << endl;
    }

    void del(int d)
    {
        Node *temp = head;
        Node *prev = NULL;
        while (temp != NULL && temp->data != d)
        {
            prev = temp;
            temp = temp->link;
        }
        if (temp == NULL)
        {
            cout << "Element not found" << endl;
            return;
        }
        if (prev == NULL) // deleting first element
        {
            head = head->link;
        }
        else // middle or last element
        {
            prev->link = temp->link;
        }
        cout << "Deleted : " << temp->data << endl;
        delete temp;
        count--;
    }
    void search(int d)
    {
        Node *temp = head;
        while (temp != NULL && temp->data != d)
        {
            temp = temp->link;
        }
        if (temp == NULL)
        {
            cout << "Not found " << endl;
            return;
        }
        else
            cout << "Found " << endl;
        return;
    }
};
int main()
{
    SLL s;
    /* s.insert(10,1);
     s.disp();
     s.insert(20,2);
     s.insert(30,2);
     */

    s.insert(10);
    s.insert(5);
    s.insert(-10);
    s.insert(20);
    s.disp();
    s.del(-10);
    s.disp();

    s.search(2);
    s.search(5);
}