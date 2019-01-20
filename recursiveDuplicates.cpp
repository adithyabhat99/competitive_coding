/*
Given a string s, recursively remove adjacent duplicate characters from the string s. The output string should not have any adjacent duplicates.
 

Input:
The first line of input contains an integer T, denoting the no of test cases. Then T test cases follow. Each test case contains a string str.

Output:
For each test case, print a new line containing the resulting string.

Constraints:
1<=T<=100
1<=Length of string<=50

Example:
Input:
2
geeksforgeek
acaaabbbacdddd

Output:
gksforgk
acac
*/

#include <iostream>
using namespace std;
string rec(string s){
    string x;
    int i,m=0;
    
    for(i=0;i<s.length();i++){
        if(!i)
        {
            if(s[i]!=s[i+1])
            x.push_back(s[i]);
            continue;
        }
        if(i==s.length()-1)
        {
            if(s[i]!=s[i-1])
            x.push_back(s[i]);
            continue;
        }
        if(s[i]!=s[i+1] && s[i]!=s[i-1])
        x.push_back(s[i]);
        else m=1;
    }
    if(m)
    return rec(x);
    return x;
}
int main() 
{
    int t;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        s=rec(s);
        cout<<s<<endl;
    }
	return 0;
}