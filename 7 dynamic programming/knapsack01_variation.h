#include "../macro.h"
int memo[9999][9999]; // dp table in case of recursion with memoization
//	memset(memo, -1, sizeof(memo));

int t[100][100]; // dp table 


// KNAPSACK 0 1 
class KNAPSACK_01{
	public:
	
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
		for(int i=0, j=0; i<=n, j<=n; i++, j++){
			t[i][0] = 0;
			t[0][j] = 0;
		}

		// recursive case  / loop 
		for(int i=1; i<n+1; i++){
			for(int j=1; j<W+1; j++){
				if(wt[i-1]<=W){
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
		if(sum==0)
			return true;
		if(n==0 || sum<0)
			return false;

		// recursive case 
		bool take, not_take;
		if(sum-arr[n-1]>=0){
			return usingRecursive(arr, n-1, sum-arr[n-1]) ^ usingRecursive(arr, n-1, sum);
			// take ^ not_take
		}
		else{
			return usingRecursive(arr, n-1, sum);
		} 
	}
	
	bool usingRecursiveWithMemo(int arr[], int n, int sum){
		// base case 
		if(sum==0)
			return true;
		if(n==0 || sum<0)
			return false;

		// memoization
		if(memo[n][sum]!=-1)
			return memo[n][sum];
		// recursive case 
		else{
			memo[n][sum] = usingRecursive(arr, n-1, sum-arr[n-1]) ^ usingRecursive(arr, n-1, sum);
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
			t[0][j] = false;
		}

		// recursive case  / loop 
		for(int i=1; i<=n; i++){
			for(int j=1; j<=sum; j++){
				if(arr[i-1]<=sum){
					t[i][j] = t[i-1][j-arr[i-1]] ^ t[i-1][j];
				}
				else
					t[i][j] = t[i-1][j];
			}
		}
		
		// result 
		return t[n][sum];
	}

};

// EQUAL SUM PARTITION PROBLEM 
class ESPP{
	/*

	*/
	public:



};