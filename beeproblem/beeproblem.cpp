#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int fill(int i, int j, int n, int m, vector<vector<char>>& cells) {
    int count = 1, s = -1, b = 1;

    if (i % 2) {
        s = 0;
        b = 2;
    }
    
    // top bottom
    for (int x = s; x < b; x++) {
        for (int y = -1; y < 2; y += 2) {
            if ( 0 > j + x || 0 > i + y || 
                j + x >= m || i + y >= n || cells[i + y][j + x] == '#') continue;
            
            cells[i + y][j + x] = '#';
            count += fill(i + y, j + x, n, m, cells);
        }
    }
    // left right
    for (int x = -1; x < 2; x++) {
        if (0 > j + x || j + x >= m || cells[i][j + x] == '#') continue;
        
        cells[i][j + x] = '#';
        count += fill(i, j + x, n, m, cells);
    }

    return count;
}

int main() {
    int h, n, m;
    cin >> h >> n >> m;

    vector<vector<char>> cells(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cells[i][j];
        }
    }

    vector<int> counts;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (cells[i][j] == '.') {
                cells[i][j] = '#';
                counts.push_back(fill(i, j, n, m, cells));
            }
        }
    }

    sort(counts.begin(), counts.end());

    int fills = 0;
    while (h > 0) {
        h -= counts.back();
        counts.pop_back();
        fills++;
    }

    cout << fills << endl;

    return 0;
}
