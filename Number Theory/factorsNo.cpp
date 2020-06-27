//Number Of Factors

/*
A number is called n-factorful if it has exactly n distinct prime factors. Given positive integers a, b, and n, your task is to find the number of integers between a and b, inclusive, that are n-factorful. We consider 1 to be 0-factorful.
Input
Your input will consist of a single integer T followed by a newline and T test cases. Each test cases consists of a single line containing integers a, b, and n as described above.
Output
Output for each test case one line containing the number of n-factorful integers in [a, b].
Constraints
T < 10000

1 ≤ a ≤ b ≤ 10^6

0 ≤ n ≤ 10
Sample Input
5
1 3 1
1 10 2
1 10 3
1 100 3
1 1000 0
Sample Output
2 
2
0
8
1
*/


#include<bits/stdc++.h>
using namespace std;

const int MAX = 1000025;
const int M = 11;

int dp[M][MAX], has[MAX], primes[MAX];

int main()
{
	for(int i=2; i<MAX; i++)
        if(!primes[i])
            for(int j = i; j < MAX; j += i)
                has[j] ++, primes[j] = 1;
    for(int i = 1; i < MAX; i ++)
        dp[has[i]][i] = 1;
    for(int i = 0; i < M; i ++)
        for(int j = 1; j < MAX; j ++)
            dp[i][j] += dp[i][j - 1];
    
    int t, n, a, b;
    cin >> t;
    while(t --)
	{
        cin >> a >> b >> n;
        cout << dp[n][b] - dp[n][a - 1] << endl;
    }
    
    return 0;
}
