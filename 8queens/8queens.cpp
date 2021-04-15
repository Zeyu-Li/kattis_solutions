#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

vector<pair<int, int>> queens;

bool contains(int x, int y) {
    // count how many queens in dia diagonal
    int count = 0;
    for (auto coord_check: queens) {
        if (coord_check.first == x && coord_check.second == y) return true;
    }
    return false;
}

int main() {
    char tmp;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> tmp;
            if (tmp == '*') {
                queens.push_back(make_pair(i,j));
            }
        }
    }
    if (queens.size() != 8) {
        cout << "invalid" << "\n";
        return 0;
    }
    // horizontal and vertical
    for (auto coord: queens) {
        int counter_y = 0;
        int counter_x = 0;
        for (auto coord_check: queens) {
            if (coord.first == coord_check.first) counter_y++;
            if (coord.second == coord_check.second) counter_x++;
        }

        // if same column or row, it is invalid
        if (counter_x != 1 || counter_y != 1) {
            cout << "invalid" << "\n";
            return 0;
        }
    }
    // check diagonal ( should be only 1 queen on each diagonal)
    int x,y, counter;
    // not sure if this is efficient since we split the two halves but it works
    for (int i = 0; i < 8; i++) {
        // modified from https://github.com/JonSteinn/Kattis-Solutions/blob/master/src/Eight%20Queens/C/8queens.c
        x=counter=0;
        y = i;
        // down and to the right
        while (x < 8 && y < 8) {
            if (contains(x, y)) counter++;
            x++; 
            y++;
        }
        if (counter > 1) {
            cout << "invalid" << "\n";
            return 0;
        }
        counter = x = 0; 
        y = i;
        while (x < 8 && y >= 0) {
            if (contains(x, y)) counter++;
            x++; 
            y--;
        }
        
        if (counter > 1) {
            cout << "invalid" << "\n";
            return 0;
        }
        counter = 0; 
        x = 7; 
        y = i;
        while (x >= 0 && y >= 0) {
            if (contains(x, y)) counter++;
            x--; 
            y--;
        }
        
        if (counter > 1) {
            cout << "invalid" << "\n";
            return 0;
        }
        counter = 0; 
        x = 7; 
        y = i;
        while (x >= 0 && y < 8) {
            if (contains(x, y)) counter++;
            x--; 
            y++;
        }
        
        if (counter > 1) {
            cout << "invalid" << "\n";
            return 0;
        }
    }
    cout << "valid" << "\n";
    return 0;
}
