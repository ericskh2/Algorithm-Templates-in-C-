#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f;

ll gcd(ll p, ll q, ll& x, ll& y){
    ll x1,y1;
    ll g;
    if(q>p) return gcd(q,p,y,x);
    if(q==0){
        x = 1;
        y = 0;
        return p;
    }

    g = gcd(q,p%q,x1,y1);

    x = y1;
    y = (x1-floor(p/q)*y1);

    return g;
}
int main() {
    ll a,b;
    while(cin>>a>>b){
        ll x,y;
        // AX+BY=D
        cout<<x<<" "<<y<<" "<<gcd(a,b,x,y)<<endl;
    }
    return 0;
}
