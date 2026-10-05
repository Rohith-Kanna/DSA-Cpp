// sentinel search
#include <iostream>
using namespace std;

class sent
{
	int s, key, arr[100];

public:
	sent(int n)
	{
		s = n;
	}
	void input()
	{
		cout << "Enter " << s << " elememts:" << endl;
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
	void sentinel(int key)
	{
		arr[s] = key;
		int i = 0;
		while (key != arr[i])
		{
			i++;
		}	
		if (i < s)
			cout << key << " is found at " << i << endl;
		else
			cout << key << " is not present in the array" << endl;
	}
};
int main()
{
	int n, key;
	cout << "Enter no. of elements: " << endl;
	cin >> n;
	sent obj(n);
	obj.input();
	obj.disp();
	cout << "Enter element to be searched:" << endl;
	cin >> key;
	obj.sentinel(key);
}
