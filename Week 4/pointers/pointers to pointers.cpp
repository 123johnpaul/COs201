//example on pointers
#include <iostream>
using namespace std;
int main(){
	
	int var = 789;
	int *ptr2; //pointer for var
	int **ptr1; //double pointer for ptr2
	ptr2 = &var; // storing of var in ptr2
	ptr1 = &ptr2; // storing address of ptr2 in ptr1
	
	cout << "value of var = "<<var<<endl;
	cout<< "content values of single pointer ptr2 = " <<*ptr2<<endl;
	cout<< "content values of single pointer ptr2 = " <<ptr2<<endl;
	cout<< "content values of double pointer ptr1 = " <<**ptr1<<endl;
	cout<< "content values of double pointer ptr1 = " <<ptr1<<endl;
	
	return 0;
}