#include <iostream>

int gcd2(int a, int b) 
{
    int min;
    if(a<=b)
        min = a;
    else
        min = b;
    while(min > 0) 
    {
        if(a % min == 0 && b % min == 0)
            return min;
        min = min - 1;
    }
	return 0;
}

int main(){
	int x,y;
	std::cout<<"Enter first number: ";
	std::cin>>x;
	std::cout<<"Enter second number: ";
	std::cin>>y;
	std::cout<<"GCD using Consecutive Integer Checking Method : "<<gcd2(x,y)<<std::endl;
	std::cout<<"Time comlexity: "<<std::endl;
	return 0;
}	
