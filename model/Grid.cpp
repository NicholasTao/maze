//
// Created by t30002884 on 2021/11/10.
//

#include "Grid.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


void Grid::show() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << locs[i][j];
        }
        cout << endl;
    }
}

Grid::Grid(const string &fileName) {
    ifstream myfile(fileName);
    string tmp;
    for (int i = 0; i < h; i++) {
        getline(myfile, tmp);
        //        myfile >> tmp;
        for (int j = 0; j < w; j++) {
            locs[i][j] = tmp[j] - '0';
        }
    }
}

int **Grid::calAdjMtx(int h, int w, int loc[][WIDTH]) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << loc[i][j];
        }
        cout << endl;
    }
    return nullptr;
}

