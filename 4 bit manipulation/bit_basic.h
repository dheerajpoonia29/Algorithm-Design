#include "macro.h"
int boolVectorToInt(vector<bool> b);

// Total bits required to represent a num :

int findTotalBit(int num){
    //num req i bit if 2^(i-1) ≤ num ≤ 2^i – 1
    if(num==0)  return 0;
    int i = (int)log2(num)+1;
    return i;
}


// Checking iTh bit is set of unset :

bool checkIthBit(int num,int i)
{
    bool bit = num & (1<<i);
    return bit;
}

// Set iTh bit of num :

int setIthBit(int num,int i)
{
    return num |= (1 << i);
}


// Unset iTh bit of num :

int unsetIthBit(int num,int i)
{
    return num &= (~(1 << i));
}


// UNSET ALL BIT EXCEPT MSB
int unsetAllBitsExceptMSB(int x)
{
  x |= x >> 16;
  x |= x >> 8;
  x |= x >> 4;
  x |= x >> 2;
  x |= x >> 1;
  x ^= x >> 1;
  return x;
}


// Toggling a bit at i th position :

int toggleIthBit(int num,int i)
{
    return num ^= (1 << i);
}


// Adding two number :
int addUsingBit(int a, int b){
    vector<bool> ans;
    int bit=1, carry=0, currBit=0;
    while(a || b){
        if(a&bit && b&bit){
            //if both bit are set then carry is generated
            if(carry){
                currBit=1;
                carry=1;
            }
            else{
                currBit=0;
                carry=1;
            }
        }
        else if(a&bit || b&bit){
            //if one of the bit is 1
            if(carry){
                currBit=0;
                carry=1;
            }
            else{
                currBit=1;
                carry=0;
            }
        }
        else{
            //if both bit are 0
            if(carry){
                currBit=1;
                carry=0;
            }
            else{
                currBit=0;
            }
        }
        ans.pb(currBit);
        a>>=1;
        b>>=1;
    }
    if(carry){
        ans.pb(carry);
    }
    int no = boolVectorToInt(ans);
    return no;
}


// Count set bit

int findSetBits(int num)
{
    int cnt_set_bit = 0;
    while(num){
        num &= (num-1);
        cnt_set_bit++;
    }
    return cnt_set_bit;
		/* INBUILT FUNCTION 
		_builtin_popcount(num) 
		similarly _builtin_popcountl(x) and _builtin_popcountll(x)
		*/
}


// FIND PARITY
int findPairty(int num){
	// counting no of 1's let say count1 
	// parity 1 if count1 is odd 
	// pairty 0 if count1 is even
	int count1 = findSetBits(num);
	return count1%2==0?1;

	/* INBUILD FUNCTION 
	_builtin_parity(num)
	similarly _builtin_parityl(num) and _builtin_parityll(num)
	*/
}


// COUNT LEADING ZERO
int findLeadingZero(int num){
	int count0leading = 0;
	// lets say num is 64 bit then total length = 64
	int tl = 64;
	while(num){
		tl-=1;
		num>>=1;
	}

	count0leading = tl;
	return count0leading;
	/* INBUILT FUNCTION 
	__builtin_clz(num)
	*/
}


// COUNT TRAILING ZERO 
int findTrailingZero(int num){
	int count0Tralinig=0;
	while(num&(1)==0){
		count0Tralinig+=1;
		num>>=1;
	}
	return count0Tralinig;

	/* INBUILT FUNCTION 
	__builtin_ctz(num)
	*/
}


// Storing set bit pos, right to left based indexing :
vector<int> storingSetBits(int num){
	vector<int> pos;
    int i=0;
    while(num){
        if(num & (1))
            pos.pb(i);
        i++;
        num>>=1;
    }
	return pos;
}


// Converting bool vector to int :
int boolVectorToInt(vector<bool> b) {
    // need of bool vector is because bitset<len> where len is no dynamically allocated so we need vector to store binary bit
    // note 4-> vec[0,0,1] not [1,0,0] this will work for [0,0,1] don't reverse bool vector for converion
    int num;
    num = accumulate(b.rbegin(), b.rend(), 0, [](int x, int y) { return (x << 1) + y; });
    return num;
}


// Calculate log2 of num in log(n)

int log2(int num)
{
    int res = 0;
    while(num >>= 1)
        res++;
    return res;
}


// Check if num is power of 2
bool isPowerOf2(int num)
{
    if(num==0)  return false;
    else
        if((num & num-1) == 0)
            return true;
    return false;
    /*------------
    sort : return (num && !(num & num-1));
    -------------*/
}

// Check if num is power of 3
bool isPowerOf3(int num)
{
		/*
		n = 3^i 
		taking log 
		i = log3(n)
		converting it to base 10
		i = log10(n) / log10(3)
		not if i==0 it mean that n is power of 3
		*/
}

// 1’s complement of num :

int onesComp(int num)
{
    int i = totalBitReq(num);
    int j=0;
    while(j<i){
        num = toggleIthBit(num,j);
        j++;
    }
    return num;
    /*--------------------------------
    this is wrong
    return (~num);
    0000 0000  0000 0000  0000 0000  0000 1010
    When we negate it, we get
    1111 1111  1111 1111  1111 1111  1111 0101
    --------------------------------*/
}


// 2's complement of num :

int twosComp(int num)
{
    return onesComp(num)+1;
}


// Rightmost iTh set bit or lowest set bit of a num :
// or index of first least significant set bit
int lowestSetBit(int num)
{
    //1 base indexing
    int i = log2(num & -num) + 1;
    return i;
    /*
    int lsb(int pos){		  // O(logn)
		int bit = 0;      
	    while ((pos >> bit) & 1 == 0) {
	        ++bit;
	    }
	    return (1 << bit);
    }
    ---------------------------------------------    
    or 
	
	int lsb(int pos) {         // O(1)
    	return pos & -pos;
	}

	x&(-x) gives the last set bit in a number x. 
    Example: x = 10(in decimal) = 1010(in binary)
	The last set bit is given by x&(-x) = (10)1(0) & (01)1(0) = 0010 = 2(in decimal)

	x = 01101100
	~x = 10010011
	-x = 10010100
	there for : x & -x = 00000100
	---------------------------------------------
	or

    return ffs(num); // ffs(n) inbuild function
    ---------------------------------------------
    or

    int i = 1;
    int m = 1;

    while (!(n & m)) {

        // left shift
        m = m << 1;
        i++;
    }
    return i;
    */
}


// Leftmost iTh set Bit or highest set bit of num :

int highestSetBit(int num)
{
    int i=0;
    while(num){
        num>>=1;
        i++;
    }
    return i;
}


// Binary representation of num :

string numToBin(int num){
    if(num<0)   return "negative no";
    int i = totalBitReq(num);
    string bin = "";
    while(i){
        if(checkIthBit(num,i-1))
            bin+='1';
        else
            bin+='0';
        i--;
    }
    return bin;
    /*-----------------------
    string bin = std::bitset<8> (num).to_string();
    -----------------------*/

    /*-----------------------
    int binaryNum[32];
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
    -------------------------*/
}


// Decimal representation of binary or bits

unsigned long int binToNum(string bin){
    unsigned long int num = bitset<32>(bin).to_ulong();
    return num;
    /*-----------------------
    int base = 1;

    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;

        dec_value += last_digit * base;

        base = base * 2;
    }

    return dec_value;
    -------------------------*/
}


// CALCULATING HAMMING DISTANCE

int hammingDistance(int a,int b){
	int dist=0;

	while(a || b){
		if(a&(1) ^ b&(1)){
			dist++;
		}
		a>>=1;
		b>>=1;
		//pxy(a,b)
	}
	/*
	different bits = a^b xor 
	now cound 1 in different bits
	*/
	return dist;
}