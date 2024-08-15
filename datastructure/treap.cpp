#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
using namespace std;

random_device rd;
mt19937 randommm(rd());

struct Treap {
    Treap *l, *r;
    int key, pri, size, count;
    Treap(int k) : l(nullptr), r(nullptr), key(k), pri(randommm()), size(1), count(1) {}
    void pull() {
        size = count;
        if(l != nullptr) size += l->size;
        if(r != nullptr) size += r->size;
    }
};

Treap* merge(Treap *a, Treap *b) {
    if(a==nullptr) return b;
    if(b==nullptr) return a;
    if(a->pri < b->pri) {
        a->r = merge(a->r, b);
        a->pull();
        return a;
    } else {
        b->l = merge(a, b->l);
        b->pull();
        return b;
    }
}

void split(Treap *p, Treap*&a, Treap*&b, int k) {
    if(p==nullptr) {
        a = b = nullptr;
        return; 
    }
    if(p->key < k) {
        a = p;
        split(p->r, a->r, b, k);
        a->pull();
    } else {
        b = p;
        split(p->l, a, b->l, k);
        b->pull();
    }
}

void insert(Treap *&root, int k) {
    Treap *l, *r;
    split(root, l, r, k);
    Treap *m;
    split(r, m, r, k+1);
    if(m == nullptr) {
        m = new Treap(k);
    } else {
        m->count++;
        m->size++;
    }
    root = merge(merge(l, m), r);
}

void erase(Treap *&root, int k) {
    Treap *a, *b, *c;
    split(root, a, c, k);
    split(c, b, c, k+1);
    if(b != nullptr) {
        b->count--;
        if(b->count == 0) {
            delete b;
            b = nullptr;
        } else {
            b->size--;
        }
    }
    root = merge(merge(a, b), c);
}

int size(Treap *p) {
    return p == nullptr ? 0 : p->size;
}

int rank(Treap *&root, int key) {
    Treap *a, *b;
    split(root, a, b, key);
    int ret = size(a);
    root = merge(a, b);
    return ret;
}

int kth(Treap *&root, int k) {
    if(root == nullptr || k > root->size) return -1;  // 錯誤處理
    if(root->l != nullptr) {
        if(k <= root->l->size) return kth(root->l, k);
        k -= root->l->size;
    }
    if(k <= root->count) return root->key;
    return kth(root->r, k - root->count);
}

int main() {
    int x, y, a;
    cin >> x >> y;
    if(y&1) a=y/2+1;
    else a=y/2;
    Treap* t = nullptr;
    vector<int> val(x);
    for(int i=0; i<x; i++) {
        cin >> val[i];
    }
    for(int i=0; i<y; i++) {
        insert(t, val[i]);
    }
    cout << kth(t, a);
    for(int i=y; i<x; i++) {
        insert(t, val[i]);
        erase(t, val[i-y]);
        cout << " " << kth(t, a);
    }
    return 0;
}