#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int r,e,c;
        cin >> r >> e >> c;
        if (e-c==r) {
            cout << "does not matter\n";
        } else if (e-c>r) {
            cout << "advertise\n";
        } else {
            cout << "do not advertise\n";
        }
        
    }
    return 0;
}
