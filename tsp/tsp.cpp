#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

// results in a answer of ~3
int dist( int a, int b, vector<pair<float, float>> list) {
    float x, y;
    x = list[a].first - list[b].first;
    y = list[a].second - list[b].second;

    float diff = sqrt(pow(x, 2) + pow(y,2));
    return round(diff);
}

int main() {
    int x;
    cin >> x;

    vector<pair<float, float>> list;
    for (int i = 0; i < x;i++) {
        float a, b;
        cin >> a>> b;
        list.push_back(make_pair(a,b));
    }

    vector<int> tour;
    vector<bool> used;

    // zeros
    tour.resize(x, -1);
    used.resize(x, false);

    tour[0] = 0;
    used[0] = true;

    int best;
    for (int i = 1; i<x; i++) {
        best = -1;
        for (int j = 0; j < x;j++) {
            if (!used[j] && (best == -1 || dist(tour[i-1],j,list) < dist(tour[i-1],best,list)))
                best = j;
        }
        tour[i] = best;
        used[best] = true;
    }

    for (int i = 0; i < tour.size(); i++) {
        cout << tour[i] << '\n';
    }
    return 0;
}
