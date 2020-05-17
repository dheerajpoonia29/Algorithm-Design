ll gcd(ll x, ll y) {
  return y ? gcd(y, x % y) : x;
}

ll lcm(ll a, ll b)
{
   return a * b / gcd(a, b);
}

/*
CHECK GIVEN NO IS PRIME OR NOT
n(7) : 1
n(21) : 0
------------------------------
m1. O(n) 
m2. O(n/2) === m1
m3. O(sqrt(n))   TRIAL DIVISION METHOD
    if n is not prime than some no a is divide n and we get result b : b=n/a -> a*b = n then over n lies between a & b somewhere
		(a,b) composite
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
FIND ALL PRIME NUMBER UPTO N
n(20) : 2,3,5,7,11,13,17,19
----------------------------
m1. O(n*n)
m2. O(n*n/2)  === m1
m3. O(n*sqrt(n))
m4. O(n(log(logn))	SIEVE OF ERATOSTHEnES   (doubt: why not O(nlogn) )
m5. O(n) 						OPTIMIZE SIEVE OF ERATOSTHEnES

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

		// here instead of going n we go till sqrt(n) because while reaching n>sqrt(n) we find that all bool value of prime is get false
		
		for(int i=2; i<=sqrt(n); i++){			
			if(prime[i]==true)
				for(int multiple=i+i; multiple<=n; multiple+=i){
					prime[multiple]=false;
				}
		}

		for(int i=0; i<n; i++){
			if(prime[i])
				res.pb(i);
		}
		

		// optimzation of above
		//https://www.geeksforgeeks.org/sieve-eratosthenes-0n-time-complexity/
		/* not working
		vector<int>SPF(1000001);

    for (int i=2; i<n; i++) 
    { 
        if (prime[i]) 
        { 
            res.pb(i); 
  
            SPF[i] = i; 
        } 
  
        
        for (int j=0; j < (int)res.size() && 
             i*res[j] < n && res[j] <= SPF[i]; j++) 
        { 
            res[i*res[j]]=false; 
  
            SPF[i*res[j]] = res[j] ; 
        } 
    } 
		*/
		return res;
	}
	
}


/*
FIND FACTOR OF NUMBER N 
n(12) : 1,2,3,4,6,12
n(17) : 1,17 
-----------------------
m1. O(n)
m2. O(n/2) === m1				
m3. O(sqrt(n))
n(12) : 1,2,3,4,6,12
        a          b
				  a     b
					  a b 
				idea: a*b=n where a,b are factor of n 
				then n lies a & b
				1<=a<=sqrt(n)
				b=n/a
note: finding factor is similar to finding all divior of no
*/
vector<int> findFactor(int n){
	vector<int> res;
	res.pb(1);

	/*
	for(int i=2; i<=sqrt(n); i++){
		int a=i;
		int b=n/a;
		res.pb(a);
		res.pb(b);
		// NOTE: this method not gives us factor in increasing order if sort it then also i will take O(nlogn)>O(sqrt(n))
	}
	*/

	// getting in increasing order
	priority_queue<int, vector<int>, greater<int>> min_pq;
	for(int i=2; i<=sqrt(n); i++){
		int a=i;
		int b=n/a;
		min_pq.push(a);
		min_pq.push(b);
	}

	while(!min_pq.empty()){
		res.pb(min_pq.top());
		min_pq.pop();
	}

	res.pb(n);
	return res;
}


/*
FIND FACTOR OF NUMBER N 
n(12) :  2, 2, 3
n(17) :  17
-----------------------
m1. O(n)	
*/
vector<int> findPrimeFactor(int n){
	vector<int> res;
	if(n<2){
		return res;
	}
	else{

	}
	return res;
}