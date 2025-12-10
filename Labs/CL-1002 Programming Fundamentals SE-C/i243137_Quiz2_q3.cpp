//Umair Hassan Roll NO 3137 SE(C)
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
int d, bonus;
cout<<"Enter Donation"<<endl;
cin>>d;
unsigned int seed=0;
seed =srand (time(0));
bonus=rand() % (70-50) +50 ;
( d<=500) ? cout<<setw(12)<<"Bronze Tier"<<endl :
( d>=500 && d<=999) ? cout<<setw(12)<<"Silver Tier"<<endl : cout<<setw(12)<<"Gold Tier"<<endl
cout<<setw(12)<<" Orignal Denotion"<<d<<end;
cout<<setw(12)<<ixed<<setprecision(2)<<"  Denotion with bonus"<<d+bonus<<endl;
return 0;
}



