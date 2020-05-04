#include "..\tools\macros.h"
#include <unordered_map>
using namespace std;

class ArrayAlgo{

public:

    int *arr;
    int n, i;

    ArrayAlgo(int input_arr[], int size_arr){
        this->n = size_arr;
        this->arr = new int[this->n];
        this->arr = input_arr;
    }

    int[] prefixSum(){
        int prefix_arr[n]={0};
        i=0;
        prefix_arr[0] = this->arr[0];
        i=1;
        ff(i,n)
            prefix_arr[i]=prefix_arr[i-1]+arr[i];
        return prefix_arr;
    }

    int[] suffixSum(){
        int suffix_arr[n]={0};
        i=0;
        suffix_arr[0] = this->arr[0];
        i=n-1;
        fr(i,n)
        suffix_arr[i-1] = ascii_arr[i]+suffix_arr[i];
        return suffix_arr;
    }

    int subArraySumEqualK(int k){
        if(n==0)
            return 0;

        unordered_map<int,int> umap;   //Key = PrefixSUM, Value = Count of PrefixSUM.
        int curr_sum = 0, val;
        int i = 0;
        int count = 0;

        i=0;
        fo(i,n)
        {
            /*----------------------------
            Idea:
            curr_sum - k = val
            curr_sum = val + k
            -----------------------------*/
            curr_sum += arr[i];

            if(curr_sum == k)    //We found a new subArray with SUM = k
                count += 1;

            val = curr_sum-k;

            if(isKeyExist(umap, val))
                count += umap[val];

            umap[curr_sum] += 1;
        }
        return count;
    }

    ~ArrayAlgo(){
        delete [] arr;
        arr = NULL;
    }
};
