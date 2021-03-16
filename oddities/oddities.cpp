#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int s;
    cin >> s;
    for (int i = 0; i<s;i++) {
        int k;
        cin >> k;
        if (k%2) {
            cout << k << " is odd\n";
        } else {
            cout << k << " is even\n";
        }
    }
    return 0;
}
