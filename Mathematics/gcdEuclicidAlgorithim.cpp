#include<iostream>
using namespace std;
int gcd(int a,int b){
	//simple approach
	/*
	if(a==0) return b;
	if(b==0) return a;
	if(a==b) return a;
	int gcd=1;
	for(int i=1; i<=min(a,b);i++){
		
		if(a%i==0 && b%i==0){
			gcd=i;
		}
		
	}
	return gcd;
	*/
//	optimal Approach
/*	while(a>0 && b>0){
		if(a>b) a-=b;
		else b-=a;
		
	}
	if(a==0) return b;
	else return a;
	*/
	//Most Optimal Approach
	while(a>0 && b>0){                   
		if(a>b) a%=b;

		else b%=a;
		
	}
	if(a==0) return b;              //Youtube
	else return a;
	
}
int LCM(int a,int b){
	return (a*b)/gcd(a,b);
}
int main(){
	int a=10;
	int b=5;
	cout<<"GCD of "<<a<<" and "<<b <<" is "<<gcd(10,5)<<endl;
	cout<<"LCM of "<<a<<" and "<<b <<" is "<<LCM(10,5)<<endl;
return 0;
}
