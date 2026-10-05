#include<iostream>
using namespace std;

class Stack{
	struct Node{
		char data;
		Node *link;
	};
	
	struct HeadNode{
		Node *top;
		int count;
	};
	
	HeadNode *head;
	
	public:
	Stack(){
		head = new HeadNode;
		head->count = 0;
	}
	
	void PushStack(int data){
		Node *newnode = new Node;
		newnode->data = data;
		newnode->link = NULL;
		if(head->top == NULL){
			head->top = newnode;
		}
		else{
			newnode->link = head->top;
			head->top = newnode;
		}
		head->count++;
	}
	
	bool PopStack(){
		if(EmptyStack()) return false;
		Node *temp = head->top->link;
		delete head->top;
		head->top = temp;
		head->count--;
		return true;
	}
	
	bool EmptyStack(){
		if(head->top == NULL) return true;
		else return false;
	}
	
	int StackTop(){
		return head->top->data;
	}
	
	void display(){
		Node *temp = head->top;
		if(temp == NULL){
		cout << "The Stack is empty!!!\n";
		}	
		while(temp != NULL){
			cout << temp->data << ' ';
			temp = temp->link;
		}
		cout << endl;
	}
	
	void DestroyStack(){
		Node *temp = head->top;
		while(temp != NULL){
			temp = head->top->link;
			delete head->top;
			head-> top = temp;
		}
		head->count = 0;
	}
	
	int StackCount(){
		return head->count;
	}
};
