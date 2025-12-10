#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<fstream>

using namespace std;

void word(string words [] ) {
    ifstream infile("words.txt");  // Open file for reading

    if (infile.is_open()) {
        for (int i=0; i<20; i++ ){
        	infile >>words[i];
		}
       
        infile.close();
    } else {
        cout << "Unable to open file!" << endl;
    }
}
int main(){
	bool flag=true;
	int wrong=0;
	string words[20],guessWord;
	word( words ) ;
	cout<<"Please Guess the right word from the following"<<endl;
	  for (int i=0; i<20; i++ ){
        	cout<< words[i];
        	cout<<endl;
		}
		cout<<endl;
			int 	wordNum=rand()%(20);
	string randword=words[wordNum];
	
	for  (int i=0; i<6; i++){
	cout<<"Enter Guess Word"<<endl;
		cin>>guessWord;

	
	if(guessWord.length()==6){
		if(guessWord==randword){
		cout<<"You are saved now"<<endl;
		break;
	}
		else {
			cout<<"Your guess is wrong! Try again\n";
			wrong++;
		}
	
		}
		else {
			cout<<"Please Enter the 6 lettered word";
		}
			if(wrong==6){
		cout<<" ____\n";
		cout<<"|    |\n";
		cout<<"|    o\n";
		cout<<"|   /|\\"<<endl;
		cout<<"|   ___\n";
		cout<<"|   - -\n";
		cout<<"|   | |\n";
		cout<<"|\n";
		cout<<"|\n";
		cout<<"|\n";
		cout<<"|\n";
		cout<<"|________\n";
		cout<<"|        |__\n";
		cout<<"|           |\n";
		cout<<"|___________|";
	}
	if(wrong==5){
		cout<<" ____\n";
		cout<<"|    |\n";
		cout<<"|    o\n";
		cout<<"|   /|\\"<<endl;
		cout<<"|   ___\n";
		cout<<"|   - -\n";
		cout<<"|\n";
		cout<<"|\n";
		cout<<"|\n";
		cout<<"|\n";
		cout<<"|________\n";
		cout<<"|        |__\n";
		cout<<"|           |\n";
		cout<<"|___________|";
	}
	if(wrong==4){
		cout<<" ____\n";
		cout<<"|    |\n";
		cout<<"|    o\n";
		cout<<"|   /|\\"<<endl;
		cout<<"|   ___\n";
		cout<<"|\n";
		cout<<"|\n";
		cout<<"|\n";
		cout<<"|\n";
		cout<<"|________\n";
		cout<<"|        |__\n";
		cout<<"|           |\n";
		cout<<"|___________|";
	}
	if(wrong==3){
		cout<<" ____\n";
		cout<<"|    |\n";
		cout<<"|    o\n";
		cout<<"|   /|\\"<<endl;
		cout<<"|\n";
		cout<<"|\n";
		cout<<"|\n";
		cout<<"|\n";
		cout<<"|________\n";
		cout<<"|        |__\n";
		cout<<"|           |\n";
		cout<<"|___________|";
	}
	if(wrong==2){
		cout<<" ____\n";
		cout<<"|    |\n";
		cout<<"|    o\n";
		cout<<"|\n";
		cout<<"|\n";
		cout<<"|\n";
		cout<<"|\n";
		cout<<"|________\n";
		cout<<"|        |__\n";
		cout<<"|           |\n";
		cout<<"|___________|";
	}
	if(wrong==1){
		cout<<" ____\n";
		cout<<"|    |\n";
		cout<<"|\n";
		cout<<"|\n";
		cout<<"|\n";
		cout<<"|\n";
		cout<<"|________\n";
		cout<<"|        |__\n";
		cout<<"|           |\n";
		cout<<"|___________|";
	}
	cout<<endl;
	if(i==5)
	cout<<"You are hanged"<<endl;
}

	}


