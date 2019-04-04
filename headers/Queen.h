#ifndef _QUEEN_H_
#define _QUEEN_H_
#include <iostream>

using namespace std;

class Queen {
    private:
        char board[8][8];
    public:
        Queen() {
            for(int x=0; x<8; x++) {
                for(int y=0; y<8; y++) {
                    board[x][y] = '0';
                }
            }
        }

        //x == number of queens
        //I am basically done, but there is one bug where the program deosn't exit out of the recursion.  I'mm kinda stuck.
        bool queenPlace(int x, int y) {
            //cout << x << " " << y << endl;
            if(x == 8) {
                cout << "hello" << endl;
                return true;
            }
            if(!isQueenValid(x,y)) {
                cout << "Queen is not valid" << endl;
                return false;
            } else {
                board[x][y] = 'Q';
                cout << "is it" << endl;
                printBoard();
            }
            cout << "me" << endl;
            int r=0;
            while(r!=8) {
                if(!queenPlace(x+1, r))
                    r++;
            }
            cout << "looking for?" << endl;
            if(r>7) {
                replaceCol(x);
                return false;
            }

        }

        void printBoard() {
            for(int x=0; x<8; x++) {
                for(int y=0; y<8; y++) {
                    cout << board[x][y] << " ";
                }
                cout << endl;
            }
        }

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
        
        //each time the queen thing gets popped off, this deletes the row with zero.  Thus resetting the board
        void replaceCol(int x) {
            for(int y = 0; y<8; y++) {
                board[x][y] = '0';
            }
        }
};

#endif