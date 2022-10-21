#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> ii;

const int MAX = 10101;
const int INF = 1e9;
int N, M;

vector<ii> adj[MAX];  // Adjacency list holds a pair of { node, weight } from the node at index [i]
vector<int> dist;     // Holds the minimum distance calculated to reach node at index [i] from source

void dijkstra(int s) {  // [s] represents the source node index
    dist.assign(N, INF);
    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> Q;  // The priority queue keeps the pairs of { weight, node } ordered by the smallest total weight
    Q.push({0, s});
    while (!Q.empty()) {
        int u = Q.top().second;
        int d = Q.top().first;
        Q.pop();
        if (d > dist[u]) continue;
        for (auto e : adj[u]) {
            int v = e.first, w = e.second;
            // Update the smallest distance found and add the newly found { distance, node } to the priority queue
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                Q.push({dist[v], v});
            }
        }
    }
}

int main() {}