//Innocent Swaps and His Emotions

/*

There are only three phases in Swaps life: Sleep, Play and Study. Also, there are two types of emotions Swaps experiences: Happy and Sad. Each phase of his life brings either kind of emotions.
The sleep and the play phase makes Swaps happy whereas the study phase makes him sad. Quite obvious, isn't it? But we know that life isn't that great, one cannot be happy all the time.
Swaps, being a very sensitive guy, doesn't like to mix his emotions in a particular day. So each day, he is in exactly one of the three phases.
Given N which denotes the number of days and K which denotes the exact number of days Swaps needs to be happy out of these N days, can you tell him in how many ways can he achieve this? Since the output value can be very large, take modulo with 1000000007(10^9+7)
Input:
The first line of the input contains T, denoting the number of test cases.

The next T lines contain two space-separated integers N and K.
Output:
For each test-case, output a single integer, the number of ways modulo 1000000007(10^9+7).
Constraints:
1 ≤ T ≤ 10^5
1 ≤ N ≤ 10^6
1 ≤ K ≤ 10^6
K ≤ N
Sample Input :
3
1 1
2 1
3 2
Sample Output:
2
4
12
Explanation
In the first test case, he needs to be happy on Day 1. Hence, answer is 2 (He can either play or sleep).

In the second test case, he can be happy either on Day 1 or Day 2. So number of ways = 4.

*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MOD 1000000007

ll power(ll a,ll b)
{
	ll res=1;
 
    while(b)
    {
    	if(b%2)
        	res=(res*a)%MOD;
        
		b=b>>1;
        a=(a*a)%MOD;
	}
 
    return res;
}
 
ll dp[1000001];
 
int main()
{
    dp[0]=1;
    
	for(ll i=1;i<=1000000;i++)
    	dp[i]=(i*(dp[i-1]))%MOD;
 
 
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
                   
        ll temp1,temp2;

        temp1=power(2,k)%MOD;
        temp2=(dp[n]%MOD*power((dp[k]%MOD*dp[n-k]%MOD)%MOD,MOD-2)%MOD)%MOD;
        cout<<(temp1*temp2)%MOD<<'\n';
    }
    return 0;
}
