#include <iostream>
#include <fstream>
#include <string>
#include "Queen.h"
#include "BlobDetection.h"
using namespace std;

int main() {
    
    Queen q= Queen();
    if(q.queenPlace(0,0)) {
        cout << "this worked" << endl;
    }
    q.printBoard();
    
    /*
    //string file name:
    string fileName = "C:/Users/jknight22/desktop/cs273-project4-JeremyKnight/blob_test.txt";
    BlobDetection blob = BlobDetection(fileName);
    blob.printArray();
    */
    return 1;
}