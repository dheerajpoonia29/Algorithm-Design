// https://magoosh.zendesk.com/hc/en-us/articles/203445059--Odd-sum-even-sum-Can-we-use-the-sum-of-sequences-formula-


// SUM OF NATURAL NUMBER IN GIVEN RANGE [L-R]
int sumNatural(int n) 
{ 
    int sum = (n * (n + 1)) / 2; 
    return sum; 
} 
int suminRange(int l, int r) 
{ 
    return sumNatural(r) - sumNatural(l - 1); 
} 


// SUM OF ODD NATURAL NUMBER IN GIVEN RANGE [L-R]
int sumOdd(int n) 
{ 
    int terms = (n + 1) / 2; 
    int sum = terms * terms; 
    return sum; 
} 
int suminRange(int l, int r) 
{ 
    return sumOdd(r) - sumOdd(l - 1); 
/*
other approach: 
For the odd numbers,

61(61 + 1)/2
61(62)/2
61(31) 
1,891 total sum upto n 

Subtract out the even sum, 930(using below 2n approach), and we're left with an odd sum of 1,891 - 930 = 96
*/
}


// SUM OF EVEN NATRUAL NUMBER IN GIVEN RANGE [L-R]
nt sumEven(int n) 
{ 
    int sum = (n * (n + 1)); 
    return sum; 
} 
int suminRange(int l, int r) 
{ 
    return sumEven(r/2) - sumEven((l-1) / 2); 
/*
or other approach
sum of the first 30 positive even integers would be 2 * (1 + 2 + 3 + 4 + ... + 30). Using the formula, we can work that out:
2 * 30(30 + 1)/2
30(30 + 1)
30(31)
930
*/
} 
   

// DSA CHALLENGE JUNE - HACKEREARTH
// QUESTION: ODD DIVISOR
/*
given number n find the sum of greatest odd divisor/factor of number from 1 to n 
mm: tc(n) sc(n) 
	* approach dp 
	* iterate i from 1 to n 
		* best case i is odd, odd is having greatest odd divisor iteself 
		* when i even then lock for the ans at i/2 it is odd then good it is not odd then look i/2 and so on till i/2 is odd 
ba: tc(nlogn) sc(1) 
	* mm failed because given n containt are 10^18
	* code - to understand 
		cin >> N;
		long long sum = 0;
		while(N){
				sum = (sum + sqr(N / 2 + N % 2)) % M;
				N /= 2;
		}
		cout << sum << '\n';
*/
void do_it(){
	long long int n,m; cin>>n;
	int dp[n+1];
	for(int i=1;i<=n;i++){
		if(i%2!=0)
		dp[i] = i;
		else
		dp[i] = dp[i/2];
	}
	
	long long int sum=0;
	for(int i=1;i<=n;i++){
		sum+=dp[i];
	}
	cout<<sum<<"\n";
}