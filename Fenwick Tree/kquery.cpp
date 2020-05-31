//KQUERY

/*
Given a sequence of n numbers a1, a2, ..., an and a number of k- queries. A k-query is a triple (i, j, k) (1 ≤ i ≤ j ≤ n). For each k-query (i, j, k), you have to return the number of elements greater than k in the subsequence ai, ai+1, ..., aj.
Input Format
Line 1: n (1 ≤ n ≤ 30000).

Line 2: n numbers a1, a2, ..., an (1 ≤ ai ≤ 10^9).

Line 3: q (1 ≤ q ≤ 200000), the number of k- queries.

In the next q lines, each line contains 3 numbers i, j, k representing a k-query (1 ≤ i ≤ j ≤ n, 1 ≤ k ≤ 10^9).
Output Format
For each k-query (i, j, k), print the number of elements greater than k in the subsequence ai, ai+1, ..., aj in a single line.
Sample Input
5
5 1 2 3 4
3
2 4 1
4 4 4
1 5 2 
Sample Output
2
0
3 
*/


#include<bits/stdc++.h>
using namespace std;
int btree[30009];

struct pos
{
    int l,r,p;
    long long int v;
};

pos a[230009];

bool compare(pos a, pos b)
{
    if(a.v == b.v)
        return a.l > b.l;
    return a.v > b.v;
}

void update(int idx, int n)
{
    while(idx <=n)
    {
        btree[idx] += 1;
        idx += idx & (-idx);
    }
}

int query(int idx)
{
    int s=0;
    while(idx >0)
    {
        s += btree[idx];
        idx -= idx &(-idx);
    }
    return s;
}

int main()
{
    fill(btree,btree + 30009, 0);
    
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
    	cin>>a[i].v;
        a[i].l = 0;
        a[i].p =0;
        a[i].r = i+1;
    }
    int q;
    cin>>q;
    int ans[q+1];

    for(int i=n;i<n+q;i++)
    {
    	cin>>a[i].l>>a[i].r>>a[i].v;
        a[i].p = i-n+1;
    }
    sort(a,a+n+q,compare);

    for(int i=0;i<n+q;i++)
	{
		if(a[i].l == 0)
        	update(a[i].r,n + 9);
    	else
        	ans[a[i].p] = query(a[i].r) - query(a[i].l -1);
    }
    
    for(int i=1;i<=q;i++)
    	cout<<ans[i]<<"\n";
    return 0;
}
