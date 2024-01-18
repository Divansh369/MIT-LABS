#include <iostream>
using namespace std;

void Bubble_sort(int x[],int n){
	int temp;
	for (int i=0;i<n;i++){
		for (int j=i+1;j<n;j++){
			if (x[j]<x[i]){
				temp=x[i];
				x[i]=x[j];
				x[j]=temp;
			}
		}
	}
}
void Selection_sort(int x[],int n){
	int temp,min,p;
	for (int i=0;i<n-1;i++){
		min=x[i];
		p=i;
		for (int j=i+1;j<n;j++){
			if (min>x[j]){
				min=x[j];
				p=j;
				}
		}
				temp=x[i];
				x[i]=x[p];
				x[p]=temp;
	}
}
void Insertion_sort(int x[],int n){
	int temp,min,j;
	for (int i=1;i<=n-1;i++){
		temp=x[i];
		j=i-1;
		while (temp<x[j]&&j>=0){
			x[j+1]=x[j];
			j--;
		}
		x[j+1]=temp;
	}
}
int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
	}
}
void quickSort(int arr[], int start, int end)
{
    if (start >= end)
        return;
    int p = partition(arr, start, end);
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}
void displayArray(int array[],int size){
	for (int i = 0; i <size; i++) {
        cout << array[i] << " ";
    }
}
int main()
{
   int size,ch;
	cout<<"Enter size of array: ";
	cin>>size;
	int array[size];
    for (int i = 0; i <size; i++) {
    	cout<<"\nEnter element "<<i+1<<": ";
        cin>> array[i];
    }
    cout<<"\nUnsorted Array\n";
 	displayArray(array,size);
    do{
    	cout<<"\n\n1) Bubble Sort";
 		cout<<"\n2) Quick Sort";
		cout<<"\n3) Insertion Sort";
 		cout<<"\n4) Selection Sort";
 		cout<<"\n5) Exit";
 		cout<<"\n\n\nEnter a choice: ";
		cin>>ch;
		switch(ch) {
			case 1:{
				Bubble_sort(array,size);
				cout<<"\nSorted Array\n";
				displayArray(array,size);
				break;}
			case 2:{
				quickSort(array,0,size-1);
				cout<<"\nSorted Array\n";
				displayArray(array,size);
				break;}
			case 3:{
				Insertion_sort(array,size);
				cout<<"\nSorted Array\n";
				displayArray(array,size);
				break;}
			case 4:{
				Selection_sort(array,size);
				cout<<"\nSorted Array\n";
				displayArray(array,size);
				break;}
			case 5:{
				exit(0);
				break;}
			default:{
				cout<< "\n\n\nInvalid choice!\n\n\n";
				break;
			}
		}
	}
	while (ch!=5);
    return 0;
}

