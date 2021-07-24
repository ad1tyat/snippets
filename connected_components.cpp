const ll maxn = 1e6;

ll n;
vector<ll> adj[maxn];
bool used[maxn];
vector<ll> comp;

void dfs(ll v) {
    used[v] = true;
    comp.pb(v);
    for (auto x : adj[v]) {
        if (!used[x]) dfs(x);
    }
}

void find_comps() {
    for (ll i = 0; i < n; ++i) used[i] = false;
    for (ll i = 0; i < n; ++i)
        if (!used[i]) {
            comp.clear();
            dfs(i);
            cout << "Component:";
            for (size_t j = 0; j < comp.size(); ++j) cout << ' ' << comp[j];
            cout << endl;
        }
}