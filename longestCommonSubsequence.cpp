/*
Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

Input:
First line of the input contains no of test cases  T,the T test cases follow.
Each test case consist of 2 space separated integers A and B denoting the size of string str1 and str2 respectively
The next two lines contains the 2 string str1 and str2 .

Output:
For each test case print the length of longest  common subsequence of the two strings .

Constraints:
1<=T<=200
1<=size(str1),size(str2)<=100

Example:
Input:
2
6 6
ABCDGH
AEDFHR
3 2
ABC
AC

Output:
3
2

Explanation
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.

LCS of "ABC" and "AC" is "AC" of length 2
*/
#include<iostream>
using namespace std;
int LCS(string &s1,string &s2){
    int lcs[s1.size()+1][s2.size()+1];
    int i,j;
    for(i=0;i<=s1.size();i++){
        for(j=0;j<=s2.size();j++){
            if(i==0||j==0)
            lcs[i][j]=0;
            else if(s1[i-1]==s2[j-1])
            lcs[i][j]=lcs[i-1][j-1]+1;
            else lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
        }
    }
    return lcs[s1.size()][s2.size()];
}
int main() {
	//code
	int t,m,n;
	string s1,s2;
	cin>>t;
	while(t--){
	    cin>>m>>n;
	    cin>>s1>>s2;
	    cout<<LCS(s1,s2)<<endl;
	}
	return 0;
}