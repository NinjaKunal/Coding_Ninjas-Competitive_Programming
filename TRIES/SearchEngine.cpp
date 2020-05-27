//SEARCH ENGINE

/*
Let us see how search engines work. Consider the following simple auto complete feature. When you type some characters in the text bar, the engine automatically gives best matching options among it's database. Your job is simple. Given an incomplete search text, output the best search result.
Each entry in engine's database has a priority factor attached to it. We consider a result / search suggestion best if it has maximum weight and completes the given incomplete search query. For each query in the input, print the maximum weight of the string in the database, that completes the given incomplete search string. In case no such string exists, print -1.
INPUT
First line contains two integers n and q, which represent number of database entries and number of search queries need to be completed. Next n lines contain a string s and an integer weight, which are the database entry and it's corresponding priority.

Next q lines follow, each line having a string t, which needs to be completed.
OUTPUT
Output q lines, each line containing the maximum possible weight of the match for given query, else -1, in case no valid result is obtained.
CONSTRAINTS
1 ≤ n, weight, len(s), len(t) ≤ 10^6
1 ≤ q ≤ 10^5
total length of all strings in database entries ≤ 10^6
total length of all query strings ≤ 10^6
SAMPLE INPUT
2 1
hackerearth 10
hackerrank 9
hacker
SAMPLE OUTPUT
10
*/

#include <bits/stdc++.h>
using namespace std;

struct node{
    node* child[26];
    int weight;
};
node* newNode(){
    node* temp = new node;
    for(int i=0;i<26;i++)
        temp->child[i]=NULL;
    temp->weight=0;
    return temp;
}

void insert(node* root,string s,int weight){
    if(s.empty())
        return;
    node* temp;
	int index = s[0]-'a';
    if(root->child[index]){
        temp = root->child[index];
    }else{
        temp= newNode();
        root->child[index]=temp;
    }
    if(root->weight<weight)
    	root->weight=weight;
    insert(temp,s.substr(1),weight);
}

int search(node* root,string s){
    node* temp = root;
    int bestweight =-1;
    for(int i=0;i<s.size();i++){
        int index= s[i]-'a';
        node* child = temp->child[index];
        if(child){
            temp = child;
            bestweight = child->weight;
        }else {
            return -1;
        }
    }
    return bestweight; 
    
}

int main()
{
    int n,q;
    cin>>n>>q;
    node* root= newNode();
    for(int i=0;i<n;i++)
    {
        string s;
        int w;
        cin>>s>>w;
        insert(root,s,w);
    }
    for(int i=0;i<q;i++){
        string qu;
        cin>>qu;
        cout<<search(root,qu)<<"\n";
    }
    return 0;
}
