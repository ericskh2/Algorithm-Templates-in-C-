#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f

const int maxn = 5001;
ll graph[maxn+1][maxn+1];
vector<int> e[maxn+1];

void init(int n){
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            graph[i][j] = 0;
        }
    }
    for (int i = 0; i <= n; i++) {
        e[i].clear();
    }
}

void addEdge(int a, int b, ll w) {
    e[a].push_back(b);
    e[b].push_back(a);
    graph[a][b] += w;
}

bool bfs(vector<int>& p, vector<ll>& a, int n, int s, int t) {
    for (int i = 0; i < a.size(); i++) {
        a[i] = 0;
    }
    queue<int> q;
    q.push(s);
    a[s] = LLONG_MAX;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < e[x].size(); i++) {
            int y = e[x][i];
            ll temp = graph[x][y];
            if (!a[y] && temp > 0) {
                p[y] = x;
                a[y] = min(a[x], temp);
                q.push(y);
            }
        }
        if (a[t]) return true;
    }
    return false;
}

// count edges starting from source with residual value > 0
int dfs(vector<bool>& visited, int x) {
    if (visited[x]) return 0;
    visited[x] = true;
    int res = 0;
    for (int i = 0; i < e[x].size(); i++) {
        int y = e[x][i];
        if (graph[x][y] > 0 && !visited[y]) {
            res++;
            res += dfs(visited, y);
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

    init(n);

    //s = 0;
    //t = n + 1;

    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        addEdge(a, b, c);
    }

    vector<int> p(n + 2);
    vector<ll> a(n + 2, 0);

    ll ans = 0;

    while (bfs(p, a, n, s, t)) {
        for (int u = t; u != s; u = p[u]) {
            graph[p[u]][u] -= a[t];
            graph[u][p[u]] += a[t];
        }
        ans += a[t];
    }

    cout << ans << endl;
    return 0;
}
