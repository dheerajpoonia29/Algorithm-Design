#include "../macro.h"
int memo[9999][9999]; // note: also called dp table 


// LONGEST COMMON SUBSEQUENCE 
/*
longest common sub _ sequence
ABCDGHXYZ, ABEDFHR => ABDH (4)
*/
class LCS_SEQ{
	int t[100][100]; 	// dp table we called it t table 
	public:
	
	 
	//	RECURSIVE => OVERLAP SUB-PROBLEM
	// 	doubt! it is possible to print lcs using recursive (i try but failed :-)
	int	usingRecursive(string a, string b, string &lcs, int n, int m){
		// base case 
		if(n==0 || m==0)
			return 0;

		if(a[n-1]==b[m-1]){
			//pxyz("*", a, b);
			//lcs += a[n];					!doubt: it is storing all match			

			// recursive case 
			return 1+usingRecursive(a, b, lcs, n-1, m-1);			
		}

		else{
			//pxy(a, b);

			// recursive case 			
			return max(usingRecursive(a, b, lcs, n-1, m) ,usingRecursive(a, b, lcs, n, m-1));
		}
	}

	// RECURSIVE WITH MEMO (DP WITH MEMO) => BOTTOM UP DP	
	//	doubt! wrong ans
	int usingRecursiveWithMemo(string a, string b, int n, int m){
		// base case 
		if(n==0 || m==0)
			return 0;

		if(memo[n][m]!=-1){
			return memo[n][m];
		}

		else{
			if(a[n-1]==b[m-1]){
				// recursive case 
				memo[n][m] = 1+usingRecursiveWithMemo(a, b, n-1, m-1);			
			}

			else{
				// recursive case
				memo[n][m] =  max(usingRecursiveWithMemo(a, b, n-1, m) ,usingRecursiveWithMemo(a, b, n, m-1));
			}
		}

		return memo[n][m];
		//unordered_map<string, int> memo; //note: always make memo with variable varing so below n,m are changing 
		//int memo[n+1][m+1] originally [n+1][m+1]		
		//memset(memo, -1, sizeof(memo));
	}

	// DP (omit recursive call why? stack overflow - very rare) => TOP DOWN DP
	int usingDp(string a, string b){
		int n = a.size(), m = b.size();		
		// int t[n+1][m+1]

		// base case / intialization 
		for(int i=0, j=0; i<=n, j<=m; i++, j++){
			t[i][0] = 0;
			t[0][j] = 0;
		}

		// recursive case  / loop 
		for(int i=1; i<n+1; i++){
			for(int j=1; j<m+1; j++){
				if(a[i-1]==b[j-1])
					t[i][j] = 1+t[i-1][j-1];
				else
					t[i][j] = max(t[i-1][j], t[i][j-1]);
			}
		}
		
		// result 
		return t[n][m];
	}

	string printLcs(string a, string b){
		string lcs = "";
		int n = a.size(), m = b.size();

		//paMat(t, n+1, m+1);
		
		while(n>0){
			while(m>0){
				if(a[n-1]==b[m-1]){
					lcs += a[n-1];
					n--; m--;
				}
				else{
					if(t[n][m-1]==t[n][m])	
						m-=1;
					else
						n-=1;
				}
			}
		}
		reverse(lcs.begin(), lcs.end());

		return lcs;
	}
};



// LONGEST COMMON SUBSTRING 
/*
"X1234YMN", "MNABCXY1234" => commn ("1234", "MN") longest ("1234":4)
longest common sub _ string
*/
class LCS_STR{
	int t[100][100];
	public: 
	
	//	RECURSIVE => OVERLAP SUB-PROBLEM
	int	usingRecursive(string a, string b, int n, int m, int len){
		if(n==0 || m==0)
			return len;

		
		if(a[n-1]==b[m-1]){
			len += 1;
			return usingRecursive(a, b, n-1, m-1, len);
		}

		return max(len, max(usingRecursive(a, b, n-1, m, 0), usingRecursive(a, b, n, m-1, 0)));		
	}

	// RECURSIVE WITH MEMO (DP WITH MEMO) => BOTTOM UP DP	
	int usingRecursiveWithMemo(string a, string b, int n, int m, int len){
		if(n==0 || m==0)
			return len;

		if(memo[n][m]!=-1){
			return memo[n][m];
		}

		if(a[n-1]==b[n-1]){
			len += 1;
			memo[n][m] = usingRecursiveWithMemo(a, b, n-1, m-1, len);
		}
		else
		 	memo[n][m] = max(len, max(usingRecursiveWithMemo(a, b, n-1, m, 0), usingRecursiveWithMemo(a, b, n, m-1, 0)));		
			
		return memo[n][m];
	}

	// DP (omit recursive call why? stack overflow - very rare) => TOP DOWN DP
	int usingDp(string a, string b){
		int n = a.size(), m = b.size(), res=0;
		//int t[n+1][m+1]; 	// dp table we called it t table 

		// base case / intialization 
		for(int i=0, j=0; i<=n, j<=m; i++, j++){
			t[i][0] = 0;
			t[0][j] = 0;
		}

		// recursive case  / loop 
		for(int i=1; i<n+1; i++){
			for(int j=1; j<m+1; j++){
				if(a[i-1]==b[j-1]){
					t[i][j] = 1+t[i-1][j-1];
					res = max(res, t[i][j]); 
				}
				else
					t[i][j] = 0;
			}
		}
		
		// result 		
		return res;
	}

	string printLcs(string a, string b){
		string lcs = "";
		int n = a.size(), m = b.size();

		int longest_len = usingDp(a, b);  // sorry having t but again doing -> redundancy here 

		//paMat(t, n+1, m+1);

		bool flag=false;

		for(int i=n; i>0; i--){
			for(int j=m; j>0; j--){
				if(t[i][j]==longest_len){
					while(t[i][j]!=0 && a[i-1]==b[j-1]){
						lcs += a[i-1];
						i--; j--;						
					}
					flag=true; // found 
					break;
				}				
			}
			if(flag)
				break;
		}

		reverse(vall(lcs));

		return lcs; 
	}
};



// LONGEST PALINDROMIC SUBSEQUENCE
/*
BBABCBCAB => BABCBAB (7)
logest palindromic sub _ sequence
*/
string lps_seq(string a){
	string res = "";

	return res;
}



// LONGEST PALINDROMIC SUBSTRING 
/*
forgeeksskeegfor => geeksskeeg (10)
logest palindromic sub _ string
*/
string lps_str(string a){
	string res = "";

	return res;
}