#include <iostream>
using namespace std;

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void quickSort(int number[],int first,int last){
   int i, j, pivot, temp;
   if(first<last){
      pivot=first;
      i=first;
      j=last;
      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
         i++;
         while(number[j]>number[pivot])
         j--;
         if(i<j){
            swap(number[i],number[j]);
         }
      }
      swap(number[pivot],number[j]);
      quickSort(number,first,j-1);
      quickSort(number,j+1,last);
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
quickSort(x,0,n-1);
cout<<"\nList after sorting: ";
printArray(x,n);
}
