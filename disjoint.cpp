#include <iostream>
using namespace std;
struct node
{
    int data;
    int rank;
    node *parent;
};
class DisjointSet
{
private:
    node *element[50];
    int ne;

public:
    DisjointSet()
    {
        ne = 0;
    }
    void MakeSet(int v)
    {
        cout << "Creating a new singleton set with element {" << v << "}" << endl;
        node *n = new node;
        n->data = v;
        n->parent = n;
        n->rank = 1;
        ne++;
        element[v] = n;
    }
    node* FindSet(int v)
    {
        cout << "Representative element for set " << v;
        node *t = FindSet(element[v]); 
        cout << " is : " << t->data << endl;
        return t;
    }
    node* FindSet(node *u)
    {   
        if (u->parent != u)
            u->parent = FindSet(u->parent);
        return u->parent;
    }
    void Union(int u, int v)
    {
        cout << "Combining set " << u << " and set " << v << endl;
        node *x = FindSet(u);
        node *y = FindSet(v);
        if (x->data == y->data)
        {
            cout << "Both elements belongs to same set. Union not possible." << endl;
            return;
        }
        else
            Link(x, y);
    }

    void Link(node *x, node *y)
    {
        if (x->rank > y->rank)
        {
            y->parent = x;
            cout << y->data << "\'s parent is " << x->data << endl;
        }
        else
        {
            x->parent = y;
            cout << x->data << "\'s parent is " << y->data << endl;
            if (x->rank == y->rank)
                y->rank++;
        }
    }
    void Display()
    {
        for (int i = 0; i < ne; i++)
            cout << element[i]->data << "\'s parent: " << element[i]->parent->data << endl;
    }
};

int main()
{
    DisjointSet ds;
    int ne, x, y, op;
    node *t;
    cout << "Enter Number of elements: ";
    cin >> ne;
    for (int i = 0; i < ne; i++)
    {
        ds.MakeSet(i);   

    }

    cout << "Elements in the set are: " << endl;
    ds.Display();
    do
    {
        cout << "1. Find Set   2. Union   3. Display sets" << endl;
        cout << "Enter your option: ";
        cin >> op;
        switch (op)
        {
        case 1:
            cout << "Enter the element to search: ";
            cin >> x;
            t = ds.FindSet(x);
            break;
        case 2:
            cout << "Enter the elements to combine: ";
            cin >> x >> y;
            ds.Union(x, y);
            break;
        case 3:
            cout << "Elements in the set are: " << endl;
            ds.Display();
        }
    } while (op < 4);
    return 0;
}

// #include <iostream>
// using namespace std;

// // Structure representing each node in the disjoint set
// struct node {
//     int data;     // value of the element
//     int rank;     // rank (approximate tree height)
//     node *parent; // pointer to parent node
// };

// // Class for Disjoint Set (Union-Find) operations
// class DisjointSet {
// private:
//     node *element[50]; // array of element pointers
//     int ne;            // number of elements

// public:
//     // Constructor
//     DisjointSet() {
//         ne = 0;
//     }

//     // Create a new singleton set
//     void MakeSet(int v) {
//         cout << "Creating a new singleton set with element {" << v << "}" << endl;
//         node *n = new node();
//         n->data = v;
//         n->parent = n;  // parent of itself
//         n->rank = 1;
//         element[v] = n;
//         ne++;
//     }

//     // Find representative of a set (by element index)
//     node* FindSet(int v) {
//         cout << "Representative element for set " << v;
//         node *rep = FindSet(element[v]);  // call recursive version
//         cout << " is : " << rep->data << endl;
//         return rep;
//     }

//     // Find representative of a set (by node pointer)
//     node* FindSet(node *u) {
//         // Path compression: make each node point directly to root
//         if (u->parent != u)
//             u->parent = FindSet(u->parent);
//         return u->parent;
//     }

//     // Union of two sets
//     void Union(int u, int v) {
//         cout << "Combining set " << u << " and set " << v << endl;
//         node *x = FindSet(u);
//         node *y = FindSet(v);

//         if (x->data == y->data) {
//             cout << "Both elements belong to the same set. Union not possible.\n";
//             return;
//         }

//         Link(x, y);
//     }

//     // Link two trees by rank
//     void Link(node *x, node *y) {
//         // Attach smaller rank tree under higher rank tree
//         if (x->rank > y->rank) {
//             y->parent = x;
//             cout << y->data << "'s parent is now " << x->data << endl;
//         } else {
//             x->parent = y;
//             cout << x->data << "'s parent is now " << y->data << endl;
//             if (x->rank == y->rank)
//                 y->rank++; // increase rank if both were equal
//         }
//     }

//     // Display all elements and their parent
//     void Display() {
//         cout << "\nCurrent Sets (element → parent):\n";
//         for (int i = 0; i < ne; i++) {
//             cout << element[i]->data << " → " << element[i]->parent->data << endl;
//         }
//         cout << endl;
//     }

//     // Main menu for user interaction
//     void Menu() {
//         int op, x, y;
//         node *t;

//         do {
//             cout << "1. Find Set   2. Union   3. Display sets   4. Exit\n";
//             cout << "Enter your option: ";
//             cin >> op;

//             switch (op) {
//                 case 1:
//                     cout << "Enter the element to search: ";
//                     cin >> x;
//                     t = FindSet(x);
//                     break;

//                 case 2:
//                     cout << "Enter the two elements to combine: ";
//                     cin >> x >> y;
//                     Union(x, y);
//                     break;

//                 case 3:
//                     Display();
//                     break;

//                 case 4:
//                     cout << "Exiting...\n";
//                     break;

//                 default:
//                     cout << "Invalid option. Try again.\n";
//             }
//         } while (op != 4);
//     }
// };

// // Main function
// int main() {
//     DisjointSet ds;
//     int n;
//     cout << "Enter number of elements: ";
//     cin >> n;

//     // Create individual sets
//     for (int i = 0; i < n; i++) {
//         ds.MakeSet(i);
//     }

//     ds.Display(); // Show initial sets
//     ds.Menu();    // Run operations
//     return 0;
// }
