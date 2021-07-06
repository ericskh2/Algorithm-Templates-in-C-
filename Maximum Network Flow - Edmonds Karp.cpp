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
        for (int i = 1; i < graph[curr].size(); i++) {
            if (!a[i] && graph[curr][i]>0) {
                p[i] = curr;
                a[i] = min(a[curr], graph[curr][i]);
                q.push(i);
            }
        }
        if (a[t]) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int s = 1;
    int t = 1;

    int n, m;
    cin >> n >> m >> s >> t;

    vector<vector<ll>> graph(n + 1, vector<ll>(n + 1, 0));


    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        graph[a][b] += c;
    }

    vector<int> p(n + 1);
    vector<ll> a(n + 1,0);

    ll ans = 0;

    while (bfs(graph,p,a,n,s,t)) {
        for (int curr = t; curr != s; curr = p[curr]) {
            graph[p[curr]][curr] -= a[t];
            graph[curr][p[curr]] += a[t];
        }
        ans += a[t];
    }

    cout << ans <<endl;
    return 0;
}
