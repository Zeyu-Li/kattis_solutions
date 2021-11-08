#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    while (scanf("%d", &n) == 1) {
        int max_test = (int) sqrt(n);
        // if (n == 2) {
        //     cout << "2 almost perfect";
        //     continue;
        // }
        int total = 1;
        // to sqrt
        for (int i = 2; i <= max_test; i++) {
            if (!(n % i)) {
                if (n / i == i) total += i;
                else total += i + n / i;
            }
        }

        cout << n << ' ';
        if (total == n) cout << "perfect";
        else if (total-2 <= n && n <= total+2 ) cout << "almost perfect";
        else cout << "not perfect";

        cout << endl;
    }
    return 0;
}
