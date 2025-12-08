#include<iostream>
////Name Umair Hassan Roll NO 3137 SE(C)
using namespace std;
int main(){
	int price ,a,b,c;
	cout<<"Enter amount :"<<endl;
	cin>>price;
	a=price/100; // For Hundered Notes
	price%=100;  // Baqya
	b=price/50;   // for fifty notes
	price%=50;    //baqaya
	c=price/10;   // ten notes
	price=price%10;
	cout<<a<<"  Hunderd Notes  ";
	cout<<b<<"  Fifty Notes ";
		cout<<c<<"  Ten Notes ";
			cout<<price<<"  Coins ";

	
}
