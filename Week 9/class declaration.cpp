#include <iostream>
using namespace std;

class csc201{ //class declaration
	public:// access specifier
		int score;//attribute score
		string name;// attribute name
		char grade;// attribute grade
};

int main (){
	csc201 student1;
	csc201 student2;
	
	student1.score = 20;
	student1.grade = 'F';
	student1.name = "Bello Moses";
	
	student2.score = 100;
	student2.grade = 'A';
	student2.name = "Johnpaul Emmanuel";
	
	cout<<"Student name: "<<student1.name <<"\n Score: "<< student1.score<< "\n Grade: "<< student1.grade<<endl;
	cout<<"Student name: "<<student2.name <<"\n Score: "<< student2.score<< "\n Grade: "<< student2.grade;
	
	return 0;
}