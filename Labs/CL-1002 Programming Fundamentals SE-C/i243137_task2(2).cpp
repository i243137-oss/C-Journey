// Umair Hassan
// Roll no 3137 SE(C)
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;
int main(){
int rnd=rand() %201 -100;
string a=(rnd==0) ? " Zero" : (rnd>0)? "Postive" : "Negative";
cout<<a<<endl;
return 0;
}
