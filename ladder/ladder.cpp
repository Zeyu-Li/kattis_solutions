#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    float a,b;
    cin >> a >> b;

    float x = a/sin(b*M_PI/180);

    // cout << x << '\n';
    cout << ceil(x) << '\n';
    return 0;
}
