#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;

    float total = 0;
    while (n--) {
        float a, b;
        cin >> a >> b;

        total+=a*b;
    }
    cout << total << '\n';
    return 0;
}
