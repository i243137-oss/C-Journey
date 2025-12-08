#include<iostream>
#include<queue>
using namespace std;
int main(){
		priority_queue<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.emplace(5);
	
	cout<<"Top : "<<s.top()<<endl;
	while(!s.empty()){
			cout<<s.top()<<" ";
			s.pop();
			
	}
	cout<<endl;
	
	priority_queue<int> s2;
	
	s2.swap(s);
	cout<<"s size "<<s.size()<<endl;
	cout<<"s2 size "<<s2.size()<<endl;
		priority_queue<int,vector<int>,greater<int>> ss;
	ss.push(1);
	ss.push(2);
	ss.push(3);
	ss.emplace(5);
	
	cout<<"Top : "<<ss.top()<<endl;
	while(!ss.empty()){
			cout<<ss.top()<<" ";
			ss.pop();
			
	}
	cout<<endl;
	
return 0;
}
