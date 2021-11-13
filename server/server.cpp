#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    int count = 0;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    for (int i = 0; i < n; i++) {
        t-=v[i];
        if (t >= 0) {
            count++;
        } else {
            break;
        }
    }
    // if (count == 0) cout << 0 << endl;
    cout << count << endl;
    return 0;
}
