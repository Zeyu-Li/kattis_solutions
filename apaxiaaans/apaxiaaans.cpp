#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    string c;
    cin >> c;

    char previous = c[0];
    vector<char> end;
    end.push_back(previous);
    for (int i = 1; i < c.size(); i++) {
        if (previous == c[i]) {
            continue;
        } else {
            previous = c[i];
            end.push_back(previous);
        }
    }

    for (auto ch: end) {
        cout << ch;
    }
    cout << '\n';

    return 0;
}
