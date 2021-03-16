#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int n, total;
    cin >> n;
    total = 0;

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t < 0) {
            total++;
        }
    }
    cout << total << '\n';
    return 0;
}
