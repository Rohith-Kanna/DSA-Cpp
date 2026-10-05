#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    public:
    Node(int val){
        data= val;
        left = NULL;
        right = NULL;
    }
};

class BST{
    public: 
    int count = 0;
    Node* root;
    BST(){
        root = NULL;
        count = 0;
    }
    Node* addBST(Node* root, int val){
        Node* newnode = new Node(val);
        if(root == NULL){
            root=newnode;
            return root;
        }
        else if(newnode->data>=root->data){
            root->right = addBST(root->right, val);
        }
        else{
            root->left = addBST(root->left,val);
        }
        return root;

 
    }
    void insert(int val){
        root = addBST(root, val);
    }
    void display(){
        inorder(root);
        cout<<" ";
    }
    void inorder(Node* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    Node* delBST(Node* root, int del){
        if(root == NULL)
            return NULL;
        if(del<root->data){
            root->left = delBST(root->left,del);
        }
        else if(del>root->data){
            root->right = delBST(root->right,del);
        }
        else{
            if(root->right == NULL){
                Node* temp = root->left;
                delete root;
                return temp;
            }
            else if(root->left == NULL){
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else{
                Node* largest = largBST(root->left);
                root->data = largest->data;
                root->left = delBST(root->left, largest->data);
            }
        }
        return root;
    }
    void Delete(int val){
        root = delBST(root, val);
    }
    Node* largBST(Node* root){
        while(root->right!=NULL){
            root = root->right;
        }return root;
    }

    Node* searchBST(Node* root, int key){
        if(root==NULL){
            return NULL;
        }
        if(key>root->data){
            return searchBST(root->right, key);
        }
        else if(key<root->data){
            return searchBST(root->left, key);
        }
        else{
            return root;
        }
    }
    void search(int key){
        if(searchBST(root,key)!=NULL){
            cout<<"Found!"<<endl;
        }
        else cout<<"Not Found!"<<endl;
    }

};

int main(){
    BST b;
    b.insert(10);
    b.insert(20);
    b.insert(5);
    b.insert(15);
    b.display();
    cout<<endl;
    b.search(5);
    b.Delete(5);
    b.display();
    cout<<endl;
    b.search(5);
    

}