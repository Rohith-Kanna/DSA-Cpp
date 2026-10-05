#include <iostream>
#include <string.h>
using namespace std;
enum Color
{
    WHITE,
    GRAY,
    BLACK
};
struct node
{
    int ver;
    node *next;
};

struct vnode
{
    string name;
    int d;
    int f;
    Color color;
    int pi;
    node *adjptr;
};
class Graph
{
    vnode vertex[10];
    int n;
    int time;

public:
    void create()
    {
        cout << "Enter number of vertices: ";
        cin >> n;
        cout << "Enter vertex names:\n"; // initializing vertex table
        for (int i = 0; i < n; i++)
        {
            cin >> vertex[i].name;
            vertex[i].adjptr = NULL;
        }
        int edges;
        cout << "Enter number of edges: "; // no of connections for each vertex
        cin >> edges;
        cout << "Enter edges (u v) as vertex indices (0-based):\n";
        for (int i = 0; i < edges; i++)
        {
            int u, v;
            cin >> u >> v;

            node *temp = new node(); // add edge u->v
            temp->ver = v;
            temp->next = vertex[u].adjptr;
            vertex[u].adjptr = temp;

            temp = new node(); // add edge v->u for undirected graph
            temp->ver = u;
            temp->next = vertex[v].adjptr;
            vertex[v].adjptr = temp;
        }
    }
    void DFS()
    {
        int i;
        for (i = 0; i < n; i++)
        {
            vertex[i].color = WHITE;
            vertex[i].pi = -1;
        }
        for (i = 0; i < n; i++)
            if (vertex[i].color == WHITE)
                DFS_Visit(i);
    }

    void DFS_Visit(int u)
    {
        node *temp;
        int v;
        time++;

        vertex[u].d = time;
        vertex[u].color = GRAY;
        temp = vertex[u].adjptr;

        while (temp != NULL)
        {
            v = temp->ver;
            if (vertex[v].color == WHITE)
            {
                vertex[v].pi = u;
                cout << vertex[u].name << "-->" << vertex[v].name << endl;
                DFS_Visit(v);
            }
            temp = temp->next;
        }
        time++;
        vertex[u].f = time;
        vertex[u].color = BLACK;
    }

    void display()
    {
        int i;
        cout << "No.\tName\td\tf\tp\tAdjacent Node List " << endl;
        for (i = 0; i < n; i++)
        {
            cout << i << "\t" << vertex[i].name << "\t" << vertex[i].d << "\t" << vertex[i].f << "\t" << vertex[i].pi << "   ";
            node *t = vertex[i].adjptr;
            while (t != NULL)
            {
                cout << "-->" << t->ver;
                t = t->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g;
    int s, op;
    g.create();
    g.DFS();
    g.display();
    return 0;
}

// #include <iostream>
// #include <string>
// using namespace std;

// // Enum for vertex colors used in DFS
// enum Color { WHITE, GRAY, BLACK };

// // Structure for adjacency list node
// struct node {
//     int ver;
//     node *next;
// };

// // Structure for vertex details
// struct vnode {
//     string name;
//     int d;          // discovery time
//     int f;          // finish time
//     Color color;
//     int pi;         // parent index
//     node *adjptr;   // adjacency list pointer
// };

// // Graph class
// class Graph {
//     int n;               // number of vertices
//     int time;            // DFS time counter
//     vnode vertex[10];    // vertex table

// public:
//     // Create graph
//     void createGraph() {
//         cout << "Enter number of vertices: ";
//         cin >> n;
//         cout << "Enter vertex names:\n";
//         for (int i = 0; i < n; i++) {
//             cin >> vertex[i].name;
//             vertex[i].adjptr = NULL;
//         }

//         int edges;
//         cout << "Enter number of edges: ";
//         cin >> edges;
//         cout << "Enter edges (u v) as vertex indices (0-based):\n";
//         for (int i = 0; i < edges; i++) {
//             int u, v;
//             cin >> u >> v;

//             // Add edge u -> v
//             node *temp = new node();
//             temp->ver = v;
//             temp->next = vertex[u].adjptr;
//             vertex[u].adjptr = temp;

//             // Add edge v -> u (for undirected graph)
//             temp = new node();
//             temp->ver = u;
//             temp->next = vertex[v].adjptr;
//             vertex[v].adjptr = temp;
//         }
//     }

//     // Perform DFS
//     void DFS() {
//         for (int i = 0; i < n; i++) {
//             vertex[i].color = WHITE;
//             vertex[i].pi = -1;
//         }
//         time = 0;

//         cout << "\nDFS Traversal Order: ";
//         for (int i = 0; i < n; i++) {
//             if (vertex[i].color == WHITE)
//                 DFS_Visit(i);
//         }

//         cout << "\n";
//         display();
//     }

//     // Recursive DFS visit
//     void DFS_Visit(int u) {
//         time++;
//         vertex[u].d = time;
//         vertex[u].color = GRAY;

//         // print when vertex is discovered (DFS traversal order)
//         cout << vertex[u].name << " ";

//         node *temp = vertex[u].adjptr;
//         while (temp != NULL) {
//             int v = temp->ver;
//             if (vertex[v].color == WHITE) {
//                 vertex[v].pi = u;
//                 DFS_Visit(v);
//             }
//             temp = temp->next;
//         }

//         vertex[u].color = BLACK;
//         time++;
//         vertex[u].f = time;
//     }

//     // Display final table
//     void display() {
//         cout << "\n\nVertex Details after DFS:\n";
//         cout << "Index\tName\tColor\tDiscovery\tFinish\tParent\n";
//         for (int i = 0; i < n; i++) {
//             cout << i << "\t" << vertex[i].name << "\t";

//             if (vertex[i].color == WHITE) cout << "WHITE\t";
//             else if (vertex[i].color == GRAY) cout << "GRAY\t";
//             else cout << "BLACK\t";

//             cout << vertex[i].d << "\t\t" << vertex[i].f << "\t\t";

//             if (vertex[i].pi == -1)
//                 cout << "NIL\n";
//             else
//                 cout << vertex[vertex[i].pi].name << "\n";
//         }
//     }
// };

// int main() {
//     Graph g;
//     g.createGraph();
//     g.DFS();
//     return 0;
// }
