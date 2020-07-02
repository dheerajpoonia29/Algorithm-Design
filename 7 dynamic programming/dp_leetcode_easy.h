#include "../macro.h"
int memo[9999][9999]; // dp table in case of recursion with memoization
//	memset(memo, -1, sizeof(memo));
int t[100]; // dp table 
int tt[100][100];

// DIVISOR GAME : https://leetcode.com/problems/divisor-game/
class DIVISOR_GAME
{
public:

	
};

// CLIMBING STAIRS : https://leetcode.com/problems/climbing-stairs/
class CLIMBING_STAIRS
{
public:
	/*
		You are climbing a stair case. It takes n steps to reach to the top.
		Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
	*/
	
	// tle : O(2^n)
	int usingRecursion(int n){
		// base case 
            if(n==0)
                return 1;
            if(n<0)
                return 0;
        
        // recursive case 
            return usingRecursion(n-1)+usingRecursion(n-2);                    
	}

	// ac : memoization is super fast O(n) it take 0ms
	int usingRecursionWithMemo(int n){
		// base case 
            if(n==0)
                return 1;
            if(n<0)
                return 0;
        
        // memoization 
            //if(t[n]!=-1)		// wrong
            if(t[n]>0)
                return t[n];
        	
        // recursive case 
            else {
                t[n] = usingRecursionWithMemo(n-1)+usingRecursionWithMemo(n-2);        
                return t[n];
            }
	}

	// ac : O(n) it take 4ms 
	int usingDp(int n){
		// intialization / base case 
		t[0] = 1;
		

		// loop
		for(int i=2; i<=n; i++){	// i=2 because i=1 already filled
			t[i] = t[i-1]+t[i-2];
		}

		return t[n];

	}

	/*
		other approach: https://leetcode.com/problems/climbing-stairs/solution/
			
			so the problem is simply to finding the nth fibonacci number

		approach 1: binets method (logn)
		approach 2: fibonacci formula for finding nth fibonacci number (logn) power function consume time here
					public int climbStairs(int n) {
				        double sqrt5=Math.sqrt(5);
				        double fibn=Math.pow((1+sqrt5)/2,n+1)-Math.pow((1-sqrt5)/2,n+1);
				        return (int)(fibn/sqrt5);
				    }

				    formula drive from eq: a[n] = a[n-1]+a[n-2]
	*/

};




