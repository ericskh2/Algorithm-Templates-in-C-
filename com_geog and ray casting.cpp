#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f;

struct Point{
    double x;
    double y;
};

struct Line{
    Point p1;
    Point p2;
};
double det(Point a, Point b, Point c){
    return (b.x*c.y-b.y*c.x)-(a.x*c.y-a.y*c.x)+(a.x*b.y-a.y*b.x);
}

bool collinear(Point a, Point b, Point c){
    return abs((a.y-b.y)*(a.x-c.x)-(a.y-c.y)*(a.x-b.x))<DBL_EPSILON;
}
bool inside(Line l, Point c){
    Point a = l.p1;
    Point b = l.p2;
    if(!collinear(a,b,c)) return false;
    if(a.x!=b.x){
        return (a.x<=c.x && c.x<=b.x)||(b.x<=c.x && c.x<=a.x);
    } else {
        return (a.y<=c.y && c.y<=b.y)||(b.y<=c.y && c.y<=a.y);
    }
}

bool cross(Line x, Line y){
    Point a = x.p1;
    Point b = x.p2;
    Point c = y.p1;
    Point d = y.p2;
    if(collinear(a,b,c)) return false;
    double d1 = det(a,b,c);
    double d2 = det(a,b,d);
    double d3 = det(c,d,a);
    double d4 = det(c,d,b);
    if(d1*d2<0 && d3*d4<0 && c.y!=min(a.y,b.y)) return true;
    if(inside(x,c) && c.y!=min(a.y,b.y)) return true;
    if(inside(x,d) && c.y!=min(a.y,b.y)) return true;
    if(inside(y,a) && c.y!=min(a.y,b.y)) return true;
    if(inside(y,b) && c.y!=min(a.y,b.y)) return true;
    return false;
}

double distance(Line x, Point c){
    Point a = x.p1;
    Point b = x.p2;
    return abs(det(a,b,c)) / sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
}

int main() {
    int n;
    while(cin>>n){
        vector<Point> points(n);
        for(int i = 0;i<n;i++){
            cin>>points[i].x>>points[i].y;
        }
        int m;
        cin>>m;
        for(int t = 0;t<m;t++){
            bool isInside = false;
            Point p;
            cin>>p.x>>p.y;
            for(int i = 0;i<n && !isInside;i++){
                for(int j = i+1;j<n && !isInside;j++){
                    for(int k = j+1;k<n && !isInside;k++){

                        Point a = points[i];
                        Point b = points[j];
                        Point c = points[k];
                        if(collinear(a,b,c)) continue;
                        Point o;
                        o.x = min(a.x,min(b.x,c.x))-10;
                        o.y = p.y;
                        Line op;
                        op.p1 = o;
                        op.p2 = p;
                        int cnt = 0;
                        Line l1;
                        l1.p1 = a;
                        l1.p2 = b;
                        Line l2;
                        l2.p1 = a;
                        l2.p2 = c;
                        Line l3;
                        l3.p1 = b;
                        l3.p2 = c;
                        if(cross(l1,op)) cnt++;
                        if(cross(l2,op)) cnt++;
                        if(cross(l3,op)) cnt++;
                        if(cnt%2==1){
                            isInside = true;
                        }
                        if(inside(l1,p)) isInside = true;
                        if(inside(l2,p)) isInside = true;
                        if(inside(l3,p)) isInside = true;
                    }
                }
            }
            (isInside) ? cout<<"inside"<<endl : cout<<"outside"<<endl;
        }
    }
    return 0;
}
