#include <iostream>
#include <algorithm>
#include "../tools/macros.h"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[] = {2,2,1,4,4,2,4,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    Searching ob = new Searching(arr,n,);

    return 0;
}
