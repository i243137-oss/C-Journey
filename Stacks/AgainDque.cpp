#include<iostream>
#include<deque>
using namespace std;
int main(){
	deque<int> dq;
	dq.push_back(12);
	dq.push_front(4);
	dq.pop_front();
	cout<<dq.front();
return 0;
}
