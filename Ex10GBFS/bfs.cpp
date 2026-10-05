#include <iostream>
#include <string>
using namespace std;
enum vcolor
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
    int pi;
    vcolor color;
    node *adjptr;
};
struct qnode
{
    int data;
    qnode *next;
};
class Queue
{
    qnode *front;
    qnode *rear;

public:
    Queue()
    {
        front = rear = NULL;
    }
    bool isEmpty()
    {
        return front == NULL;
    }
    void enqueue(int val)
    {
        qnode *temp = new qnode();
        temp->data = val;
        temp->next = NULL;
        if (rear == NULL)
        { // only element
            front = rear = temp;
        }
        else
        { // insert at rear
            rear->next = temp;
            rear = temp;
        }
    }
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow\n";
            return -1;
        }
        qnode *temp = front;
        int val = temp->data;
        front = front->next;
        if (front == NULL)
            rear = NULL; // queue became empty
        delete temp;
        return val;
    }
};
class graph
{
    int n;            // number of vertices
    vnode vertex[10]; // vertex table
public:
    void createGraph()
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
        cout << "Enter number of edges: "; //no of connections for each vertex
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
    void BFS(int s)
    {
        for (int i = 0; i < n; i++)
        {
            vertex[i].color = WHITE;
            vertex[i].d = 9999;
            vertex[i].pi = -1;
        }

        vertex[s].color = GRAY;
        vertex[s].d = 0;
        vertex[s].pi = -1;

        Queue Q;
        Q.enqueue(s);
        cout << "\nBFS Traversal Order: ";
        while (!Q.isEmpty())
        {
            int u = Q.dequeue();
            cout << vertex[u].name << " ";
            node *temp = vertex[u].adjptr;  
            while (temp != NULL)
            {
                int v = temp->ver;
                if (vertex[v].color == WHITE)
                {
                    vertex[v].color = GRAY;
                    vertex[v].d = vertex[u].d + 1;
                    vertex[v].pi = u;
                    Q.enqueue(v);
                }
                temp = temp->next;
            }
            vertex[u].color = BLACK; //u is fully explored
        }
        cout << "\n\nVertex Details:\n";
        cout << "Vertex\tColor\tDistance\tParent\n";
        for (int i = 0; i < n; i++)
        {
            // print vertex name
            cout << vertex[i].name << "\t";

            // print color
            if (vertex[i].color == WHITE)
                cout << "WHITE\t";
            else if (vertex[i].color == GRAY)
                cout << "GRAY\t";
            else
                cout << "BLACK\t";

            
            cout << vertex[i].d << "\t\t";

            // print parent name
            if (vertex[i].pi == -1)
                cout << "NIL\n";
            else
                cout << vertex[vertex[i].pi].name << "\n";
        }
        cout << "\nPaths from source " << vertex[s].name << ":\n";
        for (int i = 0; i < n; i++)
        {
            cout << vertex[s].name << " -> " << vertex[i].name << ": ";
            PRINT_PATH(s, i);
            cout << endl;
        }
    }
    void PRINT_PATH(int s, int v)
    {
        if (s == v)
            cout << vertex[s].name;
        else if (vertex[v].pi == -1)
            cout << "No path";
        else
        {
            PRINT_PATH(s, vertex[v].pi);
            cout << " -> " << vertex[v].name;
        }
    }
};
int main()
{
    graph g;
    g.createGraph();

    int start;
    cout << "Enter start vertex index for BFS: ";
    cin >> start;

    g.BFS(start);
}