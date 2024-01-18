#include <iostream>
using namespace std;

int main()
{
    string s1, s2, result;

    cout << "Enter first string: ";
    getline(cin,s1);

    cout << "Enter second string: ";
    cin>>s2;

    result = s1 + s2;

    cout << "Final String = "<< result;

    return 0;
}
