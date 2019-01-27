/*
Given a column title string S as appears in an Excel sheet, return its corresponding column number.

 For example

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 

Input:

The first line contains an integer T, depicting total number of test cases. Then following T lines contains a string S.


Output:
Print the column number corresponding to the given string in a new line.


Constraints:
1 ≤ T ≤ 40
1 ≤ |S| <=7

Example:

Input
2
A
AA
Output
1
27
*/
#include<iostream>
using namespace std;

int main() {
	//code
	int t;
	string s;
	cin>>t;
	int i,v;
	while(t--){
	    cin>>s;
	    v=0;
	    reverse(s.begin(),s.end());
	    for(i=0;i<s.size();i++)
	    {
	        v+=((int)s[i]-64)*pow(26,i);
	    }
	    cout<<v<<endl;
	}
	return 0;
}