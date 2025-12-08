#include<iostream>
#include<vector>
using namespace std;
int main(){
	pair<int,int> a={1,2};
	// it an be also
	// paint<int,pair<int,int>> a={1,{1,2}}     
	// cout a.second.first
	cout<<a.first<<endl;
	cout<<a.second<<endl;
//	we can also  craet a vector
vector<pair<int,int>> aa={{1,2},{2,2}};
aa.push_back({2,3}); //it only insets
aa.emplace_back(1,2); //it place the objects to place
for(pair<int,int> val:aa){
	cout<<val.first<<endl;
	cout<<val.second<<endl;
}
	
return 0;
}
