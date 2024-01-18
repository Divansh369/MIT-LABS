#include <bits/stdc++.h>
using namespace std;

int subset(int idx,int n,int wt[],int values[],int arr[],
           int target,int &ans,int k,int final[],int &final_k){
    if(idx==n){
        int wt1=0,v1=0;
        for(int i=0;i<k;i++){
            wt1+=wt[arr[i]];
            v1+=values[arr[i]];}
    if(wt1<=target){
        if(v1>ans){
            ans=v1;
            final_k=k;
            for(int i=0;i<k;i++)
                final[i]=wt[arr[i]];
        }
    }
        k=0;
        return ans;
    }
    arr[k++]=idx;
    subset(idx+1,n,wt,values,arr,target,ans,k,final,final_k);
    k--;
    subset(idx+1,n,wt,values,arr,target,ans,k,final,final_k);
    return ans;
}

int main(){
	int c,n,k,ans;
	cout<<"Enter bag capacity: ";
	cin>>c;
	cout<<"\nEnter number of items: ";
	cin>>n;
	int value[n],weight[n];
	for (int i=0;i<n;i++){
		cout<<"\nEnter weight of item "<<(i+1)<<" : ";
		cin>>weight[i];
		cout<<"Enter value of item "<<(i+1)<<" : ";
		cin>>value[i];
		}
	int arr[100],final[100],final_k=0;
    subset(0,n,weight,value,arr,c,ans,0,final,final_k);
	cout <<"\nMaximum prfit: "<<ans;
	return 0;
}

