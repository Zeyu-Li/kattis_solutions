#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    // reverse both
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int a1, b1;
    a1 = stoi(a);
    b1 = stoi(b);

    if (a1 > b1) {
        cout << a1 << '\n';
    } else {
        cout << b1 << '\n';
    }

    return 0;
}
