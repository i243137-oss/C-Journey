// Umair Hassan
// Roll no 3137 SE(C)
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;
int main(){
int rnd=rand()%200;
srand(time(0));
(rnd==0) ? cout<<" zero" : (rnd%2==0)? cout<<"Number is a even" : cout<<"Number is a odd";
rnd++;
cout<<"\n";
(rnd==0) ? cout<<" zero" : (rnd%2==0)? cout<<"Number is a even" : cout<<"Number is a odd";
cout<<"\n";
return 0;
}
