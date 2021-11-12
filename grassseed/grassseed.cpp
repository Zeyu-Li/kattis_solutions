#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    float c, l;
    cin >> c >> l;
    double cost = 0;
    for (int i = 0; i < l; i++) {
        float w, k;
        cin >> w >> k;
        cost += w * k * c;
    }

    cout << setprecision(10) << fixed << cost << endl;

    return 0;
}
