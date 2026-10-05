#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node *prev,*next;
  Node(int d)
  {
      data=d;
      prev=next=NULL;
  }
};
class Head{
    public:
    int count;
    Node *front,*rear;
    
};
class DLL{
    public:
    Head *head;
    DLL()
    {
        head=new Head();
        head->count=0;
        head->rear=head->front=NULL;
    }
    void insert(int  d) //ascending order
    {
        Node *NN=new Node(d);
        Node *temp=head->front;
        if(head->front==NULL)//only node
        {
            head->rear=head->front=NN;
        }
        else if(temp->data>d)
        {
            NN->next=head->front;
            head->front->prev=NN;
            head->front=NN;
            NN->prev=NULL;
           
        }
        else //middle or last
        {
            while(temp->next!=NULL && temp->next->data<=d)
            {
                temp=temp->next;
            }
            NN->next=temp->next;
            temp->next=NN;
            NN->prev=temp;
            
            if(NN->next==NULL) //last element
            {
                head->rear=NN;
            }
            else //middle
            NN->next->prev=NN;
        }
        head->count+=1;
        cout<<"inserted"<<endl;
    }    
    void disF()
    {
        Node *temp=head->front;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            if(temp->next!=NULL)cout<<"->";
            temp=temp->next;
        }
        cout<<endl;
    }
     void disR()
    {
        Node *temp=head->rear;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            if(temp->prev!=NULL)cout<<"->";
            temp=temp->prev;
        }
        cout<<endl;
    }
    
    Node* search(int v)
    {
        Node *temp=head->front;
        while(temp!=NULL && temp->data!=v)
        {
            temp=temp->next;
        }
        if(temp==NULL)return NULL;
        else return temp;
    }
    void del(int d)
    {
        Node *temp=search(d);
        if(temp!=NULL)
        {
            if(temp->prev==NULL && temp->next==NULL)//only element
            {
                head->front=head->rear=NULL;
            }
            else if(temp->prev==NULL)//first element
            {
                head->front=temp->next;
                head->front->prev=NULL;
            }
            else if(temp->next==NULL)//last element
            {
                head->rear=temp->prev;
                head->rear->next=NULL;
            }
            else //middle element
            {
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
            }
            head->count--;
            cout<<"deleted"<<endl;
            
        }
        else cout<<"Number not present"<<endl;
    }
};

int main()
{
    DLL d;
    d.insert(10);
    d.insert(50);
    d.insert(4);
    d.insert(30);
    d.disF();
    d.disR();
    d.del(50);
    d.disF();
    d.disR();

}