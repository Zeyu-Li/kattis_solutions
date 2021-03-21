#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

// check prefix manually and not using mismatch for greater efficiency
bool prefix(string a1, string a2) {
    int len = a1.size();
    for (int i = 0; i < len; i++) {
        if (a1[i]!=a2[i]) 
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int i;
    cin >> i;

    // for each case
    while (i--) {
        int n;
        cin >> n;

        vector<string> nums;
        // get the phone numbers as strings
        while (n--) {
            string c;
            cin >> c;

            nums.push_back(c);
        }

        // sort by size
        int len = nums.size();
        sort(nums.begin(), nums.end());

        for (int j = 0; j < len - 1; j++) {
            if (prefix(nums[j], nums[j+1])) {
                goto No;
            }
        }
        cout << "YES" << '\n';
        continue;

        // GOTO
No:
        cout << "NO" << '\n';
    }

    return 0;
}
