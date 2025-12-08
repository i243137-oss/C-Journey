#include<iostream>
#include<string>
using namespace std;
int main(){
		int salery,service,time,rating,opt;
		double tsalary=0,bbonus=0,obonus=0,dbbonus=0,lallownce=0,hsbonus=0,bonus=0,income=0;
		
		        string name;
		        cout<<"Enter Employee Name "<<endl;
		
		        getline(cin,name);                       
	do {												 // loop for validity check
				cout<<"Enter Employee's salary "<<endl;
				cin>>salery;
		if(salery<0) {
			     cout<<"Invalid Input "<<endl;
				
		}
		
	}while(salery<0);
	do{											         // loop for validity check
		
				cout<<"Enter Employee's years of service "<<endl;
				cin>>service;
		if(service<0){
		        cout<<"Invalid Input "<<endl;
		 }
   }while(service<0);
	    if(service>=3){                                     // serivice must be greater than 3 for bonus
	do{
			
			    cout<<"Rate the Employees Performance (1 to 5) "<<endl;
		        cin>>rating;
		if(rating<0 || rating>5){
		           cout<<"Invalid Input "<<endl;
		    }
		}while(rating<0 || rating>5);
		if(rating>=3){
			
		switch(rating){
		case 5:
					if(service>5 && service<=10)
					tsalary=salery*0.15;                      // tsalary is base bonus
				else if(service>=3 && service <=5)
					tsalary=salery*0.1;
					else 
					tsalary=salery*0.2;
					break;
		case 4:
					if(service>5 && service<=10)
					tsalary=salery*0.1;
		else if(service>=3 && service <=5)
					tsalary=salery*0.07;
		else 
					tsalary=salery*0.15;
					break;
		case 3:
		if(service>5 && service<=10)
					tsalary=salery*0.08;
		else if(service>=3 && service <=5)
					tsalary=salery*0.05;
		else 
					tsalary=salery*0.12;
					break;
					
		}}
		}	
	do{
				
				cout<<"Enter over time in hours "<<endl;
				cin>>time;
		if(time<0 ){
					cout<<"Invalid Input "<<endl;
		}
	}while(time<0);
			if(time>=100){
			if(time>=200)
				obonus=salery*0.04;
				else
				obonus=salery*0.02;						//overtime bonus
		if(rating==5)
				obonus= obonus + obonus*0.01;
		} 
	do {                                               // // loop for validity check
				
				cout<<"Please select Depatrment (1 to 3)"<<endl;
				cout<<"1. Software Engineering"<<endl;
				cout<<"2. Sales Department"<<endl;
				cout<<"3. Other Department"<<endl;
				cin>>opt;
		if(opt<0 || opt>3 ){
				cout<<"Invalid Input "<<endl;
		}
	}while(opt<0 || opt>3);
		switch(opt){                            
	    case 1:
				 	dbbonus=salery*0.05;             //department base bonus
				 	break;
	    case 2:
	    			dbbonus=salery*0.03;
	    			break;
	    default :
	    			break;
		}
	do {                                              // loop for validity check
				
				 cout<<"Please select Region (1 to 3)"<<endl;
				 cout<<"1. Region A"<<endl;
				 cout<<"2. Region B "<<endl;
				 cout<<"3. Other Region C"<<endl;
				 cin>>opt;
		if(opt<0 || opt>3 ){
					cout<<"Invalid Input "<<endl;
	   }
	}while(opt<0 || opt>3);
		switch(opt){
	    case 1:
				 	lallownce=salery*0.05;             //location allownce;
				 	break;
	    case 2:
	    			lallownce=salery*0.03;
	    			break;
	    default :
	    			break;
		}
			        bonus=tsalary+obonus+lallownce+dbbonus +hsbonus;
			  		income=salery+bonus;
			
		if(income>100000)
			  		hsbonus=income*0.05;
			   // required ouput
				    cout<<"Employer Name :           "<<name<<endl;
				    cout<<"Salary (Without bonus) :  "<<salery<<endl;
				    cout<<"Base  bonus:              "  <<tsalary<<endl;
				    cout<<"Overtime  bonus:          " <<obonus<<endl;
				    cout<<"Department base  bonus:   "<<dbbonus<<endl;
				    cout<<"locaton allownce:         "<<lallownce<<endl;
		if(hsbonus>0)
			    	cout<<"Higher Salery bonus:      "<<hsbonus<<endl;
			     	
			    
			     	cout<<"Salary (With bonus) :      "<<income<<endl;
			    
			    
			   
			  
			  
			  
			}
			
			
		
		

