//WARM RECEPTION

/*
There is only one beauty parlour in the town CodingNinjasLand. The receptionist at the beauty parlor is flooded with appointment requests because the “Hakori” festival is round the corner and everyone wants to look good on it.
She needs your help. The problem is they don’t have chairs in reception. They are ordering chairs from NinjasKart. They don’t want to order more than required. You have to tell the minimum number of chairs required such that none of the customers has to stand.
Input Format :
First line contains the number of customers that will come. Second line contains N space-separated integers which represent the arrival timings of the customer. Third line contains N space-separated integers which represent the departure timings of the customer. Arrival and departure timings are given in 24-hour clock.
Constraints:
1<= N <= 100
Arrival and departure timings lie in the range [0000 to 2359]
Time Limit: 1 second
Output Format :
You have to print the minimum number of chairs required such that no customer has to wait standing. 
Sample Test Cases:
Sample Input 1 :
5
900 1000 1100 1030 1600
1900 1300 1130 1130 1800
Sample Output 1:
4
Explanation:
4 because at 1100 hours, we will have maximum number of customers at the shop, throughout the day. And that maximum number is 4. 
*/

#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    multimap<int,char> m;
    int arrive[n],depart[n];
    for(int i=0;i<n;i++)
        cin>>arrive[i];
    for(int i=0;i<n;i++)
        cin>>depart[i];
    for(int i=0;i<n;i++)
    {
        m.insert(make_pair(arrive[i], 'a'));
        m.insert(make_pair(depart[i], 'd'));
    }
    int result=0,chair=0;
    multimap<int, char>::iterator it;
    for(it=m.begin();it!=m.end();it++){
        if ((*it).second == 'a') 
            chair++; 
        else
            chair--; 
  
        if (chair>result) 
            result = chair; 
    }
     cout<<result;   
    
}
