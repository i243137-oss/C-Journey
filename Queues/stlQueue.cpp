//FIFO First in first out
#include<iostream>
#include<queue>
using namespace std;
int main(){
		queue<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.emplace(5);
	
	cout<<"Top : "<<s.front()<<endl;
	while(!s.empty()){
			cout<<s.front()<<" ";
			s.pop();
			
	}
	cout<<endl;
		queue<int> s2;
	
	s2.swap(s);
	cout<<"s size "<<s.size()<<endl;
	cout<<"s2 size "<<s2.size()<<endl;
return 0;
}
