//MAXIMUM XOR SUBARRAY

/*
Given an array of n integers, find subarray whose xor is maximum.
Input Format
First line contains single integer n (1<=n<=1000000).
Next line contains n space separated integers.
Output Format
Print xor of the subarray whose xor of all elements in subarray is maximum over all subarrays.
Constraints
1 <= n <= 1000000
1 <= A[i] <=100000 
Sample Input
4
1 2 3 4
Sample Output
7
*/

 
#include<bits/stdc++.h> 
using namespace std; 
  
#define INT_SIZE 32 
   
struct TrieNode 
{ 
    int value;  // Only used in leaf nodes 
    TrieNode *arr[2]; 
}; 
  
// Utility function to create a Trie node 
TrieNode *newNode() 
{ 
    TrieNode *temp = new TrieNode; 
    temp->value = 0; 
    temp->arr[0] = temp->arr[1] = NULL; 
    return temp; 
} 
  
void insert(TrieNode *root, int pre_xor) 
{ 
    TrieNode *temp = root; 
   
    for (int i=INT_SIZE-1; i>=0; i--) 
    {  
        bool val = pre_xor & (1<<i); 
  
        if (temp->arr[val] == NULL) 
            temp->arr[val] = newNode(); 
  
        temp = temp->arr[val]; 
    } 
   
    temp->value = pre_xor; 
} 
   
int query(TrieNode *root, int pre_xor) 
{ 
    TrieNode *temp = root; 
    for (int i=INT_SIZE-1; i>=0; i--) 
    {  
        bool val = pre_xor & (1<<i); 
  
    
        if (temp->arr[1-val]!=NULL) 
            temp = temp->arr[1-val]; 
  
        else if (temp->arr[val] != NULL) 
            temp = temp->arr[val]; 
    } 
    return pre_xor^(temp->value); 
} 
  
int maxSubarrayXOR(int arr[], int n) 
{ 
    TrieNode *root = newNode(); 
    insert(root, 0); 
  
    int result = INT_MIN, pre_xor =0; 
  
    for (int i=0; i<n; i++) 
    { 
        pre_xor = pre_xor^arr[i]; 
        insert(root, pre_xor); 
        result = max(result, query(root, pre_xor)); 
    } 
    return result; 
} 
  
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<maxSubarrayXOR(a,n);
    return 0;
}
