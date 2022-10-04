// https://atcoder.jp/contests/abc271/submissions/35293371

const long long MOD = 998244353;
long long modpow(long long a, long long b){
	long long ans = 1;
	while (b > 0){
		if (b % 2 == 1){
			ans *= a;
			ans %= MOD;
		}
		a *= a;
		a %= MOD;
		b /= 2;
	}
	return ans;
}
long long modinv(long long a){
	return modpow(a, MOD - 2);
}
vector<vector<long long>> matmul(vector<vector<long long>> A, vector<vector<long long>> B){
	int N = A.size();
	vector<vector<long long>> ans(N, vector<long long>(N, 0));
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			for (int k = 0; k < N; k++){
				ans[i][k] += A[i][j] * B[j][k];
				ans[i][k] %= MOD;
			}
		}
	}
	return ans;
}
vector<vector<long long>> matexp(vector<vector<long long>> A, long long b){
	int N = A.size();
	vector<vector<long long>> ans(N, vector<long long>(N, 0));
	for (int i = 0; i < N; i++){
		ans[i][i] = 1;
	}
	while (b > 0){
		if (b % 2 == 1){
			ans = matmul(ans, A);
		}
		A = matmul(A, A);
		b /= 2;
	}
	return ans;
}


/*
Ex : 
  vector<vector<long long>> A(24, vector<long long>(24, 0));
  
  A = matexp(A, N);

*/
