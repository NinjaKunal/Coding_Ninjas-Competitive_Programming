//Find Prime Numbers From 1 to N

/*
Given a number N, find number of primes in the range [1,N].
Input:
The only line of input consists of a number N
Output:
Print the number of primes in the range [1,N].`
Constraints:
1≤N≤1000000
Sample Input :
3 
Sample Output -
2
*/


#include<bits/stdc++.h>
using namespace std;
int makeSieve(int n){
	bool isPrime[n+1];
	for(int i=0;i<=n;i++){
		isPrime[i] = true;
	}
	isPrime[0] = false;
	isPrime[1] = false;
	
	for(int i=2;i*i<=n;i++){
		if(isPrime[i] == true){
		
		for(int j=i*i;j<=n;j += i){
			isPrime[j] = false;
		}
	  }
	}
	
//	for(int i=0;i<=n;i++){
//		cout<<i<<" : "<<isPrime[i]<<endl;
//	}
  int count =0;
    for(int i=0;i<=n;i++){
    	if(isPrime[i]==true){
    		count++;
		}
	}
	
	return count;
	
}
int main(){
	int n;cin>>n;
    int nPrimes =	makeSieve(n);
    
    cout<<nPrimes<<endl;
	return 0;
}
