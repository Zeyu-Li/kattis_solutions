/*
 * Using 10kinds of people with some modifications (https://open.kattis.com/problems/10kindsofpeople)
*/ 
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;


bool within(int r, int c, int y, int x) {
    return !(x < 0 || y < 0 || c <= x || r <= y);
    // think it will be the same after optimization but it makes me feel smart 😳
    // if (x < 0 || y < 0 || r <= x || c <= y) {
    //     return false;
    // }
    // return true;
}

int find(vector<int> &disjoint, int item) {
    // if disjoint is -1, it is root
    if (disjoint[item] == -1) return item;

    // build out tree
    disjoint[item] = find(disjoint, disjoint[item]);
    return disjoint[item];
}

// join from a and b
void join(vector<int> &disjoint, int a, int b) {
    a = find(disjoint, a);
    b = find(disjoint, b);

    if (a == b) return;

    disjoint[a] = b;
}

int main() {
    // This IO part is important otherwise timeout
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // row (r) is y and column (c) is x
    int n, q;
    cin >> n >> q;

    // linear 1D array joint set
    vector<int> disjoint;
    disjoint.resize(n, -1);

    while (q--) {
        char type;
        int a, b;
        cin >> type >> a >> b;

        if (type == '=') {
            join(disjoint, a, b);
        } else {
            if (find(disjoint, a) == find(disjoint, b)) {
                cout << "yes\n";
            } else {
                cout << "no\n";
            }
        }
    }

    // vector<vector<int>> map(r, vector<int>(c));
    // for (int i = 0; i < r; i++) {
    //     for (int j = 0; j < c; j++) {
    //         char c;
    //         cin >> c;
    //         map[i][j] = c - '0';
    //     }
    // }
    return 0;
}
