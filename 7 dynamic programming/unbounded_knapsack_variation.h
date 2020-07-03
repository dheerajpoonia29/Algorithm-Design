#include "../macro.h"
int memo[9999][9999]; // dp table in case of recursion with memoization
//	memset(memo, -1, sizeof(memo));

int t[100][100]; // dp table 


// KNAPSACK 0 1 
class UNBOUNDED_KNAPSACK{
	/*
	*/
	public:

		int usingRecursive(int wa[], int va[], int n, int W){
			// base case 
			if(n==0 || W==0){
				return 0;
			}

			// recursive case 
			if(wa[n-1]<=W){
				return max(	
									// donot move to previous (for more insight look into 0/1 knapsack choice diagram)
									//va[n-1] + usingRecursive(wa, va, n-1, W-wa[n-1]) , 
									va[n-1] + usingRecursive(wa, va, n, W-wa[n-1]) , 
									0 + usingRecursive(wa, va, n-1, W) 
								);
			}
			else
				return usingRecursive(wa, va, n-1, W);
		}
		
		int usingDp(int length[], int price[], int n, int W){
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
					if(length[i-1]<=j){
						//t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]], t[i-1][j]);
						t[i][j] = max(price[i-1] + t[i][j-length[i-1]], t[i-1][j]);
					}
					else
						t[i][j] = t[i-1][j];
				}
			}
			
			// result 
			return t[n][W];
		}
};

// base case
			if (n == 0)
					return 0;
	
			int maxValue = INT_MIN;
	
			// one by one partition the given rod of length n into two parts
			// of length (1, n-1), (2, n-2), (3, n-3), .... (n-1 , 1), (n, 0)
			// and take maximum
			for (int i = 1; i <= n; i++)
			{
					// rod of length i has a cost price[i-1]
					int cost = price[i - 1] + usingRecursive(length, price, n - i);
	
					if (cost > maxValue)
							maxValue = cost;
			}
	
			return maxValue;
//	ROD CUTTING PROBLEM 
class ROD_CUTTING_PROBLEM{
	/*
	rod length = 8
	length of each possible piece = {1,2,3,4,5,6,7,8};
	price of each possible piece = {1,5,8,9,10,12,17,20};	
	o/p profit=> 21

	int length[] = { 1, 2, 3, 4};    
  int price[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
  int n = 4; // rod length
	o/p profit=> 10

	note: some time length array is not given so make it 1-n
	*/
	public:

		// *imp* do it yourself => todo
		int usingRecursive(int length[], int price[], int n){
			// base case
			if (n == 0)
					return 0;
	
			int maxValue = INT_MIN;
	
			// one by one partition the given rod of length n into two parts
			// of length (1, n-1), (2, n-2), (3, n-3), .... (n-1 , 1), (n, 0)
			// and take maximum
			for (int i = 1; i <= n; i++)
			{
					// rod of length i has a cost price[i-1]
					int cost = price[i - 1] + usingRecursive(length, price, n - i);
	
					if (cost > maxValue)
							maxValue = cost;
			}
	
			return maxValue;
		}

		// top down dp 
		int usingDp(int length[], int price[], int n){
			// int t[n+1][W+1]

			// base case / intialization 
			for(int i=0, j=0; i<=n, j<=n; i++, j++){
				t[i][0] = 0;
				t[0][j] = 0;
			}

			// recursive case  / loop 
			for(int i=1; i<n+1; i++){
				for(int j=1; j<n+1; j++){
					if(length[i-1]<=j){
						t[i][j] = max(price[i-1] + t[i][j-length[i-1]], t[i-1][j]);
					}
					else
						t[i][j] = t[i-1][j];
				}
			}
			
			// result 
			return t[n][n];
			// note: for [n][n] watch video again 17:00
		}

};


//	COIN CHANGE PROBLEM : MAXIMUM NUMBER OF WAYS
class MAXIMUM_NUMBER_OF_WAYS_FOR_COIN_CHANGE{
	/*
		coin [1,2,3] having infinite no of supply 
		price = 5 
		ask: how many no of way to make price using coin array 
		
			2+3 = 5
			1+2+2 = 5
			1+1+3 = 5
			1+1+1+1+1 = 5
			1+1+1+2 = 5
		
		o/p 5 ways
	*/
	public:

		// choice diagram / recursive tree : https://www.youtube.com/watch?v=hQIGPCoVtH0 (4:23)
		int usingRecursive(int coin[], int n, int curr, int target){
			// base case 
			if(n==0)
				return 0;
			if(curr==target)
				return 1;
			if(curr>target)
				return 0;

			// recursive case 
			return usingRecursive(coin, n, curr+coin[n-1], target) + usingRecursive(coin, n-1, curr, target);
		}

		int usingRecursiveWithMemo(int coin[], int n, int curr, int target){
			// base case 
			if(n==0)
				return 0;
			if(curr==target)
				return 1;
			if(curr>target)
				return 0;

			// memoization 
			if(memo[n][curr]!=-1)
				return memo[n][curr];
			else{ 
				// recursive case 
				memo[n][curr] = usingRecursive(coin, n, curr+coin[n-1], target) + usingRecursive(coin, n-1, curr, target);
				return memo[n][curr];
			}
		}

		int usingDp(int coin[], int n, int target){
			// int t[n+1][W+1]

			// base case / intialization 
			for(int i=0; i<=n; i++){
				t[i][0] = 0;
			}
			for(int j=0; j<=target; j++){
				t[0][j] = 0;
			}

			// recursive case  / loop 
			for(int i=1; i<n+1; i++){
				for(int j=1; j<target+1; j++){
					if(coin[i-1]<=j){
						//t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]], t[i-1][j]);
						t[i][j] = max(coin[i-1] + t[i][j-coin[i-1]], t[i-1][j]);
					}
					else
						t[i][j] = t[i-1][j];
				}
			}
			
			// result 
			return t[n][target];
		}

};


// *imp*	COIN CHANGE PROBLEM : MINIMUM NUMBER OF WAYS
// must do it again <not understand, wa>
class MINIMUM_NO_OF_COIN_FOR_COIN_CHANGE{
	/*
		coin [1,2,3] having infinite no of supply 
		price = 5 
		ask: how many no of way to make price using coin array 
		
			2+3 = 5 (2 coin)
			1+2+2 = 5	(3 coin)
			1+1+3 = 5 (3  coin)
			1+1+1+1+1 = 5	(5 coin)
			1+1+1+2 = 5	(4 coin)
		
		o/p 2 ways
	*/
	public:

		int usingRecursive(int coin[], int n, int curr, int target, int cnt_coin){
			// base case 
			if(n==0)
				return INT_MAX-1;
			if(curr==target)
				return cnt_coin;
			if(curr>target)
				return INT_MAX-1;

			// recursive case 
			return min(usingRecursive(coin, n, curr+coin[n-1], target, cnt_coin+1), usingRecursive(coin, n-1, curr, target, cnt_coin+1));
		}
		
		int usingDp(int coin[], int n, int target){
			// int t[n+1][W+1]

			// base case / intialization 
			for(int i=0; i<=n; i++){
				t[i][0] = 0;
			}
			for(int j=0; j<=target; j++){
				t[0][j] = INT_MAX-1;		// NOTE! INT_MAX-1 is mandatory because when we do INT_MAX+1 int dp table then it overlow and became -1 
			}
			for(int j=1; j<=target; j++){
				if(j%coin[0]==0){
					t[1][j] = j/coin[0];
				}
				else{
					t[1][j] = INT_MAX - 1;
				}
			}

			// recursive case  / loop 
			for(int i=2; i<n+1; i++){
				for(int j=1; j<target+1; j++){				
					if(coin[i-1]<=j){
						//t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]], t[i-1][j]);
						t[i][j] = min(1 + t[i][j-coin[i-1]], t[i-1][j]);
					}
					else
						t[i][j] = t[i-1][j];
				}
			}
			
			// result 
			return t[n][target];
		}
	
};



//--------------------------------------------------------------------------------------

//	memset(memo, -1, sizeof(memo));

/*
	int length[] = { 1, 2, 3, 4};    
  int price[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
  int n = 2;

	ROD_CUTTING_PROBLEM obj;
	px(obj.usingRecursive(length, price, n));
	px(obj.usingDp(length, price, n));
*/


/*
	int coin[] = {1, 2, 3};
	int amount = 5;

	MAXIMUM_NUMBER_OF_WAYS_FOR_COIN_CHANGE obj;
	px(obj.usingRecursive(coin, 3, 0, amount));
	px(obj.usingRecursiveWithMemo(coin, 3, 0, amount));
	px(obj.usingDp(coin, 3, amount));
/*/


/*
	int coin[] = {1, 2, 3};
	int amount = 20, cnt_coin = -1, n = 3, curr = 0;

	MINIMUM_NO_OF_COIN_FOR_COIN_CHANGE obj;
	px(obj.usingRecursive(coin, n, curr, amount, cnt_coin));
	px(obj.usingDp(coin, n, amount));
*/	
