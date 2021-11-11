#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

// switch from pick (This is a monty hall problem so better to switch)
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n = 1000;
    while (n--) {
        // cout << 'A' << endl;
        char pick = 'A' + rand() % 3;
        cout << pick << endl;
        char res, state;
        cin >> res >> state;
        if (state == '1') {
            cout << res << endl;
        } else {
            // pick not pick or res
            char randomPick = 'A' + rand() % 3;
            while (randomPick == pick || randomPick == res) randomPick = 'A' + rand() % 3;
            cout << randomPick << endl;

            // if (res == 'A') cout << 'B' << endl;
            // else if (res == 'B') cout << 'C' << endl;
            // else cout << 'B' << endl;
        }
        cin >> res >> state;
    }
    return 0;
}
