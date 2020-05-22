#include "macro.h"


// CHAR BASE CONVERSION TO DECIMAL INTEGER

int letterBaseToDecimal(string letter){

	int n=-234;
	string s = to_string(n);
	reverse(s.begin(), s.end());
	cout<<s;el;
	return 0;
	
}
/*
long int BinToHex(string buf)
{
	long int longint=0;
	int len=buf.size();
	for(int i=0;i<len;i++)
	{
					longint+=(buf[len-i-1]-48) * pow(2,i);
	}
	cout<<setbase(16);
	return longint;
}

string bintohex(const string &s){
		string out;
		for(uint i = 0; i < s.size(); i += 4){
				int8_t n = 0;
				for(uint j = i; j < i + 4; ++j){
						n <<= 1;
						if(s[j] == '1')
								n |= 1;
				}

				if(n<=9)
						out.push_back('0' + n);
				else
						out.push_back('A' + n - 10);
		}

		return out;
}

	string HexToBin(string hexdec) 
	{ 
			long int i = 0; 
			string bin="";
		
			while (hexdec[i]) { 
		
						switch (hexdec[i]) { 
							case '0': 
									bin+="0000"; 
									break; 
							case '1': 
									bin+= "0001"; 
									break; 
							case '2': 
									bin+= "0010"; 
									break; 
							case '3': 
									bin+= "0011"; 
									break; 
							case '4': 
									bin+= "0100"; 
									break; 
							case '5': 
									bin+= "0101"; 
									break; 
							case '6': 
									bin+= "0110"; 
									break; 
							case '7': 
									bin+= "0111"; 
									break; 
							case '8': 
									bin+= "1000"; 
									break; 
							case '9': 
									bin+= "1001"; 
									break; 
							case 'A': 
							case 'a': 
									bin+= "1010"; 
									break; 
							case 'B': 
							case 'b': 
									bin+= "1011"; 
									break; 
							case 'C': 
							case 'c': 
									bin+= "1100"; 
									break; 
							case 'D': 
							case 'd': 
									bin+= "1101"; 
									break; 
							case 'E': 
							case 'e': 
									bin+= "1110"; 
									break; 
							case 'F': 
							case 'f': 
									bin+= "1111"; 
									break; 
							default: 
									cout << "\nInvalid hexadecimal digit "
												<< hexdec[i]; 
						} 
						i++; 
			}
			return bin;
	} 

vector<int> binToDec(vector<int> bin){
	// Converting L to its binary representation 
	L=10
	    while (L > 0) { 
	        v1.push_back(L % 2); 
	        L = L / 2; 
	    } 
		//V1=[1,0,1,0]
	return v1;
}

	string hextobin(const string &s){
    string out;
    for(auto i: s){
        uint8_t n;
        if(i <= '9' and i >= '0')
            n = i - '0';
        else
            n = 10 + i - 'A';
        for(int8_t j = 3; j >= 0; --j)
            out.push_back((n & (1<<j))? '1':'0');
    }
	return out;
}
*/