// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<ll>
#define pb push_back

const ll LOG = 20;  // = log(maxn)
const ll maxn = 2e5 + 5;
vi adj[maxn];
bool vis[maxn];
ll pare[maxn];
ll dist[maxn];
ll up[maxn][20] = {};
ll n;

void bfs(ll src, ll d) {
    vis[src] = 1;
    dist[src] = d;
    for (auto x : adj[src]) {
        if (!vis[x]) {
            bfs(x, d + 1);
        }
    }
}
int get_lca(int a, int b) {
    if (dist[a] < dist[b]) {
        swap(a, b);
    }

    int k = dist[a] - dist[b];
    for (int j = LOG - 1; j >= 0; j--) {
        if (k & (1 << j)) {
            a = up[a][j];
        }
    }
    // if b was ancestor of a
    if (a == b) {
        return a;
    }
    // else now both are at same dist
    // essentially binary search
    for (int j = LOG - 1; j >= 0; j--) {
        if (up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // n : number of nodes;
    // q : number of queries
    // queries of form (x, k) = kth ancestor of node x
    // O(N*LogN) = time and space

    cin >> n;
    ll q;
    cin >> q;
    ll u;
    for (ll i = 1; i < n; i++) {
        cin >> u;
        u--;
        adj[u].pb(i);
        adj[i].pb(u);
        pare[i] = u;
    }
    for (int v = 0; v < n; v++) {
        up[v][0] = pare[v];
    }

    for (int j = 1; j < LOG; j++) {
        for (int v = 0; v < n; v++) {
            up[v][j] = up[up[v][j - 1]][j - 1];
        }
    }
    // bfs to find depths
    bfs(0, 0);

    while (q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        cout << get_lca(a, b) + 1 << endl;
    }
    return 0;
}