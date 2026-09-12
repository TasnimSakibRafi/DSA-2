#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;
const int INF = INT_MAX/2;
int n, e; // number of nodes, number of edges
vector <vector<pii>>adj;

void dijstra(int src){
    vector <int> dist, par;
    dist.assign(n+1, INF);
    for(int i = 0 ; i <= n ; i++)
        par.push_back(i);
//    for(int i = 0 ; i <= n ; i++){
//        dist.push_back(INF);
//    }
    dist[src] = 0;
    priority_queue <pii, vector<pii>, greater<pii>> pq;
    pq.push({dist[src], src});
    while(pq.size()){
//        int d = pq.top().first;
//        int node = pq.top().second;
        auto [d, node] = pq.top();
        pq.pop();
        if(dist[node] < d) continue;
//        for(int i = 0 ; i < adj[node].size() ; i++){
//            int neighbour = adj[node][i].first;
//            int weight = adj[node][i].second;
//        }
        for(auto [neighbour, weight] : adj[node]){
            if(dist[neighbour] > dist[node] + weight){
                dist[neighbour] = dist[node] + weight;
                par[neighbour] = node;
                pq.push({dist[neighbour], neighbour});
            }
        }
    }
    for(int i = 0 ; i <= n ; i++){
        cout << "distance of node " << i << " is " << dist[i] << endl;
        cout << "Path to " << i << " : ";
        int curr = i;
        vector <int> path;
        while(par[curr] != curr){
            path.push_back(curr);
            curr = par[curr];
        }
        path.push_back(src); // complete reverse path
        reverse(path.begin(), path.end());
        for(int j = 0 ; j < path.size() ; j++)
            cout << path[j] << " ";
        cout << endl;
    }
}

int main(){
    cin >> n >> e;
//    for(int i = 0 ; i <= n ; i++)
//        adj.push_back({});
    adj.assign(n+1, {});
    for(int i = 0 ; i < e ; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w}); // not in directed graph
    }
    int src;
    cin >> src;
    dijstra(src);
    return 0;
}

/*
https://media.geeksforgeeks.org/wp-content/uploads/20240111182238/Working-of-Dijkstras-Algorithm-768.jpg

9 14
0 1 4
0 7 8
1 7 11
1 2 8
7 8 7
7 6 1
2 8 2
8 6 6
2 3 7
2 5 4
6 5 2
3 5 14
3 4 9
5 4 10
0



https://media.geeksforgeeks.org/wp-content/uploads/20251113155540209723/123456.webp

5 6
0 1 4
0 2 8
1 2 3
1 4 6
2 3 2
4 3 10
0
*/
