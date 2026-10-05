#include<iostream>
using namespace std;
class node{
    public:
    int data,rank;
    node *parent;
};
class dis
{
    public:
    int ne;
    node *e[50];
    dis()
    {ne=0;}
    void make(int v)
    {
        cout<<"creating singleton set for "<<v<<endl;
        node *temp=new node();
        temp->data=v;
        temp->rank=1;
        temp->parent=temp;
        ne++;
        e[v]=temp;
    }
    node* findset(int v)
    {
        cout<<"Rep of element "<<v;
        node *t=findset(e[v]);
        cout<<"is "<<t->data<<endl;
        return t;
    }
    node* findset(node *u)
    {
        if(u->parent!=u)return findset(u->parent);
        return u;
    }
    void combine(int u,int v)
    {
        cout<<"combining "<<u<<"and "<<v<<endl;
        node*x=findset(e[u]);
        node*y=findset(e[v]);
        if(x->data==y->data)cout<<"same set cant combine"<<endl;
        else link(x,y);
    }
    void link(node *x,node *y)
    {
        if(x->rank>y->rank)
        {y->parent=x;
        cout<<y->data<<"\'s parent is "<<x->data<<endl;
        }else 
        {
            x->parent=y;
            cout<<x->data<<"\'s parent is "<<y->data<<endl;
            if(x->rank==y->rank)y->rank++;
        }
    }
    void disp()
    {
        for(int i=0;i<ne;i++)
        cout<<e[i]->data<<"\'s parent :"<<e[i]->parent->data<<endl;
    }
};

int main()
{
    int ne=5;dis d;
    for(int i=0;i<ne;i++)
    d.make(i);
    
    d.disp();
    
    //find
    node *t=d.findset(0);
    t=d.findset(1);
    
    //combine
    d.combine(0,1);
    d.disp();
    d.combine(1,1); //same set
    d.combine(3,4);
    d.disp();
}
