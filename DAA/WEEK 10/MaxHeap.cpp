#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i; 
    int left = 2*i + 1; 
    int right = 2*i + 2; 
 
    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }       
}


void heapSort(int arr[], int n)
{
    // Build heap
    for (int i = (n / 2) - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // Delete
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
 
// Function to print an array
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << "\n";
}
 

int main()
{

    cout<<"Enter the size of the array: ";
    int n;
    cin>>n;

    int arr[n];

    cout<<"Enter "<<n<<" array elements: ";
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    cout << "Unsorted array:  \n";
    display(arr, n);
    
    heapSort(arr, n);
 
    cout << "Sorted array:  \n";
    display(arr, n);
    
    return 69;
}
