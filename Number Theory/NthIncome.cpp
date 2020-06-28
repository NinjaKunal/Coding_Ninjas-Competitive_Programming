//Income On Nth Day

/*

Daulat Ram is an affluent business man. After demonetization, IT raid was held at his accommodation in which all his money was seized. He is very eager to gain his money back, he started investing in certain ventures and earned out of them. On the first day, his income was Rs. X, followed by Rs. Y on the second day. Daulat Ram observed his growth as a function and wanted to calculate his income on the Nth day.
The function he found out was FN = FN-1 + FN-2 + FN-1×FN-2
Given his income on day 0 and day 1, calculate his income on the Nth day (yeah Its that simple).
Input:
The first line of input consists of a single integer T denoting number of test cases.

Each of the next T lines consists of three integers F0, F1 and N respectively.
Output:
For each test case, print a single integer FN, as the output can be large, calculate the answer modulo 10^9+7.
CONSTRAINTS:
1 ≤ T ≤ 10^5

0 ≤ F0, F1, N ≤ 10^9
Sample Input :
2
0 1 2
1 2 4
Sample Output:
1
107
Explanation
In the second test case his income on day 0 is 1 and the income on day 1 is 2. We need to calculate his income on day 4.

F0=1

F1=2

F2=1 + 2 + 1×2 = 5

F3=2 + 5 + 2×5 = 17

F4=5 + 17 + 5×17 = 107

*/


#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define MOD 1000000006
#define M 1000000007

ll a,b,c,d;

void fastFib(ll n,ll arr[])
{
    if(n == 0)
    {
        arr[0] = 0;
        arr[1] = 1;
        return;
    }
    fastFib((n/2),arr);
    a = arr[0];
    b = arr[1];
    c = 2*b - a;
    if(c < 0)
        c += MOD;
    c = (a * c) % MOD;
    d = (a*a + b*b) % MOD;
    if(n%2 == 0)
    {
        arr[0] = c;
        arr[1] = d;
    }
    else
    {
        arr[0] = d;
        arr[1] = c+d;
    }
}
ll power(ll base, ll exp,ll mod) {
    ll res=1;
    while(exp>0) {
       if(exp&1) res=(res*base)%mod;
       base=(base*base)%mod;
       exp/=2;
    }
    return res%mod;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    ll f,s,n;
	    cin>>f>>s;
	    cin>>n;
	    ll arr[2]={0};
	    
	    fastFib(n,arr);
	    
	    arr[1]-=arr[0];
	    arr[1]=(arr[1]+MOD)%MOD;
	    ll ans = power((1+ f),arr[1],M);
	    ans =  (ans*power(1+s,arr[0],M))%M;
	    ans =(ans-1+M)%M;
	    cout<<ans<<endl;
	}
    return 0;
}
