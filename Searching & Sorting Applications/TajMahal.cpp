//TAJ MAHAL ENTRY

/*
Taj Mahal is one of the seven wonders of the world. Aahad loves to travel places and wants to visit Taj Mahal. He visited Agra to view Taj Mahal. There is a ticketing system at Taj Mahal. There are total ‘n’ windows which provide the tickets to get entry into Taj Mahal. There are ‘Ai’ people already present at each window to get the tickets. Each window gives ticket to one person in one minute. Initially, Aahad stands in front of the first window. After each minute, if he didn’t get the ticket, he moves on to the next window to get the ticket. If he is at window 1, he will move to 2. If at 2nd, he will move to 3rd. If he is at last window, he will move to 1st again and so on. Find the window number at which he will get the ticket.
Input Format:
First line contains a single integer ‘n’ denoting the no. of windows.
Next line contains ‘n’ space separated integers denoting the no. of people already standing in front of the ith window. (1 <= i <= n)
Output Format:
Print a single integer denoting the window number that Aahad will get ticket from.
Constraints:
1 <= n <= 10^5
1 <= Ai <= 10^9
Sample Input:
4
2 3 2 0
Sample Output:
3
Explanation:
Aahad at Window 1: [2, 3, 2, 0]
Aahad at Window 2: [1, 2, 1, 0]
Aahad at Window 3: [0, 1, 0, 0]
So, when Aahad is at window 3, he got zero people before him. Hence, he will get the ticket at window 3.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int  main()
{
	int i,n,minIndex=0;
	vector<int> v1;
	vector<int> v2;
	ll p,t,min=INT_MAX;
	cin>>n;
	for(i=0;i<n;++i)
	{
		cin>>t;
		v1.push_back(t);
	}
	for(i=0;i<n;++i)
	{
		p=(v1[i]-i);
		t=p/n;
		if((p%n!=0)&&(p>=0))
			v2.push_back(n*(t+1)+i);
		else
			v2.push_back(n*t+i);
	}
	for(i=0;i<n;++i)
	{
		if(v2[i]<min)
		{
			min=v2[i];
			minIndex=i+1;
		}
	}
	cout<<minIndex<<endl;
	return 0;
}
