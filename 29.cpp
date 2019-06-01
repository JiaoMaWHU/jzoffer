#include <iostream>
#include <vector>
using namespace std;

vector<int> printMatrix(vector<vector<int> > matrix) {
    unsigned long row = matrix.size();
    unsigned long col = matrix[0].size();
    vector<int> ret;
    vector<vector<bool> > stat(row, vector<bool>(col, 0));
    int tr = 0, tc = -1, state = 0;
    while (true) {
        switch (state) {
            case 0: {
                if (stat[tr][++tc] != 0) return ret;
                ret.push_back(matrix[tr][tc]);
                stat[tr][tc] = 1;
                if (tc == col-1 || stat[tr][tc + 1] != 0) {
                    state = (state + 1) % 4;
                    if(row==1) return ret;
                }
            } break;
            case 1: {
                if (stat[++tr][tc] != 0) return ret;
                ret.push_back(matrix[tr][tc]);
                stat[tr][tc] = 1;
                if (tr == row-1 || stat[tr + 1][tc] != 0) {
                    state = (state + 1) % 4;
                    if(col==1) return ret;
                }
            } break;
            case 2: {
                if (stat[tr][--tc] != 0) return ret;
                ret.push_back(matrix[tr][tc]);
                stat[tr][tc] = 1;
                if (tc == 0 || stat[tr][tc - 1] != 0) state = (state + 1) % 4;
            } break;
            case 3: {
                if (stat[--tr][tc] != 0) return ret;
                ret.push_back(matrix[tr][tc]);
                stat[tr][tc] = 1;
                if (stat[tr - 1][tc] != 0) state = (state + 1) % 4;
            } break;
        }
    }
}