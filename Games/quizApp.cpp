#include<iostream>
using namespace std;
int main(){
  int gryffindor=0,hufflepuff=0,ravenclaw=0,slytherin=0;
  int answer1,answer2,answer3,answer4;
  cout<<"The Sorting Hat Quiz!.    "<<endl;
  cout<<"Q1) When I'm dead, I want "<<endl;
  cout<<"people to remember me as: "<<endl;
  cout<<"1) The Good  "<<endl;
  cout<<"2) The Great "<<endl;
  cout<<"3) The Wise  "<<endl;
  cout<<"4) The Bold  "<<endl;
  cout<<"Answer : "<<endl;
  cin>> answer1;
  if(answer1 == 1){
    hufflepuff+=1; }
    else if (answer1 == 2){
      slytherin+=1;
 
    }
    else if(answer1 == 3){
      ravenclaw+=1;

    } 
    else if(answer1 == 4){
      gryffindor+=1;

    }
    
    else {
      cout<<"Invalid input."<<endl;

    }
 cout<<"Q2) Dawn or Dusk?"<<endl;
 cout<<" 1) Dawn "<<endl;
  cout<<" 2) Dusk "<<endl;
 cout<<"Answer : "<<endl;
  cin>>answer2;
  if(answer2 == 1){
    gryffindor+=1;
    ravenclaw+=1;

     }
    else if (answer2 == 2){
      slytherin+=1;
      hufflepuff+=1;
 
    }
     else {
      cout<<"Invalid input."<<endl;

    }

 cout<<"Which kind of instrument "<<endl; cout<<"most pleases your ear? "<<endl;

  cout<<" 1) The violin "<<endl;
  cout<<" 2) The trumpet "<<endl;
  cout<<" 3) The piano "<<endl;
  cout<<" 4) The drum "<<endl;
 cout<<" Answer : "<<endl;
  cin>>answer3;
  if(answer3 == 1){
    slytherin+=1;
     }
    else if (answer3 == 2){
      hufflepuff+=1;
 
    }
    else if(answer3 == 3){
      ravenclaw+=1;

    } 
    else if(answer4 == 4){
      gryffindor+=1;

    }
    
    else {
      cout<<"Invalid input."<<endl;
    }
  cout<<"Q4) Which road tempts "<<endl;
  cout<<"you most?"<<endl;

 cout<<" 1) The wide, sunny grassy "<<endl; cout<<"lane "<<endl;
 cout<<" 2) The narrow, dark, "<<endl; cout<<"lantern-lit alley "<<endl;
 cout<<" 3) The twisting, leaf-strewn"<<endl; cout<<"path through woods "<<endl;
 cout<<" 4) The cobbled street lined "<<endl; cout<<"(ancient buildings) "<<endl;
 cout<<"Answer : "<<endl;
 cin>>answer4;
 if(answer4 == 1){
    slytherin+=1;
     }
    else if (answer4 == 2){
      hufflepuff+=1;
 
    }
    else if(answer4 == 3){
      gryffindor+=1;

    } 
    else if(answer4 == 4){
       ravenclaw+=1;
     

    }
    
    else {
      cout<<"Invalid input."<<endl;
    }
    int max=0;
    string house;
    if (gryffindor > max) {
  
  max = gryffindor;
  house = "Gryffindor";
  
}

if (hufflepuff > max) {

  max = hufflepuff;
  house = "Hufflepuff";
  
}

if (ravenclaw > max) {
  
  max = ravenclaw;
  house = "Ravenclaw";
  
}

if (slytherin > max) {
  
  max = slytherin;
  house = "Slytherin";
  
}

cout << house << "!\n";





    

  }






