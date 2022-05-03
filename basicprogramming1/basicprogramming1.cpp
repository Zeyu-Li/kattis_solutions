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
            cout << "7\n";
            break;
        }
        case 2: {
            if (array[0] > array[1]) cout << "Bigger\n";
            else if (array[0] == array[1]) cout << "Equal\n";
            else cout << "Smaller\n";
            break;
        }
        case 3: {
            vector<int> newArray = {array[0], array[1], array[2]};
            sort(newArray.begin(), newArray.end());
            cout << newArray[1] << '\n';
            break;
        }
        case 4: {
            ll total = 0;
            for (auto i : array) {
                total+=i;
            }
            cout << total << '\n';
            break;
        }
        case 5: {
            ll total = 0;
            for (auto i : array) {
                total+=i % 2 ? 0 : i;
            }
            cout << total << '\n';
            break;
        }
        case 6: {
            for (auto i : array) {
                cout << (char) ((i % 26) + 97);
            }
            cout << endl;
            break;
        }
        case 7: {
            int i = array[0];
            array[0] = -1;
            // int cycles = 0;
            while (true) {
                if (i >= n) {
                    cout << "Out\n";
                    return 0;
                }
                if (i == n-1) {
                    cout << "Done\n";
                    return 0;
                }
                if (i == -1) {
                    cout << "Cyclic\n";
                    return 0;
                }
                int tmp = i;
                i = array[i];
                array[tmp] = -1;
            }
            cout << "Cyclic\n";
            // int i = 0;
            // int cycles = 0;
            // while (cycles < n + 2) {
            //     cycles++;
            //     i = array[i];
            //     if (0 > i || i >= n) {
            //         cout << "Out\n";
            //         return 0;
            //     } else if (i == n-1) {
            //         cout << "Done\n";
            //         return 0;
            //     }
            // }
            // cout << "Cyclic\n";
            break;
        }
        default:
            break;
    }
    
    return 0;
}
