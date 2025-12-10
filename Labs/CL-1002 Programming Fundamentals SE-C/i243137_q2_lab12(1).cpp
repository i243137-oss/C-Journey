//Umair Hassan Class ID 3137 SE C
#include<iostream>
#include<string>
using namespace std;
int main(){
int arr[7][3];
string meal [3]={"Break Fast", "Lunch","Dinnner"};
string day[7]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
string notes[7];
 string hours[3]={"7AM TO 8AM","12 PM TO 1 PM","7PM TO 9PM"};
int mrev[3];
int rev[7];
for(int i=0; i<7; i++){ 
cout<<day[i]<<"'s Revnue "<<endl;
  for(int j=0; j<3; j++){
      cout<<meal[j]<<" : ";
      cin>>arr[i][j];
      rev[i]+=arr[i][j];
      mrev[j]+=arr[i][j];
      
      cout<<endl;
      
  } 
     cout<<day[i]<<"'s Special Notes ";
     cin.ignore();
      getline(cin,notes[i]);
      cout<<endl;
  
       
}
cout<<endl;
cout<<"Summary "<<endl; 
int max=0 , max1=0 ,counter, counter1,sum=0;
for (int i=0; i<7; i++){

 if (rev[i]>max){
 max=rev[i];
 counter=i;}
 sum+=rev[i]; 
}
 for(int i=0; i<3; i++){
 if(mrev[i]>max1){
 max1=mrev[i];
 counter1=i;
 }}
 cout<<"Highest Daily Revenue: "<<day[counter]<<" " <<max<<endl;
 cout<<"Most Profitable Meal : "<<meal[counter1]<<" (Average :  "<<max/7<"Rs )"<<endl; 
 cout<<"Peak hours "<<hours[counter1]<<" "<< meal[counter1]<<endl;
 cout<<"Special Notes"<<endl;
 for (int i=0; i<7; i++){ 
 if(notes[i]!="-"){
 cout<<day[i]<<" " <<notes[i]<<endl;
 }
 }
}
