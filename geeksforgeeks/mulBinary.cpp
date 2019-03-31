/*
Given two binary strings that represent value of two integers, find the product of two strings. For example, if the first bit string is “1100” and second bit string is “1010”, output should be 120.

Input:
First line consists of T test cases. Only line of every test case consists of 2 binary strings.

Output:
Single line output, print the multiplied value.

Constraints:
1<=T<=100
1<=Length of string<=100

Example:
Input:
2
1100 01
01 01
Output:
12
1
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int i,t,x=0,y=0;
	string s1,s2;
	cin>>t;
	while(t--){
	    cin>>s1>>s2;
	    x=y=0;
	    for(i=0;i<s1.size();i++){
	        if(s1[i]=='1')
            x+=pow(2,s1.size()-i-1);
	    }
	    for(i=0;i<s2.size();i++){
	        if(s2[i]=='1')
            y+=pow(2,s2.size()-i-1);
	    }
	    cout<<x*y<<endl;
	}
	return 0;
}