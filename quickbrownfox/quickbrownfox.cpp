#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;

    cin.ignore();
    while (n--) {
        string l;
        // cin >> l;
        getline(cin, l);
        // to lower case
        for_each(l.begin(), l.end(), [](char &c){ c = ::tolower(c); });
        // cout << l << endl;

        vector<char> missing;
        for (char i = 'a'; i <= 'z'; i++) {
            if (l.find(i) == string::npos) {
                // cout << i << endl;
                missing.push_back(i);
            }
        }

        if (missing.size() == 0) {
            cout << "pangram" << endl;
        } else {
            string s(missing.begin(), missing.end());
            cout << "missing " << s << endl;
        }
    }


    return 0;
}
