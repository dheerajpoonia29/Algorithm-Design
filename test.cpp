//#include "bit_manipulation.h"
//#include "array_manipulation.h"
#include "macro.h"
#include "mathematics.h"

int main()
{
	el;

	px(checkPrime(21));
	px(checkPrime(7));

	pv(findPrime(20));
	pv(findFactor(82944));
	pvp(findPrimeFactor(50));
	
	px(findLcm(3,15));
	px(findGcd(12, 16));

	for(int i=10; i<20; i++){
		pxy(findExpPwr(i,i*2), pow(i,i*2))
		assert(findExpPwr(i, 2)==pow(i,2));
	}

	el;
	return 0;
}
