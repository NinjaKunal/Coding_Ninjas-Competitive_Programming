//DISTINCT QUERY

/*
Given a sequence of n numbers a1, a2, ..., an and a number of d-queries. A d-query is a pair (i, j) (1 ≤ i ≤ j ≤ n). For each d-query (i, j), you have to return the number of distinct elements in the subsequence ai, ai+1, ..., aj.
Input
Line 1: n (1 ≤ n ≤ 30000).
Line 2: n numbers a1, a2, ..., an (1 ≤ ai ≤ 10^6).
Line 3: q (1 ≤ q ≤ 200000), the number of d-queries.
In the next q lines, each line contains 2 numbers i, j representing a d-query (1 ≤ i ≤ j ≤ n).
Output
For each d-query (i, j), print the number of distinct elements in the subsequence ai, ai+1, ..., aj in a single line.
Sample Input
5
1 1 2 1 3
3
1 5
2 4
3 5
Sample Output
3
2
3 
*/

#include <bits/stdc++.h>
using namespace std;

struct range{
    int id,f,s;
};

bool compare(range a, range b){
    return a.s<b.s;
}

void update(int id,int val,int n,int* BIT){
    for(;id<=n;id+=(id&(-id)))
        BIT[id]+=val;
}

int query(int id, int* BIT){
    int count=0;
    for(;id>0;id-=(id&(-id))){
        count+=BIT[id];
    }
    return count;
}

int main()
{
    int n,q;
    cin>>n;
    int* arr = new int[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    
    cin>>q;
    range* qu = new range[q];
    for(int i=0;i<q;i++){
        cin>>qu[i].f>>qu[i].s;
        qu[i].id=i;
    }
    sort(qu,qu+q,compare);
    int* BIT = new int[n+1]();
    int* ans = new int[q]();
    int* last = new int[1000001];
    int total = 0;
    int k=0;
    for(int i=0;i<1000001;i++)
        last[i]=-1;
    for(int i=1;i<=n;i++)
    {
        if(last[arr[i]]!=-1){
            update(last[arr[i]],-1,n,BIT);
        }else{
            total++;
        }
        update(i,1,n,BIT);
        last[arr[i]]=i;
        while(k<q && qu[k].s==i){
            ans[qu[k].id] = total - query(qu[k].f-1,BIT);
            k++;
        }
        
    }
    for(int i=0;i<q;i++)
        cout<<ans[i]<<endl;
        
        return 0;
}
