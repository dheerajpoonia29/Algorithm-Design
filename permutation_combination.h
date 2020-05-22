#include "macro.h"

// GENERATING STRING PERMUTATION USING STANDARD LIBRARY
vector<string> findStringPermutation(string str){
	string temp = str;
	vector<string> str_per;
	
	// Sort the string in lexicographically 
	// ascennding order 
	sort(str.begin(), str.end()); 

	// Keep printing next permutation while there 
	// is next permutation 
	do { 
			str_per.pb(str);
	} while (next_permutation(str.begin(), str.end())); 

	return str_per;
}


vector<string> findStringCombination(vector<int> arr, int n, int c){
	
    std::vector<bool> v(n);
    std::fill(v.end() - r, v.end(), true);

    do {
        for (int i = 0; i < n; ++i) {
            if (v[i]) {
                std::cout << (i + 1) << " ";
            }
        }
        std::cout << "\n";
    } while (std::next_permutation(v.begin(), v.end()));
    return comb;
}