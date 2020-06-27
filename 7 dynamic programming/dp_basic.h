#include "../macro.h"


// FIBONACCI 
/*
dp: top down 
idea: used previous sub problem result to get the next result 
tc: without memo (2^n)  with memo (n)
*/
// memset(memo, -1, sizeof(memo));  in calling function uncomment this function
int memo[100];
int findFibonacciWithMemo(int n) {
	// base case
  if (n == 0 || n == 1) 
		return n;

	// if n already visited return n
	if(memo[n]!=-1)
		return memo[n];
	else
		// Recursive step
		memo[n] = findFibonacciWithMemo(n-1) + findFibonacciWithMemo(n-2);

	return memo[n];
}


// MUTLISTAGE GRAPH 
/*
problem: https://www.youtube.com/watch?v=9iE9Mj4m8jk&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=47
	- given directed graph with weight
	- reach from source to sink with min cost 
	- preprocessing (bottom to up dp)
	- from sink to backward find cost curr and go on untill we reach source
tc: 
	- O(n^2)
dp formula:
	- l is current level from wich we get min level node and update its cost matrix
	- cost[i,j] = min(c[j,l]+c[l])
*/


// FLOYD WARSHALL - ALL PAIR SHORTEST PATH
/*
problem: https://www.youtube.com/watch?v=oNI0rf2P9gE&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=49
	- generate intermediate vertex and update matrix with this intermediate vertex
	- if 4 vertex and 4 time matrix update 
dp formula:
	- mat_update[i,j] = min{mat_prev[i,j], mat_prev[i,k]+mat_prev[k,j]};
tc: o(n^3) 
	- for1: for generate k matrix 
	- for 2&3 for matrix 
*/


// MATRIX CHAIN MULTIPLICATION 
/*
problem: https://www.youtube.com/watch?v=prx1psByp7U&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=50
	- determine optimum order in which we multiple n matrix so that they take less cost/time
	- brute force exponenetial try multipying all combiantion of matrix and then find which order give list cost 
dp formula:
  - make 2 matrix 
	- cost mat [i,j] =  
	- order mat = 
*/ 


// BELLMAN FORD ALGORITHM - FOR FINDING SINGLE SOURCE SORTEST PATH
/*
problem : https://www.youtube.com/watch?v=FtN3BYH2Zes&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=53
	- problem same as we discuess in dijstrak algorithm 
	- idea also same but dijkstrah uses greedy strategy and bellamn using dp 
	- relaxation vertex
		- d[u]+cost[u,v]<d[v]
			d[v] = d[u]+cost[u,v]
	- relax all vertex no(v) times iteratively
tc:
	- O(n^2)
drawback :
	- if cycle present it not work 
	- if graph is complete tc(n^3)
*/


// 0/1 KNAPSACK 
/*
problem : https://www.youtube.com/watch?v=zRza99HPvkQ&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=55
	- brute force trying all possible combination tc(2^n)
	- tablulation method or dp tc(n^2)
	- dp can apply when
		- solving optimization problem 
		- problem should solve in sequence of dicision
		- try all possible solution and pick best 
dp formula:
	if(wt[i]<=w)
	- dp[i][w] = max(p[i]+dp[i-1][w-w[i]), dp[i-1][w])
	else 
	- dp[i][w] = dp[i-1][w]
*/


// TRAVELLING SALESMAN PROBLEM 
/*
problem : https://www.youtube.com/watch?v=Q4zHb-Swzro


// LONGEST SUBSEQUENCE PROBLEM 
/*

*/


