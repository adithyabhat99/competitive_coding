/*
Given a string consisting of uppercase and lowercase characters, you need to sort uppercase and lowercase letters separately such that if the ith place in the original string had an Uppercase character then it should not have a lowercase character after being sorted and vice versa.

Input: The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.

The first line of each test case contains a single integer N denoting the length of string.

The second line contains a string of length N, consisting of uppercase and lowercase characters.


Output: Print T lines consisting of a sorted strings for the particular test case.


Constraints:

1 ≤ T ≤ 50

1 ≤ N ≤ 1000


Example:

Input:

1

12

defRTSersUXI

Output:

deeIRSfrsTUX
*/

#include <bits/stdc++.h>
using namespace std;
int main() {
	//code
	
	int t,i,j,n,k;
	cin>>t;
	while(t--){
	    cin>>n;
	    int min;
	    char s[n],c;
	    getchar();
	    cin>>s;
	    vector<char>upper;
	    vector<char>lower;
	   for(i=0;i<n;i++)
	   {
	       if(isupper(s[i])){
	           upper.push_back(s[i]);
	       }
	       else
	       lower.push_back(s[i]);
	   }
	   sort(upper.begin(),upper.end());
	   sort(lower.begin(),lower.end());
	   k=j=0;
	   for(i=0;i<n;i++)
	   {
	       if(islower(s[i])){
	       s[i]=lower[j];
	       j++;
	       }
	       else
	       {
	           s[i]=upper[k];
	           k++;
	       }
	   }
	   for(i=0;i<n;i++)
	   cout<<s[i];
	   cout<<endl;
	   
	}
	return 0;
}