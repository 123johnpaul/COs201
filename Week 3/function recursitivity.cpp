#include <iostream>
using namespace std;

long factorial(int a){
	if (a>1)
		return (a*factorial(a-1));
	else
		return 1;
}

int main(){
	
	int number;
	cout<< "enter the number: ";
	cin >>number;
	cout<<number<<"! = "<<factorial(number);
	return 0;
	
}