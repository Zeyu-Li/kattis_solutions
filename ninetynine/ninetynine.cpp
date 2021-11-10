#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int curr = 1;
    cout << curr << endl;
    while (curr < 99) {
        cin >> curr;
        curr+=min(3-curr % 3, 2);

        cout << curr << endl;
    }
    return 0;
}
