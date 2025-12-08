#include<iostream>
#include<vector>
using namespace std;

string isPrime(int n){
	if(n==1) return "Not Prime NotComposite\n";
	for(int i=2; i*i<=n; i++){
		if(n%i==0){
			return "Not Prime\n ";
		}
	}
	return "Prime \n";
}
//Sieve of Eratosthenes |
int countPrimes(int n){
	vector<bool> Prime(n+1,true);
	int count=0;
	
	for(int i=2;i<n;i++){
		if(Prime[i]) count++;
	
		
		for( int j=i*2;j<n;j+=i){
		
			Prime[j]=false;
			
		}
	}
	return count;
}
int main(){
//cout<<isPrime(1);
cout<<countPrimes(10);
return 0;
}