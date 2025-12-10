#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include<fstream>
using namespace std;
void UpdateDiscardPile(int discardPile[],int player[],int &card,int &card4);
void setColor(int textColor, int bgColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}

// Initialize the player's cards
void initializePlayer(int player[]) {
    for (int i = 0; i < 108; i++) {
        player[i] = 0;
    }
}
void initializeDeck (int deck[][15]){
	 for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            if (j == 0) {
                deck[i][j] = 1;
            } else if (j >= 1 && j <= 9) {
                deck[i][j] = 2;
            } else if (j == 10) {
                deck[i][j] = 2;
            } else if (j == 11) {
                deck[i][j] = 2;
            } else if (j == 12) {
                deck[i][j] = 2;
            }
        }
    }
}
int flattenDeck(int deck[4][15], int flatDeck[]) {
    int index = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 15; j++) {
            for (int k = 0; k < deck[i][j]; k++) {
                flatDeck[index++] = i * 100 + j;
            }
        }
    }
    return index;
}

void shuffleDeck(int flatDeck[]) {
    srand(time(0));
    for (int i = 108 - 1; i > 0; i--) {
        int randomIndex = rand() % (i + 1);
        swap(flatDeck[i], flatDeck[randomIndex]);
    }
}
void dealCards(int player1[], int player2[], int shuffle[],int discardPile[], int &card1, int &card2, int &card3){

 if (card1 == -1 && card2 == -1) {
        card1 = 0;
        card2 = 0;
        card3 = 93;

        for (int i = 0; i < 14; i++) {
            if (i % 2 == 0) {
                player1[card1++] = shuffle[i];
            } else {
                player2[card2++] = shuffle[i];
            }
        }

        // Shift remaining cards in shuffle array
        
        for (int i = 0; i < card3; i++) {
            if (i + 14 < 108) {
                shuffle[i] = shuffle[i + 14];
            } else {
                shuffle[i] = 0;
            }
        }
        discardPile[0] = shuffle[0];
for (int j = 1; j <= card3; j++) {
    shuffle[j - 1] = shuffle[j];
}
card3--; // Shuffle pile ki size reduce karo

}}
//
void cards(int player1[], int player2[], int arr[], int &card1, int &card2) {
int maxCard = 7; 
    int rows = (card1 + maxCard - 1) / maxCard; // Calculate how many rows are needed

    
    
    for (int r = 0; r < rows; r++) { 
        for (int i = 0; i < 10; i++) {
            for (int j = r * maxCard; j < (r + 1) * maxCard && j < card1; j++) {
           
    	int check=player1[j] / 100;
        if (check == 0 )
            setColor(1, 4);
        else if (check == 1)
            setColor(1, 2);
        else if (check == 2)
            setColor(7, 1);
        else if (check == 3)
            setColor(1, 6);
              else 
            setColor(0, 7);

            for (int k = 0; k < 15; k++) {
                if (i == 0 || k == 0 || i == 9 || k == 14)
                    cout << "*";
               else if (i == 5 && k == 7){
            		int check1=player1[j]%100;
            	  if(check1<=9){	
                	cout<<check1%10;
				}
				else
				{
					if(check1==10 )
					cout<<"R";
					else if(check1==11)
					cout<<"S";
					else if (check1==12)
					cout<<"D";
					else if(check1==13)
						cout<<"W";
					else 
						cout<<"P";
					
				}
			
                
            }
                    
                else
                    cout << " ";
            }
            setColor(0, 0);
            cout << "\t";
            
           
    
		}
		cout<<endl;
	}
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < 10; i++) {
    	for(int j=0; j<1; j++){
		
    	int check=arr[0] / 100;
        if (check == 0 )
            setColor(1, 4);
        else if (check == 1)
            setColor(1, 2);
        else if (check == 2)
            setColor(7, 1);
        else if (check == 3)
            setColor(1, 6);
              else 
            setColor(0, 7);

        for (int k = 0; k < 15; k++) {
            if (i == 0 || k == 0 || i == 9 || k == 14)
                cout << "*";
            else if (i == 5 && k == 7){
            		int check1=arr[0]%100;
            	  if(arr[0]%100<=9){
				  
				  
                
                	
                	cout<<check1%10;
				}
				else
				{
						if(check1==10 )
					cout<<"R";
					else if(check1==11)
					cout<<"S";
					else if (check1==12)
					cout<<"D";
					else if(check1==13)
						cout<<"W";
					else 
						cout<<"P";
					
				}
			
                
            }
            else
                cout << " ";
        }
         setColor(0, 0);
            cout << "\t";
		}
        cout << endl;
    }

    cout << endl;
    
    rows = (card2 + maxCard - 1) / maxCard; 

    
    
    for (int r = 0; r < rows; r++) { 
        for (int i = 0; i < 10; i++) {
            for (int j = r * maxCard; j < (r + 1) * maxCard && j < card2; j++) {
          	int check=player2[j] / 100;
        if (check == 0 )
            setColor(1, 4);
        else if (check == 1)
            setColor(1, 2);
        else if (check == 2)
            setColor(7, 1);
        else if (check == 3)
            setColor(1, 6);
              else 
            setColor(0, 7);
            for (int k = 0; k < 15; k++) {
                if (i == 0 || k == 0 || i == 9 || k == 14)
                    cout << "*";
               else if (i == 5 && k == 7){
            		int check1=player2[j]%100;
            	  if(player2[j]%100<=9){
				  
				  
                
                	
                	cout<<check1%10;
				}
				else
				{
						if(check1==10 )
					cout<<"R";
					else if(check1==11)
					cout<<"S";
					else if (check1==12)
					cout<<"D";
					else if(check1==13)
						cout<<"W";
					else 
						cout<<"P";
					
				}
			
                
            }
                else
                    cout << " ";
            }
            setColor(0, 0);
            cout << "\t";
        }
        cout << endl;
    }

    cout << endl;
    setColor(7, 0);
}}
void handleSpecialCard(int specialCardType, int discardPile[], int player1[], int player2[], int shuffle[], bool &dirrection, int &card, int &card1, int &card2, int &card3) {
    switch (specialCardType) {
        case 10: // Skip
            cout << "Next Player Turn is skipped" << endl;
            break;
        case 11: // Reverse
            cout << "Turn is reversed" << endl;
            dirrection = !dirrection;
            break;
        case 12: // Draw 2
            cout << "Next player draws 2 cards!" << endl;
            for (int i = 0; i < 2; i++) {
                if (card3 > 0) {
                    player2[card2++] = shuffle[0];
                    for (int j = 0; j < card3 - 1; j++) {
                        shuffle[j] = shuffle[j + 1];
                    }
                    card3--;
                }
            }
            break;
        case 13: // Wild
            cout << "Enter Color You Want (1-4):" << endl;
            cout << "1. Red\n2. Green\n3. Blue\n4. Yellow" << endl;
            int color;
            cin >> color;
            if (color >= 1 && color <= 4) {
                discardPile[0] = (color - 1) * 100 + specialCardType;
            } else {
                cout << "Invalid color choice. Defaulting to Red." << endl;
                discardPile[0] = 0 * 100 + specialCardType;
            }
            break;
        case 14: // Wild Draw 4
            cout << "Next player draws 4 cards!" << endl;
            for (int i = 0; i < 4; i++) {
                if (card3 > 0) {
                    player2[card2++] = shuffle[0];
                    for (int j = 0; j < card3 - 1; j++) {
                        shuffle[j] = shuffle[j + 1];
                    }
                    card3--;
                }
            }

            cout << "Enter Color You Want (1-4):" << endl;
            cout << "1. Red\n2. Green\n3. Blue\n4. Yellow" << endl;
            cin >> color;
            if (color >= 1 && color <= 4) {
                discardPile[0] = (color - 1) * 100 + specialCardType;
            } else {
                cout << "Invalid color choice. Defaulting to Red." << endl;
                discardPile[0] = 0 * 100 + specialCardType;
            }
            break;
        default:
            cout << "Invalid special card!" << endl;
            break;
    }
}
bool callUno(int & card1,int & card3, int  shuffle[],int player1[] ){
	char ch;
	if  (  card1==2 ){
		cin>>ch;
		if(ch=='U' || ch=='u') {
			cout<<"You say Uno"<<endl;
			return true;
		}
		else {
			 for (int i = 0; i < 2; i++) {
                if (card3 > 0) {
                    player1[card1++] = shuffle[0];
                    for (int j = 0; j < card3 - 1; j++) {
                        shuffle[j] = shuffle[j + 1];
                        
                    }
                    card3--;
                    cout<<"Two cards penalty for Not saying UNO"<<endl;
                    return false;
                }
            }
			
		}
	}
}
void UpdateDiscardPile(int discardPile[],int shuffle[] ,int player1[],int &card,int & card3,int &card4){
if(card3>0){

	for (int i = card4; i > 0; i--) {
            discardPile[i] = discardPile[i - 1];
        }
        discardPile[0] = player1[card];
        card4++;
}
else {
	cout<<"Deck has been Empty"<<endl;
	
	for(int i=1; i<card4; i++){
		shuffle[i-1]=discardPile[i];
	}
	card3=107;
	card4=1;
	cout<<" Now it is shuffling "<<endl;
	shuffleDeck(shuffle);
}
}
bool isValidPlay(int playerCard, int topCard){
 	if (playerCard / 100 ==  topCard / 100 || 
       playerCard % 100 ==  topCard % 100 || 
      playerCard / 100 == 4){
      	return true;
	  }
	  return false;
	  }
void PlayTurn(int discardPile[], int shuffle[], int player1[], int player2[], int card, int &card1, int &card2, int &card3, int &card4,bool & dirrection) {
     
int playerCard=player1[card]; int topCard=discardPile[0];
    if (isValidPlay( playerCard, topCard)) {
        
		if(player1[card]%100<=9){
	  	UpdateDiscardPile(discardPile, shuffle ,player1, card, card3,card4);
        // Remove card from player1's hand
        for (int i = card; i < card1 - 1; i++) {
            player1[i] = player1[i + 1];
        }
        player1[card1 - 1] = 0;
        card1--;
        dirrection=!dirrection;

        cout << " Card successfully played.  " << endl;
   } else {
   	int specialCardType=player1[card]%100;
   	
   	UpdateDiscardPile(discardPile, shuffle ,player1, card, card3,card4);

        // Remove card from player1's hand
        for (int i = card; i < card1 - 1; i++) {
            player1[i] = player1[i + 1];
        }
        player1[card1 - 1] = 0;
        card1--;
   handleSpecialCard(specialCardType, discardPile, player1,player2 ,shuffle, dirrection, card,card1, card2, card3);
   	
   }
   
    } else {
        cout << " Invalid move. Card does not match the discard pile!" << endl;
    }

}
void saveGame(int shuffle[], int discardPile[], int player1[], int player2[], int card1, int card2, int card3, int card4, bool direction) {
    ofstream outfile("myResumeGame.txt");  // Open file in write mode

    if (outfile.is_open()) {
        // Save the card counts
        outfile << card1 << " " << card2 << " " << card3 << " " << card4 << endl;

        // Save player 1's cards
        for (int i = 0; i < card1; i++) {
            outfile << player1[i] << " ";
        }
        outfile << endl;

        // Save player 2's cards
        for (int i = 0; i < card2; i++) {
            outfile << player2[i] << " ";
        }
        outfile << endl;

        // Save the direction of play
        outfile << direction << endl;

        // Save the shuffle array
        for (int i = 0; i < 108; i++) {
            outfile << shuffle[i] << " ";
        }
        outfile << endl;

        // Save the discard pile array
        for (int i = 0; i < 108; i++) {
            outfile << discardPile[i] << " ";
        }
        outfile << endl;

        // Close the file after saving
        outfile.close();
        cout << "Game saved successfully!" << endl;
    } else {
        cout << "Unable to open file!" << endl;
    }
}

void loadGame(int &card1, int &card2, int &card3, int &card4, bool &direction,
              int player1[], int player2[], int shuffle[], int discardPile[]) {
    ifstream infile("myResumeGame.txt");  // Open file for reading

    if (infile.is_open()) {
        // Read the card counts
        infile >> card1 >> card2 >> card3 >> card4;

        // Read Player 1's cards
        for (int i = 0; i < card1; i++) {
            infile >> player1[i];
        }

        // Read Player 2's cards
        for (int i = 0; i < card2; i++) {
            infile >> player2[i];
        }

        // Read direction of play
        infile >> direction;

        // Read shuffle array
        for (int i = 0; i < 108; i++) {
            infile >> shuffle[i];
        }

        // Read discard pile array
        for (int i = 0; i < 108; i++) {
            infile >> discardPile[i];
        }

        // Close the file after loading
        infile.close();
        cout << "Game loaded successfully!" << endl;
    } else {
        cout << "Unable to open file!" << endl;
    }
}

int main() {
    int deck[4][15] = {0},shuffle[108],player1[108],player2[108],card1=-1,card2=-1;
    int card4=1;;
     initializeDeck ( deck);
     initializePlayer( player1) ;
      initializePlayer( player2) ;
    int wildDeck[4] = {4, 4, 4, 4};
  int discardPile[108];
    int card3 = flattenDeck(deck, shuffle);
    for (int i = 0; i < wildDeck[0]; i++) {
        shuffle[card3++] = 4 * 100 + 13;
    }
    for (int i = 0; i < wildDeck[1]; i++) {
        shuffle[card3++] = 4 * 100 + 14;
    }
    shuffleDeck(shuffle);
  //  for (int i=0; i<108; i++){
//	cout<<shuffle[i]<<"  ";

 bool dirrection = true;
 int option;
cout<<"Enter (1-3)"<<endl;
cout<<"1.Resume Game"<<endl;
cout<<"2.New Gmae"<<endl;
do{
	cin>>option;
	if(option<1 || option>3)
	cout<<"Enter valid Input"<<endl;
}while(option<1 || option>3);

	dealCards(player1, player2,  shuffle,discardPile ,card1, card2, card3);
	system("cls");
	if (option==1)
	 loadGame(card1, card2, card3, card4, dirrection,
               player1,  player2,  shuffle,  discardPile);
	cards(player1,player2,discardPile,card1,card2);



    int choice;
    dirrection = true;
   
 


cout << endl;

    while (true) {
    	 if (choice==3){
        	break;
		}
    	if (card1==0){
    		cout<<"Player1 Wins the Match"<<endl;
    		break;
		}
		if(card2==0){
			cout<<"Player 2 wins the match"<<endl;
			
		}
    	if(dirrection) {
		
    	
        cout << "Player 1 Turn" << endl;
        cout<<"Please Select Option (1-3)"<<endl;
        cout << "1. Throw a card" << endl;
        cout << "2. Draw Card" << endl;
        cout<<  "3. Save and Exit Game"<<endl;
        if (choice==3){
        	break;
		}
		
        cin >> choice;

        switch (choice) {
            case 1: 
                int card;
                cout<<discardPile[0]<<endl;
                cout << "Please Select Card (1 to " << card1 << "): ";
                cin >> card;
                  
                if (card > 0 && card <= card1) { // Validate the selected card
                    card--; // Adjust for 0-based indexing
                  
				if(card1==2){
					callUno(card1,card3, shuffle, player1 );
					
				}
                        PlayTurn( discardPile,shuffle,player1,player2,card,card1,card2,card3,card4,dirrection);
                        
                
                        cards(player1, player2, discardPile, card1, card2); // Refresh display
                         
				
                    }
					
                    
                else {
                    cout << "Invalid selection! Try again." << endl;
                }
                break;
                case 2 : 
                 if (card3 > 0) {
                        player1[card1++] = shuffle[0];
                        for (int j = 0; j < card3 - 1; j++) {
                            shuffle[j] = shuffle[j + 1];
                        }
                        card3--;
                    }else {
                    		UpdateDiscardPile(discardPile, shuffle ,player1, card, card3,card4);
                    		 player2[card2++] = shuffle[0];
                        for (int j = 0; j < card3 - 1; j++) {
                            shuffle[j] = shuffle[j + 1];
                        }
                        card3--;
					}
                      cards(player1, player2, discardPile, card1, card2); 
                        
                break;
                case 3:
                		 saveGame( shuffle,  discardPile, player1,  player2,  card1, card2,  card3,  card4,  dirrection);
                	break;
                	default :
                		cout<<"Enter Valid Option"<<endl;
                		break;
	
}}
else {
		
        cout << "Player 2 Turn" << endl;
        cout << "1. Throw a card" << endl;
        cout << "2. Draw Card" << endl;
        cout<<  "Save and Exit Game"<<endl;
        if (choice==3){
        	break;
		}
        cin >> choice;

        switch (choice) {
            case 1: 
                int card;
                cout << "Please Select Card (1 to " << card2 << "): ";
                cin >> card;
                if (card > 0 && card <= card1) { // Validate the selected card
                    card--; // Adjust for 0-based indexing
                    
					if(card2==2){
					callUno(card2,card3, shuffle, player2 );
                        PlayTurn( discardPile,shuffle,player2,player1,card,card2,card1,card3,card4,dirrection);
                        
                
                        cards(player1, player2, discardPile, card1, card2); // Refresh display
                         
					
                     
                    }
					
                    
                else {
                    cout << "Invalid selection! Try again." << endl;
                }
                break;
                case 2 : 
                 if (card3 > 0) {
                        player2[card2++] = shuffle[0];
                        for (int j = 0; j < card3 - 1; j++) {
                            shuffle[j] = shuffle[j + 1];
                        }
                        card3--;
                    }
                    else {
                    		UpdateDiscardPile(discardPile, shuffle ,player1, card, card3,card4);
                    		 player2[card2++] = shuffle[0];
                        for (int j = 0; j < card3 - 1; j++) {
                            shuffle[j] = shuffle[j + 1];
                        }
                        card3--;
                    	
					}
                
                      cards(player1, player2, discardPile, card1, card2); 
                     
                break;
                case 3:
                		 saveGame( shuffle,  discardPile, player1,  player2,  card1, card2,  card3,  card4,  dirrection);
                	break;
                default :
                	break;
}}
}}}
