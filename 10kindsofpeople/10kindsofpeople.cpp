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
    // row (r) is y and column (c) is x
    int r, c;
    cin >> r >> c;

    vector<vector<int>> map(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            char c;
            cin >> c;
            map[i][j] = c - '0';
        }
    }

    // ~~dijkstra (a* is too much work probably)~~
    // Too slow do https://www.youtube.com/watch?v=wU6udHRIkcc
    // like kruskal where the sets are predetermined 

    // linear 1D array joint set
    vector<int> disjoint;
    disjoint.resize(r * c, -1); // initialize roots
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            // do all sides since grid
            int x, y;
            x = i - 1, y = j;
            // if in bounds and is the same zone, join the two sets
            if (within(r, c, x, y) && map[i][j] == map[x][y]) {
                join(disjoint, i * c + j, x * c + y);
            }
            x = i + 1, y = j;
            // if in bounds and is the same zone, join the two sets
            if (within(r, c, x, y) && map[i][j] == map[x][y]) {
                join(disjoint, i * c + j, x * c + y);
            }
            x = i, y = j + 1;
            // if in bounds and is the same zone, join the two sets
            if (within(r, c, x, y) && map[i][j] == map[x][y]) {
                join(disjoint, i * c + j, x * c + y);
            }
            x = i, y = j - 1;
            // if in bounds and is the same zone, join the two sets
            if (within(r, c, x, y) && map[i][j] == map[x][y]) {
                join(disjoint, i * c + j, x * c + y);
            }
        }
    }

    // after caches, do the queries
    int n;
    cin >> n;
    while (n--) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        y1--;
        y2--;
        x1--;
        x2--;

        // if same route then it can be traversed
        if (find(disjoint, y1*c+x1) == find(disjoint, y2*c+x2)) {
            cout << (map[y1][x1] == 1 ? "decimal" : "binary") << endl;
        } else {
            cout << "neither" << endl;
        }
    }
    return 0;
}
