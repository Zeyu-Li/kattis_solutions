#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<int> mins(n);
    vector<int> maxes(n);

    // int tmp;
    // for (int i = 0; i < n; i++) {
    //     cin >> tmp;
    //     nums.push_back(tmp);
    // }
    // Take in the data
    for(auto& i : nums) {
        cin >> i;
    }

    // functional min cascade

    // set first
    maxes[0] = nums[0];
    for(int i = 1; i < n; i++) {
        maxes[i] = max(nums[i], maxes[i-1]);
    }

    // set last
    mins[n-1] = nums[n-1];
    for(int i = n-2; i >= 0; i--) {
        mins[i] = min(nums[i], mins[i+1]);
    }

    // Count edge pivots
    int total = 0;
    if(nums[0] < mins[1]) total++;
    if(nums[n-1] > mins[n-2]) total++;

    // Count center pivots
    for(int i = 1; i < n-1; i++) {
        if(nums[i] < mins[i+1] && nums[i] > maxes[i-1]) {
            total++;
        }
    }

    // Print answer
    cout << total << '\n';

    return 0;
}
