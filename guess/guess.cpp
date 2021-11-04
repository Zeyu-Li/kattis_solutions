#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int max = 1001, min = 1;
    int curr = (max - min) / 2 + min;
    string res;
    cout << curr << endl;
    cin >> res;
    while (res != "correct") {
        if (res == "lower") {
            max = curr;
        } else {
            min = curr;
        }
        curr = (max - min) / 2 + min;
        cout << curr << endl;
        cin >> res;
    }

    return 0;
}
