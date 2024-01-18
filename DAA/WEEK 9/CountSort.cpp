#include <bits/stdc++.h>
using namespace std;
 
void countSort(int arr[], int n)
{
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;
 
    vector<int> count(range), output(arr.size());
    for (int i = 0; i < arr.size(); i++)
        count[arr[i] - min]++;
 
    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];
 
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
 
    for (int i = 0; i < arr.size(); i++)
        arr[i] = output[i];
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
countSort(x,n);
cout<<"\nList after sorting: ";
printArray(x,n);
}
