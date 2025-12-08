#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
	int a,b,i,ten,r,new_num,len,mul,sum=0;
	string B;
	cout<<"Enter number1"<<endl;
	cin>>a;
	cout<<"Enter number 2 "<<endl;
	cin>>b;
	cout<<endl<<endl;
	cout<<setw(6)<<a<<endl;
	cout<<setw(6)<<b<<endl;
		cout<<"-----------"<<endl;
	B=to_string(b);
	len=B.length();
	ten=1;
	new_num=b;
	for(i=0;i<len; i++){
		
		r=b%10;
		b/=10;
		mul=a*r*ten;
		cout<<setw(6)<<mul<<endl;
		sum=sum+mul;
		ten*=10;
		
	}
	cout<<"-----------"<<endl;
	cout<<setw(6)<<sum;
}
