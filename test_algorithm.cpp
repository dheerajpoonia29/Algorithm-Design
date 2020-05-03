#include <iostream>
#include "array_based_algorithm.h"
#include "../tools/macros.h"

using namespace std;

int main()
{
    fastIO

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[] = {3,4,7,2,-3,1,4,2}, i;
    int n = sizeof(arr)/sizeof(arr[0]);

    ArrayAlgo ob(arr,n);
    DBx(ob.subArraySumEqualK(7))
    return 0;
}
