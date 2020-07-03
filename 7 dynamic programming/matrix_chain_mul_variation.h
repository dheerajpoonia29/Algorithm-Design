#include "../macro.h"
int memo[9999][9999]; // dp table in case of recursion with memoization
//	memset(memo, -1, sizeof(memo));

int t[100][100]; // dp table 

// MATRIX CHAIN MULTIPLICATION 
class MCM{
	/*
		vector<pair<int, int>> mat_size{{10, 30}, {30, 5}, {5, 60}};
		
		27000 
	*/
	public:

	// doublt: data structure repo / recursion / recursion_confusion
	
	int convert(vector<pair<int, int>> mat_size){
		int n = mat_size.size()+1;
		int size[n];

		for(int i=0; i<n; i++){
			size[i] = mat_size[i].first;
		}
		size[n-1] = mat_size[n-2].second;
		pa(size, n);
		
		//return usingRecursion1(size, 1, n-1);
		return usingRecursion2(size, 0, n);
	}
	
	int usingRecursion1(int arr[], int i, int j){
		// base case 
			if(i>=j)
				return 0;
		
		// recursive case 
			int res = INT_MAX;

			for(int k=i; k<j; k++){
				res = min(res, usingRecursion1(arr, i, k) + usingRecursion1(arr, k+1, j) + (arr[i-1]*arr[k]*arr[j]) );
			}
			
			return res;
	}

	int usingRecursion2(int arr[], int k, int n){
		// base case 
			if(k>=n-1)
				return 0;

		// matrix multiplying

			// multiplying i to k
			int cnt1 = 1;
			cout<<"\n";
			for(int i=0; i<=k; i++){
				cout<<arr[i]<<" ";
				cnt1 *= arr[i]*arr[i+1];
			}
			
			// multiplying k to j
			int cnt2 = 1;
			cout<<" * ";
			for(int j=k+1; j<n; j++){
				cout<<arr[j]<<" ";
				cnt2 *= arr[j];
			}
			
			// multiplying i-k to k-j
			int cnt3 = 1;
			cout<<"\n";
			cout<<"cnt1="<<cnt1<<" cnt2="<<cnt2<<"\n";
			

		// recursive case
			return min(cnt1+cnt2+cnt3, usingRecursion2(arr, k+1, n));
	}

};
