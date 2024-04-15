#include <iostream>
using namespace std;
class flight
{
	int flight_number;
	char destination[30];
	float distance;
	float fuel= 13.2;
	
		int calculate_fuel(float distance)
	{
		if(distance<=1000)
		fuel=500.0;
		else if(distance>2000)
		fuel=2200.0;
		else
		fuel=1100.0;
	}
	
	public:
		

	
	void information_entry()
	{
		cout<<"Enter flight number:";
		cin>>flight_number;
		cout<<"Enter destination:";
		cin>>destination;
		cout<<"Enter distance:";
		cin>>distance;
		calculate_fuel(distance);
	}
	
	void display_info()
	{
		cout<<"Flight Number:\t\t\t"<<flight_number;
		cout<<"\nDestination:\t\t\t"<<destination;
		cout<<"\nDistance:\t\t\t"<<distance;
		cout<<"\nFuel:\t\t\t\t"<<fuel;
	}
		
};
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	flight f;
	f.information_entry();
	f.display_info();
	
	return 0;
}
