#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f

double vx;
double vy;
int v;

struct Point{
    ll x;
    ll y;
};

double det(Point a, Point b, Point c){
    double x1 = a.x;
    double y1 = a.y;
    double x2 = b.x;
    double y2 = b.y;
    double x3 = c.x;
    double y3 = c.y;
    return (x2*y3-y2*x3)-(x1*y3-y1*x3)+(x1*y2-y1*x2);
}

bool cmp(Point a, Point b){
    double x1 = a.x;
    double y1 = a.y;
    double x2 = b.x;
    double y2 = b.y;
    double result = (x1*y2-y1*x2)-(vx*y2-vy*x2)+(vx*y1-vy*x1);
    if(abs(result)<=DBL_EPSILON){
        return (a.x-vx)*(a.x-vx)+(a.y-vy)*(a.y-vy) < (b.x-vx)*(b.x-vx)+(b.y-vy)*(b.y-vy);
    } else {
        return result>0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    cout<<t<<endl;
    while(t--){
        int n;
        cin>>n;
        vector<Point> points(n);
        cin>>points[0].x>>points[0].y;
        vx = points[0].x;
        vy = points[0].y;
        v = 0;
        for(int i = 1;i<n;i++){
            cin>>points[i].x>>points[i].y;
            if(points[i].y < vy || points[i].y == vy && points[i].x < vx){
                vx = points[i].x;
                vy = points[i].y;
                v = i;
            }
        }
        swap(points[0],points[v]);
        sort(points.begin(),points.end(),cmp);
        stack<Point> st;
        st.push(points[0]);
        st.push(points[1]);
        for(int i = 2;i<n;i++){
            while(st.size()>=2){
                Point b = st.top();
                st.pop();
                Point a = st.top();
                st.pop();
                if(det(a,b,points[i])>0){
                    st.push(a);
                    st.push(b);

                    break;
                } else {
                    st.push(a);
                }
            }
            st.push(points[i]);
        }
        st.push(points[0]);
        cout<<st.size()<<endl;
        stack<Point> ans;
        while(!st.empty()){
            ans.push(st.top());
            st.pop();
        }
        while(!ans.empty()){
            cout<<ans.top().x;
            cout<<" ";
            cout<<ans.top().y;
            cout<<endl;
            ans.pop();
        }

        int useless;
        if(t>0){
            cin>>useless;
            cout<<useless<<endl;
        }
    }
    return 0;
}
