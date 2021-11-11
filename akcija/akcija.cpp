#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> books;
    while (n--) {
        int tmp;
        cin >> tmp;
        books.push_back(tmp);
    }

    sort(books.rbegin(), books.rend());
    // int sum = accumulate(books.begin(), books.end(), 0);
    int sum = 0;

    for (int i = 0; i < books.size(); i++) {
        if (i%3 != 2) sum+=books[i];
    }

    cout << sum << endl;

    return 0;
}
