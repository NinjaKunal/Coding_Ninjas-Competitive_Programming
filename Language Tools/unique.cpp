//EXTRACT UNIQUE CHARACTERS

/*
Given a string, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same.
Input format :
String S
Output format :
Output String
Constraints :
0 <= Length of S <= 10^8
Sample Input 1 :
ababacd
Sample Output 1 :
abcd
Sample Input 2 :
abcde
Sample Output 2 :
abcde
*/

char* uniqueChar(char *str){
    string st = str;  
    auto res = unique(st.begin(), st.end()); 
  
    cout << string(st.begin(), res) 
         << endl; 
    return NULL;

}
