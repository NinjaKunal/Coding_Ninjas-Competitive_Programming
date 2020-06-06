//COUNTING STRINGS

/*
Given a string 's' consisting of upper case alphabets, i.e. from 'A' to 'Z'. Your task is to find how many strings 't' with length equal to that of 's', also consisting of upper case alphabets are there satisfying the following conditions:
-> String 't' is lexicographical larger than string 's'.
-> When you write both 's' and 't' in the reverse order, 't' is still lexicographical larger than 's'.
Find out number of such strings 't'. As the answer could be very large, take modulo 10^9 + 7.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1000000007

#include<bits/stdc++.h>
using namespace std;

ll ans[100001];

int find(string s)
{
  string str="";
  int n=s.length();

  for(int i=n-1; i>=1; i--)
    str.push_back(s.at(i));
  for(int i=0;i<n-1;i++)
    ans[i]=(ans[i-1]*26%MOD+90-str.at(i))%MOD;
  ll a=0;
  ans[-1]=0;

  for(int i=0;i<n;i++)
    a=(a+(90-s.at(i))*(ans[n-i-2]+1)%MOD)%MOD;
  return a;
}

int countStrings(char* s) {
    int i=0;
    string s1="";
    while(s[i]!='\0'){
        s1=s1+s[i];
        i++;
    }
    
    return find(s1);
}

int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL) ; 
	
	char s[100005];
  cin>>s;
  int ans = countStrings(s);
  cout<<ans<<endl;

  return 0 ; 
 }
 
