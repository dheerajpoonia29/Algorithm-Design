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


    // Calculating kth row of pascall triangle in big(n)
    std::vector<int> getKthPascalTriRow(int k){
        vector<int>temp;// to store the resultant row
        
        int n  = 1;
        for( int col = 0; col <= k ; col++){// kth row will have k + 1 elements in pascal triangle
            temp.push_back(n);
            n = n * (k - col)/(col + 1);// mathematics
        }
        // t.c O(n)
        return temp;
        
        /*-------------------------
        my idea 1: get upper all row and return last one kth
                    t.c = O(n^2)
        idea 2: directly get kth row by formula nCr where n=k and 0<=r<n+1
                    t.c = O(n*f(ncr)!)
        ----------------------------*/
    }
       

    // Sort array and by storing there original index using stable sort
    template <typename T>
    vector<size_t> sortByStoringIndex(vector<T> v){
        // initialize original index locations
        vector<size_t> idx(v.size());
        iota(idx.begin(), idx.end(), 0);
        
        // sort indexes based on comparing values in v
        // using std::stable_sort instead of std::sort
        // to avoid unnecessary index re-orderings
        // when v contains elements of equal values 
        stable_sort(idx.begin(), idx.end(),[&v](size_t i1, size_t i2) {return v[i1] < v[i2];});
        return idx;

        /*------------------
        accessing method
        vector<int> arr{ 10,1,6,3,9,0 };
        int n = arr.size();
        
        vector<int> idx(n,0);
        int i=0;
        
        for (auto arrIdx: sortByStoringIndex(arr)) {
            idx[i++] = arrIdx;
        }
        
        for(auto i: idx){
            cout<<i<<" ";
        }

        Other approach:

            vector<pair<int, int> > vp; 

            for (int i = 0; i < n; ++i) { 
                vp.push_back(make_pair(arr[i], i)); 
            } 

            // Sorting pair vector 
            sort(vp.begin(), vp.end()); 

            // Displaying sorted element 
            // with previous indexes 
            // corresponding to each element 
            cout << "Element\t"
                << "index" << endl; 
            for (int i = 0; i < vp.size(); i++) { 
                cout << vp[i].first << "\t"
                    << vp[i].second << endl; 
            } 
        -------------------*/


    }


    // Counting maximum overlap interval in O(nlogn)
    int maxOverlapIntervalCount(vector<int> arrive, vector<int> depart){
        int curr_ovlp=0, max_ovlp=0;
        sort(arrive.begin(), arrive.end());
        sort(depart.begin(), depart.end());
        
        int i=0, j=0, n=arrive.size();
        
        while(i<n && j<n){
            if(arrive[i]<depart[j]){
                curr_ovlp++;
                max_ovlp = max(max_ovlp, curr_ovlp);
                i++;
            }
            else{
                curr_ovlp--;
                j++;
            }
        }
        
        return max_ovlp;    // 1-2 2-3 ovlp=1
        // returing max_ovlp-1 would not condier overal for 1-2 2-3 here ovlp=0
    }


    // Finding duplicate in array in tc=> O(n), sc=> O(1)
    int findDuplicateInArray(int list[], int n){

        if (list.size() <= 1)
        return -1;

            int slow = list[0];
            int fast = list[list[0]];

            // we exit when we detech a cycle
            while (fast != slow) {
            slow = list[slow];
            fast = list[list[fast]];
            }


            slow = 0;
            while (fast != slow) {
            slow = list[slow];
            fast = list[fast];
            }

          return slow;
    }


    // implementation of difficult pattern printing problem : spiralorder
    void spiralOrderPrinting(std::vector<std::vector<int> > v){
		/*
		before run this function remove comment
		struct Point{
		    int i,j;
		};

		typedef Point point;

		bool condition(point a, point b, point c, point d){
		    if(a.i<=c.i && d.j<=b.j){
		        return true;
		    }
		    return false;
		}

		void show(point a, point b, point c, point d){
		    cout<<"\n----------------\n";
		    cout<<a.i<<","<<a.j<<"\n";
		    cout<<b.i<<","<<b.j<<"\n";
		    cout<<c.i<<","<<c.j<<"\n";
		    cout<<d.i<<","<<d.j<<"\n";
		    cout<<"-------------\n";
		}

		void decrement(point &a, point &b, point &c, point &d){
		    a.i+=1; a.j+=1;
		    b.i+=1; b.j-=1;
		    c.i-=1; c.j-=1;
		    d.i-=1; d.j+=1;
		}

		bool checkSpecial1(point a, point b, point c, point d){
		    if(a.i==c.i && d.j==b.j){
		        return true;
		    }
		    return false;
		}

		bool checkSpecial2(point a, point b, point c, point d){
		    if( (a.i==b.i && a.j==b.j) && (c.i==d.i && c.j==d.j) ){
		        return true;
		    }
		    return false;
		}

		bool checkSpecial3(point a, point b, point c, point d){
		    if( (a.i==d.i && a.j==d.j) && (b.i==c.i && b.j==c.j)){
		        return true;
		    }
		    return false;
		}

		*/
		    int row=v.size(), col=v[0].size();
		    
		    vector<int> arr;
		    
		    point a,b,c,d;
		    a.i=0; a.j=0;
		    b.i=0; b.j=col-1;
		    c.i=row-1; c.j=col-1;
		    d.i=row-1; d.j=0;
		    
		    
		    
		    
		    while(condition(a,b,c,d)){
		        
		        // show(a,b,c,d);   
		        
		        //when we have middle remaining
		        if(checkSpecial1(a,b,c,d)){
		            
		            cout<<v[a.i][a.j]<<endl;
		            break;
		        }
		        
		        
		        //when we have vertical remaining
		        if(checkSpecial2(a,b,c,d)){
		            
		            i=b.i; j=b.j;
		            while(i<=c.i){
		                cout<<v[i][j]<<" ";
		                i++;
		            }
		            cout<<endl;
		            break;
		        }
		        
		        //when we have horizontal remaining
		        if(checkSpecial3(a,b,c,d)){
		            
		            i=a.i; j=a.j;
		            while(i<=b.i && j<=b.j){
		                cout<<v[i][j]<<" ";
		                j++;
		            }
		            cout<<endl;
		            break;
		        }
		        
		        
		        i=a.i; j=a.j;
		        while(i<=b.i && j<=b.j){
		            cout<<v[i][j]<<" ";
		            j++;
		        }
		        cout<<endl;
		        
		        i=b.i+1; j=b.j;
		        while(i<c.i){
		            cout<<v[i][j]<<" ";
		            i++;
		        }
		        cout<<endl;
		        
		        
		        i=c.i; j=c.j;
		        while(j>=d.j){
		            cout<<v[i][j]<<" ";
		            j--;
		        }
		        cout<<endl;
		        
		        
		        i=d.i-1; j=d.j;
		        while(i>a.i){
		            cout<<v[i][j]<<" ";
		            i--;
		        }
		        cout<<endl;
		        
		        decrement(a,b,c,d);
		    }

    }

    ~ArrayAlgo(){
        delete [] arr;
        arr = NULL;
    }
};
