//#include "bit_manipulation.h"
//#include "array_manipulation.h"
#include "mathematics.h"
//#include "base_conversion.h"
//#include "permutation_combination.h"
//#include "macro.h"

void do_it();

int main()
{
	// your code goes here
	fastio;
	pvp(findPrimeFactor(50))

	return 0;
}

int countPower(int n){
	int totalPrimeCount=0;
	if(n<2){
		return totalPrimeCount;
	}
	else{
		// 2 is only a even prime number 
		int p=2, exp=0;
		while(n%p==0){
			n/=p;
			exp++;			
		}
		if(exp!=0)
		totalPrimeCount++;

		// rest all are prime are odd i+=2
		for(p=3; p*p<=n; p+=2){	// either p<=sqrt(n)
			exp=0;
			while(n%p==0){
				n/=p;
				exp++;
			}
			if(exp!=0)
			totalPrimeCount++;
		}
		// special case
		if(n!=1)	totalPrimeCount++;
	}
	return totalPrimeCount;
}	

void do_it(){
	// count no of prime factor between a to b;
	int a = 2, b= 20, k=3;
	int res=0;
	for(int i=a; i<=b; i++){
		int pfc=0; //prime_factor_count
		if(countPower(i)>=k){
			res++;
		}
	}
	pi(res);
}