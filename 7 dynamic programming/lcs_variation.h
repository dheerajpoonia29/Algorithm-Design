#include "../macro.h"
int memo[9999][9999]; // dp table in case of recursion with memoization
//	memset(memo, -1, sizeof(memo));

int t[100][100]; // dp table


//LONGEST COMMON SUBSEQUENCE
class LCS_SEQ
{
    /*
    longest common sub _ sequence
    "AGGTAB", "GXTXAYB" => ("GTAB") (4)
    */
public:

    //	RECURSIVE => OVERLAP SUB-PROBLEM
    // 	doubt! it is possible to print lcs using recursive (i try but failed :-)
    int	usingRecursive(string a, string b, string &lcs, int n, int m)
    {
        // base case
        if(n == 0 || m == 0)
            return 0;

        if(a[n - 1] == b[m - 1])
        {
            //pxyz("*", a, b);
            //lcs += a[n];					!doubt: it is storing all match

            // recursive case
            return 1 + usingRecursive(a, b, lcs, n - 1, m - 1);
        }

        else
        {
            //pxy(a, b);

            // recursive case
            return max(usingRecursive(a, b, lcs, n - 1, m), usingRecursive(a, b, lcs, n, m - 1));
        }
    }

    // RECURSIVE WITH MEMO (DP WITH MEMO) => BOTTOM UP DP
    int usingRecursiveWithMemo(string a, string b, int n, int m)
    {
        // base case
        if(n == 0 || m == 0)
            return 0;

        // memoization
        if(memo[n][m] != -1)
        {
            return memo[n][m];
        }

        // recursive case
        else
        {
            if(a[n - 1] == b[m - 1])
            {
                memo[n][m] = 1 + usingRecursiveWithMemo(a, b, n - 1, m - 1);
            }
            else
            {
                memo[n][m] =  max(usingRecursiveWithMemo(a, b, n - 1, m), usingRecursiveWithMemo(a, b, n, m - 1));
            }
            return memo[n][m];
        }

        //unordered_map<string, int> memo; //note: always make memo with varing variable so below n,m are changing
        //int memo[n+1][m+1] originally [n+1][m+1]
        //memset(memo, -1, sizeof(memo));
    }

    // DP (omit recursive call why? stack overflow - very rare) => TOP DOWN DP
    int usingDp(string a, string b)
    {
        int n = a.size(), m = b.size();
        // int t[n+1][m+1]

        // base case / intialization
        for(int i = 0, j = 0; i <= n, j <= m; i++, j++)
        {
            t[i][0] = 0;
            t[0][j] = 0;
        }

        // recursive case  / loop
        for(int i = 1; i < n + 1; i++)
        {
            for(int j = 1; j < m + 1; j++)
            {
                if(a[i - 1] == b[j - 1])
                    t[i][j] = 1 + t[i - 1][j - 1];
                else
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }

        // result
        return t[n][m];
    }

    string printLcs(string a, string b)
    {
        string lcs = "";
        int m = a.size(), n = b.size();

        //paMat(t, n+1, m+1);

        int i = m, j = n;
        while (i > 0 && j > 0)
        {
            if (a[i - 1] == b[j - 1])
            {
                lcs += a[i - 1];
                i--;
                j--;
            }

            else if (t[i - 1][j] > t[i][j - 1])
                i--;
            else
                j--;
        }

        reverse(lcs.begin(), lcs.end());

        return lcs;
    }
};


// LONGEST COMMON SUBSTRING
class LCS_STR
{
    /*
    "X1234YMN", "MNABCXY1234" => commn ("1234", "MN") longest ("1234":4)
    longest common sub _ string
    */
public:

    //	RECURSIVE => OVERLAP SUB-PROBLEM
    int	usingRecursive(string a, string b, int n, int m, int len)
    {
        if(n == 0 || m == 0)
            return len;

        if(a[n - 1] == b[m - 1])
        {
            len += 1;
            return usingRecursive(a, b, n - 1, m - 1, len);
        }

        return max(len, max(usingRecursive(a, b, n - 1, m, 0), usingRecursive(a, b, n, m - 1, 0)));
    }

    // RECURSIVE WITH MEMO (DP WITH MEMO) => BOTTOM UP DP
    int usingRecursiveWithMemo(string a, string b, int n, int m, int len)
    {
        // base case
        if(n == 0 || m == 0)
            return len;

        // memoization
        if(memo[n][m] != -1)
        {
            return memo[n][m];
        }

        // recursive case
        else
        {
            if(a[n - 1] == b[n - 1])
            {
                len += 1;
                memo[n][m] = usingRecursiveWithMemo(a, b, n - 1, m - 1, len);
            }
            else
                memo[n][m] = max(len, max(usingRecursiveWithMemo(a, b, n - 1, m, 0), usingRecursiveWithMemo(a, b, n, m - 1, 0)));

            return memo[n][m];
        }
    }

    // DP (omit recursive call why? stack overflow - very rare) => TOP DOWN DP
    int usingDp(string a, string b)
    {
        int n = a.size(), m = b.size(), res = 0;
        //int t[n+1][m+1]; 	// dp table we called it t table

        // base case / intialization
        for(int i = 0, j = 0; i <= n, j <= m; i++, j++)
        {
            t[i][0] = 0;
            t[0][j] = 0;
        }

        // recursive case  / loop
        for(int i = 1; i < n + 1; i++)
        {
            for(int j = 1; j < m + 1; j++)
            {
                if(a[i - 1] == b[j - 1])
                {
                    t[i][j] = 1 + t[i - 1][j - 1];
                    res = max(res, t[i][j]);
                }
                else
                    t[i][j] = 0;
            }
        }

        // result
        return res;
    }

    string printLcs(string a, string b)
    {
        string lcs = "";
        int n = a.size(), m = b.size();

        usingDp(a, b);

        int longest_len = t[n][m];
        //paMat(t, n+1, m+1);

        bool flag = false;

        for(int i = n; i > 0; i--)
        {
            for(int j = m; j > 0; j--)
            {
                if(t[i][j] == longest_len)
                {
                    while(t[i][j] != 0 && a[i - 1] == b[j - 1])
                    {
                        lcs += a[i - 1];
                        i--;
                        j--;
                    }
                    flag = true; // found
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


// SHORTEST COMMON SUPERSEQUENCE
// to-do
class SCS_SEQ  : public LCS_SEQ
{
    /*
    "AGGTAB", "GXTXAYB" => "AGXGTXAYB" : 9
    */
public:

    // to-do
    // int usingRecursive()
    // int usingRecursiveWithMemo()

    int usingDp(string a, string b)
    {
        // idea : simple solution a+b for optimization reduced with common subsequence
        int n = a.size(), m = b.size();
        LCS_SEQ::usingDp(a, b);
        return a.size() + b.size() - t[n][m];
    }

    // wa
    string printScs(string a, string b)
    {
        string scs = "";

        int m = a.size(), n = b.size();

        //paMat(t, n+1, m+1);

        int i = m, j = n;
        while (i > 0 && j > 0)
        {
            if (a[i - 1] == b[j - 1])
            {
                scs += a[i - 1];
                i--;
                j--;
            }

            else if (t[i - 1][j] > t[i][j - 1])
            {
                scs += b[j - 1];
                j--;
            }
            else
            {
                scs += a[i - 1];
                i--;
            }
        }

        while (i > 0)
        {
            scs += a[i - 1];
            i--;
        }

        while (j > 0)
        {
            scs += b[j - 1];
            j--;
        }

        reverse(scs.begin(), scs.end());

        return scs;
    }


};


// MINIMUM NO OF INSERTION AND DELETION TO CONVERT STRING A TO B
class CONVERT_STR_A_TO_B : public LCS_SEQ
{
    /*
    	"heap"->"pea"
    		insert 'p'
    		delete 'h'
    		delete 'p'
    */
public:

    int usingRecursive(string a, string b, int n, int m)
    {
        // base case
        if(n == 0 || m == 0)
            return 0;

        if(a[n - 1] == b[m - 1])
        {
            return 2;
        }

        // recursive case
        return 1 + min(usingRecursive(a, b, n - 1, m), usingRecursive(a, b, n, m - 1));
    }

    int usingRecursiveWithMemo(string a, string b, int n, int m)
    {
        // base case
        if(n == 0 || m == 0)
            return 0;

        if(a[n - 1] == b[m - 1])
        {
            return 2;
        }

        // memoization
        if(memo[n][m] != -1)
        {
            return memo[n][m];
        }
        // recursive case
        else
        {
            memo[n][m] = 1 + min(usingRecursive(a, b, n - 1, m), usingRecursive(a, b, n, m - 1));
            return memo[n][m];
        }
    }

    int usingDp(string a, string b)
    {
        int n = a.size(), m = b.size();
        int lcs = LCS_SEQ::usingDp(a, b);

        // no of deletion = a.size()-lcs
        // no of insertion = b.size()-lcs

        return (a.size() - lcs) + (b.size() - lcs);
    }

};


// LONGEST REPEATING SUBSEQUENCE
/*
"AABEBCDD" => "ABD"
to-do
idea:
	- AABEBCDD
	- AABEBCDD
	- lcs = AABEBCDD BUT WE NEED ABC
	- E, C NEED TO REMOVE THEN IN LCS IF PART I!=J CONDITION NEED TO BE IMPOSED
	-
*/


// SEQUENCE PATTERN MATCHING
/*
"AXY", "ADXCPY" => "AXY" (true)
to-do
idea:
	- just find lcs
	- if lcs return len == len(axy) : true
	- else : false
*/


//LONGEST PALINDROMIC SUBSEQUENCE
class LPS_SEQ : public LCS_SEQ
{
    /*
    AGBCBA => ABCBA (5)
    logest palindromic sub _ sequence
    */
public:

    int usingRecursive(string a, int l, int r)
    {
        // base case
        if(l > r)
            return 0;
        else if(l == r)
            return 1;

        // recursive case
        if(a[l - 1] == a[r - 1])
            return 2 + usingRecursive(a, l + 1, r - 1);
        else
            return max(usingRecursive(a, l + 1, r), usingRecursive(a, l, r - 1));
    }

    int usingRecursiveWithMemo(string a, int l, int r)
    {
        // base case
        if(l > r)
            return 0;
        else if(l == r)
            return 1;

        // memoization
        if(memo[l][r] != -1)
        {
            return memo[l][r];
        }
        // recursive case
        else
        {
            if(a[l - 1] == a[r - 1])
                memo[l][r] = 2 + usingRecursive(a, l + 1, r - 1);
            else
                memo[l][r] = max(usingRecursive(a, l + 1, r), usingRecursive(a, l, r - 1));
            return memo[l][r];
        }
    }

    // ! here is catch this is lcs variant and b string is missing
    // doubt! i try earlier to changing recursive code (bottom up) => dp code (top down) but unable todo
    // how we do this with recursive code ?
    int usingDp(string a)
    {

        string b = a;
        reverse(b.begin(), b.end());

        return LCS_SEQ::usingDp(a, b);
    }

};


// LONGEST PALINDROMIC SUBSTRING
class LPS_STR : public LCS_STR
{
    /*
    forgeeksskeegfor => geeksskeeg (10)
    logest palindromic sub _ string
    */
public:

    // to-do
    // int usingRecursive()
    // int usingRecursiveWithMemo()

    int usingDp(string a)
    {
        string b = a;
        reverse(b.begin(), b.end());

        return LCS_STR::usingDp(a, b);
    }


};


// MINIMUM NO OF DELETION IN STRING TO MAKE PALINDROMIC STRING
class CONVERT_STR_TO_PALINDROMIC_STR : public LPS_SEQ
{
    /*
    agbcba => abcba (delete: g) => 1 is min deletion
    */
public:

    // to-do
    // int usingRecursive()
    // int usingRecursiveWithMemo()

    int usingDp(string a)
    {
        return a.size() - LPS_SEQ::usingDp(a);
    }
};


// MINIMUM NO OF INSERTION IN STRING TO MAKE PALINDROMIC STRING
/*
"aebcbda" => adebcbeda then (de) 2 insertion
2 = 7 - 5 where 5 length of lcs
similar to above question
*/



/*------------------------------------------------------------------------------------------------------------

	LCS_SEQ lcs;
	px(lcs.usingDp("AGGTAB", "GXTXAYB"));
	px(lcs.printLcs("AGGTAB", "GXTXAYB"));


	LCS_STR lcs;
	px(lcs.usingDp("X1234Y", "MNABCXY1234"));
	px(lcs.printLcs("X1234Y", "MNABCXY1234"));


	SCS_SEQ obj;
	px(obj.usingDp("AGGTAB", "GXTXAYB"));
	px(obj.printScs("AGGTAB", "GXTXAYB"));


	CONVERT_STR_A_TO_B obj;
	px(obj.usingRecursive("heap", "pea", 4, 3));
	px(obj.usingRecursiveWithMemo("heap", "pea", 4, 3));
	px(obj.usingDp("heap", "pea"));


	LPS_SEQ lps;
	px(lps.usingRecursive("AGBCBA", 1, 6));
	px(lps.usingRecursiveWithMemo("AGBCBA", 1, 6));
	px(lps.usingDp("AGBCBA"));



	LPS_STR lps;
	px(lps.usingDp("forgeeksskeegfor"));



	CONVERT_STR_TO_PALINDROMIC_STR obj;
	px(obj.usingDp("agbcba"));
*/
