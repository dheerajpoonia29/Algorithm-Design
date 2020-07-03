//#include "bit_manipulation.h"
//#include "3 mathematics/math_basic.h"
//#include "base_conversion.h"
//#include "5 backtracking/backtracking_basic.h"
//#include "6 greedy/greedy_basic.h"
//#include "7 dynamic programming/dp_basic.h"
//#include "7 dynamic programming/lcs_variation.h"
//#include "7 dynamic programming/knapsack01_variation.h"
//#include "7 dynamic programming/unbounded_knapsack_variation.h"
//#include "7 dynamic programming/dp_leetcode_easy.h"
#include "7 dynamic programming/matrix_chain_mul_variation.h"


int main()
{

	memset(memo, -1, sizeof(memo));
	//int arr[] = {10, 30, 5, 60};
	//int n = ;

	vector<pair<int, int>> mat_size{{10, 30}, {30, 5}, {5, 60}};

	MCM obj;
	px(obj.convert(mat_size));

	return 0;
}

