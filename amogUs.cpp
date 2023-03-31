#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include linearlist-implementation.h
#include linearlist.h
#include queue.h

using namespace std;

// Function: readData
// Purpose: reads in the data from the file and stores it in a vector
// Input: the file name and the vector

void readData(string fileName, 

// Function: printData
// Purpose: prints the data from the vector
// Input: the vector

void printData(vector<string> data) {
    for (int i = 0; i < data.size(); i++) {
        cout << data[i] << endl;
    }
}

// Function: findPath
// Purpose: finds the path from the start to the end


