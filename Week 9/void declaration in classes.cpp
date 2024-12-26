#include <iostream>
using namespace std;

class csc201{
	public:
		int score;
		string name;
		char grade;
	public:
		void prerequisite(){
			cout<< "Student must pass csc101\n";
		}
		void verdict (){
			cout << "To pass the course the student must have a minimum score of 40";
		}

};

int main(){
	csc201 student1;
	
	student1.score = 20;
	student1.grade = 'F';
	student1.name = "Bello Moses";
	cout<<"Student name: "<<student1.name <<"\n Score: "<< student1.score<< "\n Grade: "<< student1.grade<<endl;
	
	student1.prerequisite();
	student1.verdict();
}