// Umair Hassan Class ID 3137 SE C 
#include<iostream>
using namespace std;
int main(){
		int max=0,a1,a2,a3,a4,a5,n;        // variables
		cout<<"Enter values "<<endl;	 
	for(int i=1; i<=5; i++)    // loop for finding maximum value
	{
		if(i==1){
		    cout<<"1 : ";
			cin>>a1;
			n=a1;
		}
		else if (i==2){
			cout<<"2 : ";
			cin>>a2;
			n=a2;
		}
		else if (i==3){
			cout<<"3 : ";
			cin>>a3;
			n=a3;
		}
		else if (i==4){
			cout<<"4 : ";
			cin>>a4;
			n=a4;
		}
		else {
			cout<<"5 : ";
			cin>>a5;
			n=a5;
		}
		if(n>max)
			max=n;	
	}
			cout<<endl<<endl;     
    // printing graph
    
	for(int i=max; i>=1;i--){ 
	
	    if(i>=10)					// if-else for aligning
	    
			cout<<i;                // row umber
		else
			cout<<"0"<<i;
	for(int j=1; j<=5; j++){
		
		if(i<=a1 && j==1){
				cout<<" *";
		}
		else if(i<=a2 && j==2){
				
				cout<<" *";
		}
		else if(i<=a3 && j==3){
				
				cout<<" *";
		}
		else if(i<=a4 && j==4){
				
				cout<<" *";
			
		}
		else if(i<=a5 && j==5){
				
				cout<<" *";
			
		}
			else{
				cout<<"  ";
		}
		}
				cout<<endl;
	}
	for(int i=0; i<=5; i++){
		if(i==0)
		         cout<<"  ";          // space for aligning
		else 
		          cout<<" "<<i;       // print x axis
	}
}
