

int linearSearch(int arr[], int n, int sk)
{
    int ki = -1;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == sk)
        {
            ki = i;
            break;
        }
    }
    return ki;
}



int binarySearch(vector<int> arr, x)
{
    int a = 0, b = n - 1;
    while (a <= b)
    {
        int k = (a + b) / 2;
        if (arr[k] == x)
        {
            // x found at index k
            return k;
        }
        if (arr[k] > x)
            b = k - 1;
        else a = k + 1;
    }
}
/*
int recursiveBinarySearch(vector<int> arr, int sk)
{
	int low=0, int high=arr.size()-1, mid;
	int ki=-1;

	if(low>high){
			return -1;
	}
	int mid=(low+high)/2;
	if(a[mid]==sk){
			return mid;
	}
	else if(a[mid]<sk)
	{
			low=mid+1;
	}
	else
	{
			high=mid-1;
	}
	return binarySearch(low, high, key);
}

int lowerBound(int low, int high){

	while(low<=high){
						total_iteration++;
						int mid = low + (high - low) / 2;
						if(arr[mid]<sk){
								low=mid+1;
						}
						else if(arr[mid]>=sk){
								high=mid-1;
								ki=mid;
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
						if(arr[mid]<=sk){
								low=mid+1;
								ki=mid;
						}
						else if(arr[mid]>sk){
								high=mid-1;
						}
		}
}

-------other implementation------------
void lower&upperBound(int arr[], int target){
	int n = A.size();
	int i = 0, j = n - 1;
	int start = -1, end = -1;

	// FIND FIRST -> LOWER BOUND
	while (i < j)
	{
			int mid = (i + j) /2;
			if (A[mid] < target) i = mid + 1;
			else j = mid;
	}
	if (A[i] != target) return 0; // target not exit

	start = i;  <- LB

	// FINDLAST   -> UPPER BOUND
	j = n - 1;  // We don't have to set i to 0 the second time.
	while (i < j)
	{
			int mid = (i + j) /2 + 1;   // Make mid biased to the right
			if (A[mid] > target) j = mid - 1;
			else i = mid;
	}
	end = j;    <- UB
}
*/

int findSqrt(int n)
{
    int low = 1, high = n, ans;
    long long mid;
    while(low <= high)
    {
        mid = low + (high - low) / 2;
        if(mid * mid == n)
            return mid;
        else if(mid * mid < n)
        {
            ans = mid;
            // till now ans is sqrt but it may possbile that we find higher closet sqrt of number n
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int countDuplicateInSortedArray(vector<int> A, int B)
{
    int start_idx = lb(A, B, 0, 0);
    if(A[start_idx] != B)
        start_idx = -1;

    int end_idx = ub(A, B, 0, 0) - 1;
    if(A[end_idx] != B)
        end_idx = -1;

    if(start_idx != -1 && end_idx != -1)
    {
        return end_idx - start_idx;
    }
    return -1;
}

int findPower(int base, int exponent)
{

}