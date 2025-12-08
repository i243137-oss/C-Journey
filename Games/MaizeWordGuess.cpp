#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cctype>
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

    void addWord(const char* word) {
        char** temp = new char*[wordCount + 1];
        bool* tempFound = new bool[wordCount + 1];

        for (int i = 0; i < wordCount; i++) {
            temp[i] = words[i];
            tempFound[i] = found[i];
        }

        temp[wordCount] = new char[strlen(word) + 1];
        strcpy(temp[wordCount], word);
        tempFound[wordCount] = false;

        delete[] words;
        delete[] found;

        words = temp;
        found = tempFound;
        wordCount++;
    }

    bool checkFound(int i) { return found[i]; }

    bool isInDictionary(const char* word) {
        for (int i = 0; i < wordCount; i++) {
            if (strlen(word) == strlen(words[i])) {
                bool match = true;
                for (int j = 0; j < strlen(word); j++) {
                    if (tolower(word[j]) != tolower(words[i][j])) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    found[i] = true;
                    return true;
                }
            }
        }
        return false;
    }

    bool allWordsFound() {
        for (int i = 0; i < wordCount; i++) {
            if (!found[i]) return false;
        }
        return true;
    }

    int getWordCount() { return wordCount; }

    const char* getWord(int i) {
        if (i < 0 || i >= wordCount) return nullptr;
        return words[i];
    }
};

class Maze {
public:
    char** maze;
    int rows;
    int cols;

    Maze(int r = 7, int c = 7) {
        rows = r;
        cols = c;
        maze = new char*[rows];
        for (int i = 0; i < rows; i++) {
            maze[i] = new char[cols];
        }
    }

    void genMaze() {
        srand(time(0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int letter = rand() % (122 - 97 + 1) + 97;
                maze[i][j] = (char)letter;
            }
        }
    }

   bool placeWord(const char* word) {
    if (strlen(word) > 5) return false;

    int maxAttempts = 50; // Try up to 50 times to find a valid position
    for (int attempt = 0; attempt < maxAttempts; attempt++) {
        int direction = rand() % 8;
        int row, col;
        int len = strlen(word);
        bool canPlace = true;

        // Calculate position based on direction
        if (direction == 0 && rows >= len) {
            row = rand() % (rows - len + 1);
            col = rand() % cols;
            
            // Check if we can place the word without overwriting
            for (int i = 0; i < len; i++) {
                if (maze[row + i][col] != tolower(maze[row + i][col])) {
                    canPlace = false;
                    break;
                }
            }
            
            if (canPlace) {
                for (int i = 0; i < len; i++) maze[row + i][col] = word[i];
                return true;
            }
        }
        else if (direction == 1 && rows >= len) {
            row = rand() % (rows - len + 1) + (len - 1);
            col = rand() % cols;
            
            for (int i = 0; i < len; i++) {
                if (maze[row - i][col] != tolower(maze[row - i][col])) {
                    canPlace = false;
                    break;
                }
            }
            
            if (canPlace) {
                for (int i = 0; i < len; i++) maze[row - i][col] = word[i];
                return true;
            }
        }
        else if (direction == 2 && cols >= len) {
            row = rand() % rows;
            col = rand() % (cols - len + 1);
            
            for (int i = 0; i < len; i++) {
                if (maze[row][col + i] != tolower(maze[row][col + i])) {
                    canPlace = false;
                    break;
                }
            }
            
            if (canPlace) {
                for (int i = 0; i < len; i++) maze[row][col + i] = word[i];
                return true;
            }
        }
        else if (direction == 3 && cols >= len) {
            row = rand() % rows;
            col = rand() % (cols - len + 1) + (len - 1);
            
            for (int i = 0; i < len; i++) {
                if (maze[row][col - i] != tolower(maze[row][col - i])) {
                    canPlace = false;
                    break;
                }
            }
            
            if (canPlace) {
                for (int i = 0; i < len; i++) maze[row][col - i] = word[i];
                return true;
            }
        }
        else if (direction == 4 && rows >= len && cols >= len) {
            row = rand() % (rows - len + 1);
            col = rand() % (cols - len + 1);
            
            for (int i = 0; i < len; i++) {
                if (maze[row + i][col + i] != tolower(maze[row + i][col + i])) {
                    canPlace = false;
                    break;
                }
            }
            
            if (canPlace) {
                for (int i = 0; i < len; i++) maze[row + i][col + i] = word[i];
                return true;
            }
        }
        else if (direction == 5 && rows >= len && cols >= len) {
            row = rand() % (rows - len + 1) + (len - 1);
            col = rand() % (cols - len + 1) + (len - 1);
            
            for (int i = 0; i < len; i++) {
                if (maze[row - i][col - i] != tolower(maze[row - i][col - i])) {
                    canPlace = false;
                    break;
                }
            }
            
            if (canPlace) {
                for (int i = 0; i < len; i++) maze[row - i][col - i] = word[i];
                return true;
            }
        }
        else if (direction == 6 && rows >= len && cols >= len) {
            row = rand() % (rows - len + 1);
            col = rand() % (cols - len + 1) + (len - 1);
            
            for (int i = 0; i < len; i++) {
                if (maze[row + i][col - i] != tolower(maze[row + i][col - i])) {
                    canPlace = false;
                    break;
                }
            }
            
            if (canPlace) {
                for (int i = 0; i < len; i++) maze[row + i][col - i] = word[i];
                return true;
            }
        }
        else if (direction == 7 && rows >= len && cols >= len) {
            row = rand() % (rows - len + 1) + (len - 1);
            col = rand() % (cols - len + 1);
            
            for (int i = 0; i < len; i++) {
                if (maze[row - i][col + i] != tolower(maze[row - i][col + i])) {
                    canPlace = false;
                    break;
                }
            }
            
            if (canPlace) {
                for (int i = 0; i < len; i++) maze[row - i][col + i] = word[i];
                return true;
            }
        }
    }
    
    return false; 
}

    void displayMaze() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << " " << maze[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class Game {
    Maze maze;
    Dictionary dictionary;
    int attempts;
    time_t startTime, endTime;
    bool hintUsed;
    int remainingWords;

public:
    Game() : maze(7, 7) {
        attempts = 0;
        hintUsed = false;
        remainingWords = dictionary.getWordCount();
    }

    void start() {
        cout << "Game Started!" << endl;

        maze.genMaze();

        dictionary.addWord("cat");
        dictionary.addWord("dog");
        dictionary.addWord("bat");

        cout << "You have to find " << dictionary.getWordCount() << " words " << endl;
        for (int i = 0; i < dictionary.getWordCount(); i++) {
            maze.placeWord(dictionary.getWord(i));
        }

        maze.displayMaze();
        startTime = time(0);
    }

    bool IsHeRight(const char* word, int row, int col, int direction) {
        int len = strlen(word);

        if (direction == 0 && maze.rows - row >= len) {
            for (int i = 0; i < len; i++)
                if (tolower(word[i]) != tolower(maze.maze[row + i][col])) return false;
            for (int i = 0; i < len; i++)
			 maze.maze[row + i][col] = toupper(maze.maze[row + i][col]);
            return true;
        }
        if (direction == 1 && row - len + 1 >= 0) {
            for (int i = 0; i < len; i++)
                if (tolower(word[i]) != tolower(maze.maze[row - i][col])) return false;
            for (int i = 0; i < len; i++) 
			maze.maze[row - i][col] = toupper(maze.maze[row - i][col]);
            return true;
        }
        if (direction == 2 && maze.cols - col >= len) {
            for (int i = 0; i < len; i++)
                if (tolower(word[i]) != tolower(maze.maze[row][col + i])) return false;
            for (int i = 0; i < len; i++)
			 maze.maze[row][col + i] = toupper(maze.maze[row][col + i]);
            return true;
        }
        if (direction == 3 && col - len + 1 >= 0) {
            for (int i = 0; i < len; i++)
                if (tolower(word[i]) != tolower(maze.maze[row][col - i])) return false;
            for (int i = 0; i < len; i++)
			 maze.maze[row][col - i] = toupper(maze.maze[row][col - i]);
            return true;
        }
        if (direction == 4 && maze.rows - row >= len && maze.cols - col >= len) {
            for (int i = 0; i < len; i++)
                if (tolower(word[i]) != tolower(maze.maze[row + i][col + i])) return false;
            for (int i = 0; i < len; i++) 
			maze.maze[row + i][col + i] = toupper(maze.maze[row + i][col + i]);
            return true;
        }
        if (direction == 5 && row - len + 1 >= 0 && col - len + 1 >= 0) {
            for (int i = 0; i < len; i++)
                if (tolower(word[i]) != tolower(maze.maze[row - i][col - i])) return false;
            for (int i = 0; i < len; i++)
			 maze.maze[row - i][col - i] = toupper(maze.maze[row - i][col - i]);
            return true;
        }
        if (direction == 6 && maze.rows - row >= len && col - len + 1 >= 0) {
            for (int i = 0; i < len; i++)
                if (tolower(word[i]) != tolower(maze.maze[row + i][col - i])) return false;
            for (int i = 0; i < len; i++)
			 maze.maze[row + i][col - i] = toupper(maze.maze[row + i][col - i]);
            return true;
        }
        if (direction == 7 && row - len + 1 >= 0 && maze.cols - col >= len) {
            for (int i = 0; i < len; i++)
                if (tolower(word[i]) != tolower(maze.maze[row - i][col + i])) return false;
            for (int i = 0; i < len; i++) maze.maze[row - i][col + i] = toupper(maze.maze[row - i][col + i]);
            return true;
        }

        return false;
    }

    void playTurn(const char* word, int row, int col, int direction) {
    attempts++;
    cout << "Attempt " << attempts << ": " << word << endl;
    
    bool inDictionary = dictionary.isInDictionary(word);
    bool inCorrectPosition = IsHeRight(word, row, col, direction);
    
    if (inDictionary && inCorrectPosition) {
        cout << " Word found in maze and capitalized" << endl;
        remainingWords--;
        cout << remainingWords << " words are left" << endl;
    } 
    else if (inDictionary) {
        cout << "Word exists in dictionary but not at given position" << endl;
    } 
    else {
        cout << "Not in dictionary" << endl;
    }
    maze.displayMaze();
}

    void getHint() {
        if (hintUsed) {
            cout << "No more Hint" << endl;
            return;
        }

        if (!hintUsed) {
            string hintWord;
            int i = 0;
            while (dictionary.checkFound(i)) {
                i++;
            }
            hintWord = dictionary.getWord(i);
            cout << "Hint: Try finding word \""<< hintWord << "\"" << endl;
            hintUsed = true;
        } else {
            cout << "All words already found!" << endl;
        }
    }

    bool checkGameEnd() {
	 return dictionary.allWordsFound();
	  }

    void showFinalResult() {
        endTime = time(0);
        cout << endl << "===== GAME RESULT =====" << endl;
        maze.displayMaze();
        cout << "Attempts: " << attempts << endl;
        cout << "Time taken: " << difftime(endTime, startTime) << " seconds" << endl;
        cout << "Hint used: " << (hintUsed ? "Yes" : "No") << endl;
        if (checkGameEnd()) {
            cout << "Congratulations! You Win!" << endl;
        } else {
            cout << "Game Over." << endl;
        }
    }
};

int main() {
    Game game;
    game.start();

    while (true) {
        cout << endl << "===== MENU =====" << endl;
        cout << "1. Play Turn" << endl;
        cout << "2. Get Hint" << endl;
        cout << "3. Quit" << endl;
        cout << "Choose option: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            string word;
            int row, col, dir;
            cout << "Enter guessed word: ";
            cin >> word;
cout << "===========Position==========" << endl;
            cout << "Enter row (1-7): ";
            cin >> row;
            while (row < 1 || row > 7) {
                cout << "Invalid row! Enter again: ";
                cin >> row;
            }

            cout << "Enter column (1-7): ";
            cin >> col;
            while (col < 1 || col > 7) {
                cout << "Invalid col! Enter again: ";
                cin >> col;
            }
            cout << "======Dirrection=============" << endl;
            cout << "Select direction:" << endl;
            cout << "1 = Top to Bottom" << endl;
            cout << "2 = Bottom to Top" << endl;
            cout << "3 = Left to Right" << endl;
            cout << "4 = Right to Left" << endl;
            cout << "5 = Top-Left to Bottom-Right" << endl;
            cout << "6 = Bottom-Right to Top-Left" << endl;
            cout << "7 = Top-Right to Bottom-Left" << endl;
            cout << "8 = Bottom-Left to Top-Right" << endl;
            
            cin >> dir;
            cout<<"=============================="<<endl;
            while (dir < 1 || dir > 8) {
                cout << "Invalid! Enter direction (1-8): ";
                cin >> dir;
            }

            game.playTurn(word.c_str(), row - 1, col - 1, dir - 1);
            if (game.checkGameEnd()) {
                game.showFinalResult();
                break;
            }
        } else if (choice == 2) {
            game.getHint();
        } else if (choice == 3) {
            cout << "Thank You" << endl;
            game.showFinalResult();
            break;
        } else {
            cout << "Invalid option" << endl;
        }
    }

    return 0;
}