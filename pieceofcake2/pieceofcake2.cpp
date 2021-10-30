#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int n, h, v;
    cin >> n >> h >> v;

    int width = 4;

    // base
    int largest = h * v;

    largest = max(largest, (n - h) * v);
    largest = max(largest, h * (n - v));
    largest = max(largest, (n - h) * (n-v));

    cout << largest * 4 << endl;

    return 0;
}
