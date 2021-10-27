#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (1) {
        int n, m;
        cin >> n >> m;

        // while not end case
        if (n == 0 && m == 0) {
            return 0;
        }

        // adj graph that is doubly directional
        vector<vector<pair<int, ld>>> adj_graph(n);
        
        // gets into adjacency list
        for (int i = 0; i < m; i++) {
            int x, y;
            // double f;
            ld f;
            cin >> x >> y >> f;
            adj_graph[x].push_back(make_pair(y, f));
            adj_graph[y].push_back(make_pair(x, f));
        }

        vector<bool> seen(n, false);
        vector<ld> dist(n, 0);

        // dijkstra
        // NOTE: priority queues only queue on the first item in pair
        priority_queue<pair<ld, int>> queue;
        queue.push({1, 0});

        while (!queue.empty()) {
            int curr = queue.top().second;
            ld size = queue.top().first;
            queue.pop();

            // if seen continue
            if (seen[curr]) continue;

            seen[curr] = true;
            dist[curr] = size;

            for (auto connected : adj_graph[curr]) {
                int next = connected.first;
                ld factor = connected.second;
                queue.push({size * factor, next});
            }
        }

        // cout reduction size
        cout << setprecision(4) << fixed;
        cout << dist[n-1] << '\n';
    }
}
