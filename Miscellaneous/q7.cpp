#include<iostream>
//Name Umair Hassan Roll NO 3137 SE(C)
using namespace std;
int main(){
	int pf,cal,ap,ict,ps,hpf,hcal,hap,hict,hps;    //PF  ARE marks of COURSES  //h maean credit hours
	float gpf,gcal,gap,gps,gict;                   // g in variable for grade of course 
	cout<<"Enter the absolutes of first course :"<<endl;
	cin>>pf;
	cout<<"Enter the credit hours : "<<endl;
	cin>>hpf;
	cout<<"Enter the absolutes of second course :"<<endl;
	cin>>cal;
	cout<<"Enter the credit hours : "<<endl;
	cin>>hcal;
	cout<<"Enter the absolutes of third course :"<<endl;
	cin>>ap;
	cout<<"Enter the credit hours : "<<endl;
	cin>>hap;
	cout<<"Enter the absolutes of fourth  course :"<<endl;
	cin>>ict;
	cout<<"Enter the credit hours : "<<endl;
	cin>>hict;
	cout<<"Enter the absolutes of fifth  course :"<<endl;
	cin>>ps;
	cout<<"Enter the credit hours : "<<endl;
	cin>>hps; 
	
	//gradeponts
	gpf=(pf>=90)? 4.00:
	 (pf>=86)? 4.00:
	 (pf>=82)? 3.67:
	 (pf>=78)? 3.33:
	 (pf>=74)? 3.00:
	 (pf>=70)? 2.67:
	 (pf>=66)? 2.33:
	 (pf>=62)? 2.00:
	 (pf>=58)? 1.67:
	 (pf>=54)? 1.33:
	 (pf>=50)? 1.00: 0;
	 //2nd course
	 gcal=(cal>=90)? 4.00:
	 (cal>=86)? 4.00:
	 (cal>=82)? 3.67:
	 (cal>=78)? 3.33:
	 (cal>=74)? 3.00:
	 (cal>=70)? 2.67:
	 (cal>=66)? 2.33:
	 (cal>=62)? 2.00:
	 (cal>=58)? 1.67:
	 (cal>=54)? 1.33:
	 (cal>=50)? 1.00: 0;
	 //3rd course
	 gap=(ap>=90)? 4.00:
	 (ap>=86)? 4.00:
	 (ap>=82)? 3.67:
	 (ap>=78)? 3.33:
	 (ap>=74)? 3.00:
	 (ap>=70)? 2.67:
	 (ap>=66)? 2.33:
	 (ap>=62)? 2.00:
	 (ap>=58)? 1.67:
	 (ap>=54)? 1.33:
	 (ap>=50)? 1.00: 0;
	 // 4th course
	 gict=(ict>=90)? 4.00:
	 (ict>=86)? 4.00:
	 (ict>=82)? 3.67:
	 (ict>=78)? 3.33:
	 (ict>=74)? 3.00:
	 (ict>=70)? 2.67:
	 (ict>=66)? 2.33:
	 (ict>=62)? 2.00:
	 (ict>=58)? 1.67:
	 (ict>=54)? 1.33:
	 (ict>=50)? 1.00: 0;
	 // 5th course
	 gps=(ps>=90)? 4.00:
	 (ps>=86)? 4.00:
	 (ps>=82)? 3.67:
	 (ps>=78)? 3.33:
	 (ps>=74)? 3.00:
	 (ps>=70)? 2.67:
	 (ps>=66)? 2.33:
	 (ps>=62)? 2.00:
	 (ps>=58)? 1.67:
	 (ps>=54)? 1.33:
	 (ps>=50)? 1.00: 0;
	float sgp=gps*hps+gict*hict+gpf*hpf+gap*hap+gcal*hcal;   // course GP sum
	int hours=hps+hcal+hpf+hict+hap;                           // credit "sum
	float gpa=sgp/hours;
	cout<<"Your Gpa : "<<gpa<<endl;
	(gpa==4.00)? cout<<"Congratulations ! Your name is placed in Rector List of Honor ":
	(gpa>3.50)	? cout<<"Congratulations ! Your name is placed in Dean List of Honor.":
	(gpa <2.00)	? cout<<" Your name is placed in Warning  .": cout<<" Keep Up  .";
	 return 0;
}
	
	

