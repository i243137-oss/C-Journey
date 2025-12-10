// Umair Hassan Class ID 3137 SE(c)
#include<iostream> 
using namespace std;
int main(){
int i,counter=0;
  string sign[5]={"Tiger","Snake","Dragon","Monkey","Bird"};
  //int choice={1,2,3,4,5};
  
 int signi[8];
 int sign_naruto[8];
 cout<<"Sign Demonstration"<<endl;
   cout<<"1: Tiger"<<endl;
   cout<<" 2 : Snake "<<endl;
   cout<<"3: Dragon"<<endl;
   cout<<" 4: Monkey,"<<endl;
   cout<<" 4: Monkey,"<<endl;
   
     
 cout<<"Sensie Sign Demonstration"<<endl;
 for(i=1;i<=8; i++){
 
 cin>>signi[i-1];
 while(signi[i-1] <0 ||  signi[i-1] >5 ){
  cout<<"Invalid Input"<<endl;
  cin>>signi[i-1];
 
 }
 }
 cout<<"Nuroto Sign Demonstration"<<endl;
 for(i=1;i<=8; i++){
 
 cin>>sign_naruto[i-1];
 while(sign_naruto[i-1] <0 ||  sign_naruto[i-1] >5 ){
  cout<<"Invalid Input"<<endl;
  cin>>sign_naruto[i-1];
 
 }
 }
 for(i=0; i<8; i++){
   if(signi[i]==sign_naruto[i]){
   cout<<i<<" :"<<endl;
    cout<<"Sensie sign is "<<sign[signi[i]]<<endl;
    cout<<"Naruto  sign is "<<sign[sign_naruto[i]]<<endl;
    cout<<"Correct"<<endl;
    counter++;
    cout<<endl;
    }
    else{
  
   cout<<i<<" :"<<endl;
   
    cout<<"Sensie sign is "<<sign[signi[i]]<<endl;
    cout<<"Naruto  sign is "<<sign[sign_naruto[i]]<<endl;
    cout<<"Wrong"<<endl;
     cout<<endl;
    }
 }
 cout<<endl<<endl;
 cout<<counter<<"was correct"<<endl;
 if(counter>6)
 cout<<"She is now master"<<endl;
 
 }
 
 
 


