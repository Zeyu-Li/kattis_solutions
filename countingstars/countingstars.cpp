#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

bool checkBounds(int i, int j, int x, int y) {
    return 0 <= i && i < x && 0 <= j && j < y;
}

void floodfill(vector<vector<bool>> &board, int curr_i, int curr_j, int x, int y) {
    stack<pair<int, int>> stack; 
    stack.push({curr_i, curr_j});
    while (!stack.empty()) {
        pair<int, int> curr = stack.top();
        stack.pop();
        int i = curr.first;
        int j = curr.second;
        if (!board[i][j]) continue;
        // cout << i << ':' << j << endl;
        board[i][j] = false;
        // do all for directions
        if (checkBounds(i+1, j, x, y) && board[i+1][j]) {
            stack.push({i+1, j});
        }
        if (checkBounds(i, j+1, x, y) && board[i][j+1]) {
            stack.push({i, j+1});
        }
        if (checkBounds(i-1, j, x, y) && board[i-1][j]) {
            stack.push({i-1, j});
        }
        if (checkBounds(i, j-1, x, y) && board[i][j-1]) {
            stack.push({i, j-1});
        }
    }
    // cout << "done flood fill\n";
}

void printb(vector<vector<bool>> board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    // flood fill algo
    int x;
    int y;
    int ccase = 1;
    while (cin >> x) {
        cin >> y;
        // vector<vector<bool>> board(y, vector<bool>(x));
        vector<vector<bool>> board;
        for (int i = 0; i < x; i++) {
            vector<bool> row;
            for (int j = 0; j < y; j++) {
                char tmp;
                cin >> tmp;
                row.push_back(tmp == '-');
            }
            board.push_back(row);
        }

        // check every square if and if empty, flood fill
        int total = 0;
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                if (board[i][j]) {
                    // cout << i << ':' << j << endl;
                    floodfill(board, i, j, x, y);
                    // printb(board);
                    total++;
                }
            }
        }

        cout << "Case " << ccase << ": " << total << endl;
        ccase++;
    }
    return 0;
}
