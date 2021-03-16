#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int h, m;
    cin >> h >> m;
    int total = h*60+m;
    total -= 45;
    // revert positive
    if (total < 0) {
        total += 24*60;
    }

    cout << total/60 << ' ' << total % 60 << '\n';
    return 0;
}
