#include <iostream>

using namespace std;

int main() {
    int s1, r1;
    cin >> r1 >> s1;
    // cout << r1 << " "<< s1 << endl;
    int s2 = (s1 << 1) - r1;
    cout << s2 << endl;
    return 0;
}
