#include <iostream>
#define MAXFACTORS 1024

typedef struct
{
    int size;
    int factor[MAXFACTORS + 1];
    int exponent[MAXFACTORS + 1];
} FACTORIZATION;

void FindFactorization(int x, FACTORIZATION* factorization)
{
    int i, j = 1;
    int n = x, c = 0;
    int k = 1;
    factorization->factor[0] = 1;
    factorization->exponent[0] = 1;
    for (i = 2; i <= n; i++) {
        c = 0;
        while (n % i == 0) {
            c++;
            n = n / i;
        }
        if (c > 0) {
            factorization->exponent[k] = c;
            factorization->factor[k] = i;
            k++;
        }
    }
    factorization->size = k - 1;
}

int gcd3(int m, int n)
{
    FACTORIZATION mFactorization, nFactorization;
    int r, mi, ni, i, k, x = 1, j;
    FindFactorization(m, &mFactorization);
    FindFactorization(n, &nFactorization);
    int min;
    i = 1;
    j = 1;
    while (i <= mFactorization.size && j <= nFactorization.size) {
        if (mFactorization.factor[i] < nFactorization.factor[j])
            i++;
        else if (nFactorization.factor[j] < mFactorization.factor[i])
            j++;
        else 
        {
            min = mFactorization.exponent[i] > nFactorization.exponent[j]
                      ? nFactorization.exponent[j]
                      : mFactorization.exponent[i];
            x = x * mFactorization.factor[i] * min;
            i++;
            j++;
        }
    }
    return x;
}

int main(){
	int x,y;
	std::cout<<"Enter first number: ";
	std::cin>>x;
	std::cout<<"Enter second number: ";
	std::cin>>y;
	std::cout<<"GCD using Middle School Method: "<<gcd3(x,y)<<std::endl;
	std::cout<<"Time comlexity: "<<std::endl;
	return 0;
}	
