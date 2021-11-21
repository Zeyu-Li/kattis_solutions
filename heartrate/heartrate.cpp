#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << setprecision(4) << fixed;
    while (n--) {
        float b, p;
        cin >> b >> p;
        float bpm = b/p * 60.0;
        float abpm = 60.0 / p;
        cout << bpm - abpm << ' ' << bpm << ' ' << bpm + abpm << endl;
    }
    return 0;
}
