#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int x;
    cin >> x;
    int n;
    cin >> n;

    // vector<int> days;
    int k = x*(n+1);
    int total = 0;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        total += c;
    }

    cout << k-total << "\n";
    return 0;
}
