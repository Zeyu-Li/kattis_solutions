#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void printb(vector<vector<int>> board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}

void backtrack(vector<vector<int>> &dp, vector<int> &values, vector<int> &weights, vector<int> &result, int c, int n) {
    // cout << c << ':' << n << endl;
    if(dp[n][c] == 0) return;

    if (dp[n-1][c] == dp[n][c]) {
        backtrack(dp, values, weights, result, c, n-1);
    } else {
        backtrack(dp, values, weights, result, c-weights[n-1], n-1);
        result.push_back(n-1);
    }
}

int main() {
    int c, n;
    while (cin >> c && cin >> n) {
        vector<int> values, weights;
        for (int i = 0; i < n; i++) {
            int value, weight;
            cin >> value >> weight;
            values.push_back(value);
            weights.push_back(weight);
        }

        vector<vector<int>> dp(n + 1, vector<int>(c + 1));
        // dp solution (skip first row/column since 0s)
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < c + 1; j++) {
                // if bound my knapsack capcity, do DP, otherwise set 
                if (weights[i - 1] <= j) {
                    dp[i][j] = max(values[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
            // printb(dp);
        }
        // cout << dp[n][c] << endl;

        // backtrack from result (dp table)
        // see https://github.com/mpfeifer1/Kattis/blob/master/knapsack.cpp#L66
        vector<int> result;
        backtrack(dp, values, weights, result, c, n);

        cout << result.size() << '\n';
        for(int i : result) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
