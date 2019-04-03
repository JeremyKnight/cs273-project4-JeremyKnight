#ifndef _QUEEN_H_
#define _QUEEN_H_

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
        bool queenPlace(int x, int y) {
            if(x == 9) {
                return true;
            }
            if(!isQueenValid(x,y)) {
                return false
            }


            
            /*
            if(board[x][y] == '0'){
                //loop through and mark where the queen covers with 1
                board[x][y] = 'Q';
                return true
            } else {//if(board[x][y]!=) 
                if(x==8) {
                    return queenPlace(0,y+1);
                } else {
                    return queenPlace(x+1,y);
                }
            }
            */

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
            int tempx = x;
            int tempy = y;
            for(int i = 0; i<8; i++) {
                if(board[x][i] == 'Q' || board[i][y] == 'Q') {
                    return false
                } 
                if(x==0) {
                      
                }
            }
        }
};

#endif