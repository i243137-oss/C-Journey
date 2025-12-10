//Umair Hassan Class ID 3137 SE(c)
#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
	int n1,n2;
	
	cout<<"Enter starting Number ";
	cin>>n1;
	cout<<"Enter Ending Number " ;
	cin>>n2;
	for(n1; n1<=n2; n1++){
	for(int i=n1; i<=n2; i++){
	if((i*n1)%10==0){
	cout<<n1<<" x "<<i<<" = *"<<endl;
	
	}
	else
	cout<<n1<<" x "<<i<<" = "<<i*n1<<endl;
	}
	
	 
	}
	}
	 
