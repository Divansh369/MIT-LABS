#include <iostream>
using namespace std;

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void insertionSort(int arr[], int n) 
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++)
    {
      cout << arr[i] << " "; 
    }
} 

int main(){
int n,i;
cout<<"Enter number of elements: ";
cin>>n;
int x[n];
for (i=0; i < n; i++)
{
cout << "Enter element: "; 
cin>>x[i];
}
cout<<"\nList before sorting: ";
printArray(x,n);
insertionSort(x,n);
cout<<"\nList after sorting: ";
printArray(x,n);
}
