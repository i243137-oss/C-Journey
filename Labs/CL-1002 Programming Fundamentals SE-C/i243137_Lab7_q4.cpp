// Umair Hassan class id 3137 SE(C)
#include<iostream>
using namespace std;
int main(){
	long int x,y;
		cout<<"Umair Hassan Class ID 3137 SE(C)"<<endl<<endl;
	cout<<"Enter the x cordinate :  ";
	cin>>x;
	cout<<"Enter the y cordinate :  ";
	cin>>y;
		cout<<endl<<endl;
	if(x>0 && y>0){
		cout<<"the point ("<<x<<", "<<y<<") lies in Quadrant I. ";
	}
	else if(x<0 && y>0){
	
		cout<<"the point ("<<x<<", "<<y<<") lies in Quadrant II. ";
	}
	else if(x<0 && y<0){
	
		cout<<"the point ("<<x<<", "<<y<<") lies in Quadrant III. ";
	}
	else if(x>0 && y<0){
	
		cout<<"the point ("<<x<<", "<<y<<") lies in Quadrant IV. ";
	
	}
	else if(x==0 && y!=0){
	
		cout<<"the point ("<<x<<", "<<y<<") lies  on y-axs. ";
   }
    else if( y==0 && x!=0){
	
		cout<<"the point ("<<x<<", "<<y<<") lies on x-axis. ";
	}
   else if(x==0 && y==0){
	
		cout<<"the point ("<<x<<", "<<y<<") lies on origin. "; 
	}
	else {
		cout<<"Enter Valid Input";
	}



	
	
}
