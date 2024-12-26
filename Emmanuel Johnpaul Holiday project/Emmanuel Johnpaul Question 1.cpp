#include <iostream>
#include <string>
#include <random> 
#include <cstdlib>
#include <iterator>
#include <ctime>
#include<bits/stdc++.h>
#include <algorithm> 
#include <cctype>  
#include <map>
using namespace std;

//function to decide to start the test or end it
int start_stop(){
	cout<<"Welcome to COS101 CBT test\n"<<endl;	
	collect_user_input:
		string a;
		cout<<"Input s to proceed to authentication phase\nInput q to Quit\n"<<endl;
		getline(cin,a);
		
		//convert from capital letter to small letter
		std::transform(a.begin(), a.end(), a.begin(),[](unsigned char c) { return std::tolower(c); });
		
		//remove whitespace in user input
		a.erase(std::remove(a.begin(), a.end(), ' '), a.end());
		
		int o = 1;
		int b = 0;
		
		if (a=="s"){
			cout<<"\n"<<endl;
			return o;
		}
		else if (a=="q"){
			cout<<"\n"<<endl;
			cout<<"You have decided not to authenticate your self and take the test\n"<<endl;
			return b;
		}
		else{
			cout<<"\n"<<endl;
			cout<<"WRONG INPUT!!!\nTry again\n"<<endl;
			goto collect_user_input;
		}
}

//declaring a function that will return a tuple containing user's input email and password
tuple <string, string> user_details(){
	string user_email;
	string user_password;
	
	cout<<"-----------Authentication process-----------\n"<<endl;
	//get student email
	cout<<"Input your student email: ";
	getline(cin,user_email);
	cout<<"\n"<<endl;
	
	//transform from capital letters to small letters
	std::transform(user_email.begin(), user_email.end(), user_email.begin(),[](unsigned char c) { return std::tolower(c); });
	
	//remove whitespace in user input
	user_email.erase(std::remove(user_email.begin(), user_email.end(), ' '), user_email.end());
	
	//get student password
	cout<<"Input your password: ";
	getline(cin,user_password);
	cout<<"\n"<<endl;
	
	//remove whitespace in user input
	user_password.erase(std::remove(user_password.begin(), user_password.end(), ' '), user_password.end());
	
	//return a tuple
	return make_tuple(user_email,user_password);
}

//authenticating student account
int valid_student(string db_email,string db_password,string u_email,string u_password){
	if(u_email==db_email && u_password==db_password){
		return 1;
	}
	else if(u_email==db_email && u_password!=db_password){
		return 2;
	}
	else{
		return 0;
	}
}

//display questions and return a tuple
tuple<int, string> display_questions(int s_n, string question, string option1, string option2, string option3, string option4, string uchoice){
	string uanswer;
	
	cout<<s_n<<". "<<question<<"\n"<<endl;
	cout<<option1<<"\n";
	cout<<option2<<"\n";
	cout<<option3<<"\n";
	cout<<option4<<"\n"<<endl;
	
	if(uchoice !=""){
		cout<<"previous answer: "<<uchoice<<"\n"<<endl;
		cout<<"Input new choice to change previous choice\n";
		cout<<"your answer: "<<"\n"<<endl;
		getline(cin,uanswer);
		cout<<"answer saved!\n"<<endl;
	}
	else{
		cout<<"your answer: "<<"\n"<<endl;
		getline(cin,uanswer);
		cout<<"answer saved!\n"<<endl;
	}
	//convert from capital letter to small letter
	std::transform(uanswer.begin(), uanswer.end(), uanswer.begin(),[](unsigned char c) { return std::tolower(c); });
	
	//remove whitespace in user input
	uanswer.erase(std::remove(uanswer.begin(), uanswer.end(), ' '), uanswer.end());
	
	return make_tuple(s_n, uanswer);
}

//confirm student's submission
string validate_submission(string uin){
	if(uin=="s"){
		string sub_stat;
		cout<<"You have opted to submit\nInput y to confirm submission\nInput n to go back";
		cout<<": ";
		getline(cin,sub_stat);
		
		//convert from capital letter to small letter
		std::transform(sub_stat.begin(), sub_stat.end(), sub_stat.begin(),[](unsigned char c) { return std::tolower(c); });
		
		//remove whitespace in user input
		sub_stat.erase(std::remove(sub_stat.begin(), sub_stat.end(), ' '), sub_stat.end());
		
		return sub_stat;
	}
	else{
		string sub_stat;
		cout<<"\n\nYou have answered the last question\n do you want to submit\nInput y to confirm submission\nInput n to go back";
		cout<<": ";
		getline(cin,sub_stat);
		
		//convert from capital letter to small letter
		std::transform(sub_stat.begin(), sub_stat.end(), sub_stat.begin(),[](unsigned char c) { return std::tolower(c); });
		
		//remove whitespace in user input
		sub_stat.erase(std::remove(sub_stat.begin(), sub_stat.end(), ' '), sub_stat.end());
		
		return sub_stat;
	}
}

//function to display student's script
void student_script(int s_n, string question, string option1, string option2, string option3, string option4, string uchoice,string correct){
	cout<<s_n<<". "<<question<<"\n"<<endl;
	cout<<option1<<"\n";
	cout<<option2<<"\n";
	cout<<option3<<"\n";
	cout<<option4<<"\n"<<endl;
	
	if(uchoice==correct){
		cout<<"your answer: "<<uchoice<<"\t\tCorrect"<<endl;
		cout<<"Correct answer: "<<correct<<"\n"<<endl;
	}
	else{
		cout<<"your answer: "<<uchoice<<"\t\tWrong"<<endl;
		cout<<"Correct answer: "<<correct<<"\n"<<endl;
	}
	
}

//Main function
int main(){
	int authenticating_status = start_stop();
	string uname,upassword;
	
	authenticating:
		if(authenticating_status==1){
			tie(uname,upassword) = user_details();
		}
		else{
			return 0;
		}
	
	//I used chat gpt to generate the student emails and passwords
	map<string,string> student_accounts = {
        {"james.okafor@pau.edu.ng", "jjjjj"},
		{"amara.igwe@pau.edu.ng", "Am@rIg#45"},{"david.adewale@pau.edu.ng", "Da43A*dE!"},{"chioma.nwankwo@pau.edu.ng", "Ch@Xw^75"},
		{"michael.akinola@pau.edu.ng", "MiK#oLa@2"},{"faith.ugochukwu@pau.edu.ng", "Fa!U9c*12"},{"john.okechukwu@pau.edu.ng", "Jo33Ke!54"},
        {"precious.balogun@pau.edu.ng", "Pr@loB*76"},{"emeka.onwuka@pau.edu.ng", "Em3@nu!98"},{"linda.okoro@pau.edu.ng", "Li9Oro#11"},
        {"paul.omowunmi@pau.edu.ng", "PaWo@8%23"},{"grace.adetayo@pau.edu.ng", "GrAc7!02@"},{"mary.eke@pau.edu.ng", "MaYkE*10@"},
		{"samuel.ibrahim@pau.edu.ng", "SaMuE!22$"},{"chukwuemeka.anu@pau.edu.ng", "Ch!a^Nu9@"},{"adaobi.alabi@pau.edu.ng", "Ad!Lo9*18"},
        {"daniel.ifeanyi@pau.edu.ng", "Da3@Fi%14"},{"sarah.oyewole@pau.edu.ng", "SaR@Yo#56"},{"victor.olawale@pau.edu.ng", "Vi0rOw^99"},
        {"toyin.udoka@pau.edu.ng", "To@Ka*29$"},{"gloria.nnamdi@pau.edu.ng", "Gl^Ni@23#1"},{"elijah.bassey@pau.edu.ng", "El2@Ba6!42"},
        {"chidera.ifeoma@pau.edu.ng", "Ch2Fe@12%"},{"timothy.abdul@pau.edu.ng", "Ti!yAd#77"},{"esther.oluchi@pau.edu.ng", "EsOcU*19@"},
        {"kelvin.ugwu@pau.edu.ng", "KeUw@5$20"},{"ruth.okon@pau.edu.ng", "Ru@Ko*11#"},{"solomon.osagie@pau.edu.ng", "SoOs@!39$"},
        {"ebuka.joseph@pau.edu.ng", "EbJo@45#89"},{"ngozi.amaechi@pau.edu.ng", "Ng@Am*21$"},{"martin.ayomide@pau.edu.ng", "Ma@Ai^9#22"},
        {"uche.chinwe@pau.edu.ng", "Uc@Ch3!29$"},{"felix.kingsley@pau.edu.ng", "FeKi!13@55"},{"joy.omolara@pau.edu.ng", "JoOl@2#99"},
        {"frank.edeh@pau.edu.ng", "FrEd!18^22"},{"patience.obinna@pau.edu.ng", "Pa!Ob@8$23"},{"simon.akpan@pau.edu.ng", "SiAk2@1!37"},
		{"anthony.chukwuma@pau.edu.ng", "AnCh^w2@98"},{"blessing.ifeoma@pau.edu.ng", "Bl!If*11@22"},{"cynthia.adewumi@pau.edu.ng", "CyAd!10#21"}
    };
    
    //I used chat gpt to generate the questions and answers
	map<string, array<string, 4>> questions = 
	{
        {"How do you create a mutable variable in Rust?", 
          {"a) Use `var` instead of `let`", "b) Add the `mut` keyword before the variable name", 
           "c) Use the `mutable` keyword after the variable name", "d) Add `&mut` before the variable type"}
		},
        {"How do you define a constant in Rust?", 
            {"a) const VALUE: i32 = 10;", "b) let VALUE = 10;", "c) immutable VALUE = 10;", "d) static VALUE = 10;"}
		},
		{"How is error handling typically performed in Rust?", 
            {"a) Using `try...catch` blocks", "b) Using the `Result` and `Option` enums", "c) Using a garbage collector", "d) Using assertions"}
		},
		{"What does the `let` keyword in Rust do?", 
            {"a) Declares a constant variable","b) Declares a mutable variable by default",
			"c) Declares an immutable variable by default","d) Initializes the main function"}
		},
		{"What does the `unwrap` method do in Rust?", 
           {"a) Converts a string to an integer", "b) Handles errors in a `Result` type silently", 
            "c) Extracts the value inside an `Option` or `Result` type, panicking if it's `None` or `Err`", 
			"d) Reverses the contents of a collection"}
		},
		{"What is the correct way to print \"Hello, world!\" in Rust?", 
            {"a) print(\"Hello, world!\");", "b) println(\"Hello, world!\");", "c) println!(\"Hello, world!\");", "d) printf!(\"Hello, world!\");"}
		},
		{"What is the default integer type in Rust?", 
            {"a) i8", "b) i16", "c) i32", "d) i64"}
		},
		{"What is the ownership model in Rust?", 
          {"a) A model that ensures variables can only be assigned once", "b) A mechanism for garbage collection", 
           "c) A set of rules ensuring memory safety without a garbage collector", "d) A system for managing access rights to variables"}
		},
        {"What is the primary focus of the Rust programming language?", 
            {"a) Memory safety and concurrency", "b) High-speed numerical computation", "c) Web development only","d) Artificial intelligence"}
		},
		{"What is the purpose of the `cargo` tool in Rust?", 
            {"a) To compile Rust code","b) To manage Rust projects and dependencies", "c) To clean up unused variables", "d) To debug Rust programs"}
		},
		{"What is the purpose of the `match` expression in Rust?", 
            {"a) To compare values in a switch-like statement", "b) To initialize variables", "c) To iterate over collections", 
			"d) To perform dynamic type checks"}
		},
		{"What keyword is used to define a function in Rust?", 
            {"a) def", "b) function", "c) fn", "d) func"}
		},
		{"Which Rust data type is used for text?", 
            {"a) String only", "b) str and String", "c) char only", "d) Both str and char"}
		},
		{"Which Rust keyword is used to define a structure?", 
            {"a) struct", "b) class", "c) type", "d) object"}
		},
        {"Which trait is used to compare two values for equality in Rust?", 
            {"a) Comparable", "b) Eq", "c) Equal", "d) Ord"}
		}
    };
    
    array<tuple<int, string, string>, 15> answers = {
    	make_tuple(1, "b", "Add the mut keyword before the variable name"),
        make_tuple(2, "a", "const VALUE: i32 = 10;"),
        make_tuple(3, "b", "Using the Result and Option enums"),
        make_tuple(4, "c", "Declares an immutable variable by default"),
		make_tuple(5, "c", "Extracts the value inside an Option or Result type, panicking if it's None or Err"),
		make_tuple(6, "c", "println!(\"Hello, world!\")"),
		make_tuple(7, "c", "i32"),
		make_tuple(8, "c", "A set of rules ensuring memory safety without a garbage collector"),
		make_tuple(9, "a", "Memory safety and concurrency"),
		make_tuple(10, "b", "To manage Rust projects and dependencies"),
		make_tuple(11, "a", "To compare values in a switch-like statement"),
        make_tuple(12, "c", "fn"),
        make_tuple(13, "b", "str and String"),
        make_tuple(14, "a", "struct"),
        make_tuple(15, "b", "Eq")
    };
    
    int student_valid;
    int h;
    
    //declaring an iterator to pass the key and values in a map to a function
	std::map<std::string, std::string>::iterator itr;
	
    for (itr=student_accounts.begin(); itr!=student_accounts.end(); ++itr){
    	student_valid = valid_student(itr->first,itr->second,uname,upassword);
    	if(student_valid == 1){
			h=student_valid;
			break;
		}
		else{
			h=student_valid;
		}
	}
	
	if(h == 1){
		cout<<"you have been verified\n"<<endl;
		cout<<"Input N to skip current question\n";
		cout<<"Input P to go to previous question\n";
		cout<<"Input S to submit your test\n"<<endl;
	}
	else{
		cout<<"Wrong login details\n"<<endl;
		goto authenticating;
	}
	
	string c_question, c_option1, c_option2, c_option3, c_option4;
	string optionss[4];
	
	//user answers stored in array
	string u_answers[15];
	string ua_questions[15];
	int student_score = 0;
	
	int s_n[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	
	std::map<std::string, std::array<string,4>>::iterator it;
	go_through:
		for(int x = 0; x<16; x++){
			string user_in;
			for (it=questions.begin(); it!=questions.end(); ++itr) {
			    string uin;
			    int qnum;
			    int p = 0;
			
			    c_question = it->first;
			    
			    const auto& options = it->second;
			
			    int e = 0;
			    for (const auto& option : options) {
			        optionss[e] = option; 
			        e += 1;
			    }
			    c_option1=optionss[0];
			    c_option2=optionss[1];
			    c_option3=optionss[2];
			    c_option4=optionss[3];
			    wrong_input:
			    	tie(qnum,uin) = display_questions(s_n[x], c_question, c_option1, c_option2, c_option3, c_option4,u_answers[x]);
			    	user_in = uin;
			    
			    if(uin == "s"){
				    again:
						string substat = validate_submission(user_in);
						if(substat == "y"){
							cout<<"\nYou have submitted your test\n"<<endl;
							cout<<"your score: "<<student_score<<"/15\n"<<endl;
							string view_script;
							
							view:
								cout<<"Do you want to view your script\nInput y to view script\nInput n to skip viewing your script\n"<<endl;
								cout<<"your input: ";
								getline(cin,view_script);
								cout<<"\n"<<endl;
								//convert from capital letter to small letter
								std::transform(view_script.begin(), view_script.end(), view_script.begin(),[](unsigned char c) { return std::tolower(c); });
								
								//remove whitespace in user input
								view_script.erase(std::remove(view_script.begin(), view_script.end(), ' '), view_script.end());
							
							if(view_script == "y"){
								for(int t = 0; t<15; t++){
									int v = t;
									string correct_option = get<1>(answers[v]);
									student_script(s_n[t], c_question, c_option1, c_option2, c_option3, c_option4,u_answers[t],correct_option);
								}
								x=15;
				    			break;
							}
							else if(view_script == "n"){
								x=15;
				    			break;
							}
							else{
								cout<<"Wrong Input!!!\n"<<endl;
								goto view;
							}
						}
						else if(substat == "n"){
							cout<<"\nyou are going back to the start of the test\n";
							cout<<"all your answered questions have already been saved and can still be changed\n"<<endl;
							goto go_through;
						}
						else{
							cout<<"Wrong Input\n"<<endl;
							goto again;
						}
				}
				else if(uin == "n"){ 
					if (x != 14) {
			            ++it;
			        	++x;
			            continue;
			        } else {
			            cout << "\n\nAlready at the last question!\n";
			            cout<<"\n"<<endl;
			            ++x;
			            ++it;
			            --it;
			            --x;
			            continue;
			        }
				}
				else if(uin == "p"){
					if (it != questions.begin()) {
			            it--;
			            --x;
			            continue;
			        } else {
			            cout << "\n\nAlready at the first question!\n";
			            cout<<"\n"<<endl;
			        }
				}
				else{
					
					int f = s_n[x] - 1;
					
					string c_option = get<1>(answers[f]);
					if(uin=="a"||uin=="b"||uin=="c"||uin=="d"){
						if(uin == c_option){
							student_score += 1;
							if(x!=14){
									u_answers[f] = uin;
									ua_questions[f] = qnum;
									++it;
									++x;
									continue;
								}
								else{
									u_answers[f] = uin;
									ua_questions[f] = qnum;
									goto final_question;
								}
						}
						else if(uin != c_option){
							if(x!=14){
								u_answers[f] = uin;
								ua_questions[f] = qnum;
								++it;
								++x;
								continue;
							}
							else{
								u_answers[f] = uin;
								ua_questions[f] = qnum;
								goto final_question;
							}
							
						}
					}
					else{
						cout<<"Wrong input!!!\nTry again...\n"<<endl;
						goto wrong_input;
					}
				}
				final_question:
					if(x==14){
						again1:
							string substat = validate_submission(user_in);
							if(substat == "y"){
								cout<<"\nYou have submitted your test\n"<<endl;
								cout<<"your score: "<<student_score<<"/15\n"<<endl;
								cout<<"\n"<<endl;
								string view_script;
								
								view1:
									cout<<"Do you want to view your script\nInput y to view script\nInput n to skip viewing your script\n"<<endl;
									cout<<"your input: ";
									getline(cin,view_script);
									cout<<"\n"<<endl;
									//convert from capital letter to small letter
									std::transform(view_script.begin(), view_script.end(), view_script.begin(),[](unsigned char c) { return std::tolower(c); });
									
									//remove whitespace in user input
									view_script.erase(std::remove(view_script.begin(), view_script.end(), ' '), view_script.end());
								
								if(view_script == "y"){
									for(int t = 0; t<15; t++){
										int v = t;
										string correct_option = get<1>(answers[v]);
										student_script(s_n[t], c_question, c_option1, c_option2, c_option3, c_option4,u_answers[t],correct_option);
									}
									x=15;
					    			break;
								}
								else if(view_script == "n"){
									x=15;
					    			break;
								}
								else{
									cout<<"Wrong Input!!!\n"<<endl;
									goto view1;
								}
							}
							else if(substat == "n"){
								cout<<"\nyou are going back to the start of the test\n";
								cout<<"all your answered questions have already been saved and can still be changed\n"<<endl;
								goto go_through;
							}
							else{
								cout<<"Wrong Input\n"<<endl;
								goto again;
							}
					}
			}
		}
}
