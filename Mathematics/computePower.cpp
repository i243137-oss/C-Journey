#include<iostream>
using namespace std;
// every numer has ln x+1 has binary digits.for Example .8 has ln8+1 digits=4 digits
double calPow(double x,int n){
	if(n==0) return 1;
	if(x==0 && n>0) return 0;
	if(x==0 && n<0) {
		cout<<"Error"<<endl;
		return -1;
	}
	if(x==1) return 1;
	if(x==-1 && n%2==0) return 1;
	if(x==-1 && n%2!=0) return -1;
	
	long binform=n;
	double ans=1;
	if(n<0){
		x=1/x;
		binform=-binform;
	}
	while(binform>0){
		if(binform%2==1){
			ans*=x;
			
		}
		x=x*x;
		binform/=2;
	}
	return ans;
}
int main(){
	cout<<calPow(0,-2);
return 0;
}
