//INVERSION COUNT

/*
Let A[0 ... n-1] be an array of n distinct positive integers. If i < j and A[i] > A[j] then the pair (i, j) is called an inversion of A (where i and j are indexes of A). Given an integer array A, your task is to find the number of inversions in A.
Input format :
Line 1 : n, array size
Line 2 : Array elements (separated by space).
Output format :
Count of inversions
Constraints :
1 <= n <= 10^5
1 <= A[i] <= 10^9
Sample Input 1 :
3
3 2 1
Sample Output 1 :
3
Sample Input 2 :
5
2 5 1 3 4
Sample Output 1 :
4
*/

typedef long long int ll;

ll merging(int arr[], ll temp[], ll left,ll mid, ll right) 
{ 
    ll i, j, k; 
    ll count = 0; 
  
    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right)) { 
        if (arr[i] <= arr[j]) { 
            temp[k++] = arr[i++]; 
        } 
        else { 
            temp[k++] = arr[j++]; 
            count += (mid - i); 
        } 
    } 
    while (i <= mid - 1) 
        temp[k++] = arr[i++]; 
    while (j <= right) 
        temp[k++] = arr[j++]; 
    for (i = left; i <= right; i++) 
        arr[i] = temp[i]; 
  
    return count; 
}
  
ll mergeSort(int arr[], ll temp[], ll left, ll right) 
{ 
    ll mid, count = 0; 
    if (right > left) { 
        mid = (right + left) / 2; 
  
        count += mergeSort(arr, temp, left, mid); 
        count += mergeSort(arr, temp, mid + 1, right); 
        count += merging(arr, temp, left, mid + 1, right); 
    } 
    return count; 
}
long long solve(int A[], int size)
{   ll temp[size];
    ll n =size;
	return mergeSort(A, temp, 0, n - 1);
}
