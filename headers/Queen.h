#ifndef _QUEEN_H_
#define _QUEEN_H_
#include <iostream>

using namespace std;

class Queen {
    private:

        char board[8][8];
    public:
        //Constructor that takes no arguements
        //basically sets the board up for the queens
        Queen() {
            for(int x=0; x<8; x++) {
                for(int y=0; y<8; y++) {
                    board[x][y] = '0';
                }
            }
        }

        //This is the recursion that places the queens where they need to be.
        //input: possible queen placement in terms of x and y
        //output: boolean of if a queen can be placed there
        bool queenPlace(int x, int y) {
            //base case to check if there are 8 queens in a differnent column.
            if(x == 8) {
                return true;
            }
            //checks whether a queen can be placed there. 
            //if not, then pop off stack, but if so then place a queen at spot x and y
            if(!isQueenValid(x,y)) {
                return false;
            } else {
                board[x][y] = 'Q';
            }
            //iterates through possible queen places until it finds one or returns false
            int r=0;
            while(r<=7) {
                if(!queenPlace(x+1, r))
                    r++;
                else 
                    return true;
            }
            //if the loop above has run through the entire column, then delete the current column
            if(r>=8) {
                replaceCol(x);
                return false;
            }

        }

        //prints the board
        void printBoard() {
            for(int x=0; x<8; x++) {
                for(int y=0; y<8; y++) {
                    cout << board[x][y] << " ";
                }
                cout << endl;
            }
        }

        //checks if a queen can be placed there
        //input: possible queen placement at board position x and y
        //output: true if can can be placed there, false if not
        bool isQueenValid(int x, int y) {
            for(int i = 0; i<8; i++) {
                if(board[x][i] == 'Q' || board[i][y] == 'Q') {
                    return false;
                }
                if(x-i!=x && y-i!=y) {
                    if(x-i>-1 && y-i>-1 && board[x-i][y-i] == 'Q') { return false; }
                    if(x+i<8 && y-i>-1 && board[x+i][y-i] == 'Q') { return false; }
                    if(x-i>-1 && y+i<8 && board[x-i][y+i] == 'Q') { return false; }
                    if(x+i<8 && y+i<8 && board[x+i][y+i] == 'Q') { return false; }
                }
            }
            return true;

            
            
        }
        
        //deletes the col at x
        //input: where to delete the col
        void replaceCol(int x) {
            for(int y = 0; y<8; y++) {
                board[x][y] = '0';
            }
        }
};

#endif