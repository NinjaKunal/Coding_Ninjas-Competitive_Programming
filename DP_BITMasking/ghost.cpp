//GHOST TYPE

/*

Gengar has got an integer N. Now using his ghostly powers, he can create the permutation from 1 to N of this given number.
Since, he's a special kind of Poke'mon, so he thinks he deserves special permutations. He wants to find the total number of special permutations of length N, consisting of the integers from 1 to N
.

A permutation is called special if it satisfies following condition:
If Ap & Aq == Ap, then p < q, where p and q are two distinct indices of permutation and A is the permutation itself. "&" denotes the bitwise and operation.
Help Gengar in finding the number of such permutations.
Input format:
The only line of input will consist of a single integer N denoting the length of the permutation.
Output format:
Output the total number of special permutations of length N
.

Constraints:
1 ≤ N ≤ 20

SAMPLE INPUT
4

SAMPLE OUTPUT
8

Explanation
All the special permutations of length 4 are: 1 2 3 4

1 2 4 3

1 4 2 3

2 1 3 4

2 1 4 3

2 4 1 3

4 1 2 3

4 2 1 3

*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll check(ll mask,int* dp,int n)
{
    if(dp[mask]!=-1) return dp[mask];
    if(mask==((1<<n)-1))
        return 1;
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        if(((mask>>i)&1)==0)
        {
            ll ans1=1;
            for(ll j=0;j<i;j++)
            {
                if(((j+1)&(i+1))==(j+1) && ((mask>>j)&1)==0)
                {
                    ans1=0;
                    break;
                }
            }
            if(ans1)
            {
                ans+=check(mask|(1<<i),dp,n);
 
            }
        }
    }
    dp[mask]=ans;
    return ans;
}

int main()
{
    int n,c=0;
    cin>>n;
    int* dp = new int[1<<n]();
    for(int i=0;i<(1<<n);i++)
        dp[i]=-1;
    
        cout<<check(0,dp,n);

    return 0;
}
