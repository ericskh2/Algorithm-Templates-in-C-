#include <bits/stdc++.h>
using namespace std;
#define maxn 251
#define ll long long
#define INF 0x3f3f3f3f

struct Edge {
    int from, to, cap, flow;
    Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};


int n, m;
vector<Edge> edges;
vector<int> G[maxn+1];
int a[maxn+1], p[maxn+1];

void init(int n) {
    for (int i = 0; i <= n; i++) G[i].clear();
    edges.clear();
}

void addEdge(int from, int to, int cap) {
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    m = edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
}

int maxFlow(int s, int t) {
    int flow = 0;
    for (;;) {
        memset(a, 0, sizeof(a));
        queue<int> Q;
        Q.push(s);
        a[s] = INF;
        while (!Q.empty()) {
            int x = Q.front();
            Q.pop();
            for (int i = 0; i < G[x].size(); i++) {
                Edge& e = edges[G[x][i]];
                if (!a[e.to] && e.cap > e.flow) {
                    p[e.to] = G[x][i];
                    a[e.to] =
                        min(a[x], e.cap - e.flow);
                    Q.push(e.to);
                }
            }
            if (a[t]) break;
        }
        if (!a[t])
            break;
        for (int u = t; u != s;
            u = edges[p[u]].from) {
            edges[p[u]].flow += a[t];
            edges[p[u] ^ 1].flow -= a[t];
        }
        flow += a[t];
    }
    return flow;
}

int main() {

    int n, m, s, t;
    
    while (cin>>n>>m>>s>>t) {

        init(n + 1);

        for (int i = 0; i < m; i++) {
            ll u, v, w;
            cin >> u >> v >> w;
            addEdge(u, v, w);
        }
        
        ll ans = maxFlow(s,t);

        cout << ans << endl;
    }
    return 0;
}
