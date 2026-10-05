#include <iostream>
#include<string>
using namespace std;
struct Node {
    char data;
    Node* next;
};

class Stack {
	private:
    	Node* top; 

	public:
	    Stack() {
	        top = NULL;
	    }
	    void push(char x) {
	        Node* temp = new Node();
	        temp->data = x;
	        temp->next = top; // new node points to previous top (reverse order)
	        top = temp;
	    }
	    void pop() {
	        if (top == NULL) {
	            cout << "Stack Underflow\n";
	            return;
	        }
	        Node* temp = top;
	        top = top->next; //prev top becomes new top
	        delete temp;
    	}
    	int precedence(char op){
    		if(op == '+' || op == '-'){
        		return 1;
        	}
    		if(op == '*' || op == '/'){
        		return 2;
        	}
        	if(op == '^'){
        		return 3;
        	}
    		return 0;
		}
		bool empty(){
			if(top == NULL){
				return true;
			}
			return false;
		}
		string infixToPostfix(string infix){
    		string postfix = "";
    		for (int i = 0; i < infix.length(); i++) {
        		char c = infix[i];
        		if (isalnum(c)) //alphanumeric
           			postfix += c;
        		else if (c == '(')
            		push('(');
        		else if (c == ')') {
            		while (top->data != '(') {
                		postfix += top->data;
                		pop();
            		}
            		pop();
        		}
        		else{ //`operator
            		while (!empty()&& precedence(c)<= precedence(top->data)) {
                		postfix += top->data;
                		pop();
            		}
            		push(c); // push current operator 
        		}
    		}
    		while (!empty()) {
        		postfix += top->data;
        		pop();
    		}
    		return postfix;
		}
};
int main(){
	Stack S1;
	string s;
	cout<<"Enter an InFix expression:- ";
	cin>>s;
	cout<<"In PostFix :- "<<S1.infixToPostfix(s)<<endl;
}
