#include<iostream>
using namespace std;
int main(){
int a,b,c,max,result;
cout<<"Enter score of a :  ";
cin>>a;
cout<<"Enter score of b :  ";
cin>>b;
cout<<"Enter score of c  :  ";
cin>>c;
int bonus=0;
bonus=max+(max*0.10 );
max=( a>b && a>c ) ? a: (b>a && b>c  ) ? b : c;
bonus=max+(max*0.10 );
 result=(max > 500) ? bonus : result;
 cout<<"max number is : "<< max<<endl;
 cout<<" Your now reward is "<<result<<endl;
 return 0;
 }
	
