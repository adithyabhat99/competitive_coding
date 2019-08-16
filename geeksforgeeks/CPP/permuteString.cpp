/*
Given a string, print all permutations of a given string.

Input:
The first line of input contains an integer T, denoting the number of test cases. Each test case contains a single string S in capital letter.

Output:
For each test case, print all permutations of a given string S with single space and all permutations should be in lexicographically increasing order.

Constraints:
1 ≤ T ≤ 10
1 ≤ size of string ≤ 5

Example:
Input:
2
ABC
ABSG

Output:
ABC ACB BAC BCA CAB CBA 
ABGS ABSG AGBS AGSB ASBG ASGB BAGS BASG BGAS BGSA BSAG BSGA GABS GASB GBAS GBSA GSAB GSBA SABG SAGB SBAG SBGA SGAB SGBA
*/

#include <bits/stdc++.h>
using namespace std;
set<string> s;
void printstring(string x,int l,int r){
    if(l==r){
        s.insert(x);
    }
    for(int i=l;i<=r;i++){
        swap(x[l],x[i]);
        printstring(x,l+1,r);
        swap(x[l],x[i]);
    }
}
int main() {
	//code
	string c;
	int t;
	cin>>t;
	while(t--){
	
	    cin>>c;
	    printstring(c,0,c.length()-1);
	    for(auto x:s){
	        cout<<x<<" ";
	    }
	    cout<<endl;
	    s.clear();
	}
	return 0;
}