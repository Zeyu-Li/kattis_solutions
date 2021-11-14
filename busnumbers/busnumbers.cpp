#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> buses;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        buses.push_back(tmp);
    }

    sort(buses.begin(), buses.end());

    vector<string> output;

    for (int i = 0; i < n; i++) {
        int curr = i;
        if (!(curr + 1 < n && buses[curr+1] == buses[curr] + 1)) {
            output.push_back(to_string(buses[curr]));
            continue;
        }
        if (!(curr + 2 < n && buses[curr+2] == buses[curr+1] + 1)) {
            output.push_back(to_string(buses[curr]));
            continue;
        }
        string start = to_string(buses[curr]) + '-';
        while (curr + 1 < n && buses[curr+1] == buses[curr] + 1){
            curr++;
            i++;
        }
        string push = start + to_string(buses[curr]);
        output.push_back(push);
    }

    string out;
    char delimiter = ' ';
    for (auto &s : output) {
        if (!out.empty()) out += delimiter;
        out += s;
    }

    cout << out << endl;

    return 0;
}
