#include <iostream>
using namespace std;

class prob
{
    int s, arr[100];

public:
    prob(int n)
    {
        s = n;
    }

    void input()
    {
        cout << "Enter " << s << " elements:" << endl;
        for (int i = 0; i < s; i++)
        {
            cin >> arr[i];
        }
    }

    void disp()
    {
        cout << "Displaying Array:" << endl;
        for (int i = 0; i < s; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void probabilitySearch(int key)
    {
        for (int i = 0; i < s; i++)
        {
            if (arr[i] == key) // found
            {
                cout << key << " found at index " << i << endl;

                // Probability improvement: swap with previous element (if not at front)
                if (i > 0)
                {
                    int temp = arr[i];
                    arr[i] = arr[i - 1];
                    arr[i - 1] = temp;
                }
                return; // stop after finding
            }
        }
        cout << key << " not found in the array" << endl;
    }
};

int main()
{
    int n, key;
    cout << "Enter no. of elements: " << endl;
    cin >> n;
    prob obj(n);
    obj.input();
    obj.disp();

    cout << "Enter element to be searched: " << endl;
    cin >> key;
    obj.probabilitySearch(key);

    cout << "Array after probability search (if found):" << endl;
    obj.disp();

    return 0;
}
