#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin>>n){
        vector<vector<int>> grid(n+1,vector<int>(n+1,INF));
        int t;
        cin>>t;
        while(t--){
            int a,b,c;
            cin>>a>>b>>c;
            grid[a][b] = c;
            grid[b][a] = c;
        }
        vector<int> shortest(n+1,INF);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,n});
        shortest[n] = 0;
        while(!pq.empty()){
            int dis = pq.top().first;
            int curr = pq.top().second;
            pq.pop();
            for(int i = 1;i<=n;i++){
                if(dis+grid[curr][i]<shortest[i]){
                    shortest[i] = dis + grid[curr][i];
                    pq.push({shortest[i],i});
                }
            }
        }
        cout<<shortest[1]<<endl;
    }
}
