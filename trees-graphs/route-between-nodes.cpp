#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> adj, int s, vector<bool> &vis) {
    queue<int> q;
    q.push(s);
    vis[s]=true;
    while (!q.empty()) {
        int temp = q.front();
        q.pop();
        for (int i : adj[temp]) {
            if (vis[i] == false) {
                q.push(i);
                vis[i] = true;
            }
        }
    }
}

bool isPathExists(vector<vector<int>> adj, int source,
                  int destination) {
    vector<bool> vis(adj.size(), false);
    bfs(adj, source, vis);
    return vis[destination];
}

int main() {
    int number_of_vertices, number_of_edges;
    cin >> number_of_vertices >> number_of_edges;
    vector<vector<int>> adj(number_of_vertices);
    for (int i = 0; i < number_of_edges; i++) {
        int s, d;
        cin >> s >> d;
        adj[s].push_back(d);
    }
    int source, destination;
    cin >> source >> destination;
    cout << boolalpha << isPathExists(adj, source, destination);
    return 0;
}