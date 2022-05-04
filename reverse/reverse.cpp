#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int k;
    cin >> k;

    vector<int> nums;
    while (k--) {
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }

    reverse(nums.begin(), nums.end());

    for (auto i : nums) {
        cout << i << '\n';
    }

    return 0;
}
