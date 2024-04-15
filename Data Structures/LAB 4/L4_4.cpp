#include <iostream>
using namespace std;
void towerOfHanoi(int, char ,char ,char);



int main()
{
    cout<<"A: Source disk.\n";
	cout<<"B: Auxillary disk.\n";
	cout<<"C: Destination disk.\n";
	int n;
    cout<<"\nEnter the number of disks: \n";
    cin>>n;

    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 0) 
	{

        return;

    }

    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);

    cout << "Move disk " << n << " From rod " << from_rod<< " To rod " << to_rod << endl;

    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
    
}
