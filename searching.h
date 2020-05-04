#include "..\tools\macros.h"
using namespace std;

class Searching{

public:

    int* arr
    int n, i, mid, key_index=-1, search_key=-1;
    int total_iteration = 1;
    string algo_name = "",time_complexity = "", space_complexity = "";
    double time_taken = 0.0;

    Searching(int myarr[], int myn, int mykey){
        n = myn;

        arr = new int[n];

        arr = myarr;

        search_key = mykey;
    }

    void linearSearch(){

        algo_name = "linearSearch";

        i=0;
        fo(i,n){
            total_iteration++;
            if(arr[i]==search_key){
                key_index = i;
                break;
            }
        }
    }

    int binarySearch(int low, int high){

        algo_name = "binarySearch";

        while(low<=high){
                total_iteration++;
                mid = low + (high - low) / 2;
                if(arr[mid]==search_key){
                    key_index = mid;
                }

                if(arr[mid]<search_key){
                        low=mid+1;
                }
                else{
                        high=mid-1;
                }
        }

        return 0;
    }

    int lowerBound(int low, int high){

        algo_name = "lowerBound";

        while(low<=high){
                total_iteration++;
                int mid = low + (high - low) / 2;
                if(arr[mid]<search_key){
                    low=mid+1;
                }
                else if(arr[mid]>=search_key){
                    high=mid-1;
                    key_index=mid;
                }
        }

        return 0;

    }

    int upperBound(int low, int high)
    {

        algo_name = "upperBound";

        while(low<=high){
                total_iteration++;
                int mid = low + (high - low) / 2;
                if(arr[mid]<=search_key){
                    low=mid+1;
                    key_index=mid;
                }
                else if(arr[mid]>search_key){
                    high=mid-1;
                }
        }
    }

    int inbuiltLowerBound(){

        algo_name = "stl_lower_bound";

        vector<int> v(arr, arr + n);
        key_index =  lower_bound(v.begin(), v.end(), 0) - v.begin();
    }

    int inbuiltUpperBound(){

        algo_name = "stl_upper_bound";

        vector<int> v(arr, arr + n);
        key_index = upper_bound(v.begin(), v.end(), n) - v.begin();
    }

    void computeTime(time_t s, time_t e){
        time_taken = double(e-s);
    }

    void report(){
        cout<<"_________________________"<<"\n";
        deb1(algo_name);
        deb3(arr,n);
        deb2(search_key, key_index)
        deb1(total_iteration);
        cout<<"_________________________"<<"\n\n";
    }

    void reuse(){
        total_iteration=0;
        algo_name = "";
        time_complexity = "";
        space_complexity = "";
        key_index = -1;
    }

    ~Searching(){
        delete [] arr;
        arr = NULL;
    }
};
