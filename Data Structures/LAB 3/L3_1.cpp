#include<iostream>
using namespace std;

int main(){
	int a,b,i,j,n1,n2,m=0,n=0;
	char alpha[26];
	for (i=65 ; i<91 ; i++) {
    	alpha[i-65] = char(i);
	}
	cout<<"Example representation of second degree polynomial: C(X^2)+B(X^1)+A";
	cout<<"\nEnter degree of first polynomial: ";
	cin>>a;
	int p1[a+1];
	if (a>26){
		cout<<"Polynomial degree is too high!";
		}
	for (i=0;i<a+1;i++){
		cout<<"Enter value of "<<alpha[i]<<": ";
		cin>>p1[i];
	}
	cout<<"\nEnter degree of second polynomial: ";
	cin>>b;
	int p2[b+1];
	if (b>26){
		cout<<"Polynomial degree is too high!";
		}
	for (j=0;j<b+1;j++){
		cout<<"Enter value of "<<alpha[j]<<": ";
		cin>>p2[j];
	}
	if (a>=b){
		n1=a;
		n2=b;
	}
	else
		n1=b;
		n2=a;
	cout<<"\nFirst polynomial: ";

	while (a>=0){
		if (a==0){
			cout<<p1[0];
		}
		else
			cout<<p1[a]<<"*X^("<<(a)<<")+";
		a--;
	}
	cout<<"\nSecond polynomial: ";
	while (b>=0){
		if (b==0){
			cout<<p2[0];
		}
		else
			cout<<p2[b]<<"*X^("<<(b)<<")+";
		b--;
	}
	int p3[n1];
	m=0;
    while (m<=n1){
        if (m<=n2){
        p3[m]=p1[m]+p2[m];}
        else {
            if (a>=b)
                p3[m]=p1[m];
            else if (b>a)
                p3[m]=p2[m];}
        m++;}
	cout<<"\n\nAddition of both polynomials is: ";
	while (n1>=0){
		if (n1==0){
			cout<<p3[0];
	}
		else
			cout<<p3[n1]<<"*X^("<<(n1)<<")+";
		n1--;
	}

return 0;
}

