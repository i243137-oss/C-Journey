// Umair Hassan roll no 3137 SE (C)
#include<iostream>
using namespace std;
int main(){
int n;
float dn;
cout<<"Enter Integer ";
cin>>n;
int result=(n%2==0 && n%5==0)? n*2:
    (n%2!=0 && n%3==0) ? n+3:n-1;
    cout<<"After evulution , n is "<<result<<endl;
dn=result -result*0.1;
cout<<"The deducted result is : "<<result<<endl;
}
