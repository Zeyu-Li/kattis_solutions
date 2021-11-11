#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> possible(n+m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            possible[i+j]++;
        }
    }

    int max = *max_element(possible.begin(), possible.end());

    for (int i = 0; i < m+n; i++) {
        if (max == possible[i]) cout << i + 2 << '\n';
    }

    return 0;
}
