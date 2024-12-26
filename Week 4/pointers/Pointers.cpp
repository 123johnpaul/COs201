#include <iostream>
using namespace std;
int main(){
	int x = 17;
	
	int *ip = &x;
	cout <<x<<endl;
	cout<<"Value of ip is : ";
	cout<<ip <<endl;
	cout << "Value of *ip is ; ";
	cout << *ip << endl;
	return 0;
}