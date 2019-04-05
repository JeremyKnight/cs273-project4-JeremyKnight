#ifndef _BLOBDETECTION_H_
#define _BLOBDETECTION_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class BlobDetection {
    private:
        string fileName;
        vector<vector<int>> arr; 
    public:
        //constructor for blobDetection, initializes arr
        //input: the file name for the file to look for blobs
        BlobDetection(string fn) {
            fileName = fn;
            ifstream file = ifstream(fn);
            string line;
            while(file >> line) {
                vector<int> temp;
                for(int i = 0; i < line.length(); i++) {
                    temp.push_back(line.at(i) - '0');
                }
                arr.push_back(temp);
            }
            file.close();
        }

        //prints the array
        void printArray() {
            for(int x = 0; x<arr.size(); x++) {
                for(int y = 0; y<arr[x].size(); y++) {
                    cout << arr[x][y] << " ";
                }
                cout << endl;
            }
            
        }

        //loops through the array looking for blobs, and when found appericiates the unique number
        void findBlobs() {
            int num = 2;
            for(int x = 0; x<arr.size(); x++) {
                for(int y = 0; y<arr[x].size(); y++) {
                    if(checkBlob(x,y,num)) {
                        num++;
                    }
                    
                }
            } 
        }

        //checks if there is a blob starting at x,y
        //input: int x, y: used to check if the blob is at place | num is the unique number for a certian blob
        //output: boolean of if there was a blob found 
        bool checkBlob(int x, int y, int num) {
            if(x >= arr.size() || x < 0 || y>=arr[0].size() || y<0) { return false; }
            
            if(arr[x][y] == 0) { return false;}
            if(arr[x][y] == 1) {
                arr[x][y] = num;
                
                checkBlob(x+1,y,num);
                checkBlob(x+1,y+1, num);
                checkBlob(x,y+1,num);
                checkBlob(x-1,y+1, num);
                checkBlob(x-1,y,num);
                checkBlob(x-1,y-1, num);
                checkBlob(x, y-1, num);
                checkBlob(x+1, y-1, num);
                checkBlob(x+1, y-1, num);
                                             
                return true;
            }
            return false;
        }
};

#endif