#include <iostream>
using namespace std;

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
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
bubbleSort(x,n);
cout<<"\nList after sorting: ";
printArray(x,n);
}
