#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

static void solve(vector<vector<int>> &board, int n) {
    for (int i = 0; i < 4; i++) {
        // 1 pass
        for (int j = 0; j < 3; j++) {
            switch (n) {
                case 0:
                    if (board[i][j] == board[i][j+1]) {
                        board[i][j] *= 2;
                        // set zero
                        board[i][j+1] = 0;
                    }
                    break;
                case 2:
                    if (board[i][3-j] == board[i][4-j]) {
                        board[i][3-j] = 0;
                        // set zero
                        board[i][4-j] *= 2;
                    }
                    break;
                case 1:
                    if (board[j][i] == board[j+1][i]) {
                        board[j][i] = 0;
                        // set zero
                        board[j+1][i] *= 2;
                    }
                    break;
                case 3:
                    if (board[4-j][i] == board[3-j][i]) {
                        board[3-j][i] = 0;
                        // set zero
                        board[4-j][i] *= 2;
                    }
                    break;
                default:
                    break;
            }
        }
        // shift
        int base = 0;
        for (int j = 0; j < 4; j++) {
            switch (n) {
                case 0:
                    if (board[i][j] != 0) {
                        if (base == j) {
                            base++;
                            continue;
                        }
                        board[i][base] = board[i][j];
                        // set zero
                        board[i][j] = 0;
                        base++;
                    }
                    break;
                case 2:
                    if (board[i][4-j] != 0) {
                        if (base == j) {
                            base++;
                            continue;
                        }
                        board[i][4-base] = board[i][4-j];
                        // set zero
                        board[i][4-j] = 0;
                        base++;
                    }
                    break;
                default:
                    break;
            }
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

    solve(board, n);

    // print
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
