//Divisors Of Factorial

/*
Given a number, find the total number of divisors of the factorial of the number.
Since the answer can be very large, print answer modulo 10^9+7.
Input
The first line contains T, number of testcases.


T lines follows each containing the number N.
Output
Print T lines of output each containing the answer.
Constraints
1 <= T <= 500

0 <= N <= 50000
Sample Input:
3
2
3
4
Sample Output:
2
4
8
*/


#include <bits/stdc++.h>
using namespace std;
const long long int mod=1000000000+7;
bool primes[50001];
int prime[50001];
int counter=0;
void sieve()
{
	memset(primes,false,sizeof(primes));
	for(int i=2;i<50001;i++)
	{
		if(!primes[i])
		{
			prime[counter++]=i;
			for(int j=i;j<50001;j+=i)
			primes[j]=true;
		}
	}
}

int power(int x,int y)
{
	int count=0;
	long long int z=y;
	while(x>=z)
	{
		count+=(x/z);
		z*=(long long int)y;
	}
	return count;
}

int main() {
	int t,n;
	sieve();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		long long int ans=1;
		for(int i=0;i<counter;i++)
		{
			int powers=power(n,prime[i]);
			if(powers==0)break;
			ans=(ans*((long long int)(powers+1)))%mod;
		}
		ans=ans%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
