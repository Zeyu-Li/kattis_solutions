#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int n, w, h;
    cin >> n >> w >> h;
    int max = (w*w+h*h);
    while (n--) {
        int c;
        cin >> c;
        if (c*c > max) {
            cout << "NE" << '\n';
        } else {
            cout << "DA" << '\n';
        }
    }
    return 0;
}
