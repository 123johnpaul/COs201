#include <iostream>
#include <string>
#include <random>
#include <cstdlib>
#include <ctime>
#include  <bits/stdc++.h>

using namespace std;

string scramble(const string & text){
	srand(time(0));
	string chars = text;
	for (int i=0; i < chars.length(); i++){
		int y = rand();
		int j = y % chars.length();
		char temp = chars[i];
		chars[i]= chars[j];
		chars[j]= temp;
		
	}
	
	return chars;

}


int main(){
	string words[5] = {"democracy","precedence","Onward","conditional","playful"};
	string usersanswer[5];
	string usercorrectanswer[5];
	int score = 0;
	
	string scrambledword[5];
	//number of attempts for each question
	int number_of_attempts_allowed = 5;
	int n;
	
	string start;
	cout<<"Welcome to the scrambled word game"<<endl;
	cout<<"I would love to confirm your interest in playing first/n input S to start/ninput Q to quit"<<endl;
	cin>>start;
	
	if(start == "s" || start=="S")
	{
		//store all the words in an array
		for(int i=0; i<sizeof(words); i++)
		{
			string k = scramble(words[i]);
			scrambledword[i] = k;
		}
		cout<<"You have five scrambled words to arrange"<<endl;
		for(int z=0; z<5; z++)
		{

			cout<< "choose a number from one to five"<<endl;
			cin>>n;
			int a= n-1;
			
			if(a>=0 && a<=4)
			{
				string userinput; 
				cout<<"here is your scrambled word\n you have 5 attempts to pass this question"<<endl;
				cout<<"Note:\n\tfor a hint input h\n\tBut this hint reduces your attempt by 1\n\tYou have only 5 hints through out quiz one for each question"<<endl;
				cout<<scrambledword[a]<<endl;
				for(int i=number_of_attempts_allowed; i>0; i--)
				{
					cout<<"enter the correct answer"<<endl;
					cin>>userinput;
					if(userinput == words[a])
					{
						usersanswer[a]=userinput;
						usercorrectanswer[a]=userinput;
						score = score+1;
					}
					else if(userinput == "H" || userinput=="h")
					{
						cout<<"the first three letters of your word are: "<<endl;
						string currentword = words[a];
						for(i=0; i<3; i++){
							cout<<currentword[i];
						}
						i--;
					}
					else
					{
						 cout<<"Wrong answer, try again"<<endl;
						 usersanswer[a]=userinput;
					}
				}
			}
			else if(a>4)
			{
				cout<<"You have input a number that is out of range of words in database\nInput a number from given range"<<endl;
				z--;
			}
			else
			{
				cout<<"Invalid Input\nInput a number from given range"<<endl;
				z--;
			}	
		}
		
	}
	
	
	else if(start == "q" || start=="Q")
	{
		cout<<"Thank you for your time. \nHope you play next time"<<endl;
	}
	else{
		cout<<"Wrong character entered try again"<<endl;
		
	}
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}