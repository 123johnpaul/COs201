#include <iostream>
using namespace std;
int main()
{
	int var = 10;
	int *pointer;
	int val;
	pointer = &val; //take the address of var
	val = *pointer; // take the value of available at ptr
	
	cout << "Value of ptr ;" << var << endl;
	cout << "Value of ptr ;" << pointer << endl;
	cout << "value of val ;" << val << endl;
	
	return 0;
}