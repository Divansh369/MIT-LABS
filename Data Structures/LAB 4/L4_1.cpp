#include<iostream>
using namespace std;
long int Fact(int n) {
    if (n>1)
        return n*Fact(n-1);
    else
        return 1;
}
int main() {
    int n;
    cout<<"Enter any number: ";
    cin>>n;
    if (n>=0)
    	cout<<"\nFactorial of given number is: "<<Fact(n);
    else 
    	cout<<"\nPlease enter a positive number.";
}
