#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f

const int maxn = 1000;
struct suffix{
    int idx;
    int rnk;
    int nextrnk;
};
int sa[maxn+1];
int ind[maxn+1];
int height[maxn+1];
int rnk[maxn+1];
suffix suffixes[maxn+1];

bool cmp(suffix a, suffix b){
    if(a.rnk!=b.rnk) return a.rnk<b.rnk;
    return a.nextrnk < b.nextrnk;
}

void buildSuffixArray(string& s){
    int n = s.size();
    for(int i = 0;i<n;i++){
        suffixes[i].idx = i;
        suffixes[i].rnk = s[i];
        suffixes[i].nextrnk = ((i+1)<n) ? (s[i+1]) : -1;
    }
    sort(suffixes,suffixes+n,cmp);

    for(int k = 4;k<2*n;k*=2){
        int rnk = 0;
        int prernk = suffixes[0].rnk;
        suffixes[0].rnk = rnk;
        ind[suffixes[0].idx] = 0;

        for(int i = 1;i<n;i++){
            if(suffixes[i].rnk == prernk && suffixes[i].nextrnk == suffixes[i-1].nextrnk){
                prernk = suffixes[i].rnk;
                suffixes[i].rnk = rnk;
            } else {
                prernk = suffixes[i].rnk;
                suffixes[i].rnk = ++rnk;
            }
            ind[suffixes[i].idx] = i;
        }
        for(int i = 0;i<n;i++){
            int nextidx = suffixes[i].idx + k/2;
            suffixes[i].nextrnk = (nextidx<n)?suffixes[ind[nextidx]].rnk:-1;
        }
        sort(suffixes,suffixes+n,cmp);
    }

    for(int i = 0;i<n;i++){
        sa[i] = suffixes[i].idx;
    }
}

void buildHeightArray(string& s){
    int n = s.size();
    int k = 0;

    for(int i = 0;i<n;i++) rnk[sa[i]] = i;

    for(int i = 0;i<n;i++){
        if(rnk[i]==0){
            k = 0;
            continue;
        }

        int j = sa[rnk[i]-1];

        while(i+k<n && j+k<n && s[i+k] == s[j+k]) k++;

        height[rnk[i]] = k;
        if(k)k--;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    for(int tc = 1;tc<=t;tc++){
        string in;
        cin>>in;

        int n = in.size();
        buildSuffixArray(in);
        buildHeightArray(in);

        string ans = "";
        int mx = 0;
        int mxcnt = 0;
        for(int i = 0;i<n;i++){
            if(height[i]>mx){
                mx = height[i];
                int cnt = 2;
                while(i<n-1 && height[i]==height[i+1]){
                    i++;
                    cnt++;
                }
                mxcnt = cnt;
                ans = in.substr(sa[i],mx);
            } else if(height[i]==mx){
                int cnt = 2;
                while(i<n-1 && height[i]==height[i+1]){
                    i++;
                    cnt++;
                }
                if(in.substr(sa[i],mx)<ans){
                    ans = in.substr(sa[i],mx);
                    mxcnt = cnt;
                }
            }
        }
        if(mx>0){
            cout<<ans<<" "<<mxcnt<<endl;
        } else {
            cout<<"No repetitions found!"<<endl;
        }
    }
    return 0;
}
