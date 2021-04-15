#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

vector<pair<int, int>> queens;

int check_dia1(int dia) {
    // for every queen we check to see if it is on the diagonal
    // if so increment counter -> there should be 1 queen-> the original queen
    int count = 0;
    for (auto coord_check: queens) {
        for (int i = 0; i<dia+1;i++) {
            if (coord_check.first == i && coord_check.second == 8 - i) count++;
        }
    }
    cout << count <<" ";
    return count;
}
int check_dia2(int dia) {
    int count = 0;
    for (auto coord_check: queens) {
        for (int i = 0; i<dia+1;i++) {
            if (coord_check.first == 8-i && coord_check.second == i) count++;
        }
    }
    cout << count <<" ";
    return count;
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
        // check diagonal
        if (check_dia1(min(coord.first, coord.second)) != 1 || check_dia2(max(coord.first,coord.second)) != 1) {
            cout << "invalid" << "\n";
            return 0;
        }
    }
    cout << "valid" << "\n";
    return 0;
}
