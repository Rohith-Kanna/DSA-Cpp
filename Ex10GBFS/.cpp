#include<iostream>
using namespace std;
enum color{WHITE, GRAY, BLACK};
class Node{
    int ver;
    Node* link;
};
struct vnode{
    string name;
    int d;
    int pi;
    color c;
    Node* adjptr;
};

struct qnode{
    int data;
    qnode* next;
};

class Queue{
    qnode*front;
    qnode*rear;
    public:
    Queue(){
        front = rear = NULL;
    }
    bool isEmpty(){
        return front == NULL;
    }
    void enqueue(int x)
    {
        if(rear==NULL){
            
        }
    }
}