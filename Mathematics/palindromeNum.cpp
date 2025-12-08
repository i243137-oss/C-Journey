#include<iostream>
using namespace std;
int main(){
	string num,num2;
	
	cout<<"Enter number"<<endl;
	cin>>num;
	int i=num.length() -1;
	int j=0;
	while(i>=0){
num2+=num[i];

		

		i--;
	}
	if(num==num2)
	cout<<"Yes";
	else
	cout<<"No";
	return 0;
}

