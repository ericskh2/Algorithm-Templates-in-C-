#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f

const int maxn = 5000;
int graph[maxn+1][maxn+1];
bool visited[maxn + 1];
int shortestdistance[maxn + 1];

void init() {
    for (int i = 0; i <= maxn; i++) {
        for (int j = 0; j <= maxn; j++) {
            graph[i][j] = INF;
        }
    }
    for (int i = 0; i <= maxn; i++) {
        shortestdistance[i] = INF;
    }
    for (int i = 0; i <= maxn; i++) {
        visited[i] = false;
    }
}

void init(int n) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            graph[i][j] = INF;
        }
    }
    for (int i = 0; i <= n; i++) {
        shortestdistance[i] = INF;
    }
    for (int i = 0; i <= n; i++) {
        visited[i] = false;
    }
}

ll prims(int n,int start) {
    priority_queue<pair<int,pair<int,int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> pq;
    pq.push({ 0,{start,start} });
    while (!pq.empty()) {
        int dis = pq.top().first;
        int curr = pq.top().second.first;
        int par = pq.top().second.second;
        pq.pop();
        if (visited[curr]) continue;
        visited[curr] = true;
        if (dis < shortestdistance[curr]) shortestdistance[curr] = dis;
        for (int i = 0; i <= n; i++) {
            if (shortestdistance[i] > graph[curr][i]) {
                shortestdistance[curr] = dis;
                pq.push({ graph[curr][i], {i,curr} });
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) return -1;
        ans += shortestdistance[i];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    while (cin >> n >> m) {

        init(n);

        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            c = min(c, graph[a][b]);
            graph[a][b] = c;
            graph[b][a] = c;
        }

        ll ans = prims(n,1);

        (ans != -1) ? cout << ans << endl : cout << "orz" << endl;

    }
    return 0;
}
