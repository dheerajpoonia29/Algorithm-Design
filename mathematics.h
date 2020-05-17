+ll gcd(ll x, ll y) {
  return y ? gcd(y, x % y) : x;
}

ll lcm(ll a, ll b)
{
   return a * b / gcd(a, b);
}

/*
m1. O(n) 
m2. O(n/2)
m3. O(sqrt(n))   TRIAL DIVISION METHOD
    if n is not prime than some no a is divide n and we get result b : b=n/a -> a*b = n then over n lies between a & b somewhere
*/
bool checkPrime(int n){
  if(n<=1){
    return false;
  }
  else{
    for(int i=2; i<=sqrt(n); i++){
      if(n%i==0){
        return false;
      }
    }
  }
  return true;
}


/*
m1. O(n*n)
m2. O(n*n/2)
m3. O(n*sqrt(n))
m4. O(n)	SIEVE OF ERATOSTHENES
*/
vector<int> findPrime(int n){
	vector<int> res;
	if(n<2){
		return res;
	}
	else{
		vector<bool> prime(n,true);
		prime[0]=false;
		prime[1]=false;
		for(int i=2; i<=n; i++){
			for(int multiple=i+i; multiple<=n; multiple*=i){
				prime[multiple]=false;
			}
		}
		
		for(int i=1; i<n; i++){
			if(prime[i-1]){
				res.pb(i);
			}
		}

	}
	return res;
}