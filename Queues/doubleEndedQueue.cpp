#include<iostream>
#include<vector>
#include<deque>
using namespace std;
int main(){
		deque<int> li={1,2,3};
	li.emplace_back(1);
    li.push_back(3);
    li.push_front(2);
    li.pop_back();
    li.pop_front();
    cout<<li[2]<<endl; // that is diff btw list and deque
    for(int i: li){
    	cout<<i<<",";
	}
	cout<<endl;
	
return 0;
}
