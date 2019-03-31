/*
Given a binary string S, count number of substrings that start and end with 1. For example, if the input string is “00100101”, then there are three substrings “1001”, “100101” and “101”

Input:
The first line contains T denoting the number of testcases. Then follows description of testcases. 
Each case contains a string S containing 0's and 1's.

Output:
For each test case, output a single line denoting number of substrings possible.

Constraints:
1<=T<=100
1<=Length of String<=100

Example:
Input:
1
10101
Output:
3
*/

#include<iostream>
using namespace std;
int main(){
    int t;
    string s;
    int i,j;
    cin>>t;
    while(t--){
        cin>>s;
        int c=0,a[s.length()],x=0;
        for(i=0;i<s.length();i++){
            if(s[i]=='1')
                c++;
            }
            cout<<(c*(c-1))/2<<endl;
    }
}