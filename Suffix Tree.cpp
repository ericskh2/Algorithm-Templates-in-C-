#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f

struct suffix{
    int idx;
    int rnk;
    int nextrnk;
};

bool cmp(suffix a, suffix b){
    if(a.rnk != b.rnk) return a.rnk < b.rnk;
    return a.nextrnk < b.nextrnk;
}

void buildSuffixArray(vector<int>& sa, string& s){
    int n = s.size();
    vector<suffix> suffixes(n);
    for(int i = 0;i<n;i++){
        suffixes[i].idx = i;
        suffixes[i].rnk = s[i];
        suffixes[i].nextrnk = ((i + 1) < n) ? (s[i + 1]) : -1;
    }
    sort(suffixes.begin(),suffixes.end(),cmp);

    vector<int> ind(n);
    for(int k = 4;k<2*n;k*=2){
        int rnk = 0;
        int prernk = suffixes[0].rnk;
        suffixes[0].rnk = rnk;
        ind[suffixes[0].idx] = 0;

        for(int i = 1;i<n;i++){
            if(suffixes[i].rnk == prernk && suffixes[i].nextrnk == suffixes[i - 1].nextrnk) {
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
            suffixes[i].nextrnk = (nextidx < n) ? suffixes[ind[nextidx]].rnk : -1;
        }
        sort(suffixes.begin(),suffixes.end(),cmp);
    }

    for(int i = 0;i<n;i++){
        sa[i] = suffixes[i].idx;
    }
}

void buildHeightArray(vector<int>& height, vector<int>& sa,string& s){
    int n = s.size();
    int k = 0;

    vector<int> rnk(n,0);

    for(int i = 0;i<n;i++) rnk[sa[i]] = i;

    for(int i = 0;i<n;i++){
        if(rnk[i]==0){
            k = 0;
            continue;
        }

        int j = sa[rnk[i]-1];

        while(i+k<n && j+k<n && s[i+k] == s[j+k]) k++;

        height[rnk[i]] = k;

        if(k) k--;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin>>t;
    while(t--){
        string in;
        cin>>in;

        int n = in.size();
        vector<int> sa(n);
        vector<int> height(n);
        buildSuffixArray(sa,in);
        buildHeightArray(height,sa,in);

        string ans = "";
        int times = 0;
        int temp = 1;
        for(int i = 1;i<n;i++){
            if(height[i]){
                if(height[i]==height[i-1]){
                    temp++;
                    if(height[i]>ans.size() || (height[i]==ans.size() && in.substr(sa[i],height[i])<=ans)){
                        ans = in.substr(sa[i],height[i]);
                        times = temp+1;
                    }
                } else {
                    temp = 1;

                    if(height[i]>ans.size() || (height[i]==ans.size() && in.substr(sa[i],height[i])<=ans)){
                        ans = in.substr(sa[i],height[i]);
                        times = temp+1;
                    }
                }
            }

        }
        (!ans.empty()) ? cout<<ans<<" "<<times<<endl : cout<<"No repetitions found!"<<endl;
    }

    return 0;
}
