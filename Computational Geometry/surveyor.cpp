//SURVEYOR

/*

A plot has been surveyed. Its boundary consists of segments that form a polygon. Each segment runs either North-South or East-West. Calculate the enclosed area.
The i-th character of direction and the i-th element of length describe the direction and length of the i-th segment of the polygon's boundary as the surveyor walked it. If you start at the surveyor's starting point and walk according to the sequence of directions and lengths reported by the surveyor, you will traverse the boundary of the polygon, ending up back at the starting point. This traversal described by the given segments may be either clockwise or counterclockwise.
Input Format
String s
Array of length of string
Output Format
Area
Constraints
direction will have between 4 and 50 characters inclusive.
length will have the same number of elements as the number of characters in direction.
Each element of direction will be an uppercase letter 'N', 'E', 'S', or 'W'.
Each element of length will be between 1 and 1000 inclusive.
The segments will represent a simple polygon. No two segments will touch or intersect (except that the last point of a segment is the first point of the next segment, and the last point of the final segment is the first point of the first segment).
Sample Test Case
"NWWSE"
{10,3,7,10,10}
Returns: 100


"NESWNWSW"
{20,200,30,100,20,30,10,70}
Returns: 4700

*/


#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
int main()
{
    string s;
    cin>>s;
    ll n=s.size();
    ll a[n];
    ll cor[n][2];
    for(ll i=0;i<s.size();i++)
        cin>>a[i];
    cor[0][0]=0;
    cor[0][1]=0;
    for(ll i=1;i<n;i++)
    {
        if(s[i-1]=='N')
        {
            cor[i][1] = cor[i-1][1] + a[i-1];
            cor[i][0] = cor[i-1][0];
        }
        else if(s[i-1]=='S')
        {
            cor[i][1] = cor[i-1][1] - a[i-1];
            cor[i][0] = cor[i-1][0];
        }
        else if(s[i-1]=='W')
        {
            cor[i][0] = cor[i-1][0] - a[i-1];
            cor[i][1] = cor[i-1][1];
        }
        else if(s[i-1]=='E')
        {
            cor[i][0] = cor[i-1][0] + a[i-1];
            cor[i][1] = cor[i-1][1];
        }
    }
    ll area=0;
    for(ll i=1;i<n;i++)
    {
        //cout<<"cor"<<"["<<i<<"]:"<<"("<<cor[i][0]<<","<<cor[i][1]<<")\n";
        area += (cor[i-1][0]*cor[i][1] - cor[i][0]*cor[i-1][1]);
    }
    cout<<abs(area/2);
    return 0;
}
