#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct node;
extern node *empty;

struct node {
    int sum;
    node *lf, *rt;
    node() : sum(0), lf(this), rt(this) {}
    node(int val) : sum(val), lf(empty), rt(empty) {}
};

node *empty = new node();

void add(int ind, int val, node *&nd, int ns = 1, int ne = 1e7) {
    if (ind < ns or ind > ne)
        return;
    if (nd == empty)
        nd = new node(0);
    if (ns == ne) {
        nd->sum += val;
        return;
    }
    int mid = ns + (ne - ns) / 2;
    add(ind, val, nd->lf, ns, mid);
    add(ind, val, nd->rt, mid + 1, ne);
    nd->sum = nd->lf->sum + nd->rt->sum;
}

int get(int qe, int qs, node *&nd, int ns = 1, int ne = 1e7) {
    if (qe < ns or qs > ne)
        return 0;
    if (ns >= qs and ne <= qe)
        return nd->sum;
    int mid = ns + (ne - ns) / 2;
    return get(qe, qs, nd->lf, ns, mid) +
           get(qe, qs, nd->rt, mid + 1, ne);
}

int find(int val, node *&nd, int ns = 1, int ne = 1e7) {
    if (ns == ne)
        return ns;
    int szLf = nd->lf->sum;
    int mid = ns + (ne - ns) / 2;
    if (val < szLf)
        return find(val, nd->lf, ns, mid);
    return find(val - szLf, nd->rt, mid + 1, ne);
}

struct order_statistic_set {
    node *root;
    order_statistic_set() : root(empty) {}

    void insert(int x) {
        add(x, 1, root);
    }
    int count(int x) {
        return get(x, x, root);
    }
    int operator[](int i) {
        return find(i, root);
    }
    int size() {
        return root->sum;
    }
    void erase(int val) {
        add(val, -count(val), root);
    }
    // delete cnt items of value val
    void erase(int val, int cnt) {
        add(val, -min(cnt, count(val)), root);
    }
    int lowerBound(int val) {
        return get(val - 1, 1, root);
    }
};

int n;
int arr[200005];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        order_statistic_set mySet;
        cin >> n;
        long long invCnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            invCnt += mySet.lowerBound(arr[i]);
            mySet.insert(arr[i]);
        }
        cout << invCnt << endl;
    }
    return 0;
}