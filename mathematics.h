#include "macro.h"


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
	m4. O(n(log(logn))	SIEVE OF ERATOSTHEnES   (doubt: why not O(nlogn) )     below implementation
	m5. O(n) 		(not understand till)				OPTIMIZE SIEVE OF ERATOSTHEnES
	--------------------------------------------------
	intially all are true -> prime
	then mark 2 multiple not prime 
	then mark 3 multiple not prime ..... so on 
	--------------------------------------------------
	complexity = n/2, n/3, n/5, n/7 ...
	n/4 is not executed because at here is falsed by 2 
	so t.c = n*(1/2, 1/3, 1/5, 1/7, ...)
	       = n(log(n)) if it constant 1/2 but here we see it keep reducing by -1 
				 = n(log(logn))
	*/
	vector<int> res;
	
	vector<bool> is_prime(n+1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= n; i++) {
		// or instead or doing i*i we also do like i=2; i<=sqrt(n); i++ because when reach i>sqrt(n) we find that is_prime mark to all as false, because every left side has pair present on right side which is also factor
		if (is_prime[i]) {
				for (int j = i * i; j <= n; j += i)
						is_prime[j] = false;
		}
	}

	for(int i=0; i<n+1; i++){
		if(is_prime[i]==true){
			res.pb(i);
		}
	}
	return res;
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
	m2. O(log(logn))
	n/2, n/3, n/5, n/7 ....
	*/
	vector<pair<int,int>> res;    //prime factor, exponent
	if(n<2){
		return res;
	}
	else{
		// 2 is only a even prime number 
		int p=2, exp=0;
		while(n%p==0){
			n/=p;
			exp++;			
		}
		if(exp!=0)
		res.pb(mp(p,exp));

		// rest all are prime are odd i+=2
		for(p=3; p*p<=n; p+=2){	// either p<=sqrt(n)
			exp=0;
			while(n%p==0){
				n/=p;
				exp++;
			}
			if(exp!=0)
			res.pb(mp(p,exp));
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


//	FIND GCD (GREATEST COMMON DIVISOR/FACTOR)

int findGcd(int a, int b){
	/*
	a(3) : ->1
	b(5) : ->1

	a(4)	:	1	2	->4
	a(16)	: 1	2	->4	16	

	a(12)	:	1	2	3	->4	6	12
	a(16)	: 1	2	->4	8	16	

	a(0)	: 0%5=0 there 5 is the greatest divisor which divide both 0 & 5
	a(5)	: ->5 15
	* n with 0 => n 
	* n with 1 => 1

	Follows from the definitions of coprime and greatest common divisor as follows.

    gcd{n,1}=1
    gcd{n,0}=n

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

ll findFastExp(int base, int exp, int modulo){
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
					res = (res*base)%modulo;
			}
			base = (base*base)%modulo;
			exp = exp>>1;
	}
	return res;
}


//USING STANDARD LIBRARY  #include <algorithm.h>
// gcd = __gcd(a,b);
// lcm = a*b/__gcd(a,b);

template<class T>
T gcd(T x, T y) {
	// EUCLINDEAN ALGORITHM
	// https://codility.com/media/train/10-Gcd.pdf
  return y ? gcd(y, x % y) : x;
}

template<class T>
T lcm(T a, T b)
{
   return a * b / __gcd(a, b);
}


// FIND FACTORIAL

int findFactorial(int n){
	if(n==1 || n==0){
		return 1;
	}
	return n*findFactorial(n-1)%mod;
} 


// FIND SQUARE 

vector<pair<int,int>> findSquare(int n){
	vector<pair<int,int>> res;
	for(int i=1; i<=n; i++){
		res.pb(mp(i,i*i));
	}
	return res;
}


// NTH TERM OF FIBONACCI SEQUENCE
float findFibNTerm(float n){
	/*
	xn = (φ^n − (1−φ)^n) / √5
	*/
	float t = 1.618034;
	return (pow(t,n)-pow((1-t),n))/sqrt(5);
}