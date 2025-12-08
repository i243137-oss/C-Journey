#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
class Dictionary {
    char** words;
    int wordCount;
    bool* found;

public:
    Dictionary() {
        wordCount = 0;
        words = nullptr;
        found = nullptr;
    }

    void addWord(char* word) {
        char** temp = new char*[wordCount + 1];
        bool* tempFound = new bool[wordCount + 1];

        // old values copy karo
        for (int i = 0; i < wordCount; i++) {
            temp[i] = words[i];
            tempFound[i] = found[i];
        }

        // new word add karo
        temp[wordCount] = new char[strlen(word) + 1];
        strcpy(temp[wordCount], word);
        tempFound[wordCount] = false;

        // purane arrays delete
        delete[] words;
        delete[] found;

        // update pointers
        words = temp;
        found = tempFound;

        // increase count
        wordCount++;
    }
    bool isInDictionary(const char* word) {
    for (int i = 0; i < wordCount; i++) {
        if (strlen(word) == strlen(words[i])) {
            bool match = true;
            for (int j = 0; j < strlen(word); j++) {
                if (word[j] != words[i][j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                return true;  // word mil gaya
            }
        }
    }
    return false; // agar koi match nahi mila
}

    
};

class Maze{
	char** maze;
	int rows;
	int cols;
	public:
		Maze(){
			rows=7;
			cols=7;
			maze=new char* [rows];
			for(int i=0; i<rows;i++){
				maze[i]=new char [cols];
			}
		}
		Maze(int r,int c){
			rows=r;
			cols=c;
			
		}
	void	genMaze(){
		
			int letter=rand()%(122-97+1)+97;
			srand(time(0));
			for(int i=0; i<rows;i++){
				for(int j=0; j<cols; j++){
					int letter=rand()%(122-97+1)+97;
					maze[i][j]=(char)letter;
				}
			}
		}
		void displayMaze(){
				for(int i=0; i<rows;i++){
				for(int j=0; j<cols; j++){
					if(j==0) cout<<" ";
				cout<<" "<<maze[i][j]<<" ";
				}
				cout<<endl;
			}
		}
			
		
};
int main(){
	Maze maze;
	maze.genMaze();
	maze.displayMaze();
return 0;
}
