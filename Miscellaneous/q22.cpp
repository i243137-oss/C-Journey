#include<iostream>
using namespace std;
char halt_lift(char status){
	if(status=='W'){
		cout<<"Lift is successfuly halted"<<endl;
		status='H';
		return status;
	}
	else {		
	cout<<"Lift is already halted"<<endl;
	return status;	
	}
}
char un_halt_lift(char status)  {
   if(status=='H'){
		cout<<"Lift is successfully Operational Now"<<endl;
			status='W';
		return status;
	}
	else {		
	cout<<"Lift is already Operational"<<endl;
	return status;	
	}
	
}
int liftdown(int current_floor,int requested_floor ){

		for(int i=current_floor-1;i>=-1; i--){
		
			cout<<"LIFT IS GOING DOWN"<<endl;
			if(i==-1){
					cout<<"You are at Basement"<<endl;
			}
			else if(i==0){
					cout<<"You are at Ground Floor"<<endl;
				
			}
			else if(i==1) 
			cout<<"You are at "<<i<<"st Floor"<<endl;
			else if(i==2){
				cout<<"You are at "<<i<<"nd Floor"<<endl;	
			}
			else if(i==3){
			cout<<"You are at "<<i<<"rd Floor"<<endl;	
			}
			else 
			cout<<"You are at "<<i<<"th Floor"<<endl;
		}
		
	return requested_floor;
	
}
int liftup(int current_floor,int requested_floor ){
	
		for(int i=current_floor+1;i<=4; i++){
			
			cout<<"LIFT IS GOING UP"<<endl;
			if(i==-1){
					cout<<"You are at Basement"<<endl;
			}
			else if(i==0){
					cout<<"You are at Ground Floor"<<endl;
				
			}
			else if(i==1) 
			cout<<"You are at "<<i<<"st Floor"<<endl;
			else if(i==2){
				cout<<"You are at "<<i<<"nd Floor"<<endl;	
			}
			else if(i==3){
			cout<<"You are at "<<i<<"rd Floor"<<endl;	
			}
			else 
			cout<<"You are at "<<i<<"th Floor"<<endl;
		}
	return requested_floor;	
	
}

int lift_operating_system(int requested_floor, int current_floor, char 
lift_status){
	int counter=0;
	
	while(true){

 	int choice,cho;
 	cout<<"=======Welcome To FAST NUCES======="<<endl;
 	cout<<"Enter menue (1-3)"<<endl;
	cout<<"1. Go to a floor"<<endl;
	cout<<"2. Halt the lift"<<endl;
	cout<<"3. Unhalt the lift"<<endl;
	cout<<"4. Exit        "  <<endl;
	cout<<"Enter Choice "<<endl;
	
	do {
	cin>>choice;
	if (choice<1 || choice>4){
	
	cout<<"Invalid Input  "<<endl;
	cout<<"Enter Again "<<endl;	
              }
	}while(choice<1 || choice>4);
	if(lift_status=='H' && choice==1){
		 cout<<"Lift is Halted.Unhalt it First "<<endl;
		 continue;
	}
		
	
	
	back :
	switch(choice){ 
	
	
		case 1 : 
		
		cout<<"Enter Floor You Want  To Go"<<endl;
		cout<<"-1.Basement "<<endl;
		cout<<"O.Ground Floor"<<endl;
		cout<<"1.First Floor"<<endl;
		cout<<"2.Second Floor"<<endl;
		cout<<"3.Third Floor"<<endl;
		cout<<"4.Fourth Floor"<<endl; 
		do {
	cout<<"Enter Floor"<<endl;
		cin>>requested_floor;
	if (requested_floor<-1 || requested_floor>4){
	
	cout<<"Invalid Input  "<<endl;
	cout<<"Enter Again "<<endl;	}
	
	if (requested_floor== current_floor){
	
	cout<<"You are currently on this floor  "<<endl;
	
	cout<<"Now You want to Press "<<endl;
	cout<<"1 For Exit "<<endl;
	cout<<"2 For  Back "<<endl;
}
	do {
	cin>>cho;
	if (cho<1 || cho>2){
	
	cout<<"Invalid Input  "<<endl;
	cout<<"Enter Again "<<endl;	
}
	}while(cho<1 || cho>2);
	switch(cho){
		case 1:
		choice=4;
		goto back;
		break;
		case 2:
		choice=1;
		goto back;
		break;
		} 
	}while(requested_floor<-1 || requested_floor>4);
	if ( current_floor< requested_floor ){
	 current_floor=liftup( current_floor,requested_floor );
                                         }
    else {
    current_floor=liftdown( current_floor,requested_floor );
	}

   
	break;
	case 2:
	
	 lift_status=halt_lift(lift_status);
	 lift_status='H';
		
	break;
	case 3:
	
	 lift_status=un_halt_lift(lift_status);
		
	break;
	case 4:
	cout<<"Thank For Using Lift"<<endl;
	return 0;	                 
	break;	
	}
	
 }

 
}
int main(){
	
	int requested_floor,  current_floor=-1;
	char lift_status='W';
	lift_operating_system(requested_floor, current_floor, lift_status);
	

	 
	
		

}
