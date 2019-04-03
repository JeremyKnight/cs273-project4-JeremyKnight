#include <iostream>
#include <fstream>
#include "Queen.h"
using namespace std;

int main() {
    Queen q= Queen();
    q.printBoard();
    //while(q.queenPlace(0,0))
    if(q.queenPlace(0,0)) {
        cout << "this worked" << endl;
    }
    q.printBoard();

    return 1;
}