#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class EMPLOYEE
{
	int Employee_Number;
	char Employee_Name[25];
	int Basic;
	int DA;
	int IT;
	int Net_Sal;
	int Gross_Sal;
	
	public:
		void read_data()
		{
			cout<<"\nEnter employee number: ";
			cin>>Employee_Number;
			cout<<"Enter employee name: ";
			cin>>Employee_Name;
			cout<<"Enter basic: ";
			cin>>Basic;
			
		}
		void salary()
		{
			DA=0.12*Basic;
			Gross_Sal=Basic+DA;
			IT=0.18*Gross_Sal;
			Net_Sal=Gross_Sal-IT;
			cout<<"\nGross salary:"<<Gross_Sal;
			cout<<"\nNet salary:"<<Net_Sal<<"\n";
		}
};
int main() {
	int n;
	EMPLOYEE e[100];
	cout<<"Enter number of employees: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		e[i].read_data();
		e[i].salary();
	}
	return 0;
}

