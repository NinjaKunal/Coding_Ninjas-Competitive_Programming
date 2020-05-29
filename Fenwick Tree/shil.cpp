//SHIL AND WAVE SEQUENCE

/*
Given a sequence A1 , A2 , A3 .. AN of length N . Find total number of wave subsequences having length greater than 1.
Wave subsequence of sequence A1 , A2 , A3 .. AN is defined as a set of integers i1 , i2 .. ik such that Ai1 < Ai2 > Ai3 < Ai4 .... or Ai1 > Ai2 < Ai3 > Ai4 .... and i1 < i2 < ...< ik.Two subsequences i1 , i2 .. ik and j1 , j2 .. jm are considered different if k != m or there exists some index l such that il ! = jl
INPUT
First line of input consists of integer N denoting total length of sequence.Next line consists of N integers A1 , A2 , A3 .. AN .
OUTPUT
Output total number of wave subsequences of given sequence . Since answer can be large, output it modulo 10^9+7
CONSTRAINTS
1 ≤ N ≤ 10^5

1 ≤ Ai ≤ 10^5
SAMPLE INPUT
5
1 3 5 4 2
SAMPLE OUTPUT
17
Explanation
All the possible sequences are: [ 1 3 ] , [1 5 ] , [ 1 4 ] , [1 2 ] , [1 3 2] , [1 4 2 ] , [1 5 2] , [1 5 4] , [3 5] , [3 4] , [3 2] , [3 5 2] , [3 4 2] , [3 5 4] , [5 4] , [5 2 ] , [4 2] . Note that value in the bracket are the values from the original sequence whose positions are maintained.
*/

    #include<bits/stdc++.h>
    using namespace std;
    const int N = 200005,mod = 1000000007;
    long long bit[N][2];
    void update(int idx,long long val,int k)
    {
        while(idx<N)
        {
            bit[idx][k]+=val;
            idx+=(idx&-idx);
        }
    }
    long long query(int idx,int k)
    {
        long long res = 0;
        while(idx>0)
        {
            res=(res + bit[idx][k])%mod;
            idx-=(idx&-idx); 
        }
        return res;
    }
    int main()
    {
        int n;
        cin>>n;
        long long a[n+1];
        vector<long long> v;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            v.push_back(a[i]);
        }
        v.push_back(0ll);
        sort(v.begin(),v.end());
        v.resize(unique(v.begin(),v.end())-v.begin());
        long long ans = 0;
        for(int i=1;i<=n;i++)
        {
            int idx = lower_bound(v.begin(),v.end(),a[i]) - v.begin();
            long long a = query(idx-1,0);
            long long b = (query(n,1) - query(idx,1)+mod)%mod;
            ans = (ans + a + b)%mod;
            update(idx,a+1,1);
            update(idx,b+1,0);
        }
        cout<<ans<<endl;
        return 0;
    }
