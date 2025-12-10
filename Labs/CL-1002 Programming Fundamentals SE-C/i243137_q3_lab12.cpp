#include<iostream>
using namespace std;
int main(){ 
int i,j,row,col,counter=0,counter1=0;
char clr,perm;
back:
char arr[4][4]={{'w','w','w','w'},{'w','-','-','w'},{'w','-','-','w'},{'w','w','w','w'}};

cout<<" ====== Layer's Bakery Pakistan Day Special ===== "<<endl;
for(int i=0; i<4; i++){
for(int j=0; j<4; j++ ){
 cout<<arr[i][j]<<" ";
}
cout<<endl;

} 
cout<<" Enter Row (1-4) ";
do{
cin>>row;
if(row<0 || row>3)
cout<<" Enter Valid Input"<<endl;
if(row==1 || row==4)
cout<<"  You can not uaptdate border titles "<<endl;

}while(row<0 || row>3);
cout<<endl;
cout<<" Enter column (1-4) ";
do{
cin>>col;
if(col<0 || col>3)
cout<<" Enter Valid Input"<<endl;


}while(col<0 || col>3);
cout<<endl;
cout<<"Enter Color (W/G) ";
do{
cin>>clr;
if(clr!='w' && clr!='w')
cout<<" Enter Valid Input"<<endl;
if(col==1 || col==4)
cout<<"  You can not uaptdate border titles "<<endl;


}while(clr!='w' && clr!='g');
cout<<endl;

arr[row-1][col-1]=clr;
cout<<"Updated Design "<<endl;
for(int i=0; i<4; i++){
for(int j=0; j<4; j++ ){
 cout<<arr[i][j]<<" ";
}
cout<<endl;
}
for(int i=0; i<4; i++){
for(int j=0; j<4; j++ ){
 if(arr[i][j]=='w')
 counter++;
 if(arr[i][j]=='g')
 counter1++;
}}
 cout<<"Design Sats "<<endl;
 cout<<"White Titles : "<<counter<<endl;
 cout<<"Green : "<<counter1<<endl;
 cout<<"Do you want to continue"<<endl;
 cin>>perm;
 if(perm=='Y')
 goto back;
 else
 cout<<"Good Luck "<<endl;
}

