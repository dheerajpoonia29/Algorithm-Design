#include "..\cp_contest\my_macros.h"
#include "..\data_structure\heap.h"

class ArrayAlgo{

public:

    int *arr;
    int n, i, j;

    ArrayAlgo(int input_arr[], int size_arr){
        this->n = size_arr;
        this->arr = new int[this->n];
        this->arr = input_arr;
    }


    // Cal prefix sum of array :
    // done
    int* prefixSum(){
        int prefix_arr[n]={0};
        prefix_arr[0] = this->arr[0];
        i=1;
        ff(i,n)
            prefix_arr[i]=prefix_arr[i-1]+arr[i];
        return prefix_arr;
    }


    // Cal suffix sum of array :
    // done
    int* suffixSum(){
        int suffix_arr[n]={0};
        suffix_arr[n-1] = this->arr[n-1];
        i=n-2;
        fr(i,n)
        suffix_arr[i] = arr[i]+suffix_arr[i+1];
        return suffix_arr;
    }


    // Cal Maximum sum among subarray of array :
    // simple logic
    int maxSubArraySum() {
        int ms=0, mssf=INT_MIN, ele;
        i=0;
        ff(i,n){
            ele = arr[i];
            ms = max(ms+ele, ele);  // curr maximum sum = max(prev+curr, curr)
            mssf = max(mssf, ms);   // maximum sum so far = max(maximum sum so far, curr maximum sum)
        }
        return mssf;
    }


    // K-th maximum sum of subarray :
    // simple logic + heap
    int kThMaxSubarraySum(int k){
        /*----------------------------
            Idea:
            store all the contiguous sums in another array
            sort it
            print the k-th largest.
            t.c = O(nlogn) since sorting is done
            take extra memory O(n)
        /*----------------------------
            Idea:
            cal prefix sum
            sum of subarray from index [i,j] as ps[j]-ps[i-1]
            use min heap to store sum
            similar to my approach below
            t.c = O(n^2logn)
        ------------------------------/
        /*----------------------------
            My Idea:
            store mssf (maxi sum so far) into heap
            then get kth max from heap t.c k*O(1) in worst case O(n+k)

            building heap t.c if O(n) on every insert heapify t.c O(logn)
            overall t.c O(nlogn)

            inserting into heap t.c is O(logn)

            total idea t.c = O(nlogn)+O(n+k) => O(nlogn)
            -----------------------------*/

        vector<int> heap;
        int heap_size=0;
        buildHeap(heap, "max");

        int ms=0, mssf=INT_MIN, ele;
        i=0;
        ff(i,n){
            ele = arr[i];
            ms = max(ms+ele, ele);
            if(ms>mssf){
                mssf=ms;
                DBx_line(mssf);
                insertHeap(heap,mssf);
                heap_size++;
            }
        }
        return kThMaxHeap(heap,k,heap_size);
    }


    // Count subarray sum eqaul to k :
    // hashtable + prefix sum
    int subArraySumEqualK(int k){
        if(n==0)
            return 0;

        unordered_map<int,int> umap;   //Key = PrefixSUM, Value = Count of PrefixSUM.
        int curr_sum = 0, val;
        int i = 0;
        int count = 0;

        i=0;
        ff(i,n)
        {
            /*----------------------------
            Idea:
            curr_sum is prefix sum so far
            curr_sum - k = val
            wherer val is exist somewhere in previous subarray of size k
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


    // Cal min size of subarray where sum of subarray >= given sum
    // binary search
    int minSizeSubarraySum(int sum){
        int min_size=INT_MAX, curr_sum;
        int low=0, high=n-1, mid;

        int ps[n]={0};
        ps[0] = arr[0];
        i=1;
        ff(i,n){
            DBxy(ps[i-1],arr[i])
            ps[i] = ps[i-1]+arr[i];
        }

        while(low<high){
            if(low-1<0)
                curr_sum = ps[high]-ps[0];
            else
                curr_sum = ps[high]-ps[low];

            min_size = min(min_size, high-low);

            mid = low+(high-low)/2;
            DBxy(low,high)
            if( curr_sum>sum )
                low = mid+1;
            else
                high = mid;
        }

        return min_size;
    }

    // Min & max element in each subarray of size k
    // interview bit, TODO
    void minMaxInSubarrayOfSizeK(int k){
        int mx=INT_MIN, mn=INT_MAX;

        DBarr(arr,n);

        /*----------------------------------
        IDEA : AVL TREE
        time c : O(n*logk)

        printKMaxAvl(arr,n,4);
        first we insert k subarray in bst/avl then on subarray we remove prev left most subarray ele from bst and next most ele of next subarray
        so on every subarray if we get min we go root->left and for max root->right

        /*----------------------------------
        IDEA : brute force
        time c : O(n*k)

        for(i=0; i<=n-k; i++){
            cout<<"["<<"";
            for(j=i; j<=i+k-1; j++){
                DBx_line(arr[j])
                mx = max(mx, arr[j]);
                mn = min(mn, arr[j]);
            }
            cout<<"]";
            nl;
            DBxyzw(i,i+k-1,mx,mn)
        }
        */
    }


    // Maximum product of subarray of any size :
    // dp problem, TODO
    int maxProductSubarray(){



    }


    ~ArrayAlgo(){
        delete [] arr;
        arr = NULL;
    }
};
