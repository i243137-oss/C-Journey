#include<iostream>
using namespace std;
int reverseNum(int a){
	int revNum=0;
	while(a!=0){
		int dig=a%10;
		if(revNum>INT_MAX/10 || revNum<INT_MIN/10){
			return 0;
		}
		revNum=revNum*10+dig;
		a/=10;
	}
	return revNum;
}
bool isPalindroom(int n){
	if(n<0) return false;
	return reverseNum(n)==n;
}
int main(){
cout<<"Reverse Number "<<reverseNum(1734789)<<endl;
cout<<"Palindroom "<<isPalindroom(131)<<endl;
return 0;
}
