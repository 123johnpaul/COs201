#include <iostream>
using namespace std;
char a;
string name;
int main()
{
	cout <<"a is char : " << sizeof(a) << endl;
	cout <<"name is string : " << sizeof(name) << endl;
	cout <<"size of char : " << sizeof(char) << endl;
	cout <<"size of int : " << sizeof(int) << endl;
	cout <<"size of short int : " << sizeof(short int) << endl;
	cout <<"size of long int : " << sizeof(long int) << endl;
	cout <<"size of float : " << sizeof(float) << endl;
	cout <<"size of double : " << sizeof(double) << endl;
	cout <<"size of wchat_t : " << sizeof(wchar_t) << endl;
	
	return 0;
}