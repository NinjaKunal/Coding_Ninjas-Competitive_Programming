//STRING SEARCH

/*

Given two strings S and T, write a function to find if T is present as a substring inside S or not. If yes, return the starting index otherwise return -1.
Input format :

Line 1 : String S

Line 2 : String T

Sample Input 1:
WelcomeBack
come 
Sample Output 1:
3
Sample Input 2:
WelcomeBack
code
Sample Output 2:
-1

*/


// S and T - input strings
// You need to check if string T is present in S or not
#include<bits/stdc++.h>

int* getLPS(char T[])
{
	int m=strlen(T);
	
	int* lps=new int[m];
	
	int j=0,i=1;
	lps[0]=0;
	
	while(i<m)
	{
		if(T[i]==T[j])
		{
			lps[i]=j+1;
			++i;
			++j;
		}
		else
		{
			if(j!=0)
			{
				j=lps[j-1];
			}
			else
			{
				lps[i]=0;
				++i;
			}
		}
	}
	return lps;
	
}

int KMPsearch(char S[], char T[])
{
	int n=strlen(S);
	int m=strlen(T);
	
	int ans=-1;
	
	int* lps=getLPS(T);
	
	int i=0,j=0;
	
	while(i<n && j<m)
	{
		if(S[i]==T[j])
		{
			++i;
			++j;
		}
		if(j==m)
			ans=i-j;
		else if(S[i]!=T[j])
		{
			if(j!=0)
				j=lps[j-1];
			else
				++i;
		}
	}
	return ans;
}
int findString(char S[], char T[]) {
	return KMPsearch(S,T);
}
