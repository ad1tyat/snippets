// declarations

const ll mx = 1e5 + 5;
ll dist[mx];
bool processed[mx];
priority_queue<pair<ll, ll>> q;

// Pre processing
for (ll i = 0; i < mx; i++) processed[i] = false;
for (int i = 0; i < mx; i++) dist[i] = 1e18;

// SOURCE ??
ll src = 0;

dist[src] = 0;
q.push({0, src});
while (!q.empty()) {
    int a = q.top().second;
    q.pop();
    if (processed[a]) continue;
    processed[a] = true;
    for (auto u : adj[a]) {
        int b = u.first, w = u.second;
        if (dist[a] + w < dist[b]) {
            dist[b] = dist[a] + w;
            q.push({-dist[b], b});
        }
    }
}

// dist array :)
// IF NOT REACHABLE and -1

for (ll i = 0; i < n; i++) {
    if (dist[i] == 1e18) dist[i] = -1;
}