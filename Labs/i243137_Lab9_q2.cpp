//Umair Hassan Roll NO 3137 SE(C)
#include<iostream>
using namespace std;
int main(){
	int num1,num2,hcf,i;
do 
	{
		cout<<"Enter Postive Numbers"<<endl;
		cout<<"Enter Number a  : ";
	cin>>num1;
	cout<<"Enter Number b   : ";
	cin>>num2;
}
	while(num1<=0 && num2<=0);
	i=1;
	
	while(i<=num1 ){
		if(num1%i==0 && num2%i==0){
			hcf=i;
		}
		i++;
	}
	cout<<"HCF is "<<hcf<<endl;
}
	
