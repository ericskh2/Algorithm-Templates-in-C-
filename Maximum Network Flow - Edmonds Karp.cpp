#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f

bool bfs(vector<vector<ll>>& graph, vector<int>& p, vector<ll>& a, int n, int s, int t) {
    for (int i = 0; i < a.size(); i++) {
        a[i] = 0;
    }
    queue<int> q;
    q.push(s);
    a[s] = LLONG_MAX;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int i = 0; i <= n + 1; i++) {
            if (!a[i] && graph[curr][i] > 0) {
                p[i] = curr;
                a[i] = min(a[curr], graph[curr][i]);
                q.push(i);
            }
        }
        if (a[t]) return true;
    }
    return false;
}

// count edges starting from source with residual value > 0
int dfs(vector<vector<ll>>& graph, vector<bool>& visited,int n, int x) {
    if (visited[x]) return 0;
    visited[x] = true;
    int res = 0;
    for (int i = 1; i <= n + 1; i++) {
        if (graph[x][i] > 0 && !visited[i]) {
            res++;
            res += dfs(graph, visited, n, i);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int s;
    int t;

    int n, m;
    cin >> n >> m >> s >> t;

    //s = 0;
    //t = n + 1;

    vector<vector<ll>> graph(n + 2, vector<ll>(n + 2, 0));


    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        graph[a][b] += c;
    }

    vector<int> p(n + 2);
    vector<ll> a(n + 2, 0);

    ll ans = 0;

    while (bfs(graph, p, a, n, s, t)) {
        for (int curr = t; curr != s; curr = p[curr]) {
            graph[p[curr]][curr] -= a[t];
            graph[curr][p[curr]] += a[t];
        }
        ans += a[t];
    }


    cout << ans << endl;

    // vector<bool> visited(n+2, false);
    // cout<<dfs(graph,visited,n,s)<<endl;

    return 0;
}
