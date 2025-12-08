#include<iostream>
#include<vector>
using namespace std;
int main(){
	//use of XOR
	vector<int> vec={1,3,5,5,3};
	int ans=0;
	for (int val: vec){
		ans=ans^val;
	}
	cout<<"Answer: "<<ans<<endl;
	cout<<"Size "<<vec.size()<<endl;
	cout<<"Capacity "<<vec.capacity()<<endl;
	vec.push_back(7);
	cout<<"Capacity "<<vec.capacity()<<endl;
	vec.pop_back();
	cout<<vec.front();
	cout<<vec.back();
}