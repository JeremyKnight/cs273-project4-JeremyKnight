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
            while(file >> c) {
                
            }
        }
};

#endif