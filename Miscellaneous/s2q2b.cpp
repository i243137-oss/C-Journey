#include<iostream>
using namespace std;
int main(){
int rep;
cin>>rep;
int sv=10*rep;
for(int v=sv; v>=-sv; v-=10)
cout<<v<<" ";
}

