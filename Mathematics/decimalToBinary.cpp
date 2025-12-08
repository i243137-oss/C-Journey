#include<iostream>
#include<string>
using namespace std;
int main(){
	int b;
	float A,a;
	cout<<"Enter Number"<<endl;
	cin>>A;
	 b=A;
	a=A- (int)A;
	string c="";
	string man="";
	if(A>0){
		int r;
		for (;b>0;){
		r=b%2;
		b=b/2;
		 man=to_string(r)+man;
	//	string c=c+man;
		
		}

		cout<<man;
	}
	else{
		cout<<"Error"<<endl;
	}
}
