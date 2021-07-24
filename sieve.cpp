vi primes;
void sieve() {
    const ll maxn = 1e6 + 100;
    ll isP[maxn] = {};
    for (ll i = 2; i < maxn; i++) {
        if (isP[i] == 0) {
            primes.pb(i);
            for (ll j = 2 * i; j < maxn; j += i) {
                isP[j] = 1;
            }
        }
    }
}