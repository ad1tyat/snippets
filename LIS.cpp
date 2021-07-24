ll LIS(vi v) {
	for (ll i = 0; i < n; i++) {
		ll ind = lower_bound(ans.begin(), ans.end(), v[i]) - ans.begin();
		if (ind < ans.size()) {
			ans[ind] = v[i];
		} else {
			ans.pb(v[i]);
		}
	}
	return ans.size();
}