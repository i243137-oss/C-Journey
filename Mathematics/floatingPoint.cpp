#include<iostream>
using namespace std;
int main(){
/*	double a,b;
	a=1.5;
	b=1.500000001;
	if(a==b)
	cout<<"equal";
	else
	cout<<"not equal"; // output not equal
		float a,b;
	a=1.5;
	b=1.500000001;
	if(a==b)
	cout<<"equal";
	else
	cout<<"not equal"; // output equal
	*/
	//  Scope of Variable
	int num=20;
	if(true){
	//	#include<cstdlib>
		int num=30;
		cout<<num<<endl;
		system("cls");
	}
	cout<<num<<endl;  //output 30 20
}
