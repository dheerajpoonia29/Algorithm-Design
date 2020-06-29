//#include "bit_manipulation.h"
//#include "array_manipulation.h"
//#include "3 mathematics/math_basic.h"
//#include "base_conversion.h"
//#include "5 backtracking/backtracking_basic.h"
//#include "6 greedy/greedy_basic.h"
//#include "7 dynamic programming/dp_basic.h"
//#include "7 dynamic programming/lcs_variation.h"
#include "7 dynamic programming/knapsack01_variation.h"


int main()
{

	memset(memo, -1, sizeof(memo));

/*
	int wa[] = {1, 3, 4, 5};
	int va[] = {1, 4, 5, 2};
	int W = 7;
	int n = 4;

	KNAPSACK_01 obj;
	px(obj.usingRecursive(wa, va, n, W));	
	px(obj.usingRecursiveWithMemo(wa, va, n, W));
	px(obj.usingDp(wa, va, n, W));
*/


	int arr[] = {2,3,7,8,10};
	int n = 5, sum = 14;

	SSP obj;
	px(obj.usingRecursive(arr, n, sum));
	px(obj.usingRecursiveWithMemo(arr, n, sum));
	px(obj.usingDp(arr, n, sum));

	return 0;
}
