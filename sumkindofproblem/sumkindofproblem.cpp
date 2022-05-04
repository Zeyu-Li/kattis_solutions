#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int curr, num;
        cin >> curr >> num;
        cout << curr  << ' ' << num * (num+1) / 2  << ' '  << num * num  << ' '  << num * (num+1) << '\n';
    }
    return 0;
}
