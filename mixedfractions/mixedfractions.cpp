#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int gcd(int int1, int int2){
    if (int2 == 0) return int1;
    return gcd(int2, int1 % int2);
}

int main() {
    int n, d;
    cin >> n >> d;
    while (!(n == 0 && n==0)) {
        int whole = n / d;
        // int _gcd = gcd(d, n % d);

        cout << whole << ' ' << n % d << " / " << d << endl;

        // next iter
        cin >> n >> d;
    }
    return 0;
}
