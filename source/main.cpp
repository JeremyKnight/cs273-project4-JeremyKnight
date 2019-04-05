#include <iostream>
#include <fstream>
#include <string>
#include "Queen.h"
#include "BlobDetection.h"
using namespace std;

int main() {
    
    cout << "Queen problem:" << endl;
    Queen q= Queen();
    if(q.queenPlace(0,0)) {
        q.printBoard();
    }
    
    
    cout << endl;

    cout << "blob detection problem:" << endl;
    //string file name:
    string fileName = "C:/Users/jknight22/desktop/cs273-project4-JeremyKnight/blob_test.txt";
    BlobDetection blob = BlobDetection(fileName);
    blob.findBlobs();
    blob.printArray();
    
    return 1;
}