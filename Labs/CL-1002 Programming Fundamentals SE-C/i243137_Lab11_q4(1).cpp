// Umair Hassan Class ID 3137 SE(c)
#include<iostream> 
using namespace std;
int main(){
  string dumpling[4]={" Grab Dumpling","Bite Dumpling","Chew Dumpling"," Swallow Dumpling"};
  int moves[5]={1, 2, 3, 4, 2}
  ,num;
  cout<<"Enter the number of dumplings Po wants to eat"<<endl;
  
  cin>>num;
  
  
  if(num==0 ){
  cout<<"PU is full"<<endl;
  }
  else {
  for(int i=0; i<num; i++){
  for(int j=0; j<4; j++){
  cout<<dumpling[moves[j]-1]<<endl;
  }
  cout<<endl<<endl;
  }
  
}
}
