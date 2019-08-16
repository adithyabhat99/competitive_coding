/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 

NOTE: The alphabets are all in uppercase.

 

Input:

The first line contains an integer T, depicting total number of test cases. Then following T lines contains an integer N.


Output:

Print the string corrosponding to the column number.


Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 10000000

Example:

Input
1
51
Output
AY
/

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	int n,i,j,rem;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    char a[26];
	    for(i=0,j=65;i<26;i++,j++)
	    a[i]=char(j);
	    if(n<=26)
	    cout<<a[n-1];
	    else{
	    vector<char> v;
	    while(n)
	    {
	        rem=n%26;
	        if(rem==0)
	        {
	            v.push_back('Z');n=n/26-1;
	            
	        }
	        else{
	        v.push_back(a[rem-1]);
	        n=n/26;}
	    }
	    std::reverse(std::begin(v),std::end(v));
	    for(auto x:v)
	    cout<<x;
	    }
	    cout<<endl;
	}
	return 0;
}