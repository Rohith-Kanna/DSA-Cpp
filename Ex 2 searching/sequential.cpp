// sequential serach
#include <iostream>
using namespace std;
int main()
{
	int s, key;
	cout << "Enter no. of elements: " << endl;
	cin >> s;
	int arr[s];
	cout << "Enter " << s << " elememts:" << endl;
	for (int i = 0; i < s; i++)
	{
		cin >> arr[i];
	}
	cout << "Displaying Array:" << endl;
	for (int i = 0; i < s; i++)	
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Enter element to be searched:" << endl;
	cin >> key;
	int i = 0;
	// search begins here
	while (i < s && key != arr[i])
	{
		i++;
	}
	if (arr[i] == key)
		cout << key << " is found at " << i << endl;
	else
		cout << key << " is not present in the array" << endl;
}
