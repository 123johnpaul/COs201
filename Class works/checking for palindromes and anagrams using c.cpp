#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int palindrome(string word1,string word2){
	//first word
	//converting string to char array
	int i = word1.length();//get the length of the string
	char word11 [i];//create an array using the length of the string plus1
	strcpy(word11, word1.c_str());//function to convert from string to char array
	
	//Reverse array in c++ by me
	char a[i];
	
	for(int j=i-1; j>-1; j--){
		a[i-1-j] = word11[j];
	}
	//convert from char array to string
	string str = "";
	str = a;
	
	
	//Second word
	//converting string to char array
	int k = word2.length();//get the length of the string
	char word111 [k];//create an array using the length of the string plus1
	strcpy(word111, word2.c_str());//function to convert from string to char array

	
	
	//Reverse array in c++ by me
	char b[k];
	for(int j=k-1; j>-1; j--){
		b[k-1-j] = word111[j];
	}
	//convert from char array to string
	string str2 = "";
	str2 = b;
	
	//compare the two input words and their reverse
	int q = word1.compare(str);
	int w = word2.compare(str2);
	cout<<w<<endl;
	
	//if statments to know if it is a palindrome or not
	cout<< "For your first input word: " <<word1<< endl;
	if(q==0)
		cout<<"this word is a palindrome"<<endl;
	else
		cout<<"this word is not a palindrome"<<endl;
	
	cout<< "For your Second input word: " << word2 << endl;
	if(w==0)
		cout<<"this word is a palindrome"<<endl;
	else
		cout<<"this word is not a palindrome"<<endl;
		
	return 0;
}


int main(){
	string word1;
	string word2;
	cout<< "Input a two word that is a palindrome or an anagram respectively"<<endl;
	
	cin >> word1;
	cin >> word2;
	
	palindrome(word1,word2);
}
