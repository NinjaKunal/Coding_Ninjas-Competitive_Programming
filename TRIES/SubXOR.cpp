//SUBXOR

/*
A straightforward question. Given an array of positive integers you have to print the number of subarrays whose XOR is less than K. Subarrays are defined as a sequence of continuous elements Ai, Ai+1, ..., Aj . XOR of a subarray is defined as Ai ^ Ai+1 ^ ... ^ Aj. Symbol ^ is Exclusive Or.
Input Format
First line contains T, the number of test cases. 
Each of the test case consists of N and K in one line, followed by N space separated integers in next line.
Output Format
For each test case, print the required answer.
Constraints:
1 ≤ T ≤ 5
1 ≤ N ≤ 10^5
1 ≤ A[i] ≤ 10^5
1 ≤ K ≤ 10^6
Sample Input
1
5 2
4 1 3 2 7   
Sample Output
3
*/

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int lCount,rCount;
    Node *lChild,*rChild;
    
};
Node *CreateNode()
    {
    
    Node *pNode = NULL;
 
    pNode = (struct Node *)malloc(sizeof(Node));
 
    if (pNode)
    {
        pNode->lCount=pNode->rCount=0;
        pNode->lChild =pNode->rChild =NULL;
 
    }
 
    return pNode;
    }
void addBit(Node *root,int n)
{
    for(int i=20;i>=0;i--)
    {
        int x= (n>>i) & 1;
    
        if(x)
        {
            root->rCount++;
            if(root->rChild == NULL)
                root->rChild = CreateNode();
            root = root->rChild;
        }
        else
        {
            root->lCount++;
            if(root->lChild == NULL)
                root->lChild = CreateNode();
            root = root->lChild;
        }
    }
}
int query(Node *root,int n,int k)
{
    if(root == NULL)
        return 0;
    int res = 0;
    for(int i=20;i>=0;i--)
    {
        bool ch1=(k>>i) & 1;
        bool ch2=(n>>i) & 1;
        if(ch1)
        {
            if(ch2){
                res+=root->rCount;
                if(root->lChild == NULL)
                    return res;
                root = root->lChild;
            }
 
            else{
                res+=root->lCount;
                if(root->rChild == NULL)
                    return res;
                root = root->rChild;
            }
        }
        else
        {
            if(ch2){
                if(root->rChild == NULL)
                    return res;
                root= root->rChild;
            }
            else{
                if(root->lChild == NULL)
                    return res;
                root= root->lChild;
            }
        }
    }
    return res;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int temp,temp1,temp2=0;
        Node *root = CreateNode();
        addBit(root,0);
        long long total =0;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            temp1= temp2^temp;
            total+=(long long)query(root,temp1,k);
            addBit(root , temp1);
            temp2 = temp1;
        }
        printf("%lld\n",total);
    }
    return 0;
}



/*
// Same logic but showing Runtime Error
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Trie
{
    int lc[2];
    Trie* a[2];
    
};

Trie *newNode() 
{ 
    Trie* temp = new Trie; 
    temp->lc[0]=temp->lc[1]=0;
    temp->a[0] = temp->a[1] = NULL; 
    return temp; 
}

void insert(Trie* root,int pre_xor)
{
	Trie* temp=root;
    for(int i=20;i>=0;i--)
    {
        int cb= pre_xor & (1<<i);
    	if(temp->a[cb] == NULL)
            temp->a[cb] = newNode();
        temp = temp->a[cb];
    }
}

int query(Trie *root,int pre_xor,int k)
{
    if(root == NULL)
        return 0;
    int res = 0;
    Trie* temp=root;
    for(int i=20;i>=0;i--)
    {
        bool kcb=k & (1<<i);
        bool pcb=pre_xor & (1<<i);
        if(kcb)
        {
            if(pcb)
			{
                res+=temp->lc[pcb];
                if(temp->a[1-pcb]== NULL)
                    return res;
                temp=temp->a[1-pcb];
            }
 			else
			{
				res+=temp->lc[pcb];
                if(temp->a[1-pcb] == NULL)
                    return res;
                temp= temp->a[1-pcb];
            }
        }
        else
        {
            if(pcb)
			{
                if(temp->a[pcb] == NULL)
                    return res;
                temp= temp->a[pcb];
            }
            else
			{
                if(temp->a[pcb] == NULL)
                    return res;
                temp= temp->a[pcb];
            }
        }
    }
    return res;
}

ll SubXor(int* a, int n, int k)
{
	Trie* root= newNode();
	insert(root,0);
	ll res=0;
	int pre_xor=0;
	 
	for(int i=0;i<n;++i)
	{
		pre_xor^=a[i];
		res+=query(root,pre_xor,k);
		insert(root,pre_xor);
	}
	
	return res;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int* a=new int[n];
        
        for(int i=0;i<n;i++)
        	cin>>a[i];
        cout<<SubXor(a,n,k)<<endl;
    }
    return 0;
} 
*/
