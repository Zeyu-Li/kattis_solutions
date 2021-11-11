#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int l, d, x;
    cin >> l >> d >> x;
    int min = -1;
    int l1, l2;
    for (int i = l; i <= d; i++) {
        int sum = 0;
        l1 = i;
        while (l1 > 0) { 
            sum += l1 % 10;
            l1 /= 10;
        }
        if (sum == x) {
            if (min == -1) {
                min = i;
                cout << min << '\n'; 
                break;
            }
        }
    }
    int max = -1;
    for (int i = d; i >= l; i--) {
        int sum = 0;
        l2 = i;
        while (l2 > 0) { 
            sum += l2 % 10;
            l2 = l2 / 10;
        }
        if (sum == x) {
            if (max == -1) {
                max = i;
                cout << max << '\n'; 
                break;
            }
        }
    }
    return 0;
}
