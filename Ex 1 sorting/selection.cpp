// selection sort
#include <iostream>
using namespace std;
int main()
{
	int s;
	cout << "Enter no. of elements: " << endl;
	cin >> s;
	int arr[s];
	cout << "Enter " << s << " elememts:" << endl;
	for (int i = 0; i < s; i++)
	{
		cin >> arr[i];
	}
	cout << "Array before Sorting: " << endl;
	for (int i = 0; i < s; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	// sorting begins here
	for (int i = 0; i < s - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < s; j++)
		{
			if (arr[j] < arr[min])
				min = j;
		}
		if (min != i)
		{
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;

			//prints only if swap occurs
			cout << "Pass " << i + 1 << ": ";
			for (int i = 0; i < s; i++)
			{
				cout << arr[i] << " ";
			}
			cout << endl;
		}
	}
}
