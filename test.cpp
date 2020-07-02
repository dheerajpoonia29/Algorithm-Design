//#include "bit_manipulation.h"
//#include "array_manipulation.h"
//#include "3 mathematics/math_basic.h"
//#include "base_conversion.h"
//#include "5 backtracking/backtracking_basic.h"
//#include "6 greedy/greedy_basic.h"
//#include "7 dynamic programming/dp_basic.h"
//#include "7 dynamic programming/lcs_variation.h"
//#include "7 dynamic programming/knapsack01_variation.h"
//#include "7 dynamic programming/unbounded_knapsack_variation.h"
#include "7 dynamic programming/dp_leetcode_easy.h"


int main()
{
	memset(memo, -1, sizeof(memo)); // for memoziation

	int total_step_of_stair = 12;
	CLIMBING_STAIRS obj;
	px(obj.usingRecursion(total_step_of_stair));
	px(obj.usingRecursionWithMemo(total_step_of_stair));
	px(obj.usingDp(total_step_of_stair));

	return 0;
}

