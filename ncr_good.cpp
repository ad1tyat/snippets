#include <bits/stdc++.h>
using namespace std;

#define M1 1000000007
#define M2 998244353
#define ll long long
#define pll pair<ll,ll>
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPR(i,a,b) for(ll i=b-1;i>=a;i--)
#define forr(i,n) for(ll i=0;i<n;i++)
#define F first
#define S second
#define pb push_back
#define DB pop_back
#define mp make_pair
#define MT make_tuple
#define V(a) vector<a>
#define vi vector<ll>
#define endl '\n'
#define ce(ele) cout<<ele<<' '
#define cs(ele) cout<<ele<<'\n'
#define CASE(t) ll t; cin>>t; while(t--)
int binomialCoeff(int n, int k)
{
	int C[n + 1][k + 1];
	int i, j;

	// Caculate value of Binomial Coefficient in bottom up manner
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= min(i, k); j++)
		{
			// Base Cases
			if (j == 0 || j == i)
				C[i][j] = 1;

			// Calculate value using previously stored values
			else
				C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}

	return C[n][k];
}
void FAST() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
const ll maxn = 100050;
ll fact[maxn] = {};
ll invf[maxn] = {};
long long power(long long x, long long y) {
	long long res = 1;
	while (y) {
		if (y & 1) res = (res * x) % M1;
		x = (x * x) % M1;
		y >>= 1;
	}
	return res;
}
long long ncr(int n, int r) {
	if (n < 0 || r < 0 || n < r) return 0;
	long long res = fact[n];
	res = (res * invf[r]) % M1;
	res = (res * invf[n - r]) % M1;
	return res;
}
int main() {
	FAST();
	fact[0] = 1;
	invf[0] = 1;
	for (long long i = 1; i < maxn; i++) {
		fact[i] = (i * fact[i - 1]) % M1;
	}
	invf[maxn - 1] = power(fact[maxn - 1], M1 - 2);
	for (long long i = maxn - 2; i >= 1; i--) {
		invf[i] = ((i + 1) * invf[i + 1]) % M1;
	}
	//SIMPLY CALL ncr(n,r)
	//M1 = 1000000007;
	//change accordingly
	return 0;
}