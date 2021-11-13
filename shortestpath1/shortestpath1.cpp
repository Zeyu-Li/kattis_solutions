#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

struct Node_pair {
    vector<pair<int, int>> neighbours;
    int distance;
};

int main() {
    // bfs instead with adjacency lists
    
    while (1) {
        int n, m, q, s;
        cin >> n >> m >> q >> s;
        if (n == 0) return 0;

        Node_pair init;
        init.distance = INT_MAX;

        vector<Node_pair> adj(n, init);
        
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].neighbours.push_back({v, w});
        }
        
        std::queue<int> list;

        // starting node
        adj[s].distance = 0;
        list.push(s);

        // while queue is not empty
        while (!list.empty()) {
            // sets new node as first in queue
            int current = list.front();
            // dequeues
            list.pop();

            // gets all adjacent vertices
            for (auto i : adj[current].neighbours) {
                int neighbour = i.first;
                int weight = i.second;
                if (adj[current].distance + weight < adj[neighbour].distance) {
                    adj[neighbour].distance = adj[current].distance + weight;
                    list.push(neighbour);
                }
            }
        }

        for (int i = 0; i < q; i++) {
            // queries
            int tmp;
            cin >> tmp;
            int dist = adj[tmp].distance;
            if (dist == INT_MAX) {
                cout << "Impossible\n";
            } else {
                cout << dist << '\n';
            }
        }

        cout << endl;
    }

    return 0;
}


// Dijkstra is too slow but if the query size was closer to node size it 
// would be a better fit 
// class Graph_m {
//     public:
//         // contructors, default undirected
//         Graph_m();
//         // contructor with directness boolean, true means directed 
//         Graph_m(bool);
//         // contructor with size (number of vertices)
//         Graph_m(int);
//         Graph_m(bool, int);
//         // destructor
//         ~Graph_m();

//         // print
//         void print();
//         int get_size();

//         // resize
//         void resize(int new_size);

//         // setter (edge)
//         void add_edge(int, int);
//         // overloads when default weight is not 1
//         void add_edge(int, int, int);

//         // main matrix, therefore getter unnecessary
//         std::vector<std::vector <int>> matrix;
//     protected:
//         int size;
//         bool directed;
// };

// Graph_m::Graph_m() {
//     size=0;
//     directed = true;
// }
// Graph_m::Graph_m(bool direc) {
//     size=0;
//     directed = direc;
// }
// Graph_m::Graph_m(int n) {
//     directed = true;
//     // resize
//     size=0;
//     resize(n);
//     size=n;
// }
// Graph_m::Graph_m(bool direc, int n) {
//     directed = direc;
//     // resize
//     size=0;
//     resize(n);
//     size=n;
// }
// Graph_m::~Graph_m() {
//     size=0;
// }

// // resize
// void Graph_m::resize(int new_size) {
//     if (new_size > size) {
//         // enlarge the matrix
//         for (int i = size; i<new_size; i++) {
//             // add zero to each row
//             // zeros for each row
//             std::vector<int> bottom;
//             for (int j = size; j<new_size; j++) {
//                 bottom.push_back(0);
//             }
//             matrix.push_back(bottom);
//         }
//     }
// }

// // add edge row then column
// void Graph_m::add_edge(int y, int x) {
//     // sets size as the max of x or y
//     int max = x > y ? x : y;
//     if (max>size) {
//         size = max;
//         // Resize
//         resize(max);
//     }
//     matrix[y][x] = 1;
//     // if undirected
//     if (!directed) matrix[x][y] = 1;
// }
// void Graph_m::add_edge(int y, int x, int weight) {
//     // sets size as the max of x or y
//     int max = x > y ? x : y;
//     if (max>size) {
//         size = max;
//     }
//     matrix[y][x] = weight;
//     // if undirected
//     if (!directed) matrix[x][y] = weight;
// }

// int Graph_m::get_size(void) {
//     return size;
// }

// void Graph_m::print(void) {
//     int n = size;
//     for (int i=0;i<n;i++) {
//         for (int j=0;j<n;j++) {
//             std::cout << matrix[i][j] << '\t';
//         }
//         std::cout << std::endl;
//     }
// }

// class Graph_dijkstra: public Graph_m {
//     public:
//         Graph_dijkstra(): Graph_m() {};
//         Graph_dijkstra(bool a): Graph_m(a) {};
//         Graph_dijkstra(int a): Graph_m(a) {};
//         Graph_dijkstra(bool a, int b): Graph_m(a, b) {};
//         // returns a vector of the result of dijkstra's alg
//         std::vector<int> dijkstra(int);
//         // stores dijkstra results in second argument
//         void dijkstra(int, std::vector<int>&);
//         // returns shortest path given start and end
//         int dijkstra(int, int);
//     private:
//         // gets min distance
//         int min_dist(std::vector<int>&, std::vector<bool>&);
// };

// int Graph_dijkstra::min_dist(std::vector<int>& dist, std::vector<bool>& shortest_path) {
//     int min = INT_MAX, min_index;
//     // for each vertex
//     for (int v = 0; v < size; v++) {
//         // if is connected and smaller than current min, swap to that one
//         if ((!shortest_path[v]) && dist[v] <= min) {
//             min = dist[v];
//             min_index = v;
//         }
//     }
//     return min_index;
// }


// std::vector<int> Graph_dijkstra::dijkstra(int start) {
//     std::vector<int> dist(size); // shortest path distance of each point
//     std::fill_n(dist.begin(), size, INT_MAX);
//     std::vector<bool> shortest_path(size);
//     std::fill_n(shortest_path.begin(), size, false);

//     // start of path is of distance 0
//     dist[start] = 0;
//     // for every vertex
//     for (int i = 0; i < size - 1; i++) {
//         // gets shortest path to work off of
//         int u = min_dist(dist, shortest_path);
//         // check the current node
//         shortest_path[u] = true;

//         // update dist of adjacent vertices to the shortest path if it is connect and shorter than previous entry (dp)
//         for (int v = 0; v < size; v++) {
//             if (!shortest_path[v] && matrix[u][v] && dist[u] != INT_MAX && dist[u] + matrix[u][v] < dist[v]) {
//                 dist[v] = dist[u] + matrix[u][v];
//             }
//         }
        
//         // breaks early
//         // if (u == end) break;
//     }
//     // return the distances of all nodes
//     return dist;
// }

// void Graph_dijkstra::dijkstra(int start, std::vector<int>&path) {
//     std::vector<int> d_path = dijkstra(start);
//     // copy vectors
//     for(int i=0; i<d_path.size(); ++i) path.push_back(d_path[i]);
// }

// int Graph_dijkstra::dijkstra(int start, int end) {
//     std::vector<int> d_path = dijkstra(start);
//     // return length of shortest path
//     return d_path[end];
// }


// int main() {
//     while (1) {
//         int n, m, q, s;
//         cin >> n >> m >> q >> s;
//         if (n == 0) return 0;
//         Graph_dijkstra Dijkstra(true, n);
        
//         for (int i = 0; i < m; i++) {
//             int u, v, w;
//             cin >> u >> v >> w;
//             Dijkstra.add_edge(u, v, w);
//         }
//         vector<int> d_path;
//         Dijkstra.dijkstra(s, d_path);

//         for (int i = 0; i < q; i++) {
//             // queries
//             int tmp;
//             cin >> tmp;
//             if (d_path[tmp] == INT_MAX) {
//                 cout << "Impossible\n";
//             } else {
//                 cout << d_path[tmp] << '\n';
//             }
//         }
//         cout << endl;
//     }

//     return 0;
// }
