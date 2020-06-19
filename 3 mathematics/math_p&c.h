// TO - DO
/*
given set of integer of length n
generate permutation of set ele r 
nPr
*/
class PERMUTATION{
public:

	size_t findFactorial(size_t n){
		if(n==1 || n==0){
			return 1;
		}
		return n*findFactorial(n-1);
	} 
	
	int findNpR(int n, int r){
		// N p R => (n)! / (n-r)!
		return findFactorial(n) / findFactorial(n-r);
	}

	void permute(string a, int l, int r) 
	{ 
		int i; 
		if (l == r) 
			cout<<a<<endl; 
		else
		{ 
			for (i = l; i <= r; i++) 
			{ 
				swap(s[l], s[i]); // combination
				permute(s, l+1, r, p);  // recursion 
				swap(s[l], s[i]); //backtrack (restore for the next round)
			} 
		} 
	} 

	// N: TOTAL OBJ 
	// R: OUT OF TOTAL N, R WE HAVE TO CHOSEN OBJECT

	vector<vector<int> > findPermutation(int n, vector<int> set, int r){	
		int tp, i, j, tpi;

		tp = findNpR(n, r);	// TOTAL PERMUTATION (permutation: ordered combination)
		vector<vector<int>> npr(tp, vector<int>(r, -1)); // STORING PERMUTATION
		tpi = 0; // FIRST PERMUTATION

		permute(str,0,2);

		return npr;
	}

};