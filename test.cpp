//#include "bit_manipulation.h"
//#include "array_manipulation.h"
//#include "3 mathematics/math_basic.h"
//#include "base_conversion.h"
//#include "5 backtracking/backtracking_basic.h"
//#include "6 greedy/greedy_basic.h"
//#include "7 dynamic programming/dp_basic.h"
#include "7 dynamic programming/lcs_variation.h"

int main()
{

	//LCS_SEQ lcs;
	//px(lcs.usingDp("ABCDGHXYZ", "ABEDFHR"));
	//px(lcs.printLcs("ABCDGH", "ABEDFHR"));
	
	LCS_STR lcs;
	px(lcs.usingDp("X1234Y", "MNABCXY1234"));
	px(lcs.printLcs("X1234Y", "MNABCXY1234"));
	
	//px(obj.lps_seq("BBABCBCAB"));
	//px(obj.lps_str("forgeeksskeegfor"));

	return 0;
}
