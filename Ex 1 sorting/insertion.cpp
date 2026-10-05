//insertion sort
#include<iostream>
using namespace std;
int main()
{
	int s;
	cout<<"Enter no. of elements: "<<endl;
	cin>>s;
	int arr[s];
	cout<<"Enter "<<s<<" elememts:"<<endl;
	for(int i=0;i<s;i++)
	{
		cin>>arr[i];
	}
	//sorting begins here
	for(int i=1;i<s;i++)
	{
		int key=arr[i];
		int min=i;
		int j=i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=key;
		
		//prints only if swap occurs
		cout<<"Pass "<<i<<": ";
			for(int i=0;i<s;i++)
			{
				cout<<arr[i]<<" ";
			}
			cout<<endl;
	}
}
