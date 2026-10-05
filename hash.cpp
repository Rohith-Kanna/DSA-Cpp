#include <iostream>       // For input and output
using namespace std;

#define MAXSIZE 10        // Maximum allowed size for hash table

// ======================================================
// Structure: DataNode
// Each DataNode represents one element in the hash table
// ======================================================
struct DataNode {
    int data;             // Stores the actual value (key)
    DataNode* link;       // Pointer to the next node in the chain (for collisions)
};

// ======================================================
// Structure: HeadNode
// Each HeadNode represents one index (bucket) in the hash table
// ======================================================
struct HeadNode {
    int count;            // Number of elements in this bucket
    DataNode* first;      // Pointer to the first DataNode (start of chain)
};

// ======================================================
// Function: createHashTable
// Purpose: Initialize all buckets in the hash table as empty
// ======================================================
void createHashTable(HeadNode hashTable[], int size) {
    for (int i = 0; i < size; i++) {
        hashTable[i].count = 0;    // Initially no elements in this index
        hashTable[i].first = nullptr;  // No linked list yet
    }
}

// ======================================================
// Function: createNode
// Purpose: Create and return a new DataNode with given key
// ======================================================
DataNode* createNode(int key) {
    DataNode* newNode = new DataNode;  // Allocate memory for a new node
    newNode->data = key;               // Store the key value
    newNode->link = nullptr;           // Set next pointer to null
    return newNode;                    // Return the new node
}

// ======================================================
// Function: hashFunction
// Purpose: Compute the hash index using modulo division
// Formula: hashIndex = key % size
// ======================================================
int hashFunction(int key, int size) {
    int hashIndex = key % size;        // Compute hash index
    if (hashIndex < 0)                 // If key is negative, make index positive
        hashIndex += size;
    return hashIndex;                  // Return final hash index
}

// ======================================================
// Function: insertToHashTable
// Purpose: Insert a new key into the hash table
// Collision Handling: Separate Chaining using linked list
// ======================================================
bool insertToHashTable(HeadNode hashTable[], int size, int key) {
    int hashIndex = hashFunction(key, size);   // Compute where to store the key
    DataNode* newNode = createNode(key);       // Create a new node for the key

    // Insert at beginning of linked list at hashIndex
    newNode->link = hashTable[hashIndex].first;  // Point new node to current first
    hashTable[hashIndex].first = newNode;        // Make new node the first node
    hashTable[hashIndex].count++;                // Increase count for that index

    cout << "Inserted at " << hashIndex << endl; // Display where element was stored
    return true;
}

// ======================================================
// Function: searchInHashTable
// Purpose: Search for a given key in the hash table
// ======================================================
bool searchInHashTable(HeadNode hashTable[], int size, int key, int &locn) {
    int hashIndex = hashFunction(key, size);          // Compute which index to search
    DataNode* searchNode = hashTable[hashIndex].first; // Get the start of chain

    // Traverse the linked list at this index
    while (searchNode != nullptr) {
        if (searchNode->data == key) {   // Key found
            locn = hashIndex;            // Store index in locn variable
            return true;
        }
        searchNode = searchNode->link;   // Move to next node
    }
    return false;  // Key not found in hash table
}

// ======================================================
// Function: displayHashTable
// Purpose: Display all elements present in the hash table
// ======================================================
void displayHashTable(HeadNode hashTable[], int size) {
    cout << "\nContents of the HashTable:\n";
    for (int i = 0; i < size; i++) {
        cout << "Elements at index " << i << ": ";

        // If no elements at this index
        if (hashTable[i].first == nullptr) {
            cout << "No data!\n";
        } else {
            // Traverse the linked list at this index
            DataNode* temp = hashTable[i].first;
            while (temp != nullptr) {
                cout << temp->data;        // Print node data
                temp = temp->link;         // Move to next node
                if (temp != nullptr)
                    cout << " -> ";        // Show arrow if another node exists
            }
            cout << endl;
        }
    }
}

// ======================================================
// Function: freeHashTable
// Purpose: Deallocate all dynamically allocated memory
// ======================================================
void freeHashTable(HeadNode hashTable[], int size) {
    for (int i = 0; i < size; i++) {
        DataNode* current = hashTable[i].first;   // Start at head of each chain
        while (current != nullptr) {
            DataNode* next = current->link;       // Save next node
            delete current;                       // Delete current node
            current = next;                       // Move to next node
        }
        // Reset bucket after deleting all nodes
        hashTable[i].first = nullptr;
        hashTable[i].count = 0;
    }
}

// ======================================================
// Main Function
// Provides menu to Insert, Search, Display, and Exit
// ======================================================
int main() {
    int size;
    cout << "Enter Hash Table Size: ";
    cin >> size;

    // Validate user input
    if (size <= 0 || size > MAXSIZE) {
        cout << "Invalid size! Using default size " << MAXSIZE << endl;
        size = MAXSIZE;
    }

    // Declare the hash table array
    HeadNode hashTable[MAXSIZE];

    // Initialize hash table buckets
    createHashTable(hashTable, size);

    int option;  // Menu choice

    // Menu-driven loop
    do {
        cout << "\nOptions: 1.Insert, 2.Search, 3.Display, 4.Exit\n";
        cout << "Enter option: ";
        cin >> option;

        if (option == 1) {
            // Insert new element
            int data;
            cout << "Enter data: ";
            cin >> data;
            insertToHashTable(hashTable, size, data);
        } 
        else if (option == 2) {
            // Search for an element
            int data, locn = -1;
            cout << "Enter data: ";
            cin >> data;
            bool found = searchInHashTable(hashTable, size, data, locn);
            if (found)
                cout << "Element Found at " << locn << endl;
            else
                cout << "Element not found\n";
        } 
        else if (option == 3) {
            // Display all contents
            displayHashTable(hashTable, size);
        } 
        else if (option == 4) {
            // Exit program
            cout << "Exiting...\n";
        } 
        else {
            cout << "Invalid option!\n";
        }

    } while (option != 4);  // Repeat until Exit is chosen

    // Free dynamically allocated nodes before program ends
    freeHashTable(hashTable, size);
    return 0;
}
