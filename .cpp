#include <iostream>
using namespace std;

class Employee{
    public:
    string name;
    int id;
    string desg;
    
    Employee(){}
    Employee(string n, int i, string d){
        name = n;
        id = i;
        desg = d;
    }
    
    void display(){
        cout<<"Name: "<<name<<" ID: "<<id<<" Designation: "<<desg<<endl;
    }
};

struct Node{
    public:
    Employee emp;
    Node* left;
    Node* right;
    
    Node(Employee e){
        emp = e;
        left = NULL;
        right = NULL;
    }
    
};

class BST{
    
    Node* root;
    int count = 0;
    public: 
    BST(){
        
        root = NULL;
        count = 0;
    }
    
    Node* addBST(Node* root, Employee e){
        //Node* newnode = new Node(e);
        if(root == NULL){
            return new Node(e);
        }
        
        else if(e.id<root->emp.id){
            root->left = addBST(root->left, e);
        }
        else root->right  = addBST(root->right,e);
        count++;
        return root;
    }
    
    void insert(Employee e){
        root = addBST(root,e);
    }
    
    void inorderBST(Node* root){
        if(root==NULL) return;
        inorderBST(root->left);
        cout<<root->emp.id<<" ";
        inorderBST(root->right);
    }
    void preorderBST(Node* root){
        if(root==NULL) return;
        
        cout<<root->emp.id<<" ";
        preorderBST(root->left);
       
        preorderBST(root->right);
    }
    void postorderBST(Node* root){
        if(root==NULL) return;
        
        postorderBST(root->left);
        
        postorderBST(root->right);
        cout<<root->emp.id<<" ";
    }
    void display(){
        inorderBST(root);
        cout<<endl;
        preorderBST(root);
        cout<<endl;
        postorderBST(root);
        cout<<endl;
    }
    
    Node* delBST(Node* root, int id){
        if(root == NULL){
            cout<<"Tree is empty"<<endl;
            return root;
        }
        if(id>root->emp.id){root->right = delBST(root->right, id);}
        else if(id<root->emp.id){root->left = delBST(root->left, id);}
        else{
            if(root->left == NULL){
                root = root->right;
                return root;
            }
            else if(root->right == NULL){
                root= root->left;
                return root;
            }
            else{
                Node* largest = largBST(root->left);
                root->emp = largest->emp;
                root->left = delBST(root->left, largest->emp.id);
            }
        }
        return root;
    }
    Node* largBST(Node* root){
        while(root->right!=NULL){
            root = root->right;
        }
        return root;
    }
    
    void Delete(int id){
        root = delBST(root,id);
    }
    
    Node* SearchBST(Node* root, int id){
        if(root==NULL) return root;
        if(id > root->emp.id) root = SearchBST(root->right, id);
        else if(id<root->emp.id) root = SearchBST(root->left, id);
        else {return root;}
        return root;
 
    }
    void search(int id){
        if(SearchBST(root,id) == NULL){
            cout<<"Not Found!"<<endl;
        }
        else cout<<"Found!"<<endl;
    }
    
    void modify(Employee e1, Employee e2){
        Node* temp = new Node(e2);
        if(temp==NULL){
            cout<<"No such element found";
            return;
        }
        Delete(e2.id);
        insert(e1);
        cout<<"Modified";
    }
};

int main(){
    
    Employee e[10] = {
        {"Shubham", 10,"Manager"},{"niru", 14,"employee1"},{"Amrutha", 11,"CEO"},{"messi", 12,"employee2"},{"Ronaldo", 13,"employee3"},{"Haaland", 15,"employee4"}};
    
    BST b;
    
    b.insert(e[0]);
    b.insert(e[1]);
    b.insert(e[2]);
    b.insert(e[3]);
    b.insert(e[4]);
    b.insert(e[5]);
    b.display();
    
    b.search(15);
    b.Delete(15);
    b.display();
    
    b.search(15);
    b.search(11);
}