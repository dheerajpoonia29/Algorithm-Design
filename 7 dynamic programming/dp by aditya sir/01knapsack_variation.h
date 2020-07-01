#include "../macro.h"
int memo[9999][9999]; // dp table in case of recursion with memoization
//	memset(memo, -1, sizeof(memo));

int t[100][100]; // dp table 


// KNAPSACK 0 1 
class KNAPSACK_01{
	
	/*
	wt[] = {1, 3, 4, 5};
	val[] = {1, 4, 5, 2};
	W = 7;
	n = 4;
	=> max_profit = (4+5) 9; knapsack{{3:4}, {4:5}}
	*/
	public:
	
	// recursion with overlap subproblem
	int usingRecursive(int wa[], int va[], int n, int W){
		// base case 
		if(n==0 || W==0){
			return 0;
		}

		// recursive case 
		if(wa[n-1]<=W){
			return max(	
								va[n-1] + usingRecursive(wa, va, n-1, W-wa[n-1]) , 
								0 + usingRecursive(wa, va, n-1, W) 
							);
		}
		else
			return usingRecursive(wa, va, n-1, W);
	}

	// bottom up dp
	int usingRecursiveWithMemo(int wa[], int va[], int n, int W){
		// base case 
		if(n==0 || W==0){
			return 0;
		}

		// memoization
		if(memo[n][W]!=-1){
			return memo[n][W];
		}
		// recursive case 
		else{
			if(wa[n-1]<=W){
				memo[n][W] = max(	
									va[n-1] + usingRecursive(wa, va, n-1, W-wa[n-1]) , 
									0 + usingRecursive(wa, va, n-1, W) 
								);
			}
			else
				memo[n][W] = usingRecursive(wa, va, n-1, W);
			return memo[n][W];
		}		
	}

	// top down dp 
	int usingDp(int wt[], int val[], int n, int W){
		// int t[n+1][W+1]

		// base case / intialization 
		for(int i=0; i<=n; i++){
			t[i][0] = 0;
		}
		for(int j=0; j<=W; j++){
			t[0][j] = 0;
		}

		// recursive case  / loop 
		for(int i=1; i<n+1; i++){
			for(int j=1; j<W+1; j++){
				if(wt[i-1]<=j){
					t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]], t[i-1][j]);
				}
				else
					t[i][j] = t[i-1][j];
			}
		}
		
		// result 
		return t[n][W];
	}
};


// --------------------------- 6 VARIANT OF KNAPSACK ---------------------------

// SUBSET SUM PROBLEM 
class SSP{
	/*
	[2,3,7,8,10] sum = 11 => yes present {3,8}
	[2,3,7,8,10] sum = 14 => no
	*/
	public:
	
	bool usingRecursive(int arr[], int n, int sum){
		// base case 
		if(n==0 && sum!=0)		//note! here || lead to wrong ans 
			return false;
		if(sum==0)
			return true;		

		// recursive case 
		if(arr[n-1]>sum){
			return usingRecursive(arr, n-1, sum);
		}
		else{
			return usingRecursive(arr, n-1, sum-arr[n-1]) || usingRecursive(arr, n-1, sum);
			// choice: either take | or not_take
		} 
	}
	
	bool usingRecursiveWithMemo(int arr[], int n, int sum){
		// base case 
		if(sum==0)
			return true;
		if(n==0 && sum<0)
			return false;

		// memoization
		if(memo[n][sum]!=-1)
			return memo[n][sum];
		// recursive case 
		else{
			memo[n][sum] = usingRecursive(arr, n-1, sum-arr[n-1]) || usingRecursive(arr, n-1, sum);
			return memo[n][sum];
		}
	}

	// wrong ans : to-do
	bool usingBacktracking(int arr[], int n, int sum){
		// base case 
		if(sum==0)
			return true; 
		if(n==0 || sum<0)
			return false;

		int kyaNextKoIncludeKrPaenge = usingBacktracking(arr, n-1, sum-arr[n-1]);
		if(kyaNextKoIncludeKrPaenge){
			return true;
		}
		return false;		// usingBacktracking
	}

	bool usingDp(int arr[], int n, int sum){
		// int t[n+1][sum+1]

		// intialization / base case 
		for(int i=0, j=0; i<=n, j<=sum; i++, j++){
			t[i][0] = true;
			if(j!=0) // :-) care about that nob
				t[0][j] = false;
		}

		// recursive case  / loop 
		for(int i=1; i<=n; i++){
			for(int j=1; j<=sum; j++){
				if(arr[i-1]>j){
					t[i][j] = t[i-1][j];
				}else{
					t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
				}					
			}
		}
		
		// result 
		return t[n][sum];
	}

};


// EQUAL SUM PARTITION PROBLEM 
class ESPP : public SSP{
	/*
	[1,5,11,5] sum=11, => yes {1,5,5}, {11}
	[1,5,11,5] sum=10  => false 

	idea: child of ssp 
		* my approach
			- espp state that find 2 subset with given sum 
			- if ssp return cnt=2 on true
			- else false
			- this approach is failed when sum=5 then it return true but actual ans is false 
			- since question ask to partition complete array not sub array 
		* aditay sir approach 
			- take sum of whole array	
			- if sum is odd so it impossible to separate {21 n+m where n||m is odd}
			- else 
				- ssp(arr, n, sum/2)
	*/
	public:

	int usingDp(int arr[], int n){
		int sum=0, i=0;

		ff(i,n){
			sum += arr[i];
		}

		if(sum%2!=0){
			return false;
		}
		else{
			SSP::usingDp(arr, n, sum/2);

			pxyz(sum, sum/2, t[n][sum/2]);

			return t[n][sum/2];
		}
	}

};


// COUNT OF SUBSET WITH GIVEN SUM 
class COSWGS : public SSP{
	/*
	[2, 3, 5 ,6, 8, 10] sum=10 => {2,3,5}, {2,8}, {10} ans(3)
	*/
	public:

	int usingDp(int arr[], int n, int sum){
		// int t[n+1][sum+1]

		// intialization / base case 
		for(int i=0, j=0; i<=n, j<=sum; i++, j++){
			t[i][0] = 1;
			if(j!=0) // :-) care about that nob
				t[0][j] = 0;
		}

		// recursive case  / loop 
		for(int i=1; i<=n; i++){
			for(int j=1; j<=sum; j++){
				if(arr[i-1]>j){
					t[i][j] = t[i-1][j];
				}else{
					t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
				}					
			}
		}
		
		// result 
		return t[n][sum];
	}

};


// *imp* MINIMUM SUBSET SUM DIFFERENCE 
class MSSD : public SSP{
	/*
	this question show sometime code of recusion is much harder and dp is much easy
	partition array in two subset then difference of these two subset is minimum
	[1, 6, 11, 5] => {1,6}-{11,5} diff = 9
	 							=> {1,6,5}-{11} diff = 1 o/p

	[1, 2, 7] => {1,2}-{7} diff = 4 o/p
	*/
	public:
	
	/*
		*my approach 1: greedy approach
			-[1,6,11,5] sort -> [1,5,6,11]
			-find prefix sum -> [1,6,12,23]
			-applying greedy	
				- {1,5,6}[12] : {11}[11]  12-11=1
				- {1,5}[6] : {6,11}[17] 17-6=11
				-	so on 
				- ans = 1
			- wrong approach 
				- given to find subset if we change order then we unalbe to find correct subset 
		*my approach 2: binary search + dp 
			- sum = arr 
			- bs(s,sum) then s, rem=sum-s possible with espp(s) && espp(rem)
		*dp :
			- totalSum = sigma(arr) 
			- if we divide array in equal part then left side we have s1 and right side we have s2 
			- s1 = 1 to totalSum/2 
			- s2 = totalSum - s1 
			- given minimize s2-s1 which we also write like this (totalSum-s1)-s1 => totalSum-2*s1
			- other good obervation is 
				- s1 never cross totalSum/2 value because we need to take minimize diff 
			- so first if we make t table using "SUBSET SUM PROBLEM" on sum=totalSum then on the last row 
			- where row=4 it mean we consider all array participation then on last col=totalSum 
			- in between we have to find s1, s2 where we know that s1<=totalSum/2 and s2=totalSum-2*s1 
			- then we just extract the j (curr sum) in vector v, value on that curr sum t[i][j]==true which mean that on [i][j] {i=4, j=sum} we have 2 subset in array = true 
			- after extract each j value in separate array, we mn = min(mn, totalSum-2*)
	*/

	int usingDp(int arr[], int n){
		int total_sum = 0;
		
		for(int i=0; i<n; i++){
			total_sum += arr[i];
		}

		SSP::usingDp(arr, n, total_sum);
		
		//paMat(t, n+1, total_sum+1);

		vi possible_subset_partition_sum;
		for(int j=1; j<=total_sum/2; j++){
			if(t[n][j]==true){
				possible_subset_partition_sum.pb(j);
			}
		}

		int min_subset_partition_sum = INT_MAX;

		for(auto s1: possible_subset_partition_sum){
			int s2 = total_sum - s1;
			min_subset_partition_sum = min(min_subset_partition_sum, s2 - s1);
		}

		return min_subset_partition_sum;
	}

};


// COUNT NO OF SUBSET WITH GIVEN DIFFERENCE 
class CNOSWGD : public COSWGS{
	/*
	[1, 1, 2, 3] given_diff = 1 
	ask: find 2 subset s1 & s2 where sum(s1)-sum(s2) = given_diff, constraint s1+s2 = arr complete
	o/p: 
			[1,1,2,3] => {1,3}-{1,2} = 1
								=> {1,3}-{1,2} = 1 *note here 1 are interchange where i!=j 
								=> {1,1,2}-{3} = 1
								=> o/p = 3 such pair of subset which give difference = 1 								
	*/
	public:

	/*
		*idea
			- sum(s1)-sum(s2) = given_diff -> eq1
			- sum(s1)+sum(s2) = sum(arr)	 -> eq2 
			- eq1 + eq2 
			-	2sum(s1) = given_diff + sum(arr)

		*what we have 
			- 2sum(s1) = given_diff + sum(arr)
			- what is known = given_diff=1, sum(arr)=7 
			- find sum(s1) = ( given_diff + sum(arr) )/ 2
			-							 = ( 1 + 7)/2
										 = 4 
			- to count of 2 subset s1,s2 at given condition sum(s1)-sum(s2)=1 we must have sum(s1)=4 
			- so sum(s1)=4 then sum(s2) = sum(s1) - given_diff	
			-														= 4 - 1 
																	= 3 
			- if we observe above o/p subset so sum(s1)=4 & sum(s2)=3 always 

		*how to know which parent problem it is inherit from 
			- know the question is how many subset we have with sum equal to either 4 or 3 
			- COSWGS "count of subset with given sum"
	*/

	int usingDp(int arr[], int n, int given_diff){
		int s1=0, s2=0, total_sum=0;
		
		for(int i=0; i<n; i++)
			total_sum += arr[i];

		s1 = (given_diff+total_sum)/2;
		
		COSWGS::usingDp(arr, n, s1);

		return t[n][s1];
	}

};


// *imp* TARGET SUM 
class TS : public CNOSWGD{
	/*
	[1,1,2,3] , target_sum = 1 
	by addition +,- with each ele of array how many combination of expression it form 
	so that we evaluate  the expression result equal to target_sum
	*/
	public:

	/*
		sign[1] = +
		sign[0] = -
	*/

	int usingRecursive(int arr[], int sign[], int j, int n, int target_sum){
		// base case 
		if(j==0){
			// evaluate 
			int res = 0;
			for(int i=0; i<n; i++){
				if(sign[i]==1)
					res += arr[i];
				else 
					res -= arr[i];
			}

			if(res == target_sum)
				return 1;
			
			else 
				return 0;
		}

		// recursive case 
		int res1=0, res2=0;
		sign[j] = 1;
			res1 = usingRecursive(arr, sign, j-1, n, target_sum);
		sign[j] = 0;
			res2 = usingRecursive(arr, sign, j-1, n, target_sum);
		return res1 + res2;
	}

	int usingDp(int arr[], int n, int target_sum){
		CNOSWGD::usingDp(arr, n, target_sum);

		return t[n][target_sum];		// mind blowing; parent->child->* child problem 
	}

};



//----------------------------------------------------------------------------------
/*
	int wa[] = {1, 3, 4, 5};
	int va[] = {1, 4, 5, 2};
	int W = 7;
	int n = 4;

	KNAPSACK_01 obj;
	px(obj.usingRecursive(wa, va, n, W));	
	px(obj.usingRecursiveWithMemo(wa, va, n, W));
	px(obj.usingDp(wa, va, n, W));
*/

/*
	int arr[] = {2,3,7,8,10};
	int n = 5, sum = 12;

	SSP obj;
	px(obj.usingRecursive(arr, n, sum));
	px(obj.usingRecursiveWithMemo(arr, n, sum));
	px(obj.usingDp(arr, n, sum));
*/

/*
	int arr[] = {1, 5, 11, 5};
	int n = 4;

	ESPP obj;
	px(obj.usingDp(arr, n));
*/

/*
	int arr[] = {2, 3, 5 ,6, 8, 10};
	int n = 6, sum=10;

	COSWGS obj;
	px(obj.usingDp(arr, n, sum));
*/

/*
	int arr[] = {1, 2, 7};
	int n = 3;

	MSSD obj;
	px(obj.usingDp(arr, n));
*/


/*
	int arr[] = {1,1,2,3};
	int n = 4, diff = 1;

	CNOSWGD obj;
	px(obj.usingDp(arr, n, diff));
*/


/*
	int arr[] = {1,1,2,3};
	int n = 4, target_sum = 1;

	TS obj;
	int sign[] = {0, 0, 0, 0};
	px(obj.usingRecursive(arr, sign, n, n, target_sum));
	px(obj.usingDp(arr, n, target_sum));
*/