#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

// modified from https://github.com/andrewome/kattis-problems/blob/master/joinstrings.cpp
void print(int index, vector<vector<int>> &map, vector<string> &strings) {
    cout << strings[index];
    for (int i : map[index]) {
        print(i, map, strings);
    }
}


int main() {
    // IO
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >>n;

    vector<string> strings;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;

        strings.push_back(x);
    }

    int a,b;
    // last must be included and a cannot be used ¯\(°_o)/¯
    int last = 0;
    vector<vector<int>> matrix;
    matrix.assign(n, vector<int>());
    for (int i = 1; i < n; i++) {
        
        cin >> a >> b;
        a--;
        b--;

        matrix[a].push_back(b);
        last = a;
        // strings[a] = strings[a] + strings[b];
        // strings[b] = "";
    }

    // recursively print
    print(last, matrix, strings);
    // for (int i = 0; i < n; i++) {
    //     cout << strings[i];
    // }
    cout << '\n';

    return 0;
}
