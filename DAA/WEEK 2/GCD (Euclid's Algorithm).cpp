#include <iostream>

int gcd1(int a,int b){
	if (a==0){
		return b;
	}
	return gcd1(b%a,a);
}
int main(){
	int x,y;
	std::cout<<"Enter first number: ";
	std::cin>>x;
	std::cout<<"Enter second number: ";
	std::cin>>y;
	std::cout<<"GCD using Euclid's algorithm: "<<gcd1(x,y)<<std::endl;
	std::cout<<"Time comlexity: O (log (min (a, b))"<<std::endl;
	return 0;
}
