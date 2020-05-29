//INCSEQ

/*
Given a sequence of N (1 ≤ N ≤ 10,000) integers S1, ..., SN (0 ≤ Si < 100,000), compute the number of increasing subsequences of S with length K (1 ≤ K ≤ 50 and K ≤ N); that is, the number of K-tuples i1, ..., iK such that 1 ≤ i1 < ... < iK ≤ N and Si1 < ... < SiK.
Input
The first line contains the two integers N and K. The following N lines contain the integers of the sequence in order.
Output
Print a single integer representing the number of increasing subsequences of S of length K, modulo 5,000,000.
Sample Input
4 3
1
2
2
10
Output:
2
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n , k , ans = 0 , mod = 5000000 ;
ll tree[51][100000+10] ;

void update(int id,int j ,ll val)
{
    while(id<=100005)
    {
        tree[j][id]=(tree[j][id]+val)%mod;
        id+=id&(-id);
    }
}

ll query(int id,int j)
{
    ll sum=0;
    while(id>0)
    {
        sum=(sum+tree[j][id])%mod;
        id-=id&(-id);
    }
    return sum;
}

int main()
{
    cin>>n>>k;
    for(int j=1;j<=n;j++)
    {
        int a ;
        cin>>a;
        a++;
        for(int i=1;i<=k;i++)
        {
            ll p =  i == 1 ? 1 : query(a-1,i-1);
            update(a,i,p);
            if(i==k) ans=(ans+p)%mod;
        }
    }
    cout << ans << endl ;
    return 0;
}
