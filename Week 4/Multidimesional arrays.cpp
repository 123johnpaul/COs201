#include <iostream>
using namespace std;

int score [4][5]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
int result=0;

int main(){
	for(int n=0; n<4; n++){
		for(int j=0; j<5; j++){
			result += score[n][j];
			cout<<result<<endl;
		}
	}
	
	cout<<result;
}