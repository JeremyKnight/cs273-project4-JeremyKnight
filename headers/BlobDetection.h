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
        }

        void printArray() {
            
            for(int x = 0; x<arr.size(); x++) {
                for(int y = 0; y<arr[x].size(); y++) {
                    cout << arr[x][y];
                }
                cout << endl;
            }
            
        }

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

        bool checkBlob(int x, int y, int num) {
            if(x > arr.size() || x < 0 || y>arr[x].size() || y<0) { return false; }
            if(arr[x][y] == 1) {
                arr[x][y] = num;
                //for()
            } 

            if(arr[x]][y] == num) {
                //return true;
            } 

            return false;
            
        }


};

#endif