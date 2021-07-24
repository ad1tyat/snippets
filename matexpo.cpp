vector<vi> mull(vector<vi> a, vector<vi> b) {
    ll n = a.size();
    vector<vi> res(n, vi(n));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            for (ll k = 0; k < n; k++) {
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= M1;
            }
        }
    }
    return res;
}
vector<vi> matexpo(vector<vi> a, ll k) {
    ll n = a.size();
    vector<vi> res(n, vi(n));
    if (k == 0) {
        for (ll i = 0; i < n; i++) {
            res[i][i] = 1;
        }
        return res;
    }
    vector<vi> gg = matexpo(a, k / 2);
    gg = mull(gg, gg);
    if (k % 2 == 1) gg = mull(gg, a);
    return gg;
}