#include <iostream>
#include <string>
#include <random> 
#include <cstdlib>
#include <ctime>
#include<bits/stdc++.h>
#include <algorithm> 
#include <cctype>  
using namespace std;

//function that scrambles words
string scramble(const string & word2scramble){
	srand(time(0));
	string chars = word2scramble;
	for (int i=0; i < chars.length(); i++){
		int y = rand();
		int j = y % chars.length();
		char temp = chars[i];
		chars[i]= chars[j];
		chars[j]= temp;
		
	}
	return chars;

}



int start_stop(){
	cout<<"Welcome to the scrambled game quiz\n"<<endl;	
	collect_user_input:
		string a;
		cout<<"Input s to Start\nInput q to Quit\n"<<endl;
		getline(cin,a);
		//convert from capital letter to small letter
		std::transform(a.begin(), a.end(), a.begin(),[](unsigned char c) { return std::tolower(c); });
		
		//remove whitespace in user input
		a.erase(std::remove(a.begin(), a.end(), ' '), a.end());
		
		int o = 1;
		int b = 0;
		
		if (a=="s"){
			cout<<"you have started the quiz\n"<<endl;
			return o;
		}
		else if (a=="q"){
			cout<<"You have decided not to take the test\nWe hope you take it next time\n";
			return b;
		}
		else{
			cout<<"WRONG INPUT!!!\nTry again\n"<<endl;
			goto collect_user_input;
		}
}


//the next line declares a function that will take different inputs and return a tuple at the end of the function
tuple<int, int> question_display(const string & wordscrambled, const string & correctword, int e,int i){
	int used_hints = 0;
	int attempts_taken = 0;
	string hints[5] = {
	"A system where power is shared among the people.",
	"The act of being considered more important than something else.",
	"Suggests moving forward in time or space.",
	"Relates to something that depends on specific circumstances.",
	"Characterized by a lighthearted, fun, or teasing attitude."
	};
	std::string userinput;
	cout<<"*Input G for GET CORRECT LETTER"<<endl;
	cout<<"*Input H for a hint"<<endl;
	cout<<"*Input N to go to the next question\n"<<endl;
	quiz:
		cout<<wordscrambled<<endl;
		cout<<"Your input: ";
		getline(cin,userinput);
		cout<<"\n"<<endl;
		
		//transform all input from capital letters to lower case
		std::transform(userinput.begin(), userinput.end(), userinput.begin(),[](unsigned char c) { return std::tolower(c); });
		userinput.erase(std::remove(userinput.begin(), userinput.end(), ' '), userinput.end());
		
		if(attempts_taken < 7){
			if(userinput == correctword){
				cout<<"Correct! You spelt the word correctly\n"<<endl;
				return make_tuple(1,used_hints);
			}
			else if(userinput == "g"||userinput =="G"){
				if(used_hints<e){
					for(int i=0; i<used_hints+1; i++){
						cout<<correctword[i];
					}
					cout<<"\n"<<endl;
					used_hints +=1;
					attempts_taken +=1;
					goto quiz;
				}
				else{
					cout<<"You have used all GET CORRECT LETTER attempts given to you\n"<<endl;
					goto quiz;
				}			
			}
			else if(userinput == "N"||userinput == "n"){
				cout<<"\n";
				cout<<"you have forfeited this question\n"<<endl;
				cout<<"The correct word is "<<correctword<<"\n"<<endl;
				return make_tuple(0,used_hints);
			}
			else if(userinput == "H"||userinput == "h"){
				cout<<hints[i]<<"\n"<<endl;
				goto quiz;
			}
			else{
				cout<<"Incorrect spelling! Try again\n"<<endl;
				attempts_taken += 1;
				goto quiz;
			}
		}
		else{
			cout<<"You have used all your attempts for this question\n"<<endl;
			cout<<"The correct word is "<<correctword<<"\n"<<endl;
			return make_tuple(0,used_hints);
		}
}



int main(){
	string words[5] = {"democracy","precedence","onward","conditional","playful"};
	string usersanswer[5];
	string usercorrectanswer[5];
	string scrambledword[5];
	int score = 0;
	
	//calling function that scrambles words
	for(int i=0; i<(sizeof(words)/sizeof(words[0])); i++)
		{
			string k = words[i];
			const string &q = scramble(k);
			scrambledword[i] = q;
		}
	
	int quiz_status = start_stop();
	int a,p;
	
	if (quiz_status == 1){
		cout<<"-----------RULES-----------"<<endl;
		cout<<"*You have 8 attempts to enter the correct word for the displayed scrambled word"<<endl;
		cout<<"*You have 5 GET A CORRECT LETTER attempts that will display a correct letter and it's placement in the word"<<endl;
		cout<<"*For each time you use the GET A CORRECT LETTER option the number of attempts you have for the question reduce by 1"<<endl;
		cout<<"*You have the HINT option"<<endl;
		cout<<"*this option gived you a clue about the meaning of the scrambled word"<<endl;
		cout<<"*you have the option of skipping the current question"<<endl;
		cout<<"*But when you skip a question you automatically fail that question and the correct answer is displayed for you"<<endl;
		int get_correct_letter = 5;
		int k;
		int b=sizeof(words)/sizeof(words[0]);
		k = b;
		b-=2;
		for(int i=0; i<(sizeof(words)/sizeof(words[0])); i++){
			if(i==b)
			{
				cout<<"This is the last word\n"<<endl;
				tie(a,p) = question_display(scrambledword[i],words[i],get_correct_letter,i);
				if(a==1){
					score+=1;
					get_correct_letter -=p;
					get_correct_letter +=1;
					cout<<"current score: "<<score<<"/"<<k<<"\n"<<endl;
					cout<<"GET CORRECT LETTER attempts left: "<<get_correct_letter<<"\n"<<endl;
				}
				else{
					get_correct_letter -=p;
					cout<<"current score: "<<score<<"/"<<k<<"\n"<<endl;
					cout<<"GET CORRECT LETTER attempts left: "<<get_correct_letter<<"\n"<<endl;
				}
			}
			else{
				tie(a,p) = question_display(scrambledword[i],words[i],get_correct_letter,i);
				if(a==1){
					score+=1;
					get_correct_letter -=p;
					get_correct_letter +=1;
					cout<<"current score: "<<score<<"/"<<k<<"\n"<<endl;
					cout<<"GET CORRECT LETTER attempts left: "<<get_correct_letter<<"\n"<<endl;
				}
				else{
					get_correct_letter -=p;
					cout<<"current score: "<<score<<"/"<<k<<"\n"<<endl;
					cout<<"GET CORRECT LETTER attempts left: "<<get_correct_letter<<"\n"<<endl;
				}	
			}	
		}
		
		cout<<"your total score is: "<<score<<"/"<<k<<"\n"<<endl;
	}
}