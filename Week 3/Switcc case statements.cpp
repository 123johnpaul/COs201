#include <iostream>
using namespace std;

int main(){
	char grade = 'D';
	
	switch(grade){
		case 'A':
			cout <<"Excellent";
			break;
		case 'B':
			cout << "Very Good";
			break;
		case 'C':
			cout << "Well done";
			break;
		case 'D':
			cout << "You passed";
			break;
		case 'F':
			cout<< "Better try again";
			break;
		default :
			cout << "Invalid grade";
	}
	return 0;
}