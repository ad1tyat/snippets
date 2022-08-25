// ll mxn= 1e6 + 2;
// Call manipulated_sieve(mxn)

const long long MAX_SIZE = 1000005;

vector<long long> isprime(MAX_SIZE, true);
vector<long long> prime;
vector<long long> SPF(MAX_SIZE);

// function generate all prime number less than N in O(n)
void manipulated_seive(int N) {
    // 0 and 1 are not prime
    isprime[0] = isprime[1] = false;

    // Fill rest of the entries
    for (long long int i = 2; i < N; i++) {
        // If isPrime[i] == True then i is
        // prime number
        if (isprime[i]) {
            // put i into prime[] vector
            prime.push_back(i);

            // A prime number is its own smallest
            // prime factor
            SPF[i] = i;
        }

        // Remove all multiples of  i*prime[j] which are
        // not prime by making isPrime[i*prime[j]] = false
        // and put smallest prime factor of i*Prime[j] as prime[j]
        // [ for exp :let  i = 5 , j = 0 , prime[j] = 2 [ i*prime[j] = 10 ]
        // so smallest prime factor of '10' is '2' that is prime[j] ]
        // this loop run only one time for number which are not prime
        for (long long int j = 0; j < (int)prime.size() && i * prime[j] < N && prime[j] <= SPF[i]; j++) {
            isprime[i * prime[j]] = false;

            // put smallest prime factor of i*prime[j]
            SPF[i * prime[j]] = prime[j];
        }
    }
}

// if n = p1^a1 * p2^a2 ...
// returns {p1, a1}, {p2, a2} ....
// in log(n) time with ABOVE preprocessing

// n should be upto 1e6 only !!
vector<pair<long long, int>> factorize(long long n) {
    vector<pair<long long, int>> myprimes;
    while (n != 1) {
        ll ncpy2 = n;
        ll times = 0;
        while (n % SPF[ncpy2] == 0) {
            n /= SPF[ncpy2];
            times++;
        }
        myprimes.push_back({SPF[ncpy2], times});
    }
    return myprimes;
}
