
#include <iostream>     // std::cout
#include <algorithm>    // std::set_union, std::sort
#include <vector>       // std::vector
#include <set>       // std::vector

typedef long long ll;
using namespace std;

int main() {
    int n, m;
    int c, total;

    while (true) {
        cin >> n >> m;

        // break if EOF
        if (n == 0 && m == 0) {
            break;
        }

        vector<int> set1;
        vector<int> set2;

        for (int i = 0; i<n;i++) {
            cin >> c;
            set1.push_back(c);
        }

        for (int j = 0; j<m;j++) {
            cin >> c;
            set2.push_back(c);
        }

        // set union
        vector<int> v;

        std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), back_inserter(v));

        // resize and get size
        cout << v.size() << '\n';
    }
    return 0;
}
