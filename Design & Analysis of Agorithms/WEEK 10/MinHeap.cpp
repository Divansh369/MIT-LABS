#include <iostream>

using namespace std;
void heapify(int arr[], int n, int i)
{
    int smallest = i; // Initialize smallest as root
    int left = 2*i + 1; // Left child index
    int right = 2*i + 2; // Right child index
 
    if(left<n && arr[left]<arr[smallest])
        smallest=left;
    if(right<n && arr[right]<arr[smallest])
        smallest=right;    
    if(i!=smallest){
        swap(arr[i],arr[smallest]);
        heapify(arr,n,smallest);
    }
}

void deleter(int a[],int &n){
    if(n==0)return;
    a[0]=a[n-1];
    n--;
    heapify(a,n,0);
}

void heapsort(int a[],int n){
    for(int i=(n/2)-1;i>=0;i--){
        heapify(a,n,i);
    }
}
int main()
{
    int n;
    cout<<"Enter n: "<<endl;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    heapsort(a,n);
    cout<<"Elements are: "<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    deleter(a,n);
    
    cout<<"Elements after deleting minimum: "<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
