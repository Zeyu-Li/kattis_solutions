#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> array;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        array.push_back(tmp);
    }

    switch (t) {
        case 1: {
            sort(array.begin(), array.end());

            for ( auto item : array ) {
                if (binary_search(array.begin(), array.end(), 7777-item)) {
                    cout << "Yes\n";
                    return 0;
                }
            }
            cout << "No\n";
            break;
        }
        case 2: {
            unordered_set<int> map;
            for (int i : array) {
                if (map.find(i) == map.end()) // Not found
                    map.insert(i);
                else {
                    cout << "Contains duplicate\n";
                    return 0;
                }
            }
            cout << "Unique\n";
            break;
        }
        case 3: {
            unordered_map<int, int> map;
            int size = array.size();
            for (int i : array) {
                if (map.find(i) == map.end()) { // Not found
                    map.insert({i, 1});
                } else {
                    map[i]++;
                    if (map[i] > size / 2) {
                        cout << i << endl;
                        return 0;
                    }
                }
            }
            cout << "-1\n";
            break;
        }
        case 4: {
            sort(array.begin(), array.end());
            int size = array.size();
            if (size & 1) { // Odd
                cout << array[size / 2] << endl;
            } else {
                cout << array[size / 2 - 1] << ' ' << array[size / 2] << '\n';
            }
            break;
        }
        case 5: {
            sort(array.begin(), array.end());
            for (int i : array) {
                if (100 <= i && i <= 999)
                    cout << i << " ";
            }
            break;
        }
        default:
            break;
    }
    
    return 0;
}
