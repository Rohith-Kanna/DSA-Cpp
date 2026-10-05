#include <iostream>
#include <climits>
using namespace std;

enum Color { WHITE, GRAY, BLACK };

struct vtable {
    char name[10];
    int d;
    enum Color color;
    int pi;
};

class Graph {
    vtable vertex[10];
    int adj[10][10]; // adjacency matrix
    int n;
public:
    void constructgraph(int);
    void initialize();
    void BFS(int s);
    void display();
    void printpath(int i, int src);
};

// --- Construct adjacency matrix graph ---
void Graph::constructgraph(int n) {
    this->n = n;
    cout << "Enter the names of " << n << " vertices:\n";
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i << ": ";
        cin >> vertex[i].name;
    }

    cout << "\nEnter adjacency matrix (0 = no edge, 1 = edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Edge " << vertex[i].name << " -> " << vertex[j].name << " (0/1): ";
            cin >> adj[i][j];
        }
    }
}

// --- Initialize BFS values ---
void Graph::initialize() {
    for (int i = 0; i < n; i++) {
        vertex[i].d = INT_MAX;
        vertex[i].color = WHITE;
        vertex[i].pi = -1;
    }
}

// --- Simple queue implementation ---
class Queue {
    int arr[20];
    int front, rear;
public:
    Queue() { front = -1; rear = -1; }
    bool empty() { return front == -1; }
    void enqueue(int x) {
        if (rear == 19) return;
        if (front == -1) front = 0;
        arr[++rear] = x;
    }
    int dequeue() {
        if (front == -1) return -1;
        int x = arr[front];
        if (front == rear) front = rear = -1;
        else front++;
        return x;
    }
};

// --- BFS Algorithm ---
void Graph::BFS(int s) {
    Queue Q;
    vertex[s].d = 0;
    vertex[s].color = GRAY;
    Q.enqueue(s);

    cout << "\nEdges used in BFS Traversal:\n";

    while (!Q.empty()) {
        int u = Q.dequeue();

        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1 && vertex[v].color == WHITE) {
                vertex[v].color = GRAY;
                vertex[v].d = vertex[u].d + 1;
                vertex[v].pi = u;
                cout << vertex[u].name << " -> " << vertex[v].name << endl;
                Q.enqueue(v);
            }
        }
        vertex[u].color = BLACK;
    }
}

// --- Display Table ---
void Graph::display() {
    cout << "\nNo.\tName\td\tpi\tColor\n";
    for (int i = 0; i < n; i++) {
        cout << i << "\t" << vertex[i].name << "\t" << vertex[i].d << "\t" << vertex[i].pi << "\t";
        if (vertex[i].color == WHITE) cout << "WHITE";
        else if (vertex[i].color == GRAY) cout << "GRAY";
        else cout << "BLACK";
        cout << endl;
    }
}

// --- Print Path (like pseudocode PRINTPATH) ---
void Graph::printpath(int i, int src) {
    if (i == src)
        cout << vertex[i].name << "->";
    else if (vertex[i].pi == -1)
        cout << "No path from " << vertex[src].name << " to " << vertex[i].name;
    else {
        printpath(vertex[i].pi, src);
        cout << vertex[i].name << "->";
    }
}

int main() {
    Graph g;
    int n, s;
    cout << "Enter number of vertices: ";
    cin >> n;

    g.constructgraph(n);
    cout << "\nEnter the index of starting vertex: ";
    cin >> s;

    g.initialize();
    g.BFS(s);
    g.display();

    cout << "\n--- Paths from Source ---\n";
    for (int i = 0; i < n; i++) {
        g.printpath(i, s);
        cout << endl;
    }

    return 0;
}