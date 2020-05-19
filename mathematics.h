// CHECK GIVEN NO IS PRIME OR NOT

bool checkPrime(int n){
	/*
	n(7) : 1
	n(21) : 0
	------------------------------
	m1. O(n) 
	m2. O(n/2) === m1
	m3. O(sqrt(n))   TRIAL DIVISION METHOD
			if n is not prime than some no a is divide n and we get result b : b=n/a -> a*b = n then over n lies between a & b somewhere
			(a,b) composite
	*/
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


// NEXT PRIME NUMBER FROM GIVEN NUMBER

int nextPrime(int n){
	while(!checkPrime(++n));
	return n;
}


// FIND ALL PRIME NUMBER UPTO N

vector<int> findPrime(int n){
	/*
	n(20) : 2,3,5,7,11,13,17,19
	----------------------------
	m1. O(n*n)
	m2. O(n*n/2)  === m1
	m3. O(n*sqrt(n))
	m4. O(n(log(logn))	SIEVE OF ERATOSTHEnES   (doubt: why not O(nlogn) )
	m5. O(n) 						OPTIMIZE SIEVE OF ERATOSTHEnES
	*/
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
		/* not understand : TODO
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


// FIND FACTOR OF NUMBER N 

vector<int> findFactor(int n){
	/*
	Factor of a number 'n' is a number a such that a divides n.
	That is, N % d == 0.

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
	vector<int> res;
	if(n<1)	return res;
	res.pb(1);
	if(n==1)	return res;

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
	int a=0;
	for(int i=2; i<=sqrt(n); i++){
		if(n%i==0){
			min_pq.push(i);
			if(i!=n/i)
				min_pq.push(n/i);
		}
	}

	while(!min_pq.empty()){
		res.pb(min_pq.top());
		min_pq.pop();
	}

	res.pb(n);
	return res;
}


// FIND FACTOR OF NUMBER N 

vector<pair<int,int>> findPrimeFactor(int n){
	/*
	n(12) :  2, 2, 3
	n(17) :  17
	-----------------------
	m1. O(n)	
	m2. O(sqrt(n))
	*/
	vector<pair<int,int>> res;    //prime factor, exponent
	if(n<2){
		return res;
	}
	else{
		/*
		int a=2;
		int b = 0;
		int rem;

		while(b!=1){
			b = n/a;
			rem = n%a;
			if(rem==0){
				res.pb(a);
				n=b;
			}
			else{
				a = nextPrime(a);      //O(n)
				b=0;
			}
		}
		*/
		for(int i=2; i<=sqrt(n); i++){
			if(n%i==0){
				int exp=0;
				while(n%i==0){
					exp+=1;
					n/=i;
				}
				res.pb(mp(i,exp));
			}
		}
		// special case
		if(n!=1)	res.pb(mp(n,1));
	}
	return res;
}


//	FIND LCM (LONGEST COMMON MULTIPLE)

int findLcm(int a, int b){
	/*
	a(3) :	3	6	9	12	->15 
	b(5) :	5	10	->15

	a(2) :	2	4	6	10	12	->14	16	18	20
	a(7) :	7	->14	21	28	35	42	49	56	63	70
	----------------------------------------------
	m1. O(max(a,b))
	*/
	if(a>b)	swap(a,b);

	int res=b;
	while(res%a!=0){
		res = res+b;
	}
	return res;
}


//	FIND GCD (GREATEST COMMON DIVISOR)

int findGcd(int a, int b){
	/*
	a(3) : ->1
	b(5) : ->1

	a(4)	:	1	2	->4
	a(16)	: 1	2	->4	16	

	a(12)	:	1	2	3	->4	6	12
	a(16)	: 1	2	->4	8	16	
	---------------------------------
	m1. O(min(a,b))
	*/
	if(a>b)	swap(a,b);

	int res=0;
	int divisor = 2;
	while(divisor<=a){
		if(a%divisor==0 && b%divisor==0){
			res = divisor;
		}
		divisor+=1;
	}

	if(res>a){
		return 1;
	}
	return res;
}


// FIND FAST MOD EXPONENTIATION

ll findFastExp(int base, int exp, int mod){
	/*
	m1. O(exp)   (note: it will raise tle for large value of exp)
	m2. O(log(exp)) 		(using bitmasking)
	idea: 
		3^5 = 3*3^4 = 3*3*3^3 and so on
		  bin(5) =	1		0		1
								3^4	3^2	3
							
								addition result where we have set bit and 
								every time we goes toward left shift sqaure
								the current exponent

	----------------------------------------------------------
	int base = 3;
	int exp = 10;
	int res = 1;
	for(int i = 1; i <= exp; i++)
	{
		res *= base;
	}
	*/
	ll res = 1;
	while(exp>0){
			if(exp&1){
					res = (res*base)%mod;
			}
			base = (base*base)%mod;
			exp = exp>>1;
	}
	return res;
}


//USING STANDARD LIBRARY

ll gcd(ll x, ll y) {
  return y ? gcd(y, x % y) : x;
}

ll lcm(ll a, ll b)
{
   return a * b / gcd(a, b);
}