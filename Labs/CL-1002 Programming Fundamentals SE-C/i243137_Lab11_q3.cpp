// Umair Hassan Class ID 3137 SE(c)
#include<iostream> 
using namespace std;
int main(){
int i,counter=0;
int catr[8];
cout<<"Enter Catridjes level"<<endl;
for(int i=1; i<=8; i++){ 
do {
cin>>catr[i];
if(catr[i]<0 || catr[i]>100)
cout<<"Error"<<endl;
}while(catr[i]<0 || catr[i]>100);


} 
 cout<<"Orignal  Catridjes level ";
 for(int i=1; i<=8; i++){ 
cout<<catr[i]<<"% ";


} 
cout<<endl;
 cout<<"  Catridjes Need Refiling ";
 for(int i=1; i<=8; i++){ 
 if(catr[i]<=30){
cout<<catr[i]<<"% ";
counter++;

}


} 

cout<<endl;
 cout<<"  Total Need Refiling "<<counter<<endl;
 }

