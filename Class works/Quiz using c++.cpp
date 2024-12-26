#include <iostream>
#include <string>
#include <array>

using namespace std;

int introduction(){
	int a;
	cout<<"Hey there, welcome to my mini friendship quiz"<<endl;
	cout<<"I would love to confirm your interst in playing first/n input 1 to start/ninput 2 to quit"<<endl;
	cin>>a;
	return a;
}

std::array<string, 5> game(const array<string, 5>& a, const array<array<string, 4>, 5>& b) {
   
	
	std::array<string,5> user_answers;
	
	cout<<"The rules for this quiz are listed below/n/tIn order to answer the question input in capital letter the option you belive to be the answer"<<endl;
	cout<<"/t To skip a question input n/n/tTo go to previous question input p/n/tTo submit input s"<<endl;
	for(int i=0; i<5; i++){
		cout<<a[i]<<endl;
		for(int j=0; j<4; j++){
			cout<<b[i][j]<<endl;
		}
		cout<<"enter your answer"<<endl;
		cin>>user_answers[i];
	}
	return user_answers;
}

int main(){
	
	array<string, 5>questions [5] = {"What is my name?","How old am I?","What is my favorite sport?","What are my hobbies?","What is my favorite color?"};
	array<array<string, 4>, 5> answers[5][4] = {
		{"A.\tJohnpaul","B.\tJohn","C.\tkayden","D.\tObama"},
		{"A.\t20","A.\t19","C.\t23","D.\t11"},
		{"A.\ttennis","B.\tGolf","C.\tBasket ball","D.\tHockey"},
		{"A.\tGaming and sleeping", "B.\tgaming and watching anime", "C.\tgaming and hooping", "D.\tdriving and playing golf"},
		{"A.\tblue","B.\tblack","C.\tpurple","D.\tgrey"}
	};
	
	array<string, 5> correct_answers[5] = {"A","B","C","B","B"};
	
	int start = introduction();
	string okay[5];
	if(start==2){
		auto okay=game(questions,answers);
	}
	

}



