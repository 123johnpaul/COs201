#include <iostream>
using namespace std;
int score=40;

int main (){
	if(score>=70)
		cout<<"Grade A";
	else if(score >= 60)
		cout<<"Grade B";
	else if(score >= 50)
		cout<<"Grade C";
	else if(score >= 40)
		cout<<"Grade D";
	else
		cout<<"Grade F";
		
	return 0;
}