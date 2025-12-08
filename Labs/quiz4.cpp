//Umair Hassan Class ID 3137 24 OCT
#include<iostream>
using namespace std;
int main(){
	int sal1,sal2,sal3,sal4,sal5,max;
	float avgs;
	cout<<"Enter sellery of Employer1 : ";
	cin>>sal1;
	cout<<"Enter sellery of Employer2 : ";
	cin>>sal2;
	cout<<"Enter sellery of Employer3 : ";
	cin>>sal3;
	cout<<"Enter sellery of Employer4 : ";
	cin>>sal4;
	cout<<"Enter sellery of Employer5 : ";
	cin>>sal5;
	cout<<endl;
	avgs=(sal1+sal2+sal3+sal4+sal5)/5;
	cout<<" Saleries"<<endl;
	cout<<" Employer1 : "<<sal1<<endl;
	cout<<" Employer2 : "<<sal2<<endl;
	cout<<" Employer3 : "<<sal1<<endl;
	cout<<" Employer4 : "<<sal1<<endl;
	cout<<" Employer5 : "<<sal1<<endl;
	cout<<" Average Salery : "<<avgs<<endl;
	if(sal1>sal2 && sal1>sal3 &&sal1>sal4 &&sal1>sal5 ){
		max=sal1;
	}
	else if(sal2>sal1 && sal2>sal3 &&sal2>sal4 &&sal2>sal5 ){
		max=sal2;
	}
	
	
}
