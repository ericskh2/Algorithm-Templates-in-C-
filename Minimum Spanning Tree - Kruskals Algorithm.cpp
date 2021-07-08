#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f

const int maxn = 5001;

int parent[maxn + 1];

void init() {
    for (int i = 0; i <= maxn; i++) {
        parent[i] = -1;
    }
}

void init(int n) {
    for (int i = 0; i <= n; i++) {
        parent[i] = -1;
    }
}

int findParent(int x) {
    if (parent[x] < 0) return x;
    parent[x] = findParent(parent[x]);
    return parent[x];
}

void unionJoin(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (parent[a] < parent[b]) {
        parent[a] += parent[b];
        parent[b] = a;
    }
    else {
        parent[b] += parent[a];
        parent[a] = b;
    }
}

ll kruskal(vector<pair<int, pair<int, int>>>& edges, int n) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for (auto e : edges) {
        pq.push(e);
    }
    ll ans = 0;
    int sets = n;
    while (!pq.empty() && sets>1) {
        int dis = pq.top().first;
        int a = pq.top().second.first;
        int b = pq.top().second.second;
        pq.pop();
        a = findParent(a);
        b = findParent(b);
        if (a == b) {
            continue;
        }
        else {
            ans += dis;
            unionJoin(a, b);
            sets--;

        }
    }
    if (sets > 1) return -1;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    while (cin >> n >> m) {

        init(n);

        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            edges.push_back({ c,{a,b} });
        }

        ll ans = kruskal(edges, n);

        (ans != -1) ? cout << ans << endl : cout << "orz" << endl;

    }
    return 0;
}
