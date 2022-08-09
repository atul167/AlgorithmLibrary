/*
Smallest Prime Factor
*/

long long SPF[N + 5];
     
// initially SPF[i] = i
for (long long i = 1; i <= N; i++)
    SPF[i] = i;

// use sieve concept to store the first prime factor of every number
for (int i = 2; i * i <= N; i++) {
    if (SPF[i] == i) {
        // mark all factors of i
        for (int j = i * i; j <= N; j += i)
            if (SPF[j] == j)
                SPF[j] = i;
    }
}









// O(n*log(log(n))) 
ll spf[N+5];
void SPF() { 
	// marking smallest prime factor for every number to be itself.
	for (ll i = 1; i <= N; i++) spf[i] = i; 
  
	// separately marking spf for every even number as 2 
	for (ll i = 4; i<= N; i += 2) spf[i] = 2;
  
	for (ll i = 3; i * i <= N; i++) { 
		// checking if i is prime 
		if (spf[i] == i) { 
			// marking SPF for all numbers divisible by i 
			for (ll j=i*i; j <= N; j+=i) 
				// marking spf[j] if it is not  
				// previously marked 
				if (spf[j]==j) spf[j] = i; 
		} 
	} 
}






int spf[N+5];
bool prime[N+5];
void SieveAndSPF() {
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;

	// marking smallest prime factor for every number to be itself.
	for (int i = 1; i <= N; i++) spf[i] = i;
	
	for(int p=2; p*p<=N; p++) { 
		if (prime[p] == true) {
			for(int i=p*p;i<=N;i+=p) {
				prime[i] = false; 
				spf[i] = min(spf[i], p);
			}
		} 
	}
}
