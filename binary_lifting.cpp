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

    // setting 1st, 2nd, 4th, 8th, 16th... ancestor of each node
    // 2^jth ancesstor = 2^(j-1) + 2^(j-1)
    // = 2^(j-1) ancestor of 2^(j-1)th ancestor
    // seems hard, isn't

    for (int j = 1; j < LOG; j++) {
        for (int v = 0; v < n; v++) {
            up[v][j] = up[up[v][j - 1]][j - 1];
        }
    }
    // bfs to find depths
    bfs(0, 0);

    while (q--) {
        int x, k;
        cin >> x >> k;
        x--;
        if (dist[x] < k) {
            // impossible
            cout << -1 << endl;
        } else {
            ll ans = x;
            for (int j = 0; j < LOG; j++) {
                if (k & (1 << j)) {
                    ans = up[ans][j];
                }
            }
            cout << ans + 1 << endl;
        }
    }
    return 0;
}