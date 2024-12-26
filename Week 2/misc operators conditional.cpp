#include <iostream>
using namespace std;

int main()
{
	int a;
	int y = 10;
	int z = 5;
	
	a = (y < z) ? y - z : z - y;
	cout << "(y < z) ? y - z : z - y;" << a << endl;
	
	return 0;
}