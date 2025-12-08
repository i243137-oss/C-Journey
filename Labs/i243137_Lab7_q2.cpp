//Umair Hassan class id 3137 SE(C)
#include<iostream>
using namespace std;
int main(){
	char grade;
		cout<<"Umair Hassan Class ID 3137 SE(C)"<<endl<<endl;
	cout<<"Enter Your Grade"<<endl;
	cin>> grade;
	if(grade>='A' && grade<='G'){
		if(grade=='A'){
			cout<<"Exellent!Keep it Up!"<<endl;
			cout<<"GPA : 4.OO"<<endl;
		}
	else if(grade=='B'){
			cout<<"Well Done! Good Job"<<endl;
			cout<<"GPA : 3.OO"<<endl;
		}
	else if(grade=='C'){
			cout<<"Satisfactory. Work harder for improvement."<<endl;
			cout<<"GPA : 2.OO"<<endl;
		}
	else if(grade=='D'){
			cout<<"Needs improvement. Focus on your studies."<<endl;
			cout<<"GPA : 1.OO"<<endl; }
   else   {
   	        cout<<"Fail. Additional effort required."<<endl;
   	        cout<<"GPA :0.00"<<endl;
				
			}}
	else  {
		cout<<"Inavid Input \a"<<endl;
	}	
			

}
