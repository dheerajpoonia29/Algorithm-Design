//#include "bit_manipulation.h"
#include "array_manipulation.h"

int main()
{
    fastio

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[]={1,4,4};
    //int arr[] = {2,3,1,2,4,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    ArrayAlgo ob(arr,n);

    DBx(ob.minSizeSubarraySum(3))

    return 0;
}
