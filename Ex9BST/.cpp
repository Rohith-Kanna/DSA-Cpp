// bst operations (my own code)
#include <iostream>
using namespace std;

class Node //DOUBLY LINKED LIST NODE
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class BST
{
public:
    Node *root;

    BST()
    {
        root = NULL;
    }
    Node *addBST(Node *root, int val)
    {
        Node *NN = new Node(val);
        if (root == NULL)
        {
            root = NN; //add
            return root;
        }
        else if (root->data <= val)
            root->right= addBST(root->right, val);
        else if (root->data > val)
            root->left= addBST(root->left, val);
        return root;
    }
    void insert(int val)
    {
        root = addBST(root, val);
    }

    void inorder(Node *root) // inorder
    {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    void display()
    {
        inorder(root);
        cout << " ";
    }
    Node *delBST(Node *root, int val)
    {
        if (root == NULL)
            return root; // searching the node
        else if (root->data > val)
            root->left= delBST(root->left, val);
        else if (root->data <val)
            root->right= delBST(root->right, val);
        else // this is the node to be deleted
        {
            if (root->right == NULL)
            {
                Node *temp = root->left;
                delete root;
                 return temp;
            }
            else if (root->left == NULL)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else
            {
                Node *largest = largeBST(root->left); // taking the largest node of left subtree
                root->data = largest->data;
                root->left = delBST(root->left, largest->data); // deleting the largest value after interchanging with the node to be deleted
            }
        }
        return root;
    }
    void Delete(int v)
    {
        root = delBST(root, v);
    }
    Node *largeBST(Node *root)
    {
        if (root->right == NULL)
            return root;
        else
            return largeBST(root->right);
    }
    
    Node* searchBST(Node* root,int v)
    {
        if(root==NULL)return NULL;
        else if(v>root->data)return searchBST(root->right,v);
        else if(v<root->data)return searchBST(root->left,v);
        else
        return root;
    }
    void search(int val)
    {
        if(searchBST(root,val)!=NULL)cout<<"Found"<<endl;
        else cout<<"not Found"<<endl;
    }
};

int main() //insert, delete, search, display
{
   BST b;
    b.insert(10);
    b.insert(20);
    b.insert(5);
    b.insert(15);
    b.search(15);
    b.search(99);
    b.display();
    cout<<endl;// 5 10 15 20
    b.Delete(5);
    b.display();  
    cout<<endl;// 10 15 20
    b.Delete(20);
    b.display();
    cout<<endl;// 10 15
}