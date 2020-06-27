//Strange Order

/*
Given an integer n . Initially you have permutation p of size n : p[i] = i . To build new array a from p following steps are done while permutation p is not empty:
Choose maximum existing element in p and define it as x ; Choose all such y in p that gcd ( x , y ) ≠ 1 ; Add all chosen numbers into array a in decreasing order and remove them from permutation. Your task is to find a after p became empty.
Note: gcd ( a , b ) is the greatest common divisor of integers a and b .
Input format
Input contains single integer n ( 1 ≤ n ≤ 2 * 10^6) — the size of permutation p p.
Output format
Print n integers — array a .
Sample Input:
5
Sample Output:
5 4 2 3 1
Explanation
It's needed 4 iterations to create array a:
Add 5
Add 4 and 2
Add 3
Add 1
*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main()
{
	ll n;
  	cin>>n;
  
  	ll spf[n+1];
  	for(ll h=0;h<=n;h++)
    	spf[h]=h;
  
  	for(ll y=2;y*y<=n;y++)
    	if(spf[y]==y)
      		for(ll i=2*y;i<=n;i+=y)
        		if(spf[i]==i)
          			spf[i]=y;
  
  	ll arr[n+1];
  	
	  for(ll h=0;h<=n;h++)
    	arr[h]=-1;
  
  	ll in=1;
  	for(ll h=n;h>=2;h--)
  	{
    	if(arr[h]!=-1)
      		continue;
    
    	ll num=h;
    	while(num!=1)
    	{
    		ll tmp=spf[num];
    		for(ll p=h;p>=tmp;p-=tmp)
      			if(arr[p]==-1)
      				arr[p]=in;
      
      		num=num/spf[num];
    	}
    in++;
  	}
  	
	arr[1]=in;
  	vector<ll> *v;
  	v=new vector<ll>[in+1];
  
  	for(ll j=n;j>=1;j--)
    	v[arr[j]].push_back(j);
  
  	for(ll r=1;r<=in;r++)
    	for(ll h=0;h<v[r].size();h++)
      		cout<<v[r][h]<<" ";
  	
	return 0;
}
