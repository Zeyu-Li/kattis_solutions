#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

static void solve(vector<int> &row) {
    // solves a row
    
    // shift to one end
    int base = 0;
    for (int i = 0; i < 4; i++) {
        if (row[i] != 0) {
            if (base == i) {
                base++;
                continue;
            }
            row[base] = row[i];
            // set zero
            row[i] = 0;
            base++;
        }
    }
    // solve
    for (int i = 0; i < 3; i++) {
        if (row[i] == row[i+1]) {
            row[i] *= 2;
            // set zero
            row[i+1] = 0;
        }
    }
    // shift again
    base = 0;
    for (int i = 0; i < 4; i++) {
        if (row[i] != 0) {
            if (base == i) {
                base++;
                continue;
            }
            row[base] = row[i];
            // set zero
            row[i] = 0;
            base++;
        }
    }
}

int main() {
    // initialize with zero
    vector<vector<int>> board(4, vector<int>(4, 0));

    // get from standard in
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> board[i][j];
        }
    }

    // get move (0=left, 1=up, 2=right, 3=down)
    int n;
    cin >> n;

    for (int i = 0; i < 4; i++) {
        // initialize row every time
        vector<int> row;
        switch (n) {
            case 0:
                // copy row
                solve(board[i]);
                break;
            case 2:
                // reverse direction
                reverse(board[i].begin(), board[i].end());
                solve(board[i]);
                reverse(board[i].begin(), board[i].end());
                break;
            case 1:
                for (int j = 0; j < 4; j++) {
                    row.push_back(board[j][i]);
                }
                // solve row
                solve(row);
                // copy back
                for (int j = 0; j < 4; j++) {
                    board[j][i] = row[j];
                }
                break;
            case 3:
                for (int j = 0; j < 4; j++) {
                    row.push_back(board[3-j][i]);
                }
                solve(row);
                for (int j = 0; j < 4; j++) {
                    board[3-j][i] = row[j];
                }
                break;
            default:
                break;
        }
    }

    // print
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
