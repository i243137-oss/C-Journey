// Umair Hassan Class ID 3137 SE(c)
#include<iostream> 
using namespace std;
int main(){
int b=0,c=0,d=0,e=0,max=0,ord;
 string max_o;
  	string dish[5]={"Chicken","Mutton","egetable","Fish","Special"};
  	
  	int list[5]={0,0,0,0,0};
  	int price[5]={10,12,8,11,15};
  	cout<<"Which Briyani You want to ordered ?"<<endl;
  	cout<<"1: Chicken"<<endl;
  	cout<<"2: Mutton"<<endl;
  	cout<<"3: Vegetable"<<endl;
  	cout<<"4: Fish"<<endl;
  	cout<<"5: Special"<<endl;
  	while(ord!=-1){
  	
  	cin>>ord;
  	 list[ord-1]+=1;
  	
  	
  	if(list[ord-1]>max){
  	max=list[ord-1];
  	max_o=dish[ord-1];
  	}
  	if(ord<0 || ord>5)
  	cout<<"Invalid Input"<<endl;
  	
  
  	
  	}
  	for(int i=0;i<5;i++ ){
  	cout<<dish[i]<<" :   "<<list[i]<<endl<<"    Price :  "<<list[i]*price[i]<<endl;
  	
  	
  	}
  	cout<<max_o<<" was ordered most"<<endl;
  
  	



}



