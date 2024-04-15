#include <iostream>
using namespace std;
int main() {
   int n,i,j,p,q,r,t,z;
   cout<<"Enter size of the square matrix: ";
   cin>>n;
   int X_2D[n][n];
   int X_1D[n*n];
   int X_1DC[n*n];
   for (i=0;i<n;i++){
   	for (j=0;j<n;j++){
   		cout<<"X_2D["<<i<<"]["<<j<<"]="<<endl;
        cin>>X_2D[i][j];
        cin.ignore();
	   }
   }
   for (i=0;i<n;i++)
    {
    for (j=0;j<n;j++)
        {
        X_1D[i * n + j] = X_2D[i][j];
        }
    }
    cout<<"\n\nElements in 1D array are: ";
	for (i=0;i<(n*n);i++){
		cout<< X_1D[i] << " ";
		}
	
	cout<<"\n\nThe upper-triangular matrix as an 1D array is: ";
	for (i=0;i<n;i++){
   	for (j=0;j<n;j++){
   		if (j>=i)
		   cout<<X_2D[i][j]<<" ";
		else
			cout<<0<<" ";
	   }
   }
   cout<<"\n\nThe lower-triangular matrix mapped as an 1D array is: ";
	for (i=0;i<n;i++){
   	for (j=0;j<n;j++){
   		if (j<=i)
		   cout<<X_2D[i][j]<<" ";
		else
			cout<<0<<" ";
	   }
   }
   cout<<"\n\nThe diagonal matrix mapped as an 1D array is: ";
	for (i=0;i<n;i++){
   	for (j=0;j<n;j++){
   		if (j==i)
		   cout<<X_2D[i][j]<<" ";
		else
			cout<<0<<" ";
	   }
   }
   cout<<"\n\nThe tri-diagonal matrix mapped as an 1D array is: ";
	for (i=0;i<n;i++){
   	for (j=0;j<n;j++){
   		if (j==i)
			cout<<X_2D[i][j]<<" ";
		else if ((i-j)==1) 
			cout<<X_2D[i][j]<<" ";
		else if ((i-j)==-1)
			cout<<X_2D[i][j]<<" ";
		else
			cout<<0<<" ";
	   }
   }
   cout<<"\n\nThe row-major is: ";
	for (i=0;i<(n*n);i++){
		cout<< X_1D[i] << " ";
		}
	int k=0;
	for (i=0;i<n;i++)
    {
    for (j=0;j<n;j++)
        {
        X_1DC[k++]= X_2D[j][i];
        }
	cout<<"\n\nThe column-major is: ";
	for (i=0;i<(n*n);i++){
		cout<< X_1DC[i] << " ";
   }}
   cout<<"\n\nEnter row: ";
   cin>>p;
   cout<<"\nEnter column: ";
   cin>>q;
   if (p*q<=n*n){
   		cout<<"\n\nThe element found is: "<<X_2D[p-1][q-1];}
   	else
   		cout<<"\nInvalid input.";
   }

