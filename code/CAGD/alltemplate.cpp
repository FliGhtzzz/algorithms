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
ld abs(pdd a) {return sqrt(a.X * a.X + a.Y * a.Y); }
int sgn(ld v) { return v > 0 ? 1 : (v < 0 ? -1 : 0);} // return 0 1 -1 表示 平行...同側 異側
int ori(pdd a, pdd b, pdd c)  { return sgn(cross(b - a, c - a)); } //return a->c 和 a->b 的外積之方向
bool sameline(pdd a, pdd b, pdd c) { return ori(a, b, c) == 0; }
bool btw(pdd p, pdd a, pdd b) { return sameline(p, a, b) && sgn(dot(a - p, b - p)) <= 0; }  // return p是否在線段a-b 上。
bool banana(const pdd &p1, const pdd &p2, const pdd &p3, const pdd &p4) { //回傳香蕉與否
    if(btw(p1, p3, p4) || btw(p2, p3, p4) || btw(p3, p1, p2) || btw(p4, p1, p2)) return true;
    return ori(p1, p2, p3) * ori(p1, p2, p4) < 0 && ori(p3, p4, p1) * ori(p3, p4, p2) < 0;
}
pdd bananapoint(pdd p1, pdd p2, pdd p3, pdd p4){ //回傳蕉點
   ld a123 = cross(p2 - p1, p3 - p1);
   ld a124 = cross(p2 - p1, p4 - p1);
   return (p4 * a123 - p3 * a124) / (a123 - a124);
}
ld dis(pdd p, pdd a, pdd b) { return dot(p-a, b-a)/abs(b-a);} //dis from pdd p to line:a->b
pdd shadowpoint(pdd p, pdd a, pdd b) { return a+(b-a)*dot(p-a, b-a)/abs(b-a);} 