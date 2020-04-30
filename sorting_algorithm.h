#include "..\tools\macros.h"
#include <cstdlib>
#include <time.h>
using namespace std;

/*-------------------------------------------

//int arr[] = {1,2,3,4,5};   //best case    for quick sort it is worst case
//int arr[] = {7,3,1,9,2};   //avg case
//int arr[] = {5,4,3,2,1};     //worst case

//Sorting obj(array, size, modification bool)
//modification =true (original array would change), otherwise no change in original array
Sorting obj(arr,n, 0);

deb3(obj.arr,n);
obj.selectionSort();
obj.report();

--------------------------------------------*/

class Sorting{

public:

    int* arr, n, i, j, k;
    int total_iteration = 1, total_swap = 0;
    string algo_name = "",time_complexity = "", space_complexity = "";
    double time_taken = 0.0;

    Sorting(int myarr[], int myn, int modify){

        n=myn;
        arr = new int[n];

        if(modify==true){
            arr = myarr;
        }
        else{
            i=0;
            fo(i,n)
                arr[i] = myarr[i];
        }
    }

    int selectionSort(){

        algo_name = "selectionSort";
        time_complexity = "bigO(n^2)";
        space_complexity = "bigO(n)";

        i=0, j=0;
        int min_idx, curr_idx, nxt_idx  ;
        fo(i, n-1){
            curr_idx = i;
            min_idx = i;
            j=i+1;
            fo(j, n){
                total_iteration++;
                nxt_idx = j;
                if(arr[nxt_idx]<arr[min_idx])
                        min_idx = nxt_idx;
            }
            if(curr_idx!=min_idx){
                total_swap++;
                swap(arr[curr_idx],arr[min_idx]);
            }
        }
        return 0;
    }

    int bubbleSort(){

        algo_name = "bubbleSort";
        time_complexity = "bigO(n^2)";
        space_complexity = "bigO(n)";

        i=0;
        int k=0;
        bool flag;
        fo(i,n){
            j=0;
            flag=true;  //sorted
            fo(j,n-i-1){
                total_iteration++;
                if(arr[j]>arr[j+1]){
                    total_swap++;
                    swap(arr[j], arr[j+1]);
                    flag=false;
                }
            }
            if(flag)    break;
        }

        return 0;
    }

    int insertionSort(){

        algo_name = "insertionSort";
        time_complexity = "bigO(n^2)";
        space_complexity = "bigO(n)";

        i=1;
        int pick=0;
        bool flag=true; //assume array is sorted
        fo(i,n){
            pick = arr[i];
            j=i-1;
            while(j>=0 && arr[j]>pick){
                flag=false;
                total_iteration+=1;
                if(arr[j]>pick){
                    arr[j+1] = arr[j];
                    total_swap+=1;
                }
                j--;
            }
            j+=1;
            arr[j] = pick;
        }
        if(flag)    total_iteration+=n-1;
        return 0;
    }

    int mergeSort(){

        algo_name = "mergeSort";
        time_complexity = "bigO(nlogn)";
        space_complexity = "bigO(n)";

        splitArrayIntoTwo(arr, n);

        return 0;
    }

    int quickSort(bool randomize){

        if(randomize)
            algo_name = "randomizeQuickSort";
        else
            algo_name = "quickSort";
        time_complexity = "bigO(nlogn)";
        space_complexity = "inplace sorting";

        splitIndex(arr, 0, n-1, randomize);

        return 0;
    }

    int splitIndex(int* arr, int start_idx, int end_idx, bool randomize){
        if(start_idx >= end_idx)
            return 0;
        int partition_idx;
        if(randomize)
            partition_idx = randomPivot(arr, start_idx, end_idx, randomize);
        else
            partition_idx = findPartititionIndex(arr, start_idx, end_idx, randomize);
        splitIndex(arr, start_idx, partition_idx, randomize);
        splitIndex(arr, partition_idx+1, end_idx, randomize);
        total_iteration++;
    }

    int randomPivot(int* arr, int start_idx, int end_idx , bool randomize){
        srand(time(NULL));
        int random = start_idx + rand() % (end_idx - start_idx);
        swap(arr[random], arr[end_idx]);
        return findPartititionIndex(arr, start_idx, end_idx, randomize);
    }

    int findPartititionIndex(int* arr, int start_idx, int end_idx, bool randomize){
        int partition_idx = start_idx-1;
        int pivot = end_idx;
        i=start_idx;
        fo(i,end_idx){
            total_iteration++;
            if(arr[i]<=arr[pivot]){
                partition_idx++;
                swap(arr[partition_idx], arr[i]);
                total_swap++;
            }
        }
        swap(arr[partition_idx+1], arr[pivot]);
        total_swap++;
        if(randomize)
            return partition_idx+1;
        else
            return partition_idx;
    }


    void splitArrayIntoTwo(int arr[], int n){
        if(n<2) return;
        int mid = n/2;

        int* left_arr, *right_arr;
        left_arr = new int[mid];
        right_arr = new int[n-mid];

        i=0;
        fo(i,mid)
            left_arr[i]=arr[i];

        i=mid;
        fo(i,n)
            right_arr[i-mid]=arr[i];

        total_iteration++;

        splitArrayIntoTwo(left_arr, mid);
        splitArrayIntoTwo(right_arr, n-mid);

        mergeArray(arr, left_arr, mid, right_arr, n-mid);
    }

    void mergeArray(int* arr, int* left_arr, int left_ln, int* right_arr, int right_ln){
        i,j,k;

        i = 0; j = 0; k =0;

        while(i<left_ln && j< right_ln) {
            total_iteration++;
            if(left_arr[i]  < right_arr[j]) arr[k++] = left_arr[i++];
            else arr[k++] = right_arr[j++];
        }
        while(i < left_ln){
            total_iteration++;
            arr[k++] = left_arr[i++];
        }
        while(j < right_ln){
            total_iteration++;
            arr[k++] = right_arr[j++];
        }
    }

    void computeTime(time_t s, time_t e){
        time_taken = double(e-s);
    }

    void report(){
        cout<<"_________________________"<<"\n";
        deb1(algo_name);
        deb3(arr,n);
        deb1(total_iteration);
        deb1(total_swap);
        cout<<"_________________________"<<"\n\n";
    }

    void reuse(int myarr[]){

            i=0;
            fo(i,n)
                arr[i] = myarr[i];


        total_iteration=0;
        total_swap=0;
        algo_name = "";
        time_complexity = "";
        space_complexity = "";
        time_taken = 0.0;
    }

    ~Sorting(){
        delete [] arr;
        arr = NULL;
    }
};
