// cdll.cpp
// Ex. No: 08 - Demonstration of Circular Doubly Linked List (CDLL)
// Aim: Implement insertion, deletion, search, traversal (head->rear and rear->head), count, and destroy
// Circular doubly linked list: rear->next = head and head->prev = rear

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int v) : data(v), prev(NULL), next(NULL) {}
};

class CDLL {
private:
    Node* head; // pointer to head (if null -> empty)
    int count;

public:
    // createCDLL(list)
    CDLL() : head(NULL), count(0) {}

    bool emptyCDLL() const {
        return (count == 0);
    }

    int cdllCount() const {
        return count;
    }

    // searchList(list, pPre, pLoc, target)
    // For CDLL we return found and pPre/pLoc using reference params.
    // pLoc points to first node with >= target or head if wrapped.
    bool searchList(int target, Node*& pPre, Node*& pLoc) {
        pPre = NULL;
        if (head == NULL) return false;
        pLoc = head;
        // immediate match
        if (pLoc->data == target) return true;
        // if target < head->data then predecessor is last node < head (we will find it in loop)
        if (target < head->data) {
            // we will scan and stop where node->data >= target or we've circled back
            pPre = head->prev;
            pLoc = head;
            return false;
        }
        // general case: advance until pLoc->data >= target or come back to head
        pPre = head;
        pLoc = head->next;
        while (pLoc != head && target > pLoc->data) {
            pPre = pLoc;
            pLoc = pLoc->next;
        }
        if (pLoc == head) return false;
        return (pLoc->data == target);
    }

    // insertCDLL(list, dataIn)
    int insertCDLL(int dataIn) {
        Node* pred = NULL;
        Node* loc = NULL;
        bool found = searchList(dataIn, pred, loc);
        if (found) return 2; // duplicate

        Node* newNode = new Node(dataIn);
        ++count;

        if (head == NULL) {
            // first node points to itself
            newNode->next = newNode->prev = newNode;
            head = newNode;
            return 1;
        }

        // if predecessor is null => position before head (insert as new head)
        if (pred == NULL) {
            // insert before head, but maintain circular links
            Node* tail = head->prev;
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
            // if dataIn < head->data then newNode becomes head (maintain order)
            if (dataIn < head->data) head = newNode;
            return 1;
        } else {
            // insert after pred
            newNode->next = pred->next;
            newNode->prev = pred;
            pred->next->prev = newNode;
            pred->next = newNode;
            // if we inserted before head, adjust head if needed
            if (pred == head->prev && dataIn >= pred->data) {
                // inserted at end -> tail updated implicitly; head unchanged
            }
            // if inserted before current head and is smallest, update head
            if (dataIn < head->data) head = newNode;
            return 1;
        }
    }

    // deleteCDLL(list, target)
    bool deleteCDLL(int target) {
        if (head == NULL) return false;
        Node* pred = NULL;
        Node* loc = NULL;
        bool found = searchList(target, pred, loc);
        if (!found) {
            // special case: might be in head if head->data == target (searchList handles equality early)
            if (head->data != target) return false;
            loc = head;
        }

        // If list has only one node
        if (count == 1 && head == loc) {
            delete loc;
            head = NULL;
            count = 0;
            return true;
        }

        // Remove loc
        loc->prev->next = loc->next;
        loc->next->prev = loc->prev;
        if (loc == head) head = loc->next; // update head if needed
        delete loc;
        --count;
        return true;
    }

    // displayHeadToRear(list)
    void displayHeadToRear() const {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        Node* p = head;
        do {
            cout << p->data;
            p = p->next;
            if (p != head) cout << " -> ";
        } while (p != head);
        cout << "\n";
    }

    // displayRearToHead(list)
    void displayRearToHead() const {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }
        Node* p = head->prev; // tail
        Node* tail = p;
        do {
            cout << p->data;
            p = p->prev;
            if (p != tail) cout << " -> ";
        } while (p != tail);
        cout << "\n";
    }

    // destroyCDLL(list)
    void destroyCDLL() {
        if (head == NULL) return;
        Node* p = head->next;
        while (p != head) {
            Node* t = p;
            p = p->next;
            delete t;
        }
        delete head;
        head = NULL;
        count = 0;
    }

    // searchCDLLFromHead(list, target) - returns 1-based position or -1
    int searchCDLLFromHead(int target) const {
        if (!head) return -1;
        Node* p = head;
        int pos = 1;
        if (p->data == target) return 1;
        p = p->next;
        ++pos;
        while (p != head && target > p->data) {
            p = p->next;
            ++pos;
        }
        if (p == head) return -1;
        return (p->data == target) ? pos : -1;
    }

    // searchCDLLFromRear(list, target) - returns 1-based position from rear or -1
    int searchCDLLFromRear(int target) const {
        if (!head) return -1;
        Node* p = head->prev; // tail
        int pos = 1;
        if (p->data == target) return 1;
        p = p->prev;
        ++pos;
        while (p != head->prev && target < p->data) {
            p = p->prev;
            ++pos;
        }
        if (p == head->prev) return -1;
        return (p->data == target) ? pos : -1;
    }

    ~CDLL() {
        destroyCDLL();
    }
};

// Menu-driven main
int main() {
    CDLL list;
    int choice, x;
    cout << "Circular Doubly Linked List (CDLL) - Menu\n";
    do {
        cout << "\n1.Insert  2.Delete  3.SearchFromHead  4.SearchFromRear\n";
        cout << "5.DisplayHeadToRear  6.DisplayRearToHead  7.Count  8.Destroy  9.Exit\n";
        cout << "Choose option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> x;
                {
                    int r = list.insertCDLL(x);
                    if (r == 1) cout << x << " inserted\n";
                    else cout << "Duplicate. Insert failed\n";
                }
                break;

            case 2:
                cout << "Enter data to delete: ";
                cin >> x;
                if (list.deleteCDLL(x)) cout << x << " deleted\n";
                else cout << "Data not found\n";
                break;

            case 3:
                cout << "Enter key to search (from head): ";
                cin >> x;
                cout << "Position: " << list.searchCDLLFromHead(x) << "\n";
                break;

            case 4:
                cout << "Enter key to search (from rear): ";
                cin >> x;
                cout << "Position from rear: " << list.searchCDLLFromRear(x) << "\n";
                break;

            case 5:
                cout << "Head to Rear: ";
                list.displayHeadToRear();
                break;

            case 6:
                cout << "Rear to Head: ";
                list.displayRearToHead();
                break;

            case 7:
                cout << "Count: " << list.cdllCount() << "\n";
                break;

            case 8:
                list.destroyCDLL();
                cout << "List destroyed\n";
                break;

            case 9:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid option\n";
        }
    } while (choice != 9);

    return 0;
}
