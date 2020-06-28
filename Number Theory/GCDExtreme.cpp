//GCD EXTREME

/*

Given the value of N, you will have to find the value of G. The meaning of G is given in the following code
G=0;
for(i = 1 ; i < N ; i++)
   for(j = i+1 ; j <= N ; j++) 
       G+=gcd(i,j);
Here gcd() is a function that finds the greatest common divisor of the two input numbers.
Input
The input file contains at most 20000 lines of inputs. Each line contains an integer N (1 < N < 1000001). The meaning of N is given in the problem statement. Input is terminated by a line containing a single zero.
Output
For each line of input produce one line of output. This line contains the value of G for the corresponding N. The value of G will fit in a 64-bit signed integer.
Sample Input:
10
100
200000
0
Sample Output:
67
13015
143295493160

*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define N 1000001

int phi[N];
ll res[N],sum[N];

void solve()
{
    for(int i=1;i<N;i++)
		phi[i]=i;
    
	for(int i=2;i<N;i++)
	{
        if(phi[i]==i)
		{
            for(int j=i;j<N;j+=i)
			{
                phi[j]/=i;
                phi[j]*=i-1;
            }
        }
    }
    
	for(int i=1;i<N;i++)
	{
        for(int j=i;j<N;j+=i)
            res[j]=res[j]+1LL*i*phi[j/i];
    }
    
	for(int i=1;i<N;i++)
		res[i]-=i;
    
	sum[0]=0;
    
    for(int i=1;i<N;i++)
        sum[i]=sum[i-1]+res[i];

}
int main()
{
    solve();
    int n;
    while(scanf("%d",&n)!=EOF)
	{
        if(n==0) 
			return 0;
		cout<<sum[n]<<endl;
    }
    return 0;
}
