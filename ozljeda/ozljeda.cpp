#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, q;
    cin >> k;
    vector<ll> x;
    ll total = 0;
    for (int i = 0; i < k; i++) {
        ll tmp;
        cin >> tmp;
        x.push_back(tmp);
        total ^= tmp;
    }
    x.push_back(total);
    k++;

    // create segtree (will cycle every 2 * k)
    vector<ll> suml(k), sumr(k);
    ll sum = 0;
    for (int i = 0; i < k; i++) {
        sum ^= x[i];
        suml[i] = sum;
    }

    sum = 0;
    for (int i = k - 1; i >= 0; i--) {
        sum ^= x[i];
        sumr[i] = sum;
    }

    cin >> q;
    while (q--) {
        ll l, r;
        cin >> l >> r;
        l = (l - 1) % k;
        r = (r - 1) % k;
        
        ll result = 0;
        result ^= suml[r];
        result ^= sumr[l];

        cout << result << '\n';
    }

    return 0;
}
