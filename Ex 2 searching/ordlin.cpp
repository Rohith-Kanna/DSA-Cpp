#include <iostream>
using namespace std;

class OrderedListSearch {
    int s, arr[100];

public:
    OrderedListSearch(int n) {
        s = n;
    }

    void input() {
        cout << "Enter " << s << " elements in sorted order:" << endl;
        for (int i = 0; i < s; i++) {
            cin >> arr[i];
        }
    }

    void disp() {
        cout << "Displaying Array:" << endl;
        for (int i = 0; i < s; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void search(int target) {
        int looker = 0, locn = -1;
        bool found = false;

        // Step 1: check if target < last element
        if (target < arr[s - 1]) {
            looker = 0;
            while (looker <= s - 1 && target > arr[looker]) {
                looker++;
            }
            locn = looker;
        }
        else {
            locn = s - 1;
        }

        // Step 2: check if found
        if (arr[locn] == target) {
            found = true;
            cout << target << " found at index " << locn << endl;
        } else {
            found = false;
            cout << target << " not found in the array" << endl;
        }
    }
};

int main() {
    int n, key;
    cout << "Enter number of elements: ";
    cin >> n;

    OrderedListSearch obj(n);
    obj.input();
    obj.disp();

    cout << "Enter element to search: ";
    cin >> key;

    obj.search(key);

    return 0;
}
