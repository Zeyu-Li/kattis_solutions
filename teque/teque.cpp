#include <bits/stdc++.h>

typedef long long ll;
using namespace std;


// adjusts the two deques such that it is not uneven
void adjust(deque<int>&a1,deque<int>&a2, int val, bool way) {
    if (way) {
        int back = a1.back();
        a1.pop_back(); // since pop back does not actually return the data, we can't do `itn back = a1.pop_back()`
        a2.push_front(back);
    } else {
        int front = a2.front();
        a2.pop_front(); // since pop back does not actually return the data, we can't do `itn back = a1.pop_back()`
        a1.push_back(front);
    }
    ;
}

// new solution (https://github.com/BobbyZhouZijian/Kattis-Solutions/blob/master/teque.cpp): 
// two deques to be time efficient with middle operation
int main() {
    // fast IO
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    deque<int> array1;
    deque<int> array2;
    int size1, size2;
    size1 = size2 = 0;

    for (int i = 0; i < n; i++) {
        string instr;
        int x;
        cin >> instr >> x;

        if (instr=="get") {
            if (x >= size1) {
                cout << array2[x-size1] << '\n';
            } else {
                cout << array1[x] << '\n';
            }
        } else if (instr=="push_back") {
            array2.push_back(x);
            size2++;
            // adjust if inbalance
            if (size2 > size1) {
                adjust(array1, array2, x, false);
                size2--;
                size1++;
            }
        } else if (instr=="push_front") {
            array1.push_front(x);
            size1++;

            // adjust if inbalance
            if (size1 > size2+1) {
                adjust(array1, array2, x, true);
                size1--;
                size2++;
            }
        } else {
            if (size1 > size2) {
                array2.push_front(x);
                size2++;
            } else {
                array1.push_back(x);
                size1++;
            }
        }
        
    }
    return 0;
}
