#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter n: "<<endl;
    cin>>n;
    int c=0,a=-1,b=1;
    cout<<"Fibonacci series uptill n numbers: "<<endl;
    
    while(n--){
        c=a+b;
        cout<<c<<" ";
        a=b;
        b=c;
    }
    return 142;
}
