#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    int start = 2;

    while (n--) {
        start *= 2;
        start--;
    }

    cout << start * start << "\n";
    return 0;
}
