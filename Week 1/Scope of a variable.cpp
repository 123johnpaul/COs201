#include <iostream>
using namespace std;
int a = 40;
int b =30;
int main()
{

	{
		int a =2;
		int b = 4;
		cout<< "inner block a: "<<a<<endl;
		cout<<"inner block b: "<<b<<endl;
	}
	
	cout<<"outer block a:"<<a<<endl;
	cout <<"outer block b: "<<b<<endl;
	
	return 0;
}