#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

// naive solution
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    deque<int> array;

    for (int i = 0; i < n; i++) {
        string instr;
        int x;
        cin >> instr >> x;

        if (instr=="get") {
            cout << array[x] << '\n';
        } else if (instr=="push_back") {
            array.push_back(x);
        } else if (instr=="push_front") {
            array.push_front(x);
        } else {
            array.insert(array.begin() + (array.size()+1)/2, x);
        }
        
    }
    return 0;
}
