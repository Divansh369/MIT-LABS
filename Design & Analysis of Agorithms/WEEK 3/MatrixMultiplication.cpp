#include <iostream>
using namespace std;
int main()
{
int mul[10][10],r1,c1,r2,c2,i,j,k;
cout<<"Enter number of rows in first matrix: ";
cin>>r1;
cout<<"Enter number of columns in first matrix: ";
cin>>c1;
int a[r1][c1];
cout<<"Enter elements in first matrix : \n";
for(i=0;i<r1;i++)
{
for(j=0;j<c1;j++)
{
cin>>a[i][j];
}
}
cout<<"Enter number of rows in second matrix: ";
cin>>r2;
cout<<"Enter number of columns in second matrix: ";
cin>>c2;
int b[r2][c2];
cout<<"Enter elements in second matrix : \n";
for(i=0;i<r2;i++)
{
for(j=0;j<c2;j++)
{
cin>>b[i][j];
}
}
cout<<"Matrix obtained after multiplication: \n";
for(i=0;i<c1;i++)
{
for(j=0;j<r2;j++)
{
mul[i][j]=0;
for(k=0;k<c1;k++)
{
mul[i][j]+=a[i][k]*b[k][j];
}
}
}
for(i=0;i<r2;i++)
{
for(j=0;j<c1;j++)
{
cout<<mul[i][j]<<" ";
}
cout<<"\n";
}
return 0;
}
