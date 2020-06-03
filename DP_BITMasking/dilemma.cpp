//DILEMMA

/*

Abhishek, a blind man recently bought N binary strings all of equal length .A binary string only contains '0's and '1's . The strings are numbered from 1 to N and all are distinct, but Abhishek can only differentiate between these strings by touching them. In one touch Abhishek can identify one character at a position of a string from the set. Find the minimum number of touches T Abhishek has to make so that he learn that all strings are different .
Constraints :
2<=N<=10
1<=|L|<=100 , L is length of the strings .
Input Format:
Line 1 : An Integer N, denoting the number of binary strings .
Next N lines : strings of equal length
Output Format:
Return the minimum number of touches
Sample Input :
2
111010
100100
Sample Output :
2

*/

int dp[105][1<<12];

int ft(int pos,int mask,vector<string>&v) 
{ 
	if(!(mask&(mask-1))&&mask) 
		return 0; 

	if(pos == -1 || mask == 0) 
		return 100000;

 	if(dp[pos][mask])
 		return dp[pos][mask]; 

 	int newmask1 = 0,newmask2 = 0,touches = 0; 
 	
  	for(int i = 0;i<v.size();i++) 
  	{
  		if(mask & (1<<i)) 
  		{
  			touches++;
  	 		if(v[i][pos] == '0')
  	  			newmask1 |= (1<<i); 
			else
  	   			newmask2 |= (1<<i);
  	   	} 
  	} 
  	    return dp[pos][mask] = min(ft(pos-1,newmask1,v)+ft(pos-1,newmask2,v)+touches,ft(pos-1,mask,v));
} 


int minimumTouchesRequired(int n, vector<string> v)
{ 
	return ft(v[0].size()-1,(1<<n)-1,v); 
}
