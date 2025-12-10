// Umair Hassan
// Roll no 3137 SE(C)
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;
int main()
{
    int x = 8;
    int y = 16;
    cout<< "Before  Swap x ="<< x<<endl;
     cout<<" Before  Swap y="<< y<<endl;
    x = x ^ y; 
    y = x ^ y; 
    x = x ^ y; 
    cout << "After Swapping: x ="<< x<<endl;
     cout<<" y="<<y<<endl;
    return 0;
}

