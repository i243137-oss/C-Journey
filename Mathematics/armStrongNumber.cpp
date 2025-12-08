#include<iostream>
using namespace std;
// AR number is that number which dighits are equal to number
bool isArmStrongNum(int n){
	int copyN=n;
	int sum3=0;
	while(n!=0){
		int dig=n%10;
		sum3+=dig*dig*dig;
		n/=10;
	}
	return sum3==copyN;
}
int main(){
	cout<<isArmStrongNum(371)<<endl;        //157 .  1
return 0;
}
