//SEHWAG AND ETF

/*

Sehwag has been solving a lot of mathematical problems recently. He was learning ETF (Euler Totient Function) and found the topic quite interesting. So, he tried solving a question on ETF. He will be given two numbers L and R. He has to find the probability that the ETF of a number in the range [L, R] is divisible by a number K.
Input:
The first line contains the number of test cases i.e. T.
The next T lines will contain three integers L, R and K.
Output:
Print the answer in a new line after rounding off the first 6 digits after the decimal place.
Constraints:
1 <= T <= 10
1 <= L <= R <= 10^12
0 <= R - L <= 10^5
1 <= K <= 10^6
Sample Input:
3
1 4 2
2 5 2
3 10 4
Sample Output:
0.500000
0.750000
0.375000

*/


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int sieve[1000015];
     
int main()
{
	vector<int> primeVec;
    for(ll i = 2; i <= 1000003; i++)
	{
    	if (sieve[i] == 0)
		{
    		primeVec.push_back(i);
    		for (ll j = (ll)i*i; j <= 100050; j += i)
    			sieve[j] = 1;
    	}
    }
        
    int t;
    cin >> t;
    
	while (t--)
	{
    	ll l, r;
    	int k;
    
		cin >> l >> r >> k;
        
		vector<ll> v(r - l + 5);
        vector<ll> v2(r - l + 5);
        for (ll i = l; i <= r; i++)
		{
        	v[i - l] = i;
        	v2[i - l] = i;
        }
        for(vector<int>::iterator it = primeVec.begin(); it != primeVec.end(); it++)
		{
        	if (*it > sqrt(r))
        		break;
        	ll i;
        	if (l%(*it) == 0)
        		i = l;
        	else
        		i = ((l/(*it)) + 1)*(*it);
        	
			for (; i <= r; i = i + (*it))
			{
        		v[i - l] = (v[i - l]/(*it))*((*it) - 1);
        		
				while (v2[i - l]%(*it) == 0)
        			v2[i - l] = v2[i - l]/(*it);
        	}
        }
        
		int x = 0;
    	for (ll i = l; i <= r; i++)
		{
    			if(v2[i - l] != 1)
    				v[i - l] = (v[i - l]/v2[i - l])*(v2[i - l] - 1);
    			
				if(v[i - l]%k == 0)
    				x++;
    	}
    	
		cout << fixed << setprecision(6);
        cout << (float)x/(r - l + 1) << endl;
    }
}
