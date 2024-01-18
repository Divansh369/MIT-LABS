#include<iostream>
using namespace std;
long int GCD(int a, int b){
	if (b != 0)
    	return GCD(b, a % b);    
  	else
    	return a;
}
int main() {
	int a, b;
  	cout << "Enter two numbers: \n";
  	cin >> a >> b;
 	cout << "Greatest common divisor of " << a << " and " <<  b << " is: " << GCD(a, b);
 	return 0;
}
