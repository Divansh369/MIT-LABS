#include <iostream>
using namespace std;

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
    for (i = 0; i < n-1; i++)
    {
        min_idx = i; 
        for (j = i+1; j < n; j++)
        {
          if (arr[j] < arr[min_idx]) 
              min_idx = j;
        }
        if (min_idx!=i)
            swap(&arr[min_idx], &arr[i]);
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
selectionSort(x,n);
cout<<"\nList after sorting: ";
printArray(x,n);
}
