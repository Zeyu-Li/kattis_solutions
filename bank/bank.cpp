#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int c,t;
    cin >> c >> t;

    vector<int> picked(t+1, 0);
    while (c--) {
        int money, t;
        cin >> money >> t;

        // starting from the time they chose to leave to the start (0 min)
        for (int j = t; j >=0; j--) {
            // if the money gathered in current is greater than previous, switch them out for a better yielding one
            if (money > picked[j]) {
                swap(money, picked[j]);
            }
        }
    }

    // sum up total
    int total = 0;
    for (auto money:picked) {
        total+=money;
    }

    cout << total << '\n';

    return 0;
}
