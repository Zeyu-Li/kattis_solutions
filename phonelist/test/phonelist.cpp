#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

// naive solution
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
        sort(nums.begin(), nums.end(), [](const string str1, const string str2){return str1.size() < str2.size();});

        int j = 0;
        for (auto num: nums) {
            // check for j onwards
            for (int k = j + 1; k < len; k++) {
                if (mismatch(num.begin(), num.end(), nums[k].begin()).first == num.end()) {
                    goto yes;
                }
            }
            // cout << num << '\n';
            j++;
        }

        cout << "YES" << '\n';
        continue;

        // GOTO
yes:
        cout << "NO" << '\n';
    }

    return 0;
}
