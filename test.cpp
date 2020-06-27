//#include "bit_manipulation.h"
//#include "array_manipulation.h"
//#include "3 mathematics/math_basic.h"
//#include "base_conversion.h"
//#include "5 backtracking/backtracking_basic.h"
//#include "6 greedy/greedy_basic.h"
#include "7 dynamic programming/dp_basic.h"

int main()
{

	vector<pair<int, int>> v = findPrimeFactor(10);
	for(auto p: v){
		cout<<p.first<<" "<<p.second<<"\n";
	}

	return 0;
}
