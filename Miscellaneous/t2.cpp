// Umair Hassan class id 3137  Assigment 3 SE(C)
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
		char operation,a;
		int num1,num2,max,min;
		double ans,answer;                  
		
		srand(time(0));                                   // for random number
	do {												// loop for validity
		
		cout<<"For which operation an exercise should be generated?"<<endl;
		cin>>operation;														// getting operation
	}while(operation!='+'&& operation!='-'&& operation!='*'&&operation!='/');
		cout<<"What is the maximum value for the input values of the exercise?"<<endl;
		cin>>max;														// maximum value
	do{
		
		
		cout<<"Are negative values allowed in the exercise? Y for Yes N for No"<<endl;
		cin>>a;
	}while(a!='Y' && a!='N');   // loop for validity
		if(a=='Y'){
			min=-max;
		}
		else{
			min=0;
		}
		     num1=rand()%(max-min+1)+min;           
		if(a=='N'){
			do{
			num2=rand()%(max-min+1)+min;	
	do {
        num2 = rand() % (max - min + 1) + min;
    } while (operation == '/' && num2 == 0); // Avoid zero
	}while(num2>num1 && operation=='-');   //  validity check
		}
		else{
			num2=rand()%(max-min+1)+min;
		}
		
		
		
		
		
	    switch(operation){
		case'+' :
			cout<<num1<<" "<<operation<<" "<<num2<<" = ?"<<endl;
			
			ans=num1+num2;
			break;
		case'-' :
			cout<<num1<<" "<<operation<<" "<<num2<<" = ?"<<endl;
			
			ans=num1-num2;
			break;
		case'*' :
			cout<<num1<<" "<<operation<<" "<<num2<<" = ?"<<endl;
			
			ans=num1*num2;
			break;
		case'/' :
			cout<<num1<<" "<<operation<<" "<<num2<<" = ?"<<endl;
			
			ans=(double)num1/(double)num2;
			break;
		}
	do{
		    cin>>answer;              // user inpunt answer
	}while(answer!=ans);
		
			cout<<"Congratulation! You chased it"<<endl;

}

