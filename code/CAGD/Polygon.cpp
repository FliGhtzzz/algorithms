#include<bits/stdc++.h>
using namespace std;
#define int long long
#define X first 
#define Y second
#define ld long double
#define pdd pair<ld, ld>
pdd operator+(pdd a, pdd b) { return  {a.X+b.X, a.Y+b.Y}; }
pdd operator-(pdd a, pdd b) { return  {a.X-b.X, a.Y-b.Y}; }
pdd operator*(ld a, pdd b) { return  {a*b.X, a*b.Y}; }
pdd operator*(pdd b, ld a) { return  {a*b.X, a*b.Y}; }
pdd operator/(pdd a, ld i) { return {a.X / i, a.Y / i}; }
ld dot(pdd a, pdd b) { return a.X * b.X + a.Y * b.Y; }
ld cross(pdd a, pdd b) { return a.X * b.Y - a.Y * b.X; }
struct polygon {
    vector<pair<ld, ld>> points;
    polygon() {}
    polygon(vector<pair<ld, ld>> pts) : points(pts) {}
    
    void add_point(ld x, ld y) {
        points.push_back({x, y});
    }
    
    ld area() const {
        ld res = 0;
        int n = points.size();
        for(int i = 0; i < n; i++) {
            res += points[i].X * points[(i + 1) % n].Y;
            res -= points[i].Y * points[(i + 1) % n].X;
        }
        return abs(res) / 2.0;
    }
    
    bool is_convex() const { //凸的?
        int n = points.size();
        if(n < 3) return false;
        bool sign = false;
        for(int i = 0; i < n; i++) {
            ld cross_product = (points[(i + 1) % n].X - points[i].X) * (points[(i + 2) % n].Y - points[(i + 1) % n].Y) -
                               (points[(i + 1) % n].Y - points[i].Y) * (points[(i + 2) % n].X - points[(i + 1) % n].X);
            if(i == 0) sign = cross_product > 0;
            else if((cross_product > 0 && !sign) || (cross_product < 0 && sign)) return false;
        }
        return true;
    }

    bool on_segment(pdd a, pdd b, pdd p) const {
        if (cross(b - a, p - a) != 0) return false;
        return min(a.X, b.X) <= p.X && p.X <= max(a.X, b.X) &&
               min(a.Y, b.Y) <= p.Y && p.Y <= max(a.Y, b.Y);
    }

    string contains(pdd p) const {
        int n = points.size();
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            pdd a = points[i], b = points[(i + 1) % n];
            if (on_segment(a, b, p))
                return "BOUNDARY";

            if (a.Y > b.Y) swap(a, b);
            if (a.Y <= p.Y && p.Y < b.Y) {
                ld det = cross(b - a, p - a);
                if (det > 0) cnt++;
            }
        }
        return (cnt % 2 == 1 ? "INSIDE" : "OUTSIDE");
    }

    int pts_on_poly() const { //I=A-B/2+1 => I=(2*A+B+2)/2內部點數=面積-邊界點數/2+1
        int n = points.size();
        int B = 0;
        for (int i = 0; i < n; i++) {
            int x1 = round(points[i].X), y1 = round(points[i].Y);
            int x2 = round(points[(i + 1) % n].X), y2 = round(points[(i + 1) % n].Y);
            int dx = abs(x2 - x1), dy = abs(y2 - y1);
            B += gcd(dx, dy);
        }
        return B;
    }
};

