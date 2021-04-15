#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    // golden ratio approximating 😮
    int n;
    cin >> n;
    vector<ll> papers;
    for (int i = 0; i < n - 1; i++) {
        ll tmp;
        cin >> tmp;
        papers.push_back(tmp);
    }

    ld total = 0;
    ll need = 1;
    bool has = false;
    ld long_  = pow(2.0, -3/4.0);
    ld short_ = pow(2.0, -5/4.0);
    for (auto counts:papers) {
        total += need * long_;
        // swap
        ld tmp = long_;
        long_ = short_;
        short_ = tmp;
        // increase needed distance
        short_ /= 2;
        
        need = need << 1;
        need -= counts;
        if (need <= 0) {
            // we have enough
            has = true;
            break;
        }
    }
    if (!has) {
        cout << "impossible" << '\n';
    } else {
        cout << fixed;
        cout.precision(9);
        cout << total << '\n';
    }

    return 0;
}
