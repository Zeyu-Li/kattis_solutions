#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    string x, y;
    cin >> x >> y;
    int count1, count2;
    count1 = count2 = 0;
    for (auto ch : x) {
        if (ch == 'a') {
            count1++;
        }
    }
    for (auto ch : y) {
        if (ch == 'a') {
            count2++;
        }
    }
    if (count1 < count2) {
        cout << "no" << '\n';
    } else {
        cout << "go" << '\n';
    }
    return 0;
}
