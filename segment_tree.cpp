#include <bits/stdc++.h>

#define tt tuple<int,int,int>

using namespace std;
 
int nextPowerOf2(int n) {
    int count = 0;
    if (n && !(n & (n - 1))) return n;
    while(n != 0) {
        n >>= 1;
        count += 1;
    }
    return 1 << count;
}
 
 
vector<int> constructTree(int p, vector<int>& a) {
    // p = nextPowerOf2(n) = the shift; 
    int n = a.size();
    vector<int> tree(2*p);
    for (int i = p; i < 2*p; i++)
        tree[i] = (i < n + p) ? a[i-p] : 0;
    for (int i = p-1; i >= 0; i--)
        tree[i] = max(tree[2*i], tree[2*i+1]);
    return tree;
}
 
void updateValue(int k, int u, int p, vector<int>& tree) {
    k += p-1;
    tree[k] = u;
    for (k /= 2; k >= 1; k /= 2)
        tree[k] = max(tree[2*k], tree[2*k+1]);
    return;
}
 
int maximum(int a, int b, int p, vector<int>& tree) {
    a += p-1; b += p-1;
    int s = 0;
    while (a <= b) {
        if (a % 2 == 1) s = max(s, tree[a++]);
        if (b % 2 == 0) s = max(s, tree[b--]);
        a /= 2; b /= 2;
    }
    return s;
}
 
