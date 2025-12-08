#include<iostream>
#include<vector>
#include<list>
using namespace std;
int main(){
	list<int> li={1,2,3};
	li.emplace_back(1);
    li.push_back(3);
    li.push_front(2);
    li.pop_back();
    li.pop_front();
    for(int i: li){
    	cout<<i<<",";
	}
	cout<<endl;
	
return 0;
}
