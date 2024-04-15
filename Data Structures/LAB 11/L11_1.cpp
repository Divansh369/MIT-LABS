#include <iostream>
using namespace std;
 
int search(int array[], int n, int x)
{
    for (int i = 0; i < n; i++)
        if (array[i] == x)
            return i;
    return -1;
}
int binarySearch(int array[], int x, int low, int high)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (array[mid] == x)
            return mid; 
        if (array[mid] < x)
            low = mid + 1; 
        else
            high = mid - 1;
    }
    return -1;
}
int main(){
 int x,n;
 cout<<"Enter size of array: ";	
 cin>>n;
 int array[n];
 for (int i=0;i<n;i++){
 	cout<<"\nEnter element: ";	
    cin>>array[i];
 }
 cout<<"\nEnter element to be searched: "<<endl;	
 cin>>x;
 cout<<"\nUsing linear search: "<<endl;
 int result1 = search(array, n, x);
    (result1 == -1)
        ? cout << "Element not found"<<endl
        : cout << "Element found at index: " <<result1<<endl;
 cout<<"\nUsing binary search: "<<endl;
 int result2 = binarySearch(array, x, 0, n - 1);
        if (result2 == -1)
            cout<<"Element not found."<<endl;
        else
            cout<<"Element is found at index: "<<result2<<endl;
return 0;
}
