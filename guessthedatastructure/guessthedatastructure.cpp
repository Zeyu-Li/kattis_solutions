#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        stack<int> stack;
        queue<int> queue;
        priority_queue<int> priority_queue;

        vector<bool> possible = {true, true, true};
        while (n--) {
            int type, x;
            cin >> type >> x;
            if (type == 1) {
                if (possible[0]) stack.push(x);
                if (possible[1]) queue.push(x);
                if (possible[2]) priority_queue.push(x);
            } else {
                if (possible[0]) {
                    if (stack.size() == 0 || stack.top() != x) {
                        possible[0] = false;
                    } else {
                        stack.pop();
                    }
                }
                if (possible[1]) {
                    if (queue.size() == 0 || queue.front() != x) {
                        possible[1] = false;
                    } else {
                        queue.pop();
                    }
                }
                if (possible[2]) {
                    if (priority_queue.size() == 0 || priority_queue.top() != x) {
                        possible[2] = false;
                    } else {
                        priority_queue.pop();
                    }
                }
            }
        }
        // print which is possible
        if (count(possible.begin(), possible.end(), true) >= 2) {
            cout << "not sure" << endl;
        } else {
            if (count(possible.begin(), possible.end(), true) == 0) {
                cout << "impossible" << endl;
            } else {
                string name;
                if (possible[0]) name = "stack";
                else if (possible[1]) name = "queue";
                else name = "priority queue";
                cout << name << endl;
            }
        }
    }
    return 0;
}
