//HELP ME PRADYUMANA

/*
Pradyumn is tired of using auto - correct feature in his smartphone. He needs to correct his auto - correct more times than the auto - correct corrects him. Pradyumn is thinking to make his own app for mobile which will restrict auto - correct feature, instead it will provide auto - completion. Whenever Pradyumn types factorial, auto - correct changes it to fact. Pradyumn's App will show options such as fact, factorial, factory. Now, he can chose from any of these options. As Pradyumn is busy with his front - end work of his App. He asks you to help him. He said "You will be given set of words(words may repeat too but counted as one only). Now, as user starts the app, he will make queries(in lowercase letters only). So, you have to print all the words of dictionary which have the prefix same as given by user as input. And if no such words are available, add this word to your dictionary." As you know, Pradyumn want this app to be as smart as him :P So, implement a program for him such that he can release it on Fun Store.
INPUT CONSTRAINTS
1≤N≤30000
sum(len(string[i]))≤2∗10^5
1≤Q≤10^3
INPUT FORMAT
Single integer N which denotes the size of words which are input as dictionary
N lines of input, where each line is a string of consisting lowercase letter
Single integer Q which denotes the number of queries.
Q number of lines describing the query string on each line given by user
OUTPUT FORMAT
If auto - completions exists, output all of them in lexicographical order else output "No suggestions" without quotes

NOTE: All strings are lowercase
SAMPLE INPUT
3
fact
factorial
factory
2
fact
pradyumn
SAMPLE OUTPUT
fact
factorial
factory
No suggestions
*/

#include <bits/stdc++.h>
using namespace std;
#define chars 26
map<int,char> m;
struct node{
    node* child[26];
    bool wordlast;
};
node* newNode(){
    node* temp = new node;
    for(int i=0;i<26;i++)
        temp->child[i]=NULL;
    	temp->wordlast=false;
    return temp;
}

bool isleaf(node* root){
    for(int i=0;i<chars;i++)
        if(root->child[i]!=NULL)\
            return false;
    return true;
}

void dfs(node* root,string &query){
    //cout<<"new call\n";
    if(root->wordlast){
        //cout<<"last found\n";
        cout<<query<<endl;
    }
        
    if(isleaf(root)){
        //cout<<"leaf found";
        return;
    }
    for(int i=0;i<chars;i++){
        //cout<<i<<" "<<query<<"\n";
        if(root->child[i]!=NULL){
        	query.push_back(m[i]);
            node *temp= root->child[i]; 
        	dfs(temp,query);
            query.pop_back();
        }
    }
}

void insert(struct node *root,  const string s) 
{ 
    struct node *temp = root; 
  
    for (int i = 0; i < s.length(); i++) 
    { 
        int index = s[i]-'a'; 
        if (!temp->child[index]) 
            temp->child[index] = newNode(); 
  
        temp = temp->child[index]; 
    } 
   
    temp->wordlast = true; 
} 

int search(node* root,string s){
    node* temp = root;
    for(int i=0;i<s.size();i++){
        int index= s[i]-'a';
        node* child = temp->child[index];
        if(child){
            temp = child;
        }else {
            return 0;
        }
    }
    
    dfs(temp,s);
    return 1; 
    
}

int main()
{
    char x= 'a';
    for(int i=0;i<26;i++,x++){
        m[i]=x;
    }
        
    int n,q;
    cin>>n;
    node* root= newNode();
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        insert(root,s);
    }
	
    cin>>q;
    for(int i=0;i<q;i++){
        string qu;
        cin>>qu;
        if(!search(root,qu)){
           cout<<"No suggestions"<<"\n";
           insert(root,qu);
        }
           
    }
    return 0;
}
